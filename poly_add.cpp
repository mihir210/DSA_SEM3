#include <iostream>
using namespace std;


class poly
{
private:
   int cof;
   int exp;

public:
   void insert(int a, int b){
      cof = a;
      exp = b;
   }

   friend int add(poly p1[], poly p2[],poly p3[], int  t1, int t2){
      int i,j,k;
      i=j=k=0;

      while (i<t1 && j<t2)
      {
         if (p1[i].exp == p2[j].exp)
         {
            p3[k].cof = p1[i].cof + p2[j].cof;
            p3[k].exp = p1[i].exp; 
            i++;
            j++;
            k++;
              
         }
         else if (p1[i].exp > p2[j].exp)
         {
            p3[k].exp = p1[i].exp;
            p3[k].cof = p1[i].cof;
            i++;
            k++;
         
         
         }
         else
         {
            p3[k].exp = p2[j].exp;
            p3[k].cof = p2[j].cof;
            j++;
            k++;
         }
      }

      while (i<t1)
      {
         p3[k].exp = p1[i].exp;
            p3[k].cof = p1[i].cof;
            i++;
            k++;
      }

      while (j<t2)
      {
         p3[k].exp = p2[j].exp;
            p3[k].cof = p2[j].cof;
            j++;
            k++;
      }
      int t3 = k;

      return t3;
   }

   void display(){
      cout<<cof<<"x^"<<exp;
   }

};

int main()
{

   poly p1[3], p2[4], p3[10];

   p1[0].insert(10, 5);   
   p1[1].insert(44, 2);   
   p1[2].insert(43, 1);   
   // p1[3].insert(14, 1);      

   p2[0].insert(84, 5);
   p2[1].insert(45, 4);
  p2[2].insert(77, 3);
  p2[3].insert(73, 1);



   int c;
   c = add(p1, p2, p3, 3 ,4);

   for (int i = 0; i < c; i++)
   {
      p3[i].display();
      cout<<"\t";
   }
   
    return 0;
}
