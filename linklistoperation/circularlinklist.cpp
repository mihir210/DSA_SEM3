#include <iostream>
using namespace std;

class impl;
class node
{
private:
   friend impl;
   int data;
   node * link;
public:
   node(int d, node *f){
      data = d;
      link = f;
   }

};


class impl
{
private:
   node *first;
public:
   impl(){
      first =NULL;
   }
   
   void insert(int d){
      if (first==NULL)
      {
         first = new node(d, first);
         
         first->link = first;
      }
      else{
         node *t = first;
         
         while (t->link!=first)
         {
            t = t->link;
         }
         
         t->link = new node(d,first);
         
      }
      
   }
   
   
   void display(){
      
      node *t = first;
      
      while (t->link!=first)
      {
         cout<<t->data<<endl;
         t = t->link;
      }
      
      cout<<t->data;
      
   }
   
};



int main()
{
   
   impl l1;
   
   
   l1.insert(15);
   l1.insert(155);
   l1.insert(1565);
   l1.insert(155441);
   l1.insert(15544);
   

   l1.display();   
    return 0;
}
