#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>

#include <stdlib.h>

int main()
{
    int h,n,m;
     printf("\n");
     printf("Head Position :\n");
    scanf("%d",&h);    
    printf("\n");  
    printf("No.of Request:\t");
    scanf("%d",&m);
    int req[m];                
    for(n=0;n<m;n++)
    {
            scanf("%d",&req[n]);
    }
    int diff=req[0]-h;
    if(diff<0)
    {
              diff=diff*-1;
    }
    for(n=1;n<m;n++)
    {
            if((req[n]-req[n-1])>0)
               diff=diff+(req[n]-req[n-1]);
            else
               diff=diff+(req[n-1]-req[n]);
    }
    printf("Seek time = %d\n",diff);
    
}

