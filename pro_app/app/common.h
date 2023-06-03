/*
 * @Author: yangjiawei 1617324537@qq.com
 * @Date: 2023-05-23 23:37:00
 * @LastEditors: Yjw
 * @LastEditTime: 2023-06-03 22:51:49
 * @FilePath: /pro_app/common.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include "pthread_led.h"
#include "pthread_client_request.h"
#include "tool.h"
#include "project.h"
#include "data_global.h"
#include "mes.h"

// #define MSG_LEN (sizeof(Msg_t) - sizeof(long))
#define MSG_TYPE_LED 1
#endif