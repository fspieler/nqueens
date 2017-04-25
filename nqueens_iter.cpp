#include "debug.h"
#include <array>

#include "nqueens.h"

class NQueensIterSolver {
  std::array<int,25> cols;
  std::array<int,50> diag_desc;
  std::array<int,50> diag_asc;
  std::array<int,25> stack;
  int stack_index;
  long long count;
public:

  NQueensIterSolver() = delete;
  NQueensIterSolver(int n) :
    cols{},
    diag_desc{},
    diag_asc{},
    stack{},
    stack_index(0),
    count(0)
  {

    int r = 0;
  outer:
    while(r >= 0)
    {
      if(r == n)
        count++;
      else
      {
        int c = 0;
        if(stack_index > r)
        {
          c = 1+stack[stack_index--];
        }
        for(; c < (!r ? (n&1) ? n/2+1 : n/2 : n); ++c)
        {
          if(n&1 && r == 0 && c == n/2)
            count*=2;
          if(!cols[c] && !diag_desc[n-1+r-c] && !diag_asc[r+c])
          {
            stack_index++;
            stack[stack_index] = c;
            cols[c] = true;
            diag_desc[n-1+r-c] = true;
            diag_asc[r+c] = true;
            r++;
            goto outer;
          }
        }
      }

      int c = stack[stack_index];
      --r;
      cols[c] = false;
      diag_desc[n-1+r-c] = false;
      diag_asc[r+c] = false;
    }
    if(n%2==0)
      count*=2;
  }
  long long value(){
    return count;
  }
};

long long nqueens(int n)
{
  return NQueensIterSolver(n).value();
}
