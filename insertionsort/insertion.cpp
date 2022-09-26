#include <iostream>
using namespace std;


void insersort(int a[], int n){
   int j;
   
   for (int i = 0; i < n; i++)
   {
      int k = a[i];
      j  =i-1;
      
      while (j>=0 && a[j]>k)
      {
         a[j+1]= a[j];
         j--;
      }
      
      a[j+1] = k;
      
   }
   
}


int main()
{
   int a[] = {59,78,15,1,12,25};
   
   
   insersort(a, 5);
   for (int  i = 0; i < 5; i++)
   {
      cout<<a[i]<<"\t";
   }
   
   
    return 0;
}
