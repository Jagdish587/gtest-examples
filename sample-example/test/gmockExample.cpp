#ifndef TST_CALCULATOR_H
#define TST_CALCULATOR_H

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

// Assume This is Interface Class
class DatabaseConnect {
 public:

  virtual bool logging (string username, string password) {
    cout<<"Jagdish *************************** entered logging \n";
    return true;
  }
  virtual bool logout (string username, string password) {
    return false;
  }
  virtual int fetchrecord() {
    return -1;
  }

  virtual ~DatabaseConnect() {

  }

};

class MockDatabaseConnect : public DatabaseConnect {
 public:

  MOCK_METHOD2(logging, bool(string username, string password));
  MOCK_METHOD2(logout, bool(string username, string password));
  MOCK_METHOD0(fetchrecord, int());

};


// Step1 : Assume this is my real class
class MyDatabase {

  DatabaseConnect &dbs;
  string musername;
  string mpassword;

 public:

  MyDatabase(DatabaseConnect &rdbs) : dbs(rdbs) {

  }

  int init(string username, string password) {
    cout<<"entered init here \n";
    int val = dbs.logging(username, password); // dummy call 
    cout<<"logging val = "<<val<<endl;
    return val;
  }
};

// Note : If you want to disable a test case , add DISABLED_
// EX : TEST(DISABLED_MYDBTEST, LoginTest1) , This test cases wont to be compiled

TEST(MYDBTEST, LoginTest1)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Assert on test case

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);

  EXPECT_CALL(mockobj, logging(_,_)).Times(1).WillRepeatedly(Return(true));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}

TEST(MYDBTEST, LoginTest)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Assert on test case

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);

  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillRepeatedly(Return(true));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}


TEST(MYDBTEST, InvokeMockedFunc)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Aseert on test case

  // what if you want to invoke original func along wigth mock func

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);
  DatabaseConnect dbtest;

  // Use Invoke func if you want to invoke logging fucntion
  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillOnce(Invoke(&dbtest,&DatabaseConnect::logging));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}


struct testABC {

  bool dummylogging(string aa, string bb) {
    cout<<"entered inside struct dummylogging \n";
    return true;
  }

};

TEST(MYDBTEST, InvokeDummyStubCode)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Aseert on test case

  // what if you want to invoke some stuf function on mock call ,
    // well you can do it by using Invoke function

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);
  testABC structdbtest;

  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillOnce(Invoke(&structdbtest,&testABC::dummylogging));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}



bool globaldummyfunc()
{
  cout<<"insiode globaldummyfunc \n";
  return true;
}

TEST(MYDBTEST, InvokeDummyStubCodeWithoutArgs)
{
  // Step1: Arrange the test case
  // Step2: Act on test case
  // Step3: Aseert on test case

  // what if you want to invoke some global function
  // the function should be without arguments

  MockDatabaseConnect mockobj;
  MyDatabase mydb(mockobj);

  EXPECT_CALL(mockobj, logging(_, _)).Times(1).WillOnce(InvokeWithoutArgs(globaldummyfunc));

  int ret = mydb.init("Jagdish","Howryou");
  EXPECT_EQ(ret, 1);

}

struct testXYZ {

  bool dummylogging(string aa, string bb) {
    cout<<"entered inside struct dummylogging xyz \n";
   // return true;

  }
};




#endif // TST_CALCULATOR_H



