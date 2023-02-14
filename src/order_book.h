#pragma once
#include "interfaces.h"

class OrderBook : public IOrderBook {
public:
	// Add element with price and quantity .
	virtual void add(Element elem);
	// Find element with price and set new quantity for it.
	virtual void change(Element elem);
	// Remove element with price equal to price .
	virtual void del(double price);
	// Calculate Volume Weighted Average Price limiting each side with top depth levels .
	virtual double vwap(size_t depth);
};