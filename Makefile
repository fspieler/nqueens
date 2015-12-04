.PHONY: all clean

all: clean nqueens_recur


nqueens_recur: nqueens_recur.cpp
	g++ -O3 -I. -W -Wall -Wextra -std=c++11 nqueens_recur.cpp -o nqueens_recur

#run-test: test
#	@\time -p ./test --gtest_color=yes

#test: ccct_trie.t.cpp
#	g++ -O2 -I. -pthread -W -Wall -Wextra -std=c++11 ccct_trie.internal.t.cpp /usr/local/lib/libgtest.a -o test

clean: 
	rm -f nqueens_recur
