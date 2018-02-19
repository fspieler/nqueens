#include <array>
#include <iostream>
#include "nqueens.h"

class NQueensRecurSolver {
  std::array<int,25> cols;
  std::array<int,50> diag_desc;
  std::array<int,50> diag_asc;
  long long _count;
  long long recur_helper(int n, int r, long long count){
    if(r == n)
    {
      return ++count;
    }
    for(int c = 0; c < (!r ? (n&1) ? n/2+1 : n/2 : n); ++c)
    {
      if(r == 0 && n%2 && c == n/2 )
        count*=2;
      if(!cols[c] && !diag_desc[n-1+r-c] && !diag_asc[r+c])
      {
        cols[c] = true;
        diag_desc[n-1+r-c] = true;
        diag_asc[r+c] = true;
        count = recur_helper(n, r+1,count);
        cols[c] = false;
        diag_desc[n-1+r-c] = false;
        diag_asc[r+c] = false;
      }
    }
    if( r==0 && !(n&1))
      count*=2;
    return count;
  }
public:
  NQueensRecurSolver() = delete;
  NQueensRecurSolver(int n) :
    cols{},
    diag_desc{},
    diag_asc{},
    _count(recur_helper(n,0,0))
  {}
  long long value(){
    return _count;
  }
};

long long nqueens(int n){
  return NQueensRecurSolver(n).value();
}
