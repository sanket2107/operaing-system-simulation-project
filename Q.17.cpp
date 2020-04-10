#include<stdio.h>
#include<string.h>
#include<conio.h>
main()
{
    char z[10][5],tmp[5];
    int m,p,pt[10],wt[10],totwt=0,pr[10],tmp1,t;
    float avgwt;
    printf(" No. Of Processes:");
    scanf("%d",&t);
    for(m=0;m<t;m++)
    {
        printf(" Process %d Name:",m+1);
        scanf("%s",&z[m]);
        printf("Process Time:");
        scanf("%d",&pt[m]);
        printf("Enter Priority:");
        scanf("%d",&pr[m]);
    }
    for(m=0;m<t-1;m++)
    {
        for(p=m+1;p<t;p++)
        {
            if(pr[m]>pr[p])
            {
                tmp1=pr[m];
                pr[m]=pr[p];
                pr[p]=tmp1;
                tmp1=pt[m];
                pt[m]=pt[p];
                pt[p]=tmp1;
                strcpy(tmp,z[m]);
                strcpy(z[m],z[p]);
                strcpy(z[p],tmp);
            }
        }
    }
    wt[0]=0;
    for(m=1;m<t;m++)
    {
        wt[m]=wt[m-1]+wt[m-1];
        totwt=totwt+wt[m];
    }
    avgwt=(float)totwt/t;
    printf("p_name\t p_time\t priority\t w_time\n");
    for(m=0;m<t;m++)
    {
       printf(" %s\t %d\t %d\t %d\n" ,z[m],pt[m],pr[m],wt[m]);
    }
    printf("Total Waiting Time Of  = %d\n Avgerage  Waiting Time Of =%f",totwt,avgwt);
   
    int ts,pid[10],need[10],wt1[10],tat[10],m1,p1,n2,n1;
    int bt[10],flag[10],ttat=0,twt=0;
    float awt,atat;
    printf("\n Number Of Processors \n");
    scanf("%d",&t);
    n1=t;
    printf("\n Enter  Timeslice \n");
    scanf("%d",&ts);
    for(m=1;m<=t;m++)
    {
        printf("\n The process ID %d",m);
        scanf("%d",&pid[m]);
        printf("\n  Burst Time For The process");
        scanf("%d",&bt[m]);
        need[m]=bt[m];
    }
    for(m=1;m<=t;m++)
    {
        flag[m]=1;
        wt[m]=0;
    }
    while(t!=0)
    {
        for(m=1;m<=t;m++)
        {
            if(need[m]>=ts)
            {
                for(p=1;p<=t;p++)
                {
                    if((m!=p)&&(flag[m]==1)&&(need[p]!=0))
                    wt[p]+=ts;
                }
                need[m]-=ts;
                if(need[m]==0)
                {
                    flag[m]=0;
                    t--;
                }
            }
            else
            {
                for(p=1;p<=t;p++)
                {
                    if((m!=p)&&(flag[m]==1)&&(need[p]!=0))
                    wt[p]+=need[m];
                }
                need[m]=0;
                t--;
                flag[m]=0;
            }
        }
    }
    for(m=1;m<=n1;m++)
    {
        tat[m]=wt[m]+bt[m];
        twt=twt+wt[m];
        ttat=ttat+tat[m];
    }
    awt=(float)twt/n1;
    atat=(float)ttat/n1;
    printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
    for(m=1;m<=n1;m++)
    {
        printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \n", m,pid[m],bt[m],wt[m],tat[m]);
    }
    printf("\n The average Waiting Time=4.2f",awt);
    printf("\n The average Turn around Time=4.2f",atat);
}
