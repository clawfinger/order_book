#include "benchmark.h"

OrderBookBenchmark::OrderBookBenchmark(): m_arrayBook(1000000), rng(dev())
{
/*	m_worstCaseData = {
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
	m_bestCaseData = {
		{ 37.33, 209282, Side::BID },
		{ 37.34, 385363, Side::BID },
		{ 37.35, 340823, Side::BID },
		{ 37.36, 153408, Side::BID },
		{ 37.37, 187456, Side::BID },
		{ 37.42, 65811, Side::ASK },
		{ 37.41, 37236, Side::ASK },
		{ 37.40, 19760, Side::ASK },
		{ 37.39, 19601, Side::ASK },
		{ 37.38, 11380, Side::ASK },
	}*/;

}

Element OrderBookBenchmark::getRandom(double from, double to)
{
	//static std::uniform_int_distribution<std::mt19937::result_type> dist(100, 9999);
	static std::uniform_int_distribution<std::mt19937::result_type> dist(from, to);

	double price = dist(rng);
	if (price < 4949.0) {
		return { price / 100.0, 1, Side::BID };
	}
	return { price / 100.0, 1, Side::ASK };
}
