#include <iostream>
using namespace std;

class queue
{
private:
   int *arr;
   int front;
   int rear;
   int size;
public:
   queue(int a){
      arr = new int[a];
      front = rear = -1;
      size = a;
   }

   bool isFull(){
      return (rear==size-1);
   }

   bool isEmpty(){
      if (front==-1 || front>rear)
      {
         
         return true;
      }
      else{
         return false;
      }
   }

   void eaqueue(int a){
      if (isFull())
      {
         cout<<"queue is full\n";
         return;
      }
      else{
         rear++;
         arr[rear] = a;
         if (front==-1)
         {
            front++;
         }
      }
   }


   int daqueue(){
      if (isEmpty())
      {
         front=rear = -1;
         cout<<"Queue is empty\n";
         return 0;
      }
      else{
         return arr[front++];
      }
   }
};



int main()
{
   queue q1(5);

   q1.eaqueue(23);
   q1.eaqueue(2369);
   q1.eaqueue(253);
   cout<<q1.daqueue()<<endl;
   cout<<q1.daqueue()<<endl;
   
   q1.eaqueue(2023);
      cout<<q1.daqueue()<<endl;
   cout<<q1.daqueue()<<endl;
   cout<<q1.daqueue()<<endl;
   q1.eaqueue(202354);

   cout<<q1.daqueue()<<endl;

   
  

    return 0;
}
