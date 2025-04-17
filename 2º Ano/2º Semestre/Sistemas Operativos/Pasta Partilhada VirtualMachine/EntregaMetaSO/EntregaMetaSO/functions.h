#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
#include <pthread.h>
#include <signal.h>

#define MESSAGEQUEUE "/tmp/messagequeue"

#define PING 1
#define PONG 2

typedef struct
{
  /* Message type */
  long mtype;
  /* Payload */
  int total_msgs;                     /* Number of messages  */
  int some_value;                     /* Value */
} pingpong_msg;

#endif