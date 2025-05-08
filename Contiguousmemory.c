#include <stdio.h> 
#define MAX 10 
int main() { 
int blockSize[MAX], fileSize[MAX]; 
int blockCount, fileCount; 
int choice; 
printf("Memory Management Scheme:\n"); 
printf("Enter the number of blocks: "); 
scanf("%d", &blockCount); 
printf("Enter the number of files: "); 
scanf("%d", &fileCount); 
printf("Enter the size of the blocks:\n"); 
for (int i = 0; i < blockCount; i++) { 
printf("Block %d: ", i + 1); 
scanf("%d", &blockSize[i]); 
} 
printf("Enter the size of the files:\n"); 
for (int i = 0; i < fileCount; i++) { 
printf("File %d: ", i + 1); 
scanf("%d", &fileSize[i]); 
} 
do { 
printf("\n1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\nEnter your choice: "); scanf("%d", &choice); 
int allocation[MAX]; 
int tempBlockSize[MAX]; 
int allocated[MAX]={0}; 
for (int i = 0; i < blockCount; i++) 
tempBlockSize[i] = blockSize[i];
for (int i = 0; i < fileCount; i++) 
allocation[i] = -1; 
switch (choice) { 
case 1: 
printf("\n\tMemory Management Scheme – First Fit\n"); 
for (int i = 0; i < fileCount; i++) { 
for (int j = 0; j < blockCount; j++) { 
if (!allocated[j] && tempBlockSize[j] >= fileSize[i]) { 
allocation[i] = j; 
allocated[j]=1; 
break; 
} 
} 
} 
break; 
case 2: 
printf("\n\tMemory Management Scheme – Best Fit\n"); 
for (int i = 0; i < fileCount; i++) { 
int bestIdx = -1; 
for (int j = 0; j < blockCount; j++) { 
if (!allocated[j] && tempBlockSize[j] >= fileSize[i]) { 
if (bestIdx == -1 || tempBlockSize[j] < tempBlockSize[bestIdx]) { bestIdx = j; 
} 
} 
} 
if (bestIdx != -1) { 
allocation[i] = bestIdx; 
allocated[bestIdx]=1; 
} 
} 
break; 
case 3: 
printf("\n\tMemory Management Scheme – Worst Fit\n"); 
for (int i = 0; i < fileCount; i++) { 
int worstIdx = -1; 
for (int j = 0; j < blockCount; j++) { 
if (!allocated[j] && tempBlockSize[j] >= fileSize[i]) { 
if (worstIdx == -1 || tempBlockSize[j] > tempBlockSize[worstIdx]) { worstIdx = j;
} 
} 
} 
if (worstIdx != -1) { 
allocation[i] = worstIdx; 
allocated[worstIdx]=1; 
} 
} 
break; 
case 4: 
return 0; 
default: 
printf("Invalid choice\n"); 
} 
// Print allocation 
if (choice >= 1 && choice <= 3) { 
printf("File_no:\tFile_size :\tBlock_no:\tBlock_size:\n"); 
for (int i = 0; i < fileCount; i++) { 
printf("%d\t\t%d\t\t", i + 1, fileSize[i]); 
if (allocation[i] != -1) 
printf("%d\t\t%d\n", allocation[i] + 1, blockSize[allocation[i]]); else 
printf("Not Allocated\t-\n"); 
} 
} 
} while (choice != 4); 
return 0; 
} 
