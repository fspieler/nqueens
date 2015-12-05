#include <debug.h>
#include <array>

#include <nqueens.h>

std::array<int,25> cols;
std::array<int,50> diag_desc;
std::array<int,50> diag_asc;
std::array<int,25> stack;
int stack_index = 0;
int count = 0;

void reset()
{
  for(auto& e : cols)
    e = 0;
  for(auto& e : diag_desc)
    e = 0;
  for(auto& e : diag_asc)
    e = 0;
  for(auto& e : stack)
    e = 0;
  stack_index = 0;
  count = 0;
}

int nqueens(int DIM)
{
  int r = 0;
outer:
  while(r >= 0)
  {
    if(r == DIM)
      count++;
    else
    {
      int c = 0;
      if(stack_index > r)
      {
        c = 1+stack[stack_index--];
      }
      for(; c < (!r ? (DIM&1) ? DIM/2+1 : DIM/2 : DIM); ++c)
      {
        if(DIM&1 && r == 0 && c == DIM/2)
          count*=2;
        if(!cols[c] && !diag_desc[DIM-1+r-c] && !diag_asc[r+c])
        {
          stack_index++;
          stack[stack_index] = c;
          cols[c] = true;
          diag_desc[DIM-1+r-c] = true;
          diag_asc[r+c] = true;
          r++;
          goto outer;
        }
      }
    }

    int c = stack[stack_index];
    --r;
    cols[c] = false;
    diag_desc[DIM-1+r-c] = false;
    diag_asc[r+c] = false;
  }
  if(DIM%2==0)
    count*=2;
  return count;
}
