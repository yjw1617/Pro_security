/*
 * @Description: 
 * @Version: 2.0
 * @Autor: Yjw
 * @Date: 2023-06-03 22:12:35
 * @LastEditors: Yjw
 * @LastEditTime: 2023-06-03 22:45:01
 */
#include "data_global.h"
/*mutex*/
pthread_mutex_t mutex_log = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_led = PTHREAD_MUTEX_INITIALIZER;
/*end*/

/*cond*/
pthread_cond_t cond_led;
/*end*/