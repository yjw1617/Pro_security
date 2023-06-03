/*
 * @Author: yangjiawei 1617324537@qq.com
 * @Date: 2023-05-24 22:28:00
 * @LastEditors: Yjw
 * @LastEditTime: 2023-06-03 23:10:16
 * @FilePath: /pro_app/pthread_led.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "pthread_led.h"
extern pthread_mutex_t mutex_led;
extern pthread_cond_t cond_led;
static int cmd_led = 0;
int led_con(int cmd, void* parm){
    cmd_led = cmd;
}
void *pthread_led_handle(void* param){
    while(1){
        pthread_mutex_lock(&mutex_led);
        pthread_cond_wait(&cond_led, &mutex_led);
        // log_app("pthread led run");
        if(cmd_led == 0x01){
            log_app("led on");
        }else if(cmd_led == 0x00){
            log_app("led off");
        }
        pthread_mutex_unlock(&mutex_led);
    }
}
