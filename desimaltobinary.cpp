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
         char c = k -10 +  'A'; 
         st.push(c);
         
      }
      else{
         char c = k + '0';
         st.push(c);
      }
      
      n = n/i;
   }

   st.push(n);

   while (!st.empty())
   {
      char ch = st.top();
      if (int(ch) > 9)
      {
         cout<<(ch-'0');
      }
      else{
         cout<<(ch-'A');
      }
      
      st.pop();
   }
   
   


    return 0;
}
