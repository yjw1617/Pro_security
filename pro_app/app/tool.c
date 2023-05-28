/*
 * @Author: yangjiawei 1617324537@qq.com
 * @Date: 2023-05-24 22:11:03
 * @LastEditors: yangjiawei 1617324537@qq.com
 * @LastEditTime: 2023-05-24 22:14:39
 * @FilePath: /pro_app/tool.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "tool.h"
int tool_array_sum(uint8_t* arry, int len){
    int sum = 0;
    int i = 0;
    for (i = 0; i < len; i++){
        sum += arry[i];
    }
    return sum;
}