#include <stdio.h> 
#include "cgic.h" 
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int cgiMain(){
    char data[100] = {0};
    int age = 100;
    sprintf(data, "{\"name\":\"John Doe\",\"age\":%d,\"city\":\"New York\"}", age);
    cgiHeaderContentType("application/json");
    fprintf(cgiOut, data);
}