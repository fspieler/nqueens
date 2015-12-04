#include <vector>
#include <stdio.h>
#include <cstdlib>

std::vector<int> cols(25,0);
std::vector<int> diag_desc(50,0);
std::vector<int> diag_asc(50,0);
int count = 0;

int num_solns(int DIM, int r=0)
{
  if(r == DIM)
  {
    return ++count;
  }
  for(int c = 0; c < (!r ? (DIM&1) ? DIM/2+1 : DIM/2 : DIM); ++c)
  {
    if(r == 0 && DIM%2 && c == DIM/2 )
      count*=2;
    if(!cols[c] && !diag_desc[DIM-1+r-c] && !diag_asc[r+c])
    {
      cols[c] = true;
      diag_desc[DIM-1+r-c] = true;
      diag_asc[r+c] = true;
      num_solns(DIM, r+1);
      cols[c] = false;
      diag_desc[DIM-1+r-c] = false;
      diag_asc[r+c] = false;
    }
  }
  if( r==0 && !(DIM&1))
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
