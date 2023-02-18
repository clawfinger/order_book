#pragma once
#include "common.h"
#include <vector>
#include <functional>

class OrderBook {
public:
	OrderBook(size_t capacity);
	// Add element with price and quantity .
	void add(Element elem);
	// Find element with price and set new quantity for it.
	void change(Element elem);
	// Remove element with price equal to price .
	void del(double price);
	// Calculate Volume Weighted Average Price limiting each side with top depth levels .
	double vwap(size_t depth);
private:
	std::vector<Element> m_rows[2];
	std::function<bool(const Element&, const Element&)> m_comparators[2];
};