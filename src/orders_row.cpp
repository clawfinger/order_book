#include "orders_row.h"

OrdersRow::OrdersRow(size_t size) : m_row(size), m_top(0)
{
}

bool OrdersRow::add(Element elem)
{
	if (m_row.size() == m_top) {
		return false;
	}
	if (m_row[m_top].price > elem.price) {
		m_row[++m_top] = elem;
	}
	else {
		auto insertPos = std::upper_bound(m_row.begin(), m_row.end(), elem);
		memmove(insertPos, insertPos + 1, std::distance(insertPos, &m_row[m_top]) * sizeof(Element));
	}
	return true;
}

void OrdersRow::change(Element elem)
{
}

void OrdersRow::del(double price)
{
	
}

double OrdersRow::vwap(size_t depth)
{
	return 0.0;
}

size_t OrdersRow::size()
{
	return m_row.size();
}
