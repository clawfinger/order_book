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
	double totalDepthPrice = 0.0;
	double fullAmount = 0.0;

	const auto& bids = m_rows[Side::BID];
	const auto& asks = m_rows[Side::ASK];
	size_t bidsSize = bids.size();
	size_t asksSize = asks.size();
	size_t bidCount = std::min(bidsSize, depth);
	size_t askCount = std::min(asksSize, depth);

	for (size_t i = 1; i <= bidCount; i++) {
		size_t idx = bidsSize - i;
		totalDepthPrice += (bids[idx].price * bids[idx].quantity);
		fullAmount += bids[idx].quantity;
	}

	for (size_t i = 1; i <= askCount; i++) {
		size_t idx = asksSize - i;
		totalDepthPrice += (asks[idx].price * asks[idx].quantity);
		fullAmount += asks[idx].quantity;
	}

	return totalDepthPrice / fullAmount;
}
