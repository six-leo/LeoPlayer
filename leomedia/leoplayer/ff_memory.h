//
//  ff_memory.h
//  LeoPlayerMacos
//
//  Created by xiaoliu on 2017/11/2.
//  Copyright © 2017年 xiaoliu. All rights reserved.
//

#ifndef ff_memory_h
#define ff_memory_h
#include <stdlib.h>
#include<memory.h>

inline static void *mallocz(size_t size)
{
    void *mem = malloc(size);
    if (!mem)
        return mem;
    
    memset(mem, 0, size);
    return mem;
}

inline static void freep(void **mem)
{
    if (mem && *mem) {
        free(*mem);
        *mem = NULL;
    }
}

#endif /* ff_memory_h */
