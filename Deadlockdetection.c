int main() { 
int P, R; 
printf("Enter the number of processes: "); 
scanf("%d", &P); 
printf("Enter the number of resource types: "); 
scanf("%d", &R); 
int allocation[P][R], request[P][R], available[R]; 
bool finish[P]; 
// Input Allocation Matrix 
printf("Enter the Allocation Matrix (%d x %d):\n", P, R); 
for (int i = 0; i < P; i++) { 
printf("Process P%d: ", i); 
for (int j = 0; j < R; j++) { 
scanf("%d", &allocation[i][j]); 
} 
} 
// Input Request Matrix 
printf("Enter the Request Matrix (%d x %d):\n", P, R); 
for (int i = 0; i < P; i++) { 
printf("Process P%d: ", i); 
for (int j = 0; j < R; j++) { 
scanf("%d", &request[i][j]); 
} 
} 
// Input Available Resources 
printf("Enter the Available Resources (%d): ", R); 
for (int i = 0; i < R; i++) { 
scanf("%d", &available[i]); 
} 
// Initialize Finish array
for (int i = 0; i < P; i++) 
finish[i] = false; 
int work[R]; 
for (int i = 0; i < R; i++) 
work[i] = available[i]; 
bool deadlockExists = false; 
while (true) { 
bool found = false; 
for (int i = 0; i < P; i++) { 
if (!finish[i]) { 
bool canProceed = true; 
for (int j = 0; j < R; j++) { 
if (request[i][j] > work[j]) { 
canProceed = false; 
break; 
} 
} 
if (canProceed) { 
for (int j = 0; j < R; j++) 
work[j] += allocation[i][j]; 
finish[i] = true; 
found = true; 
} 
} 
} 
if (!found) 
break; 
} 
printf("Deadlocked Processes: "); for (int i = 0; i < P; i++) { 
if (!finish[i]) { 
printf("P%d ", i); 
deadlockExists = true; 
} 
} 
if (!deadlockExists) 
printf("System is in safe state."); printf("\n");
return 0; 
} 
