#include <stdio.h>

int main (){

int a[]={64,34,25,12,22,11,90};
int n=sizeof(a)/sizeof(a[0]);
for(int i=0;i<n;i++)
{
    for(int j=0;j<n-1-i;j++)
    {
        if(a[j]>a[j+1])
        {
            int t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
    }
}
for(int i=0;i<n;i++)
{
    printf("%d\t",a[i]);
}
    return 0;
}