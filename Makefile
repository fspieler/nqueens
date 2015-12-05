.PHONY: all clean run_test_iter run_test_recur

all: clean nqueens_recur nqueens_iter

nqueens_recur: nqueens_recur.cpp main.cpp
	g++ -O3 -I. -W -Wall -Wextra -std=c++14 main.cpp nqueens_recur.cpp -o nqueens_recur

nqueens_iter: nqueens_iter.cpp main.cpp
	g++ -O3 -I. -W -Wall -Wextra -std=c++14 main.cpp nqueens_iter.cpp -o nqueens_iter

run_test_iter: test_iter
	./test_iter --gtest_filter=nqueens.n_less*

run_test_recur: test_recur 
	./test_recur --gtest_filter=nqueens.n_less*

test_recur: tests.cpp nqueens_recur.cpp
	g++ -O3 -I. -pthread -W -Wall -Wextra -std=c++11 tests.cpp nqueens_recur.cpp /usr/local/lib/libgtest.a -o test_recur

test_iter: tests.cpp nqueens_iter.cpp
	g++ -O3 -I. -pthread -W -Wall -Wextra -std=c++11 tests.cpp nqueens_iter.cpp /usr/local/lib/libgtest.a -o test_iter

clean: 
	rm -f nqueens_recur nqueens_iter
