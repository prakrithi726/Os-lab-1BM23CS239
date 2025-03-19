#include<stdio.h>
#define SIZE 10
struct Process{
int id, at, bt, priority, ct, tat, wt, remt;
};
void calc_times(struct Process p[], int n, int ispreemptive){
int time=0, minidx, comp=0, ttt=0, twt=0;
int executed[SIZE]={0};
while(comp<n){
minidx=-1;
for(int i=0;i<n;i++){
if(p[i].at<=time && !executed[i]){
if(minidx==-1 || p[i].priority<p[minidx].priority)
minidx=i;

}
}
if(minidx==-1){
time++;
continue;
}
if(ispreemptive){
p[minidx].remt--;
time++;
if(p[minidx].remt==0){
p[minidx].ct=time;
p[minidx].tat=p[minidx].ct-p[minidx].at;
p[minidx].wt=p[minidx].tat-p[minidx].bt;
executed[minidx]=1;
comp++;
ttt+=p[minidx].tat;
twt+=p[minidx].wt;
}
}
else{
time+=p[minidx].bt;
p[minidx].ct=time;
p[minidx].tat=p[minidx].ct-p[minidx].at;
p[minidx].wt=p[minidx].tat-p[minidx].bt;
comp++;
executed[minidx]=1;
ttt+=p[minidx].tat;
twt+=p[minidx].wt;
}
}
printf("Process\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++)
printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat,
p[i].wt);
printf("Average TAT: %.2f units\n", (float)ttt/n);
printf("Average WT: %.2f units\n", (float)twt/n);
}
int main(){
int n, ispreemptive;
printf("Enter the number of processes:");

scanf("%d", &n);
struct Process p[n];
printf("Enter the arrival time, burst time and priority for processes:\n");
for(int i=0;i<n;i++){
p[i].id=i+1;
printf("Process %d: ", i+1);
scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
p[i].remt=p[i].bt;
}
printf("Enter:\n0.Non-Preemptive\n1.Preemptive\n");
scanf("%d", &ispreemptive);
calc_times(p, n, ispreemptive);
return 0;
}
