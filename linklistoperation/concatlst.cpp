#include <iostream>
using namespace std;

class impli;
class node
{
private:
   friend impli;
   int data;
   node *next;
public:
   node(int a){
      data = a;
      next = NULL;
   }
};

class impli
{
private:
   node  * first;
public:
   impli(){
      first = NULL;
   }

   void insert(int a){

      node *n = new node(a);

      if(first==NULL){
         first = n;     
      }
      else{
         node *t = first;
         while (t->next!=NULL)
         {
            t = t->next;
         }
         t->next = n;
      }
   }

   void remove(int a){
      node *t = first;
      while (t->next->data!=a)
      {
         t = t->next;
      }
      
      t->next = t->next->next;
   }


   void display(){
      node *t = first;

      while (t!=NULL)
      {
         cout<<t->data<<endl;
         t = t->next;
      }
      
   }

   void insertLast(int a){
      node *n = new node(a);

      node *t= first;
      while (t->next!=NULL)
      {
         t = t->next;
      }
      t->next = n;
      
   }

   void insertAfter(int a, int b){
      node *n  = new node(a);

      node *t = first;

      while (t->data!=b)
      {
         t = t->next;
      }

      n->next = t->next;
      t->next = n;
      
   }

   void insertBefore(int a, int b){
      node *n  = new node(a);

      node *t = first;
      while (t->next->data!=b)
      {
         t = t->next;
      }

      n->next = t->next;
      t->next = n;
   }

   void deleteAfter(int a){
      node * t= first;

      while (t->next!=NULL && t->data!=a)
      {
            t = t->next;
      }
      t->next = t->next->next;
      
   }

   void deleteBefore(int a){
      node *t = first;
      while (t->next->next->data !=a)
      {
         t  = t->next;
      }

      t->next = t->next->next;
      
   }


   void concat(impli n){
      node *t = first;

      while (t->next!=NULL)
      {
         t= t->next;
      }

      t->next =   n.first;
   }
};



int main()
{

   impli l1, l2;

   l1.insert(12);
   l1.insert(3);
   l1.insert(4);
   l1.insert(5);
   l1.insert(6);
   l1.insert(7);
   l1.insert(8);
   l1.insert(9);
   l1.insert(10);
   l1.insert(11);


   l2.insert(10);
   l2.insert(102);
   l2.insert(1045);
   l2.insert(104);
   l2.insert(10536);
   l2.insert(1053);
   l2.insert(1067);
   l2.insert(1076);
   l2.insert(1067);

   l1.concat(l2);
   

   l1.display();
   
   
    return 0;
}
