
#include<queue>
#include <iostream>
using namespace std;

int main()
{
   queue<int> q1;

   q1.push(10);
   q1.push(20);
   q1.push(30);
   q1.push(40);

   q1.push(50);


   cout<<q1.front()<<" "<<q1.back();
    return 0;
}
