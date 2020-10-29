#include <iostream>
#include <queue>

#include "gtest/gtest.h"


using namespace std;

class Myqueue {
public:
    Myqueue()
    {
        max_size = 5;
    }

    bool insertinQueue(int val)
    {
        if(max_size == myqueue.size()) {
            return false;
        } else {
            myqueue.push(val);
            return true;
        }
    }

    bool popFromQueue()
    {
        int currnetval = 0;
        if(myqueue.size() == 0) {
            return false;
        }

        currnetval =  myqueue.front();
        myqueue.pop();

        return true;
    }

private:
    std::queue<int> myqueue;
    int max_size;
};


TEST(QueueTest, testMaxBoundary) {

    Myqueue mysampleQueue;
    EXPECT_TRUE(mysampleQueue.insertinQueue(10));
    EXPECT_TRUE(mysampleQueue.insertinQueue(20));
    EXPECT_TRUE(mysampleQueue.insertinQueue(30));
    EXPECT_TRUE(mysampleQueue.insertinQueue(40));
    EXPECT_TRUE(mysampleQueue.insertinQueue(50));

    // Now queue size has reached max , so it should fail
    EXPECT_TRUE(mysampleQueue.insertinQueue(10));
}


TEST(QueueTest, testMinBoundary) {

    Myqueue mysampleQueue;
   
    mysampleQueue.insertinQueue(10);
    mysampleQueue.insertinQueue(20);
    mysampleQueue.insertinQueue(30);
    mysampleQueue.insertinQueue(40);
    mysampleQueue.insertinQueue(50);

    EXPECT_TRUE(mysampleQueue.popFromQueue());
    EXPECT_TRUE(mysampleQueue.popFromQueue());
    EXPECT_TRUE(mysampleQueue.popFromQueue());
    EXPECT_TRUE(mysampleQueue.popFromQueue());
    EXPECT_TRUE(mysampleQueue.popFromQueue());

    // Now test case  should fail since size became zero
    EXPECT_TRUE(mysampleQueue.popFromQueue());

}

class LimmitsBUffer
{
    int max_buffer_size;
    int min_buffer_size;
    string deviceName;
    
public :
    LimmitsBUffer()
    {
        max_buffer_size = 10;
        min_buffer_size = 3;
    }

    bool setHUName(string val)
    {
        if(val.size() >= max_buffer_size)
            return false;
        
        if(val.size() < min_buffer_size)
            return false;
        
        deviceName = val;

        return true;
    }
};

TEST(LimmitsBUffer, testMaxBufferValue) {
    LimmitsBUffer mydata;

    EXPECT_TRUE(mydata.setHUName("Jagdidsh")); // OK
    EXPECT_TRUE(mydata.setHUName("Jagdidsh Tirumala")); // NOT OK
}

TEST(LimmitsBUffer, testMinBufferValue) {
    LimmitsBUffer mydata;

    EXPECT_TRUE(mydata.setHUName("Jagdidsh")); // OK
    EXPECT_TRUE(mydata.setHUName("Ye")); // NOT OK
}


