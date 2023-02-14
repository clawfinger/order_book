#pragma once
#include <vector>
#include "interfaces.h"


class OrdersRow {
public:
	OrdersRow(size_t size);
	bool add(Element elem);
	// Find element with price and set new quantity for it.
	void change(Element elem);
	// Remove element with price equal to price .
	void del(double price);
	// Calculate Volume Weighted Average Price limiting each side with top depth levels .
	double vwap(size_t depth);
	size_t size();
private:
	std::vector<Element> m_row;
	size_t m_top;
};