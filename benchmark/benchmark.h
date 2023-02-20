#include <benchmark/benchmark.h>
#include <vector>
#include <random>
#include "common.h"
#include "array/order_book.h"
#include "b_tree/order_book.h"



class OrderBookBenchmark : public benchmark::Fixture {
public:
	OrderBookBenchmark();
	void SetUp(const ::benchmark::State& state) {
	}

	void TearDown(const ::benchmark::State& state) {
		m_arrayBook = OrderBook(1000000);
		m_treeBook = BtreeOrderBook();
	}
	Element getRandom(double from, double to);
	OrderBook m_arrayBook;
	BtreeOrderBook m_treeBook;
	std::random_device dev;
	std::mt19937 rng;
	std::uniform_int_distribution<std::mt19937::result_type> dist6;
};

BENCHMARK_F(OrderBookBenchmark, insertingArray)(benchmark::State& st) {
	for (auto _ : st) {
		m_arrayBook.add(getRandom(100, 9999));
	}
}

BENCHMARK_F(OrderBookBenchmark, insertingTree)(benchmark::State& st) {
	for (auto _ : st) {
		m_treeBook.add(getRandom(100, 9999));
	}
}

BENCHMARK_F(OrderBookBenchmark, insertingWithCalcArray)(benchmark::State& st) {
	for (auto _ : st) {
		for (int i = 0; i < 100; i++) {
			m_arrayBook.add(getRandom(100, 9999));
		}
		m_arrayBook.vwap(100);
	}
}

BENCHMARK_F(OrderBookBenchmark, insertingWithCalcTree)(benchmark::State& st) {
	for (auto _ : st) {
		for (int i = 0; i < 100; i++) {
			m_treeBook.add(getRandom(100, 9999));
		}
		m_treeBook.vwap(100);
	}
}

BENCHMARK_F(OrderBookBenchmark, insertingAtEndArray)(benchmark::State& st) {
	for (int i = 1; i <= 1000; i++) {
		m_arrayBook.add({ double(i), 1, Side::BID });
	}
	static std::uniform_int_distribution<std::mt19937::result_type> probablityDist(1, 10);
	static std::uniform_int_distribution<std::mt19937::result_type> lowProbability(1, 800);
	static std::uniform_int_distribution<std::mt19937::result_type> highProbability(801, 1000);

	for (auto _ : st) {
		int probability = probablityDist(rng);
		if (probability > 8) {
			double price = double(lowProbability(rng));
			m_arrayBook.del(price);
			m_arrayBook.add({price , 1, Side::BID });
		}
		else {
			double price = double(highProbability(rng));
			m_arrayBook.del(price);
			m_arrayBook.add({ price , 1, Side::BID });
		}
	}
}

BENCHMARK_F(OrderBookBenchmark, insertingAtEndTree)(benchmark::State& st) {
	for (int i = 1; i <= 1000; i++) {
		m_treeBook.add({ double(i), 1, Side::BID });
	}
	static std::uniform_int_distribution<std::mt19937::result_type> probablityDist(1, 10);
	static std::uniform_int_distribution<std::mt19937::result_type> lowProbability(1, 800);
	static std::uniform_int_distribution<std::mt19937::result_type> highProbability(801, 1000);

	for (auto _ : st) {
		int probability = probablityDist(rng);
		if (probability > 8) {
			double price = double(lowProbability(rng));
			m_treeBook.del(price);
			m_treeBook.add({ price , 1, Side::BID });
		}
		else {
			double price = double(highProbability(rng));
			m_treeBook.del(price);
			m_treeBook.add({ price , 1, Side::BID });
		}
	}
}