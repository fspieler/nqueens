#include "debug.h"
#include <array>
#include <vector>
#include <mutex>
#include <thread>

#include "nqueens.h"

void reset() {}

class Solver
{
  std::array<int,25> cols;
  std::array<int,50> diag_desc;
  std::array<int,50> diag_asc;
  std::array<int,25> stack;
  int stack_index = 0;
  int count = 0;
public:
  int run(int dim, int r, int c_beg, int c_end);
  Solver() = default;
  Solver(const Solver&) = default;
  Solver(Solver&&) = delete;
};

int nqueens(int DIM)
{
  if(DIM <= 14 && false)
  {
    int ret = Solver().run(DIM, 0, 0, DIM/2) * 2; 
    if(DIM % 2) //odd
      ret += Solver().run(DIM, 0, DIM/2, DIM/2+1);
    return ret;
  } else
  {
    std::mutex m;
    int count = 0;
    int cols_per_thread = 1;
    auto compute = [&](auto r, auto c_beg, auto c_end, bool double_it)->void {
      int temp = Solver().run(DIM, r, c_beg, c_end);
      if(double_it)
        temp *= 2;
      m.lock();
      count += temp;
      m.unlock();
    };

    std::vector<std::thread> threads;
    if(DIM % 2) //odd
    {
      threads.emplace_back(compute, 0, DIM/2, DIM/2+1, false);
    }
    int i = 0;
    for(;;)
    {
      threads.emplace_back( compute, 0, i*cols_per_thread, std::min(DIM/2,(i+1)*cols_per_thread), true);
      if((i+1) * cols_per_thread > DIM / 2 )
        break;
      i++;
    }

    for(std::thread& t : threads)
    {
      t.join();
    }

    return count;
  }
}

int Solver::run(int DIM, int r, int c_beg, int c_end)
{
  const int initial_r = r;
  c_end = std::min(c_end,DIM);
outer:
  while(r >= initial_r)
  {
    if(r == DIM)
      count++;
    else
    {
      int c = (initial_r==r ? c_beg : 0);
      if(stack_index > r)
      {
        c = 1+stack[stack_index--];
      }
      for(; c < (initial_r==r ? c_end : DIM ); ++c)
      {
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
    r--;
    cols[c] = false;
    diag_desc[DIM-1+r-c] = false;
    diag_asc[r+c] = false;
  }
  return count;
}
