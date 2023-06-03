/*
 * @Author: yangjiawei 1617324537@qq.com
 * @Date: 2023-05-23 23:02:35
 * @LastEditors: Yjw
 * @LastEditTime: 2023-06-03 23:18:25
 * @FilePath: /pro_app/main.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "common.h"
static pthread_t pt_led;
static pthread_t pt_client_request;
extern pthread_mutex_t mutex_log;
void main_resource_release(int sig);
int main()
{
    /*互斥锁*/
    pthread_mutex_init(&mutex_log, NULL);//用户打印的互斥索

    /*信号捕捉*/
    struct sigaction act;
    act.sa_handler = main_resource_release;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act,NULL);//这个函数更加通用
    /*创建led线程*/
    pthread_create(&pt_led, NULL, pthread_led_handle, NULL);
    pthread_create(&pt_client_request, NULL, pthread_client_request_handle, NULL);
    while(1){
        sleep(1);
        // printf("pthread main run");
    }
    return 0;
}

void main_resource_release(int sig){
    if(sig == SIGINT){
        pthread_detach(pt_led);
        pthread_cancel(pt_led);//睡眠的时候才能取消
    }
    exit(0);
}