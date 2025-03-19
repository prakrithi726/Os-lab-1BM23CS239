#include<stdio.h>
struct Process{
int id, at, bt, ct, tat, wt, remt;
};
void roundrobin(struct Process p[], int n, int tq){
int comp=0, curr=0, ttt=0, twt=0;
int queue[20], visited[n], rear=0, front=0;
for(int i=0;i<n;i++){
visited[i]=0;
p[i].remt=p[i].bt;
}
for(int i=0;i<n;i++){
if(p[i].at==0){
visited[i]=1;
queue[rear++]=i;
}
}
while(comp<n){
if(front==rear){
curr++;
for(int i=0;i<n;i++){
if(p[i].at<=curr && !visited[i]){
visited[i]=1;
queue[rear++]=i;
}
}
continue;
}
int idx=queue[front++];
int exec_time=(p[idx].remt>tq)?tq:p[idx].remt;
curr+=exec_time;
p[idx].remt-=exec_time;
for(int i=0;i<n;i++){
if(p[i].at<=curr && !visited[i]){

visited[i]=1;
queue[rear++]=i;
}
}
if(p[idx].remt==0){
comp++;
p[idx].ct=curr;
p[idx].tat=p[idx].ct-p[idx].at;
p[idx].wt=p[idx].tat-p[idx].bt;
ttt+=p[idx].tat;
twt+=p[idx].wt;
}
else{
queue[rear++]=idx;
}
}
printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++){
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
}
printf("Average TAT: %.2f units\n",(float)ttt/n);
printf("Average WT: %.2f units\n",(float)twt/n);
}
int main(){
int n,tq;
printf("Enter the number of processes:");
scanf("%d", &n);
struct Process p[n];
printf("Enter the arrival and burst time for process:\n");
for(int i=0;i<n;i++){
p[i].id=i+1;
printf("Process %d: ",i+1);
scanf("%d %d", &p[i].at, &p[i].bt);
}
printf("Enter the time quantum:");
scanf("%d", &tq);
roundrobin(p,n,tq);
return 0;
}
