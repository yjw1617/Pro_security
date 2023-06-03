/*
 * @Description: 
 * @Version: 2.0
 * @Autor: Yjw
 * @Date: 2023-05-29 00:10:39
 * @LastEditors: Yjw
 * @LastEditTime: 2023-06-03 23:23:29
 */
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
#include "mes.h"
#define Json_Print(out, cmd, msg)  \
    fprintf(out, "{\"cmd\":\"%d\",\"msg\":\"%s\"}", cmd, msg)
int cgiMain(){
    cgiHeaderContentType("application/json");

    /*打开本地资源*/
    struct Msg_t msgbuf;
    key_t key;
    if((key = ftok("/tmp",'g')) < 0){
        Json_Print(cgiOut, 0, "ftok failed");
		return -1;
	}
    int msgid = msgget(key,IPC_CREAT|0666);
	if(msgid == -1)	{
        Json_Print(cgiOut, 0, "fail to msgget");
        return -1;
	}
    // fprintf(cgiOut, "Content-type: application/json\r\n\r\n");
    // fprintf(cgiOut, data);
    // cgiFormString("led",msg_recv,1);
    char msg_send[128] = {0};
    if(strcmp(getenv("REQUEST_METHOD"), "GET") == 0){
        char* msg_recv = getenv("QUERY_STRING");
        char con[2] = {0};
        sscanf(msg_recv,"led=%s",con);
        if(strncmp(con, "0", 1) == 0){
            //发送消息给请求线程
            msgbuf.msg_type = MSG_TYPE_LED;
            msgbuf.buf[0] = 0x00;//关灯
            if(msgsnd(msgid, &msgbuf, MSG_LEN, 0) < 0){
                Json_Print(cgiOut, 0, "msgsnd faild");
            }
        }else if(strncmp(con, "1", 1) == 0){
            //发送消息给请求线程
            msgbuf.msg_type = MSG_TYPE_LED;
            msgbuf.buf[0] = 0x01;//开灯
            if(msgsnd(msgid, &msgbuf, MSG_LEN, 0) < 0){
                Json_Print(cgiOut, 0, "msgsnd faild");
            }
        }
        // fprintf(cgiOut, msg_send);
    }else if(strcmp(getenv("REQUEST_METHOD"), "POST") == 0){
        char cmd[128] = {0};
        char con[1];
        cgiFormResultType ret = cgiFormString("cmd", cmd, 128);
        Json_Print(cgiOut, 1, cmd);
    }
    
}