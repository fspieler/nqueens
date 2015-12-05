#include <vector>
#include <nqueens.h>

std::vector<int> cols(25,0);
std::vector<int> diag_desc(50,0);
std::vector<int> diag_asc(50,0);

int count = 0;

void reset()
{
  for(auto& e : cols)
    e = 0;
  for(auto& e : diag_desc)
    e = 0;
  for(auto& e : diag_asc)
    e = 0;
  count = 0;
}

int nqueens(int,int);

int nqueens(int DIM)
{
  return nqueens(DIM,0);
}

int nqueens(int DIM, int r)
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
      nqueens(DIM, r+1);
      cols[c] = false;
      diag_desc[DIM-1+r-c] = false;
      diag_asc[r+c] = false;
    }
  }
  if( r==0 && !(DIM&1))
    count*=2;
  return count;
}
