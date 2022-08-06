#include <iostream>
#include<stack>
using namespace std;

int main()
{
   stack<int> st;
   int  n;
   int a = n;
   int i;

   cout<<"Enter the number";
   cin>>n;

   cout<<"Enter the base you want to convert";
   cin>>i;

   while(n>=i)
   {
      int k  = n%i;
      st.push(k);
      n = n/i;
   }

   st.push(n);


   while (!st.empty())
   {
      cout<<st.top();
      st.pop();
   }
   
   


    return 0;
}
