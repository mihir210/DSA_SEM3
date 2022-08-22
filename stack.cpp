#include <iostream>
using namespace std;


template<class T>
class stack
{
private:
   T *p;
   int t;
   int max;
public:
   stack(int a){
       p = new T[a];
       t=-1;
       max = a;
   }

   void push(T a){
      if (t>= (max-1))
      {
         cout<<"Stack is full\n";
      }
      else{
         t++;
         p[t] = a;
      }
      
   }
   
   
   int pop(){
      if (t<0)
      {
         cout<<"stack is empty";
         return 0;
      }
      else
      {
         int x = p[t];
         t--;
         return x; 
      }
      
      
   }

};


int main()
{

   stack<int> s1(4);


   s1.push(1);
   s1.push(4);
   s1.push(5);
   s1.push(2);

   for (int i = 0; i < 4; i++)
   {
      int c = s1.pop();
      cout<<c<<endl;
   }
   

    return 0;

}
