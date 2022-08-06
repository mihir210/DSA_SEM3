#include <iostream>
using namespace std;

class Stack;
class node
{
private:
   friend Stack;
   int data;
   node *link;
public:
   node(int a){
      data  =a;
      link = NULL;
   }
   
};


class Stack
{
private:
   node *top;
public:
   Stack(){
      top = NULL;
   }

   void push(int a){
      if (isFull())
      {
         cout<<"Stack is full\n";
         return;
      }
      else
      {
         node *n = new node(a);
         n->link = top;
         top = n;
      }
   }

   bool isEmpty(){
      return (top==NULL);
   }

   bool isFull(){
      node * p = new node(0);
      return  (p==NULL);
   }

   int pop(){
      if (isEmpty())
      {
         cout<<"Stack is empty\n";
         return 0;
      }
      else{
         node *n = top;
         top = top->link;
         int x = n->data;
         free(n);
         return x;
      }
      
   }


};





int main()
{
   Stack s1;

   s1.push(1);
   s1.push(2);
   s1.push(3);
   s1.push(4);
   s1.push(5);

   cout<<s1.pop()<<endl;
   cout<<s1.pop()<<endl;
   cout<<s1.pop()<<endl;
   cout<<s1.pop()<<endl;
   cout<<s1.pop()<<endl;

   

   
    return 0;
}
