/*
 * @Author: yangjiawei 1617324537@qq.com
 * @Date: 2023-05-23 23:28:00
 * @LastEditors: yangjiawei 1617324537@qq.com
 * @LastEditTime: 2023-05-24 22:15:53
 * @FilePath: /pro_app/mes.c
 * @Description: 
 * 
 * Copyright (c) 2023 by ${git_name_email}, All Rights Reserved. 
 */
#include "mes.h"
#include "common.h"
/********内部消息协议**********/
/**
 * @description: 封装内部消息
 * @param {uint8_t*} buf : 需要被封装的数据
 * @param {uint8_t} cmd : 数据cmd
 * @param {uint8_t} len : 数据长度
 * @param {uint8_t*} data : 数据
 * @return {*}
 */
void mes_own_package(uint8_t* buf, uint8_t addr_src, uint8_t addr_dest, uint8_t cmd, uint8_t len, uint8_t* data){
    buf[0] = 0xcc;
    buf[1] = 0xaa;
    buf[2] = addr_src;
    buf[3] = addr_dest;
    buf[4] = cmd;
    buf[5] = len;
    memcpy(&buf[6], data, len);
    //校验马
    buf[6 + len] = tool_array_sum(buf, len) % 256;
}
/********内部消息协议end**********/