.PHONY: all clean run_test_iter run_test_recur run_test_threads

all: clean nqueens_recur nqueens_iter

clean: 
	rm -f nqueens_recur nqueens_iter nqueens_threads test_iter test_recur test_threads

# iterative
nqueens_iter: nqueens_iter.cpp main.cpp
	g++ -O3 -I. -W -Wall -Wextra -std=c++14 main.cpp nqueens_iter.cpp -o nqueens_iter

test_iter: tests.cpp nqueens_iter.cpp
	g++ -O3 -I. -pthread -W -Wall -Wextra -std=c++14 tests.cpp nqueens_iter.cpp -lgtest_main -o test_iter

run_test_iter: test_iter
	./test_iter --gtest_filter=nqueens.n_less*

# recursive
nqueens_recur: nqueens_recur.cpp main.cpp
	g++ -O3 -I. -W -Wall -Wextra -std=c++14 main.cpp nqueens_recur.cpp -o nqueens_recur

test_recur: tests.cpp nqueens_recur.cpp
	g++ -O3 -I. -pthread -W -Wall -Wextra -std=c++14 tests.cpp nqueens_recur.cpp -lgtest_main -o test_recur

run_test_recur: test_recur 
	./test_recur --gtest_filter=nqueens.n_less*

# multi-threaded
nqueens_threads: nqueens_threads.cpp main.cpp
	g++ -O3 -I. -pthread -W -Wall -Wextra -std=c++14 main.cpp nqueens_threads.cpp -o nqueens_threads

test_threads: tests.cpp nqueens_threads.cpp
	g++ -O3 -I. -pthread -W -Wall -Wextra -std=c++14 tests.cpp nqueens_threads.cpp -lgtest_main -o test_threads

run_test_threads: test_threads 
	./test_threads --gtest_filter=nqueens.n_less*
