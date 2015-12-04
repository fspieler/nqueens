#include <debug.h>
#include <iostream>
#include <vector>

template<int DIM>
int get_desc_index(int row, int col)
{
  return DIM-1+row-col;
}

template<int DIM>
int get_asc_index(int row, int col)
{
  return row+col;
}

template<int DIM>
bool square_is_valid
    (
      int row,
      int col,
      const std::vector<bool>& cols,
      const std::vector<bool>& diag_desc,
      const std::vector<bool>& diag_asc
    )
{
  bool val = ( ! cols[col] )  
         && !diag_desc[DIM-1+row-col]
         && ! diag_asc[row+col];
  
  return val;
}



template <int DIM>
int num_solns_helper
    (
      int& count,
      int r,
      std::vector<bool>& cols,
      std::vector<bool>& diag_desc,
      std::vector<bool>& diag_asc
    )
{
  if(r == DIM)
  {
    return ++count;
  }
  for(int c = 0; c < DIM; c++)
  {
    if(square_is_valid<DIM>(r, c, cols, diag_desc, diag_asc))
    {
      cols[c] = true;
      diag_desc[get_desc_index<DIM>(r,c)] = true;
      diag_asc[get_asc_index<DIM>(r,c)] = true;
      num_solns_helper<DIM>(count,r+1,cols,diag_desc,diag_asc);
      cols[c] = false;
      diag_desc[get_desc_index<DIM>(r,c)] = false;
      diag_asc[get_asc_index<DIM>(r,c)] = false;
    }
  }
  return count;
}

template <int DIM>
int num_solns()
{
  std::vector<bool> a(DIM,false);
  std::vector<bool> b(2*DIM-1,false);
  std::vector<bool> c(2*DIM-1,false);
  int count = 0;
  return num_solns_helper<DIM>(count,0,a,b,c);
}

template<int DIM>
void test()
{
  std::cout << DIM << ": " << num_solns<DIM>() << std::endl;
}

int main()
{
  //test<4>();
  test<14>();
  //test<10>();
  return 0;
}
