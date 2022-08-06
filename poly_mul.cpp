#include <iostream>
using namespace std;

class poly
{
private:
   int cof;
   int exp;

public:
   void insert(int a, int b)
   {
      cof = a;
      exp = b;
   }

   friend int mult(poly p1[10], poly p2[10], poly p3[10], int n1, int n2)
   {
      int i, j, k, next3, flag;
      int ex, co;
      i = next3 = 0;
      while (i < n1)
      {
         j = 0;
         while (j < n2)
         {
            ex = p1[i].exp + p2[j].exp;
            co = p1[i].cof * p2[j].cof;
            k = flag = 0;
            while (k < next3 && !flag)
            {
               if (p3[k].exp == ex)
               {
                  flag = 1;
                  break;
               }
               else
                  k++;
            }
            if (flag == 1)
                p3[k].cof = p3[k].cof + co;
            else
            {
               p3[next3].exp = ex;
               p3[next3].cof = co;
               next3++;
            }
            j++;
         }
         i++;
      }
      return next3;
   }
      void display()
      {
         cout << cof << "x^" << exp;
      }
   };

   int main()
   {


      
   poly p1[4], p2[2], p3[6];

   p1[0].insert(3, 3);   
   p1[1].insert(2, 2);   
   p1[2].insert(1, 1);   
   p1[3].insert(1, 0);      

   p2[0].insert(5, 3);
   p2[1].insert(7, 2);
//   p2[2].insert(77, 0);


   int c;
   c = mult(p1, p2, p3, 4 ,2);

   for (int i = 0; i < c; i++)
   {
      p3[i].display();
      cout<<"\t";
   }



      return 0;
   }
