#include <iostream>
using namespace std;

class Queue
{
private:
   int front, rear, size;
   int * arr;
public:
   Queue(int a){
      arr  = new int[a];
      front = rear = -1;
      size = a;
   }
   
   void insert(int a){
      if(front==-1){
         front=rear=0;
      }
      else{
         rear = (rear + 1)% size;
      }
      arr[rear] = a;
   }
   
   int pop(){
      int n = arr[front];
      if (front == rear)
      {
         front=rear=-1;
      }
      else{
         front = (front + 1)%size;
      }
      return n;
   }
   
   bool isEmpty(){
      if (front==-1)
      {
         
         return true;
      }
      else{
         return false;
      }
   }
   
   bool isFull(){
      return (front==(rear+1)%size);
   }
};




int main()
{
   Queue q1(4);
   
   q1.insert(1);
   q1.insert(2);
   q1.insert(3);
   q1.insert(4);
   
   cout<<q1.pop();
   
   q1.insert(5);
   
   for (int i = 0; i < 4; i++)
   {
      cout<<q1.pop();
   }
   
   
    return 0;
}
