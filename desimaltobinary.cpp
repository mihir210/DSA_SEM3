#include <iostream>
#include<stack>
using namespace std;

int main()
{
   stack<char> st;
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
      if (k>9)
      {
         int j;
         for ( j = 10; j <= i; j++)
         {
            if (k==j)
            {
               break;
            }
            
         }
         
         
      }
      
      
      
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
