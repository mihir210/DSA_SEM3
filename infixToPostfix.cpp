#include <iostream>
#include<string>
#include <stack>

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
 

void postfix(string infix){

      stack<char> st;
      string result;

      for (int i = 0; i < infix.length(); i++)
      {
         char c = infix[i];

         if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
            result += c;
         }
         else if (c=='(')
         {
            st.push(c);
         }
         else if (c==')')
         {
            while (st.top() !='(')
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

     cout<<result; 
}





int main()
{
   string in = "a*(b+c)-d";

   postfix(in);
    return 0;
}
