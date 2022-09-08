

#include <iostream>
using namespace std;

void path(int a[][3]){
   
   int t[3][3];
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         t[i][j] = a[i][j];
      }
      
   }
   
   
   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++)
      {
         for (int k = 0; k < 3; k++)
         {
            if ((t[j][i] + t[i][k])<t[j][k])
            {
               t[j][k] = t[j][i] + t[i][k];
            }
         }
      }
   }
   
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cout<<t[i][j]<<"\t";
      }
      cout<<endl;
      
   }
   
      
   
   
}

int main()
{
   
   int a[3][3] = {{0,4,11},{6,0,2},{3,500,0}};
   path(a);
   
    return 0;
}
