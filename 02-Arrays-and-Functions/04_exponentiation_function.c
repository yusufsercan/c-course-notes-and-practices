#include <stdio.h>
#include <stdlib.h>

float exponentiation(float x, int y);

int main()
{
   float base=0, result=0;//taban
   int exponent=0;//üs
   printf("Enter the base and the exponent values:\n");
   scanf("%f %d", &base, &exponent);
   result = exponentiation(base, exponent);
   printf("Result: %f\n", result);

   return 0;
}

float exponentiation(float x, int y)
{
   float result = 1;
   int i;
   if(y<0)
   {
    for(i=0;i<-y;i++)//buradaki işlem negatif üs için yapılır. negatif üs için 1/x alınır ve üs kadar çarpılır.
    {
        result *= 1/x;
    }
}
     else
     {
        for(i=0;i<y;i++)//buradaki işlem pozitif üs için yapılır. üs kadar çarpılır.
    
    {
            result *= x;
     }
   }
   return result;
}






