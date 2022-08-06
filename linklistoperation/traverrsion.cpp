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


   node * getfirst(){
      return first;
   }

   void traverse(node * n)
   {
	   if (n== NULL)
	   return;

	cout << n->data << "\n";

	traverse(n->next);
}


};



int main()
{

   impli l1;

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

   node *t  = l1.getfirst();


   l1.traverse(t);






   

   // l1.display();
   
   
    return 0;
}
