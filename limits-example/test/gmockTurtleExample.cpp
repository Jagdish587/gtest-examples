#include <gtest/gtest.h>

 #include "gmock/gmock-matchers.h"
#include "gmock/gmock.h"
#include <string>

using namespace testing;
using namespace std;
using ::testing::AtLeast;
using ::testing::_;
using ::testing::Invoke;
using ::testing::InvokeWithoutArgs;
using ::testing::Return;



// This is my interface class
class Turtle {
  public :
  virtual ~Turtle() {};
  virtual void PenUp() = 0;
  virtual void PenDown() = 0;
  virtual void Forward(int distance) = 0;
  virtual void Turn(int degrees) = 0;
  virtual void GoTo(int x, int y) = 0;
  virtual int GetX() const = 0;
  virtual int GetY() const = 0;
  
};


class MockTurtle : public Turtle {
 public:

  MOCK_METHOD(void, PenUp, (), (override));
  MOCK_METHOD(void, PenDown, (), (override));
  MOCK_METHOD(void, Forward, (int distance), (override));
  MOCK_METHOD(void, Turn, (int degrees), (override));
  MOCK_METHOD(void, GoTo, (int x, int y), (override));
  MOCK_METHOD(int, GetX, (), (const, override));
  MOCK_METHOD(int, GetY, (), (const, override));
};


class Painter {
    public:

    Turtle *turtleobj ;
    
    Painter(Turtle* obj) 
    {
        turtleobj = obj;
        
    }

    bool DrawCircle(int x, int y, int z) 
    {
        turtleobj->PenDown(); // dummy call
        return true;

    }

    int GetX()
    {
        turtleobj->GetX();
        return 100;
        
    }

     int GetY()
    {
        turtleobj->GetY();  
        
    }



};

TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;     


  EXPECT_CALL(turtle, PenDown())                 
      .Times(AtLeast(1));

  Painter painter(&turtle);                       

  EXPECT_TRUE(painter.DrawCircle(0, 0, 10));      
}





TEST(PainterTest, GetXTest) {
  MockTurtle turtle;   
   int ret ;                           // #2

EXPECT_CALL(turtle, GetX())
    .Times(4)
    .WillOnce(Return(100))
    .WillOnce(Return(150))
    .WillRepeatedly(Return(200));

  Painter painter(&turtle);                       // #4

    ret = turtle.GetX();

   cout<<"value = "<<ret<<endl;

   ret = turtle.GetX();

   cout<<"value = "<<ret<<endl;

   ret = turtle.GetX();

   cout<<"value = "<<ret<<endl;

   ret = turtle.GetX();

   cout<<"value = "<<ret<<endl;
  
  
}



