/*
 * @Description: 
 * @Version: 2.0
 * @Autor: Yjw
 * @Date: 2023-06-03 21:26:34
 * @LastEditors: Yjw
 * @LastEditTime: 2023-06-03 22:49:08
 */
#include "pthread_client_request.h"
extern pthread_mutex_t mutex_led;
extern pthread_cond_t cond_led;


void* pthread_client_request_handle(void* parm){
    struct Msg_t msgbuf;
    key_t key;
    if((key = ftok("/tmp",'g')) < 0){
		perror("ftok failed .\n");
		exit(-1);
	}
    int msgid = msgget(key,IPC_CREAT|0666);
	if(msgid == -1)	{
        perror("fail to msgget");
        exit(1);
	}
    while(1){
        memset(&msgbuf, 0, MSG_LEN);
        msgrcv(msgid, &msgbuf, MSG_LEN, 0, 0);//阻塞等待
        switch(msgbuf.msg_type){
            case MSG_TYPE_LED:
                pthread_mutex_lock(&mutex_led);
                led_con(msgbuf.buf[0], NULL);
				pthread_mutex_unlock(&mutex_led);
                pthread_cond_signal(&cond_led);
                break;
        }
    }
}