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
#include <stdint.h>
int cgiMain(){
    //返回数据类型
    fprintf(cgiOut, "Content-type: application/json\r\n\r\n");
    // fprintf(cgiOut, data);
    // cgiFormString("led",msg_recv,1);
    char msg_send[128] = {0};
    if(strcmp(getenv("REQUEST_METHOD"), "GET") == 0){
        char* msg_recv = getenv("QUERY_STRING");
        char con[2] = {0};
        sscanf(msg_recv,"led=%s",con);
        sprintf(msg_send, "{\"code\":\"%d\",\"msg\":\"%s\"}", 200, con);
        fprintf(cgiOut, msg_send);
    }else{
        // sprintf(msg_send, "{\"code\":\"%d\",\"msg\":\"%s\"}", 200, "strcmp error");
        // fprintf(cgiOut, msg_send);
    }
    // if(cmd == '1'){
    //     sprintf(msg, "{\"code\":\"%d\",\"msg\":\"%s\"}", 200, "led on ok");
    //     fprintf(cgiOut, msg);
    // }else if(cmd == '0'){
    //     sprintf(msg, "{\"code\":\"%d\",\"msg\":\"%s\"}", 200, "led off ok");
    //     fprintf(cgiOut, msg);
    // }
}