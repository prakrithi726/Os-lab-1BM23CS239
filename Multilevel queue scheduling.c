#include<stdio.h> 
typedef struct Process{ 
 int id, at, bt, type, ct, tat, wt, remt; 
}Process; 
int ttt=0, twt=0; 
void sortbyAT(Process p[], int n){ 
 for(int i=0;i<n-1;i++){ 
 for(int j=i+1;j<n;j++){ 
 if(p[i].at>p[j].at){ 
 Process temp=p[i]; 
 p[i]=p[j]; 
 p[j]=temp; 
 } 
 } 
 } 
} 
void fcfs(Process p[], int n, int start){ 
 int curr=start; 
 for(int i=0;i<n;i++){ 
 if(p[i].at>curr) 
 curr=p[i].at; 
 p[i].ct=p[i].bt+curr; 
 p[i].tat=p[i].ct-p[i].at; 
 p[i].wt=p[i].tat-p[i].bt; 
 curr=p[i].ct; 
 } 
}
void printProcess(Process p[], int n, char* type){ 
 printf("%s Process:\n", type); 
 printf("Process\tAT\tBT\tCT\tTAT\tWT\n"); 
 for(int i=0;i<n;i++){ 
 printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);  ttt+=p[i].tat; 
 twt+=p[i].wt; 
 } 
} 
void roundrobin(Process p[], int n, int tq, int start){ 
 int comp=0, curr=start; 
 int queue[20], visited[n], front=0, rear=0; 
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
 int exec_t=(p[idx].remt>tq)?tq:p[idx].remt; 
 curr+=exec_t; 
 p[idx].remt-=exec_t; 
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
} 
int main(){ 
 int n, sysc=0, userc=0; 
 printf("Enter the number of processes:"); 
 scanf("%d", &n); 
 Process p[n], sysp[n], userp[n]; 
 printf("Enter the AT, BT and type(0-system, 1-user) for each process:\n");  for(int i=0;i<n;i++){ 
 p[i].id=i+1; 
 printf("Process %d:", i+1); 
 scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].type); 
 if(p[i].type==0){ 
 sysp[sysc++]=p[i]; 
 } 
 else 
 userp[userc++]=p[i]; 
 }
 int c, tq; 
 printf("Enter:\n1. Both FCFS\n2. System is FCFS and user is RR\n3. System is RR and User is FCFS\n"); 
 scanf("%d", &c); 
 if(c==1){ 
 sortbyAT(sysp, sysc); 
 sortbyAT(userp, userc); 
 fcfs(sysp, sysc, 0); 
 int lct=(sysc>0)?sysp[sysc-1].ct:0; 
 fcfs(userp, userc, lct); 
 } 
 else if(c==2){ 
 printf("Enter the time quantum:"); 
 scanf("%d", &tq); 
 sortbyAT(sysp, sysc); 
 fcfs(sysp, sysc, 0); 
 int lct=(sysc>0)?sysp[sysc-1].ct:0; 
 roundrobin(userp, userc, tq,lct); 
 } 
 else{ 
 printf("Enter the time quantum:"); 
 scanf("%d", &tq); 
 roundrobin(sysp, sysc, tq,0); 
 int lct=(sysc>0)?sysp[sysc-1].ct:0; 
 fcfs(userp, userc, lct); 
 } 
 printProcess(sysp, sysc, "System"); 
 printProcess(userp, userc, "User"); 
 printf("\nAverage TAT: %.2f units\n", (float)ttt/n); 
 printf("Average WT: %.2f units\n", (float)twt/n); 
} 
