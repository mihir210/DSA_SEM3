


#include <iostream>
using namespace std;

class Arryadt
{
private:
   int *arr;
   int size;
   int lastindex;
public:
   Arryadt(int x)
   {
      arr = new int[x];
      size = x;
      lastindex = -1;

   }
   void insert(int a, int b)
   {
      if (isfull())
      {
         cout<<"array is full";
      }
      else{
         lastindex++;
         arr[a] = b;
         lastindex  =a;
      }
   }
   int isfull()
   {
      if(lastindex == size)
      {
         return 1;
      }
      else
         return 0;
   }
   void remove(int a)
   {
          for (int i = 0; i < size; i++)
         {
            if (arr[i] == a)
            {
               for (int j = i; j < size; j++)
               {
                   arr[j] = arr[j + 1];
               }
               i--;
            }
         }
   }

   void sort()
   {
      
   }
};
int main()
{

    return 0;
}
