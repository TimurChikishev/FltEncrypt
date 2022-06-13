#ifndef __COMMON_H__
#define __COMMON_H__

#define BUFSIZE 1024

#include <fltKernel.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
typedef enum _MY_COMMAND
{
    ADD,
    DEL,
    CONNECT,
    DISCONNECT
} MY_COMMAND;

typedef struct _INPUT_BUFFER
{
    MY_COMMAND command;
    WCHAR password[BUFSIZE];
    WCHAR fileName[BUFSIZE];
    WCHAR fileExt[BUFSIZE];
    WCHAR filePath[BUFSIZE];
} INPUT_BUFFER, * PINPUT_BUFFER;

#endif