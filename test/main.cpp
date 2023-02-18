#include "gtest/gtest.h"
#include "b_tree/order_book.h"
#include "array/order_book.h"
#include "common.h"

//TEST(BtreeOrderBookTest, bids) {
//	BtreeOrderBook book;
//	Element one{ 1, 1, Side::BID };
//	Element two{ 3, 1, Side::BID };
//	Element three{ 2, 1, Side::BID };
//	Element four{ 4, 1, Side::BID };
//	book.add(one);
//	book.add(two);
//	book.add(three);
//	book.add(four);
//	ASSERT_EQ(book.vwap(4), 2.5);
//}
//
//TEST(BtreeOrderBookTest, vwap) {
//	BtreeOrderBook book;
//	Element tests[10]{
//		{ 37.37, 187456, Side::BID },
//		{ 37.36, 153408, Side::BID },
//		{ 37.35, 340823, Side::BID },
//		{ 37.34, 385363, Side::BID },
//		{ 37.33, 209282, Side::BID },
//		{ 37.38, 11380, Side::ASK },
//		{ 37.39, 19601, Side::ASK },
//		{ 37.40, 19760, Side::ASK },
//		{ 37.41, 37236, Side::ASK },
//		{ 37.42, 65811, Side::ASK },
//	};
//	for (int i = 0; i < 10; i++) {
//		book.add(tests[i]);
//	}
//	double res = (int(book.vwap(5) * 10000) / 10000.0);
//	ASSERT_EQ(res, 37.3543);
//}

TEST(OrderBookTest, bids) {
	OrderBook book(10);
	Element one{ 1, 1, Side::BID };
	Element two{ 3, 1, Side::BID };
	Element three{ 2, 1, Side::BID };
	Element four{ 4, 1, Side::BID };
	book.add(one);
	book.add(two);
	book.add(three);
	book.add(four);
	ASSERT_EQ(book.vwap(4), 2.5);
}

TEST(OrderBookTest, del) {
	OrderBook book(10);
	Element one{ 1, 1, Side::BID };
	Element two{ 3, 1, Side::BID };
	Element three{ 2, 1, Side::BID };
	Element four{ 4, 1, Side::BID };
	book.add(one);
	book.add(two);
	book.add(three);
	book.del(two.price);
}

TEST(OrderBookTest, vwap) {
	OrderBook book(10);
	Element tests[10]{
		{ 37.37, 187456, Side::BID },
		{ 37.36, 153408, Side::BID },
		{ 37.35, 340823, Side::BID },
		{ 37.34, 385363, Side::BID },
		{ 37.33, 209282, Side::BID },
		{ 37.38, 11380, Side::ASK },
		{ 37.39, 19601, Side::ASK },
		{ 37.40, 19760, Side::ASK },
		{ 37.41, 37236, Side::ASK },
		{ 37.42, 65811, Side::ASK },
	};
	for (int i = 0; i < 10; i++) {
		book.add(tests[i]);
	}
	double res = (int(book.vwap(5) * 10000) / 10000.0);
	ASSERT_EQ(res, 37.3543);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}