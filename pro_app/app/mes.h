/*
 * @Description: 
 * @Version: 2.0
 * @Autor: Yjw
 * @Date: 2023-05-28 18:02:45
 * @LastEditors: Yjw
 * @LastEditTime: 2023-06-03 22:50:54
 */
#ifndef MES_H
#define MES_H
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