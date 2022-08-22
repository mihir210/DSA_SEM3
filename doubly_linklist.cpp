#include <iostream>
using namespace std;


class linkl;
class node
{
private:
   friend linkl;
   int data;
   node *next;
   node *pre;
public:
   node(int a){
      data = a;
      next = NULL;
      pre = NULL;
   }
};



class linkl
{
private:
   node *first;
public:
   linkl(){
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
         n->pre = t;
      }
   }

   void remove(int a){
      node *t = first;
      while (t->data!=a)
      {
         t = t->next;
      }
      
      t->pre->next = t->next;
      t->next->pre = t->pre;
   }

   void insertAfter(int a, int b){
      node *n = new node(a);
      node *t= first;

      while (t->data!=b)
      {
         t = t->next;
      }


      n->pre = t;
      n->next = t->next;
      t->next->pre = n;
      t->next = n;
      
   }
   
   
   void insertBefore(int a , int b){
      node *n  = new node(a);
      node *t  = first;
      
      while (t->data!=b)
      {
         t = t->next;
      }
      
      n->pre = t->pre;
      
      n->next = t;
      t->pre->next = n;
      t->pre = n; 
   }


   void deleteAfter(int a){
      node *t = first;
      
      while (t->data!=a)
      {
         t = t->next;
      }
      
      t->next->next->pre  = t;
      t->next = t->next->next;
   }
   
   
   void deleteBefore(int a){
      node *t  = first;
      
      while (t->data!=a)
      {
         t = t->next;
      }
      
      t->pre->pre->next = t;
      t->pre = t->pre->pre;
      
   }
   
   
   
   void display(){
      node *t = first;

      while (t!=NULL)
      {
         cout<<t->data<<endl;
         t = t->next;
      }
      
   }

};




int main()
{
   linkl l1;
   l1.insert(12);
   l1.insert(3);
   l1.insert(4);
   l1.insert(5);
   l1.insert(6);
   l1.insert(7);
   l1.insert(8);
   l1.insertAfter(1000, 4);
   l1.insertBefore(200, 4);
   

   l1.display();
   cout<<"after remove 3 :\n";
   l1.remove(3);

   l1.display();
    return 0;
}
