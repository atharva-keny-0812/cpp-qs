#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr=NULL;
    printf("Please enter the size of your array:\t");
    int n;
    scanf("%d",&n);
    //ptr=(int*)malloc(n*sizeof(int));
    ptr=(int*)calloc(n,sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory cannot be allocated.");
        exit(0);
    }
    //printf("\n%p",ptr);
    for(int i=0;i<n;i++)
    ptr[i]=i;
    for(int i=0;i<n;i++)
    printf("%d",*(ptr+i));
    free(ptr);
    int n1;
    scanf("%d",&n1);
    ptr=(int*)realloc(ptr,n1*sizeof(int));
    if(n1>n)
    {
        for(int i=n;i<n1;i++)
    ptr[i]=2*i;
    for(int i=0;i<n1;i++)
    printf("%d",*(ptr+i));
    }
}