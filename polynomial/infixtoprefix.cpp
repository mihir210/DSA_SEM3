<<<<<<< HEAD
#include<string>
#include<cstring>
#include<stack>
#include <iostream>
#include <algorithm>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 

void prefix(string infix){

      stack<char> st;
      string result;

      for (int i = infix.length()-1; i >= 0 ; i--)
      {
         char c = infix[i];

         if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result += c;
         }
         else if (c==')')
         {
            st.push(c);
         }
         else if (c=='(')
         {
            while (st.top() !=')')
            {
               result += st.top();
               st.pop();
            }
            st.pop();
            
         }
         else{
            while (!st.empty()
                   && prec(infix[i]) <= prec(st.top())) {
                if (c == '^' && st.top() != '^')
                    break;
                else {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
         }
      }

      while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    st.pop();
    reverse(result.begin(), result.end());
     cout<<result; 
}





int main()
{
   string in = "P+(Q*R)/(S-T)";

   prefix(in);

    return 0;
}
=======
#include<string>
#include<cstring>
#include<stack>
#include <iostream>
#include <algorithm>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
 

void prefix(string infix){

      stack<char> st;
      string result;

      for (int i = infix.length()-1; i > 0 ; i--)
      {
         char c = infix[i];

         if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result += c;
         }
         else if (c==')')
         {
            st.push(c);
         }
         else if (c=='(')
         {
            while (st.top() !=')')
            {
               result += st.top();
               st.pop();
            }
            st.pop();
            
         }
         else{
            while (!st.empty()
                   && prec(infix[i]) <= prec(st.top())) {
                if (c == '^' && st.top() != '^')
                    break;
                else {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
         }
      }

      while (!st.empty() && st.top()!=')') {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
     cout<<result; 
}





int main()
{
   string in = "(P+(Q*R)/(S-T))";

   prefix(in);

    return 0;
}
>>>>>>> 1486726aa5d6e76f2a574aa75829147390e19edc
