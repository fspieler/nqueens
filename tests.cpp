#include <gtest/gtest.h>
#include "nqueens.h"

TEST(nqueens,n_1)
{
  EXPECT_EQ(1,nqueens(1));
}
TEST(nqueens,n_2){
  EXPECT_EQ(0,nqueens(2));
}
TEST(nqueens,n_3){
  EXPECT_EQ(0,nqueens(3));
}
TEST(nqueens,n_4){
  EXPECT_EQ(2,nqueens(4));
}
TEST(nqueens,n_5){
  EXPECT_EQ(10,nqueens(5));
}
TEST(nqueens,n_6){
  EXPECT_EQ(4,nqueens(6));
}
TEST(nqueens,n_7){
  EXPECT_EQ(40,nqueens(7));
}
TEST(nqueens,n_8){
  EXPECT_EQ(92,nqueens(8));
}
TEST(nqueens,n_9){
  EXPECT_EQ(352,nqueens(9));
}
TEST(nqueens,n_10){
  EXPECT_EQ(724,nqueens(10));
}
TEST(nqueens,n_11){
  EXPECT_EQ(2680,nqueens(11));
}
TEST(nqueens,n_12){
  EXPECT_EQ(14200,nqueens(12));
}
TEST(nqueens,n_13){
  EXPECT_EQ(73712,nqueens(13));
}
TEST(nqueens,n_14){
  EXPECT_EQ(365596,nqueens(14));
}
TEST(nqueens,n_15){
  EXPECT_EQ(2279184,nqueens(15));
}
TEST(nqueens,n_16){
  EXPECT_EQ(14772512,nqueens(16));
}
TEST(nqueens,n_17) {
  EXPECT_EQ(95815104,nqueens(17));
}
