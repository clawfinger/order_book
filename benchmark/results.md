Results of add without push_back check
--------------------------------------------------------------------------------
Benchmark                                      Time             CPU   Iterations
--------------------------------------------------------------------------------
OrderBookBenchmark/insertingBestCase      475565 ns       284375 ns        10000
OrderBookBenchmark/insertingWorstCase     840637 ns       470312 ns        10000

Results of add with push_back check
--------------------------------------------------------------------------------
Benchmark                                      Time             CPU   Iterations
--------------------------------------------------------------------------------
OrderBookBenchmark/insertingBestCase      196365 ns       100000 ns        10000
OrderBookBenchmark/insertingWorstCase     283021 ns       153125 ns        10000

