#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int at[SIZE], bt[SIZE], ct[SIZE], tat[SIZE], wt[SIZE], rt[SIZE];
void input(){
printf("\nEnter the arrival times:\n");
for(int i=0;i<SIZE;i++){
scanf("%d", &at[i]);
}
printf("\nEnter the burst times:\n");
for(int i=0;i<SIZE;i++){
scanf("%d", &bt[i]);
}
}
void sorting(){
for(int i=0;i<SIZE-1;i++){
for(int j=i+1;j<SIZE;j++){
if(at[i]>at[j]){
int temp=at[i];
at[i]=at[j];
at[j]=temp;
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
}
}
}
}

void calc_times(){
for(int i=0;i<SIZE;i++){
if(i==0) ct[i]=at[i]+bt[i];
else if(at[i]<ct[i-1]) ct[i]=ct[i-1]+bt[i];
else ct[i]=at[i]+bt[i];
}
for(int i=0;i<SIZE;i++){
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
if(i==0) rt[i]=0;
else if(at[i]<ct[i-1]) rt[i]=ct[i-1]-at[i];
else rt[i]=0;
}
printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT");
for(int i=0;i<SIZE;i++){
printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d",(i+1),at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
}
}
void calc_avg(){
float sum=0,avg;
for(int i=0;i<SIZE;i++)
sum+=tat[i];
avg=sum/SIZE;
printf("\nAverage TAT=%.2f units",avg);
sum=0;
for(int i=0;i<SIZE;i++)
sum+=wt[i];
avg=sum/SIZE;
printf("\nAverage WT=%.2f units",avg);
sum=0;
for(int i=0;i<SIZE;i++)
sum+=rt[i];
avg=sum/SIZE;
printf("\nAverage RT=%.2f units\n",avg);
}

int main(){
input();
sorting();
calc_times();
calc_avg();
return 0;
}


