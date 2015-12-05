# nqueens

N-Queens is a comp sci take on a classic chess problem:

> Given a standard 8x8 board, place eight queens on the board such that none of the queens can attack any of the others.

*N-Queens* means that we must place N queens on an NxN board.

This project is a progression of attempts I made at answering how many possible solutions there exist for a given N.

All attempts use fundamentally the same backtracking approach; I try placing a queen on the first column in the first row, then place a queen on the first square on the second row that doesn't attack the first square, and so on, until I have either found a solution or run out of squares. If I run out of squares, I go up one level and move that queen over one column.

While I was familiar with the backtracking solution described above, I also gained inspiration and borrowed intuition from [Jeff Somers's solution and write up](http://jsomers.com/nqueen_demo/nqueens.html) and in particular an article he cites: http://penguin.ewu.edu/~trolfe/SCCS-95/SCCS-95.html.

There are several optimizations I use:

* There's no need to iterate over every column in the first row, since each solution after the midway point should be a reflection of a solution before the midway point. So it should be enough to simply double the number of solutions for each column in the first row, although if there is an odd number of columns (ie N is odd), it's total should not be doubled.

* Checking whether or not a square is attacked by one of the already-placed queens can be a constant time operation by keeping three additional arrays: occupied columns, occupied "ascending" diagonals, and occupied "descending" diagonals. For a given row and column, there should be a constant time lookup to see whether or not the current column, ascending diagonal, or descending diagonal is already occupied. If none are, that square is a candidate. If any are, it is not.

* While my initial attempt was recursive, which required that the inner loop of the algorithm required frequent function calls. Depending on the problem size, this could mean trillions of extra function calls, which adds up. So subsequent attempts are iterative. This ended up having a negligible effect on performance.

* Computing all of the permutations and solutions for different columns in a row is embarassingly parallel, so I sped up my iterative solution by computing each column of the first row in its own thread. This ended up having a rather large effect on performance on my 8-core processor: hovering around 6x for problem sets around N=14 through N=17 (I haven't tested higher yet).

A limitation of the above multi-threading approach is that some columns are more difficult than others, so typically one thread takes longer than all the rest to finish. I'm still exploring approaches for keeping threads busy. Perhaps it is possible to get closer to that mythical 8x speedup.

