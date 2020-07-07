#include "gtest/gtest.h"
#include "Calculator.h"


TEST(blaTest, test1) {

    Calculator calcmyobj;

    int val = calcmyobj.add(5, 6) ;

    EXPECT_EQ(11, val) ;
   
}


TEST(blaTest, test2) {

    Calculator calcmyobj;

    int val = calcmyobj.add(12, 6) ;

    EXPECT_EQ(18, val) ;
   
}