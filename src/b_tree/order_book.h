#pragma once
#include "common.h"
#include <absl/container/btree_map.h>

class BtreeOrderBook {
public:
	BtreeOrderBook();
	// Add element with price and quantity .
	void add(Element elem);
	// Find element with price and set new quantity for it.
	void change(Element elem);
	// Remove element with price equal to price .
	void del(double price);
	// Calculate Volume Weighted Average Price limiting each side with top depth levels .
	double vwap(size_t depth);
private:
	absl::btree_map<double, double, std::less<double>> m_bids;
	absl::btree_map<double, double, std::greater<double>> m_asks;
};