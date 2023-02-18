#pragma once

enum Side { BID = 0, ASK = 1};

struct Element {
	double price;
	double quantity;
	Side side;
};

class IOrderBook {
public:
	// Add element with price and quantity .
	virtual void add(Element elem) = 0;
	// Find element with price and set new quantity for it.
	virtual void change(Element elem) = 0;
	// Remove element with price equal to price .
	virtual void del(double price) = 0;
	// Calculate Volume Weighted Average Price limiting each side with top depth levels .
	virtual double vwap(size_t depth) = 0;
};