#include <stdio.h>
#include <stdlib.h>
#define _MAX 20
/* 
void print1DArray(int *arr,int size)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",arr[i]); //*(arr+i)
    }
    printf("\n");
}
*/
int main()
{
    /*
    float x;
    float *ptr,*ptr2;
    ptr=&x;
    x=5;
    *ptr=6.567;
    printf("x=%.2f,*ptr=%.2f, ptr=%p\n",x,*ptr,ptr);

    float arr[_MAX];
    for(int i=0;i<_MAX;i++)
    {
        arr[i]=10.1*i;
        printf("\n%0.2f",arr[i]);
    }
    ptr=&arr[5];
    printf("\narr[5]=%.2f,*ptr=%.2f, ptr=%p\n",arr[5],*ptr,ptr);
    //ptr++;//ptr=ptr+sizeof(float)*1
    printf("\narr[5]=%.2f,*ptr=%.2f, ptr=%p\n",arr[5],*ptr--,ptr);
    printf("\n*ptr=%0.2f\n",*ptr);

    ptr2=&arr[6];
    printf("*ptr2=%p,ptr=%p, ptr2-ptr=%ld\n",ptr2,ptr,ptr2-ptr);//address subtraction/sizeof(float);

    printf("*(ptr+3)=%0.2f\n",*(ptr+3));

    ptr2=NULL;
    printf("ptr2=%p",ptr2);
    */

   /*
   int arr1D[5];
   for(int i=0;i<5;i++)
   {
        arr1D[i]=i;
   }
   print1DArray(arr1D,5);
   return 0;
    */
   /*
   int **pptr;
   int *ptr;
   int x=8;
   ptr=&x;
   pptr=&ptr;
   printf("*pptr =%d, ptr=%d\n",*pptr,ptr);
   */
   int *ptrarr[10];
   return 0;
}