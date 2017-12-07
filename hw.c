/*
    -c N
        Create a semaphore and set its value to N
        If the semaphore already exists, it should pint a message saying so
    -v
        View the current value of the semaphore
    -r
        remove the semaphore

Note: you can use $ ipcs -s to check on any active semaphores from the command line. This will be useful to develop your program.

Sample program output:
Example output:
$ ./control -c 4
semaphore created: 589842
value set: 0
$ ./control -v
semaphore value: 4
$ ./control -c 3
semaphore already exists
$ ./control -v
semaphore value: 4
$ ./control -r
semaphore removed: 0

In order to create this function, you will need to be able to set and view the semaphore, that has to be done using the semctl function

    semctl( DESCRIPTOR, INDEX, OPERATION, DATA )
        DESCRIPTOR: return value of semget
        INDEX: Index of the semaphore in the semaphore set
        OPERATION: For this assignment, you only need the following operations:
            SETVAL
            GETVAL
        DATA: Required for SETVAL
        Check out $ man semctl for more info. Focus on SETVAL and GETVAL
  */

#include 'head.h'
int main(int argct, char** args)
{
  if (argct < 2)
    {
      printf("Not enough arguments.");
      exit(0);
    }
}
