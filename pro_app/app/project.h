/*
 * @Author: yangjiawei 1617324537@qq.com
 * @Date: 2023-05-24 22:35:43
 * @LastEditors: yangjiawei 1617324537@qq.com
 * @LastEditTime: 2023-05-25 00:07:47
 * @FilePath: /pro_app/project.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef PROJECT_H
#define PROJECT_H
#include "common.h"
/**************************log**************************************/
#define Support_App_Log 1

#if Support_App_Log
extern pthread_mutex_t mutex_log;//查阅文档printf虽然是线程安全的不过还是加一个互斥锁
#define log_app(...)                        \
    do                                      \
    {                                       \
        pthread_mutex_lock(&mutex_log);     \
        printf("[App] : ");                 \
        printf(__VA_ARGS__);                \
        printf("\n");                       \
        pthread_mutex_unlock(&mutex_log);   \
    } while (0)
#else
	#define log_app
#endif
#endif