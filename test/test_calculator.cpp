#include "gtest/gtest.h"
#include "Calculator.h"


TEST(blaTest, test1) {


    cout<<"I am Jagdish Tirumala from blaTest\n ";
    Calculator calcmyobj;

    int val = calcmyobj.add(5, 6) ;

    EXPECT_EQ(11, val) ;
   
}


TEST(blaTest, test2) {

    Calculator calcmyobj;

    int val = calcmyobj.add(12, 6) ;

    EXPECT_EQ(18, val) ;

    
   
}

::testing::AssertionResult IsEven(int n) {
  if ((n % 2) == 0)
     return ::testing::AssertionSuccess();
  else {
      cout<<"failure ********** \n";
    return ::testing::AssertionFailure() << n << " is odd";
  }
     
}


class TestCalculator : public ::testing::Test 
{
   
protected:
	
     Calculator* calcmyobj;
     static int *sharedreosurce ;

	TestCalculator() 
    {
		 cout<<"TestCalculator cosntsructor\n";
	}

	virtual ~TestCalculator() 
    {
		cout<<"TestCalculator destructor \n";
	}

	// This is Per Each Fixture 
	virtual void SetUp() 
    {
		cout<<"I am in SetUp \n";
        calcmyobj = new Calculator();
        
	}

    // This is Per Each Fixture 
	virtual void TearDown() 
    {
		cout<<"I am in TearDown \n";
        delete calcmyobj;
        calcmyobj = nullptr;

       
	}

    static void SetUpTestSuite() 
    {
        cout<<"Hello I am in SetUpTestSuite \n";

        sharedreosurce = new int();
    }

    static void TearDownTestSuite()
    {
        cout<<"Hello I am in TearDownTestSuite \n";

        // let's delete the shared resource 
        delete sharedreosurce;
        sharedreosurce = nullptr;
    }
	
};

int* TestCalculator::sharedreosurce = nullptr;


TEST_F(TestCalculator, MethodTestAdd) 
{
     cout<<"start with MethodTestAdd \n";

	int ret = calcmyobj->add(5, 6) ;

    EXPECT_EQ(11, ret) <<"This function got passed \n";

}

TEST_F(TestCalculator, MethodTestSub) 
{
	int ret = calcmyobj->add(5, 6) ;

    float pi = 3.14;
    
    // for floating pint values use EXPECT_FLOAT_EQ
    EXPECT_FLOAT_EQ(3.14, pi) ; 
  

   

    cout<<"done with test cases \n";

    

}