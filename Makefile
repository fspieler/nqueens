.PHONY: all run-test clean

all: clean run

run: nqueens
	@\time -p ./nqueens

nqueens:
	g++ -O2 -I. -W -Wall -Wextra -std=c++14 main.cpp -o nqueens

run-test: test
	@\time -p ./test --gtest_color=yes

test: ccct_trie.t.cpp
	g++ -O2 -I. -pthread -W -Wall -Wextra -std=c++14 ccct_trie.internal.t.cpp /usr/local/lib/libgtest.a -o test

clean: 
	rm -f nqueens
