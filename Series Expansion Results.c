#include <stdio.h>
#include <stdlib.h>
float xsum(float n,float x);
float xerr(float n,float x);
float xerr(float n,float x)
{
    int i;
    float res,err=0;
    res=1/pow((1-x),2);
    for(i=1;i<=(int)n;i++)
    {
        err=pow((res-xsum(i,x)),2);
    }
    return err;
}
float xsum(float n,float x)
{
    int i;
    float sum=0;
    for(i=1;i<=(int)n;i++)
    {
         sum=sum+(float)i*pow(x,i-1);
    }
   return sum;
}
int main()
{
    int i,num,a,b,c;
    float fres,ferr,sum=0,x;
    printf("Enter your number: ");
    scanf("%d",&num);
    b=num%10;
    a=num%100;
    c=100*(num/10000000);
    x=(float)(a+c)/10000;
    printf("Series Expansion Results of 1/(1-x)^2 for x= %.4f \n\n",x);
    printf("   k     Expansion Result                Error\n");
    for(i=1;i<=40+b;i++)
    {
       xsum(i,x);
       xerr(i,x);
        if(i%2==0 && i!=0)
        {
          if(i<10)
        {
          printf("   %d\t       %.8f\t    %.8f\n",i,xsum(i,x),xerr(i,x));
        }
        else
        {
            printf("  %d\t       %.8f\t    %.8f\n",i,xsum(i,x),xerr(i,x));
        }
        }
        if(xerr(i,x)-xerr(i-1,x)<x*pow(10,-4))
        {
            ferr=xerr(i,x);
            fres=xsum(i,x);
        }
    }
    printf("\n Inf\t       %.8f\t    %.8f",fres,ferr);
        return 0;
}
