#include <gtest/gtest.h>
#include "interfaces.h"
#include "orders_row.h"

// Demonstrate some basic assertions.
TEST(Row, RowInsert) {
	OrdersRow row(5);
	Element one{ 1, 1, Side::BID };
	Element two{ 3, 1, Side::BID };
	Element three{ 2, 1, Side::BID };
	row.add(one);
	row.add(two);
	row.add(three);
}