/*
 * @Author: yangjiawei 1617324537@qq.com
 * @Date: 2023-05-24 22:28:28
 * @LastEditors: yangjiawei 1617324537@qq.com
 * @LastEditTime: 2023-05-24 23:20:20
 * @FilePath: /pro_app/pthread_led.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef PTHREAD_H
#define PTHREAD_H
#include "common.h"
void *pthread_led_handle(void* param);
void pthread_led_release();
#endif