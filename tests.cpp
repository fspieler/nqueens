#include <gtest/gtest.h>
#include <nqueens.h>

TEST(nqueens,n_less_than_or_equal_to_12)
{
  EXPECT_EQ(1,nqueens(1));
  reset();
  EXPECT_EQ(0,nqueens(2));
  reset();
  EXPECT_EQ(0,nqueens(3)); 
  reset();
  EXPECT_EQ(2,nqueens(4));  
  reset();
  EXPECT_EQ(10,nqueens(5));  
  reset();
  EXPECT_EQ(4,nqueens(6));  
  reset();
  EXPECT_EQ(40,nqueens(7));  
  reset();
  EXPECT_EQ(92,nqueens(8));  
  reset();
  EXPECT_EQ(352,nqueens(9));  
  reset();
  EXPECT_EQ(724,nqueens(10));  
  reset();
  EXPECT_EQ(2680,nqueens(11));  
  reset();
  EXPECT_EQ(14200,nqueens(12));  
  reset();
}

TEST(nqueens,n_greater_than_12)
{
  EXPECT_EQ(73712,nqueens(13));  
  reset();
  EXPECT_EQ(365596,nqueens(14));
  reset();
  EXPECT_EQ(2279184,nqueens(15));
  reset();
  EXPECT_EQ(14772512,nqueens(16));
  reset();
  EXPECT_EQ(95815104,nqueens(17));
  reset();
}
