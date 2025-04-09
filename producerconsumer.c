#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 5
int buffer[SIZE];
int in = 0, out = 0;
int mutex = 1; 
int full = 0;
int empty = SIZE;
int wait(int *s) {
while (*s <= 0);
(*s)--;
return 0;
}
int Signal(int *s) {
(*s)++;
return 0;
}
void* producer(void* arg) {
int item = 1;
while(1) {
wait(&empty); 
wait(&mutex); 
buffer[in] = item;
printf("Produced %d at %d\n", item, in);

in = (in + 1) % SIZE;
item++;
Signal(&mutex); 
Signal(&full); 
sleep(1);
}
return NULL;
}
void* consumer(void* arg) {
while(1) {
wait(&full); 
wait(&mutex); 
int item = buffer[out];
printf("Consumed %d from %d\n", item, out);
out = (out + 1) % SIZE;
Signal(&mutex); 
Signal(&empty); 
sleep(1);
}
return NULL;
}
int main() {
pthread_t p, c;
pthread_create(&p, NULL, producer, NULL);
pthread_create(&c, NULL, consumer, NULL);
pthread_join(p, NULL);
pthread_join(c, NULL);
return 0;
}
