#include <stdio.h>
int prime(int n)
{
    int i;
    int flag=0;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    if(flag==0)
    {
        return 1;
    }    
}
int main()
{
    int no;
    scanf("%d",&no);
    int factor=2;
    int power=0;
    int flag=0;
    while(no>1)
    {
        if(prime(no)==1)
        {
            printf("SF");
            break;
        }
        else if(prime(factor)==1)
        {
            if(no%(factor*factor)==0)
            {
                printf("NSF");
                flag=1;
            }
            else if(no%factor==0)
            no/=factor;
        }
        factor++;
        while(prime(factor)!=1)
        {
            factor++;
        }
        if(flag==1)
        break;
    }
}