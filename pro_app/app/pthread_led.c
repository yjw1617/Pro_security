/*
 * @Author: yangjiawei 1617324537@qq.com
 * @Date: 2023-05-24 22:28:00
 * @LastEditors: yangjiawei 1617324537@qq.com
 * @LastEditTime: 2023-05-24 23:56:30
 * @FilePath: /pro_app/pthread_led.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "pthread_led.h"
void *pthread_led_handle(void* param){
    while(1){
        sleep(1);
        // log_app("pthread led run");
        printf("pthread led run");
    }
}
