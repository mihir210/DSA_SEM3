#include <iostream>
using namespace std;

void quicksort(int a[], int left, int right)
{

   if (left < right)
   {
      int p = a[left];
      int i = left;
      int j = right + 1;

      do
      {
         do
         {
            i++;
         } while (p > a[i]);

         do
         {
            j--;
         } while (p < a[j]);

         if (i < j)
         {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
         }
      } while (i < j);

      if (i > j)
      {
         int t = a[left];
         a[left] = a[j];
         a[j] = t;
      }

      quicksort(a, left, j - 1);
      quicksort(a, j + 1, right);
   }
}

int main()
{
   int a[] = {1,88,96,15,2,18,3,5,8};
   
   quicksort(a,0,9);
   
   
   for (int i = 0; i < 9; i++)
   {
      cout<<a[i]<<endl;
   }
   

   return 0;
}
