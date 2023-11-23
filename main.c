#include<stdio.h>
#include<limits.h>
#include<stdbool.h>


int main(){
    int quantum;
    int n,i,j;

    printf("Enter the no. of processes :");
    scanf("%d",&n);

    int at[n];
    int bt[n];
    int st[n][15];
    int ft[n];
    int wt[n];
    int tat[n];

    printf("Enter the quantumum \n");
    scanf("%d",&quantum);

    printf("Enter the Arrival time of processes \n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter the Burst time of processes \n");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);

    int count=n,temp[n][20];
    float time=0,mini=INT_MAX,b[n],a[n];

    int index=-1;
    for(i=0;i<n;i++){
        b[i]=bt[i];
        a[i]=at[i];
        for(j=0;j<20;j++){
            temp[i][j]=-1;
        }
    }

    int tot_wt,tot_tat;
    tot_wt=0;
    tot_tat=0;
    bool flag=false;

    while(count!=0){
        //This part calculates the start time
        mini=INT_MAX;
        flag=false;

        for(i=0;i<n;i++){
            float p=time+0.1;
            if(a[i]<=p && mini>a[i] && b[i]>0){
                index=i;
                mini=a[i];
                flag=true;

            }
        }

        if(!flag){
            time++;
            continue;
        }

        j=0;

        while(temp[index][j]!=-1){
            j++;
        }

        if(temp[index][j]==-1){
            temp[index][j]=time;
            st[index][j]=time;
        }

        if(b[index]<=quantum){
            time+=b[index];
            b[index]=0;
        }
        else{
            time+=quantum;
            b[index]-=quantum;
        }

        if(b[index]>0){
            a[index]=time+0.1;
        }

        if(b[index]==0){
            count--;
            ft[index] = time;
            tat[index] = ft[index] - at[index];
            wt[index] = tat[index] - bt[index];
            tot_wt+=wt[index];
            tot_tat+=tat[index];
        }

    }

    printf("Process number ");
    printf(" Arrival time ");
    printf("   Burst time ");
    printf("     Finish time");
    printf("\tWait Time ");
    printf("\tTurnAround Time");
    printf("\t\tStart time \n");

    for(i=0;i<n;i++){
        printf("%d",i+1);
        printf("\t\t%d",at[i]);
        printf("\t\t%d",bt[i]);
        printf("\t\t%d",ft[i]);
        printf("\t\t%d",wt[i]);
        printf("\t\t%d\t\t\t",tat[i]);
        j=0;
        int v=0;
        while(temp[i][j]!=-1){
            printf("%d ",st[i][j]);
            j++;
            v+=3;
        }
        printf("\n");
    }

    double avg_wt,avg_tat;
    avg_wt=tot_wt/(float)n;
    avg_tat=tot_tat/(float)n;

    printf("The average wait time is : %lf\n",avg_wt);
    printf("The average TurnAround time is : %lf\n",avg_tat);
    return 0;
}


