//
//  ff_msg_queue.h
//  LeoPlayerMacos
//
//  Created by xiaoliu on 2017/11/2.
//  Copyright © 2017年 xiaoliu. All rights reserved.
//

#ifndef ff_msg_queue_h
#define ff_msg_queue_h

#include <stdbool.h>

typedef struct AVMessage {
    int what;
    int arg1;
    int arg2;
    void *obj;
    void (*free_l)(void *obj);
    struct AVMessage *next;
} AVMessage;


#endif /* ff_msg_queue_h */
