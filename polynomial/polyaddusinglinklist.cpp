#include <iostream>
using namespace std;


class poly;
class term
{
private:
   friend poly;
   int cof;
   int exp;
   term *next;
public:
   term(int c, int e){
      cof = c;
      exp = e;
      next = NULL;
   }
};


class poly
{
private:
   term *first;
public:
   poly(){
      first = NULL;
   }
   
   void insert(int c, int e){
      if(first==NULL){
         first = new term(c,e);
      }
      else{
         term *t = first;
         
         while(t->next!=NULL){
            t = t->next;
         }
         t->next = new term(c,e);
      }
   }
   
   
   term * getFirst(){
      return first;
   }
   
   
   void add(term *f, term *s){
      term *t = f, *t2 = s;
      
      while(t!=NULL && t2!=NULL){
         if(t->exp==t2->exp){
            int c = t->cof  + t2->cof;
            int e = t->exp;
            this->insert(c,e);
            t = t->next;
            t2 = t2->next;
             
         }
         else if (t->exp > t2->exp)
         {
            int c = t->cof;
            int e = t->exp;
            this->insert(c,e);
            t = t->next;
         }
         else{
         
            int c = t2->cof;
            int e = t2->exp;
            this->insert(c,e);
            t2 = t2->next;   
         }
      }
      
      while (t!=NULL)
      {
         int c = t->cof;
            int e = t->exp;
            this->insert(c,e);
            t = t->next;
      }
      while (t2!=NULL)
      {
         int c = t2->cof;
            int e = t2->exp;
            this->insert(c,e);
            t2 = t2->next; 
         
      }
   }
   
   void display(){
      term *t = first;
      while (t!=NULL)
      {
         cout<<t->cof<<"x^"<<t->exp<<"\t";
         t = t->next;
      }
   }
};






int main()
{
      poly p1, p2, p3;

   p1.insert(10, 5);   
   p1.insert(44, 2);   
   p1.insert(43, 1);         

   p2.insert(84, 5);
   p2.insert(45, 4);
  p2.insert(77, 3);
  p2.insert(73, 1);
   
   p3.add(p1.getFirst(), p2.getFirst());
   
   p3.display();
    return 0;
}
