//
//  leoplayer_internal.h
//  LeoPlayerMacos
//
//  Created by leo.liufu on 2017/11/2.
//  Copyright © 2017年 leo.liufu. All rights reserved.
//

#ifndef leoplayer_internal_h
#define leoplayer_internal_h

#include "ff_play.h"
#include "leoplayer.h"
#include <SDL.h>
#include <SDL_thread.h>
#include <assert.h>


struct LeoMediaPlayer {
    volatile int ref_count;
    
    pthread_mutex_t mutex;//maybe use SDL_mutex instead for corss platform
    
    FFPlayer *ffplayer;
    
    
    int (*msg_loop)(void*);
};

#endif /* leoplayer_internal_h */
