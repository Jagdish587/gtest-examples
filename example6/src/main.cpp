
#include <iostream>
using namespace std;
#include "Calculator.h"

int main()
{
    cout<<"Hello I am from main \n" ;

    Calculator calcobj;

   cout<<"add value of 5 , 9 = "<<calcobj.add(5, 9)<<endl;

    return 0;
}