#include <debug.h>
#include <vector>
#include <array>
#include <stdio.h>
#include <cstdlib>

std::array<int,25> cols;
std::array<int,50> diag_desc;
std::array<int,50> diag_asc;
std::array<int,25> stack;
int stack_index = 0;
int count = 0;

int num_solns(int DIM)
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

int main(int argc,char**argv)
{
  if(argc < 2)
  {
    printf("Provide single argument n (number of queens on n*n board)\n");
    return 1;
  }

  int dim = atoi(argv[1]);
  printf("%d: %d\n", dim, num_solns(dim));
  return 0;
}
