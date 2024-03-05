// C++ program to show that we can access a global
// variable using scope resolution operator :: when
// there is a local variable with same name
#include<iostream>
using namespace std;

// Global x
int x = 1;
int main()
{
   int x=2;
   {

       int x=3;
       cout<<x<<endl;
       cout<<::x<<endl;
   }
   cout<<x<<endl;
   cout<<::x<<endl;
}
