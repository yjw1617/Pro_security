/*
 * @Description: 
 * @Version: 2.0
 * @Autor: Yjw
 * @Date: 2023-06-03 22:53:58
 * @LastEditors: Yjw
 * @LastEditTime: 2023-06-03 23:07:36
 */
#ifndef MES_H
#define MES_H
#define MSG_TYPE_LED 1
struct Msg_t
{
	long msg_type;
    char buf[128];
};
#define MSG_LEN (sizeof(struct Msg_t) - sizeof(long))
/********内部消息协议**********/
#define MES_OWN_HEAD1 0xcc
#define MES_OWN_HEAD2 0xaa
/*********内部消息协议end******/
#endif