/*
 * Jen Yu
 * Systems pd10
 * 2017-12-06
 * W14: Get sem control!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define KEY 38

int main(int argct, char** args){
  int sem;
  if(argct < 2){
    printf("Too few arguments.\n");
    printf("args: %s, %s\n", args[0], args[1]);
  }
  else{
    //semaphore creation!
    //if more than 3 arguments "./run -c <num" and strcmp() == 0 
    if((argct >= 3) && (!strcmp(args[1], "-c"))){
      sem = semget(KEY, 1, IPC_CREAT | IPC_EXCL | 0644);
      //if already exists, errno
      if (sem == -1){
	printf("The semaphore already exists.\n");
      }
      //else take inputted # and set val
      else{
	int input;
	sscanf(args[2], "%d", &input);
	semctl(sem, 0, SETVAL, input);
	printf("Semaphore %d created with value %d.\n", sem, input);
      }
    }
    //semaphore value procural!!
    //gets the semaphore val
    else if(!strcmp(args[1], "-v")){
      sem = semget(KEY, 0, 0);
      int val = semctl(sem, 0, GETVAL);
      printf("Value of semaphore: %d\n", val);
    }
    //remove the semaphore :'(
    else if (!strcmp(args[1], "-r")){
      sem = semget(KEY, 0, 0);
      int val = semctl(sem, 0, IPC_RMID);
      printf("Removed semaphore: %d\n", val);
    }
    else{
      printf("Could not read input.\n");
    }
  }
  return 0;
}
