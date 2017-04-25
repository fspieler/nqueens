#include <nqueens.h>
#include <stdio.h>
#include <cstdlib>

int main(int argc,char**argv)
{
  if(argc < 2)
  {
    printf("Provide single argument n (number of queens on n*n board)\n");
    return 1;
  }

  int dim = atoi(argv[1]);
  printf("%d: %lld\n", dim, nqueens(dim));
  return 0;
}
