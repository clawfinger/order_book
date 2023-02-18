#include "order_book.h"

BtreeOrderBook::BtreeOrderBook()
{
}

void BtreeOrderBook::add(Element elem)
{
	switch (elem.side) {
	case Side::ASK:
		m_asks[elem.price] = elem.quantity;
	case Side::BID:
		m_bids[elem.price] = elem.quantity;
	}
}

void BtreeOrderBook::change(Element elem)
{
	switch (elem.side) {
	case Side::ASK:
		m_asks[elem.price] += elem.quantity;
	case Side::BID:
		m_bids[elem.price] += elem.quantity;
	}
}

void BtreeOrderBook::del(double price)
{
	if (price <= m_bids.begin()->first) {
		m_bids.erase(price);
		return;
	}
	m_asks.erase(price);
}

double BtreeOrderBook::vwap(size_t depth)
{
	double totoalDepthPrice = 0.0;
	double fullAmount = 0.0;
	auto bidIt = m_bids.begin();
	auto askIt = m_asks.begin();
	while (depth != 0) {
		if (bidIt != m_bids.end()) {
			totoalDepthPrice += (bidIt->first * bidIt->second);
			fullAmount += bidIt->second;
			std::advance(bidIt, 1);
		}

		if (askIt != m_asks.end()) {
			totoalDepthPrice += (askIt->first * askIt->second);
			fullAmount += askIt->second;
			std::advance(askIt, 1);
		}

		depth--;
	}
	return totoalDepthPrice / fullAmount;
}
