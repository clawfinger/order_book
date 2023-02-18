#include "order_book.h"

OrderBook::OrderBook(size_t capacity)
{
	m_rows[Side::BID].reserve(capacity);
	m_rows[Side::ASK].reserve(capacity);
	m_comparators[Side::BID] = [](const Element& left, const Element& right) -> bool{
		return left.price < right.price;
	};
	m_comparators[Side::ASK] = [](const Element& left, const Element& right) -> bool {
		return left.price > right.price;
	};
}

void OrderBook::add(Element elem)
{
	auto& row = m_rows[elem.side];
	auto insertPoint = row.end();
	while (insertPoint != row.begin()) {
		insertPoint--;
		if (m_comparators[elem.side](*insertPoint, elem)) {
			insertPoint++;
			break;
		}
	}
	row.insert(insertPoint, elem);
}

void OrderBook::change(Element elem)
{
	auto& row = m_rows[elem.side];
	auto insertPoint = row.end();
	while (insertPoint != row.begin()) {
		insertPoint--;
		if (insertPoint->price == elem.price) {
			insertPoint->quantity += elem.quantity;
			break;
		}
	}
}

void OrderBook::del(double price)
{
	std::vector<Element>* row;
	if (price <= m_rows[Side::BID].rbegin()->price) {
		row = &m_rows[Side::BID];
	}
	else {
		row = &m_rows[Side::ASK];
	}
	auto insertPoint = row->end();
	while (insertPoint != row->begin()) {
		insertPoint--;
		if (insertPoint->price == price) {
			row->erase(insertPoint);
			break;
		}
	}
}

double OrderBook::vwap(size_t depth)
{
	double totoalDepthPrice = 0.0;
	double fullAmount = 0.0;
	auto bidIt = m_rows[Side::BID].rbegin();
	auto askIt = m_rows[Side::ASK].rbegin();
	while (depth != 0) {
		if (bidIt != m_rows[Side::BID].rend()) {
			totoalDepthPrice += (bidIt->price * bidIt->quantity);
			fullAmount += bidIt->quantity;
			bidIt++;
		}

		if (askIt != m_rows[Side::ASK].rend()) {
			totoalDepthPrice += (askIt->price * askIt->quantity);
			fullAmount += askIt->quantity;
			askIt++;
		}

		depth--;
	}
	return totoalDepthPrice / fullAmount;
}
