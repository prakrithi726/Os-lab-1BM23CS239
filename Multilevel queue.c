#include <stdio.h>

#define MAX 

typedef struct {
    int id;         // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int priority;   // Priority
    int waiting;    // Waiting Time
    int turnaround; // Turnaround Time
} Process;

// Function to sort processes by Arrival Time
void sort_by_arrival(Process arr[], int n) {
    int i, j;
    Process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].arrival > arr[j].arrival) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    Process q1[MAX], q2[MAX]; // Two queues for multilevel scheduling
    int q1_count = 0, q2_count = 0;
    int total_time = 0, total_wait = 0, total_turnaround = 0;
    float avg_wait, avg_turnaround;

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    Process processes[MAX];

    // Input process details
    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("\nEnter details for Process[%d]:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst);
        printf("Priority (Lower value = Higher priority): ");
        scanf("%d", &processes[i].priority);

        // Assign to Queue 1 or Queue 2 based on priority
        if (processes[i].priority <= 3) {
            q1[q1_count++] = processes[i]; // High priority queue
        } else {
            q2[q2_count++] = processes[i]; // Low priority queue
        }
    }

    // Sort both queues by Arrival Time (FCFS)
    sort_by_arrival(q1, q1_count);
    sort_by_arrival(q2, q2_count);

    // Execute Queue 1 (Higher Priority, FCFS)
    printf("\nExecuting Queue 1 (Higher Priority, FCFS):\n");
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < q1_count; i++) {
        if (total_time < q1[i].arrival)
            total_time = q1[i].arrival;  // Ensure CPU starts at the right time

        q1[i].waiting = total_time - q1[i].arrival;
        q1[i].turnaround = q1[i].waiting + q1[i].burst;
        total_wait += q1[i].waiting;
        total_turnaround += q1[i].turnaround;
        total_time += q1[i].burst;

        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", q1[i].id, q1[i].arrival, q1[i].burst, q1[i].waiting, q1[i].turnaround);
    }

    // Execute Queue 2 (Lower Priority, FCFS)
    printf("\nExecuting Queue 2 (Lower Priority, FCFS):\n");
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < q2_count; i++) {
        if (total_time < q2[i].arrival)
            total_time = q2[i].arrival;  // Ensure CPU starts at the right time

        q2[i].waiting = total_time - q2[i].arrival;
        q2[i].turnaround = q2[i].waiting + q2[i].burst;
        total_wait += q2[i].waiting;
        total_turnaround += q2[i].turnaround;
        total_time += q2[i].burst;

        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", q2[i].id, q2[i].arrival, q2[i].burst, q2[i].waiting, q2[i].turnaround);
    }

    // Calculate averages
    avg_wait = (float)total_wait / n;
    avg_turnaround = (float)total_turnaround / n;

    printf("\nAverage Waiting Time: %.2f", avg_wait);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround);

    return 0;
}

OUTPUT:
Enter Total Number of Processes: 4

Enter details for Process[1]:
Arrival Time: 0
Burst Time: 2
Priority (Lower value = Higher priority): 1

Enter details for Process[2]:
Arrival Time: 3
Burst Time: 9
Priority (Lower value = Higher priority): 1

Enter details for Process[3]:
Arrival Time: 5
Burst Time: 9
Priority (Lower value = Higher priority): 1

Enter details for Process[4]:
Arrival Time: 7
Burst Time: 9
Priority (Lower value = Higher priority): 1

Executing Queue 1 (Higher Priority, FCFS):

Process ID	Arrival Time	Burst Time	Waiting Time	Turnaround Time
P[1]				  		 0        	2            0             2
P[2]				  		 3         	9	           0             9
P[3]		  			   5        	9	           7             16
P[4]				  		 7         	9	           14            23

Executing Queue 2 (Lower Priority, FCFS):

Process ID	Arrival Time	Burst Time	Waiting Time	Turnaround Time

Average Waiting Time: 5.25
Average Turnaround Time: 12.50
