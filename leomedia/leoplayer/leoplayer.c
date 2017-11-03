//
//  leoplayer.c
//  LeoPlayerMacos
//
//  Created by leo.liufu on 2017/11/1.
//  Copyright © 2017年 leo.liufu. All rights reserved.
//

#include "leoplayer.h"
#include "ff_play.h"
#include "player_version.h"
#include "leoplayer_internal.h"
#include "ff_memory.h"


inline static void leomp_destroy(LeoMediaPlayer *mp)
{
    if (!mp)
        return;
    
//    ffp_destroy_p(&mp->ffplayer);
//    if (mp->msg_thread) {
//        SDL_WaitThread(mp->msg_thread, NULL);
//        mp->msg_thread = NULL;
//    }
//
//    pthread_mutex_destroy(&mp->mutex);
//
//    freep((void**)&mp->data_source);
//    memset(mp, 0, sizeof(IjkMediaPlayer));
//    freep((void**)&mp);
}

inline static void leomp_destroy_p(LeoMediaPlayer **pmp)
{
    if (!pmp)
        return;
    
    leomp_destroy(*pmp);
    *pmp = NULL;
}


void  leomp_global_init()
{
    ffp_global_init();
}
void  leomp_global_uninit()
{
    ffp_global_uninit();
}
void  leomp_global_set_log_report(int use_report)
{
    
}
void  leomp_global_set_log_level(int log_level)  // log_level = AV_LOG_xxx
{
    
}
void  leomp_global_set_inject_callback(leo_inject_callback cb)
{
    
}
const char     *leomp_version()
{
    return LEOPLAYER_VERSION;
}
void  leomp_io_stat_register(void (*cb)(const char *url, int type, int bytes))
{
    
}
void  leomp_io_stat_complete_register(void (*cb)(const char *url,int64_t read_bytes, int64_t total_size,
                                                           int64_t elpased_time, int64_t total_duration))
{
    
}


// ref_count is 1 after open
LeoMediaPlayer * leomp_create(int (*msg_loop)(void*))
{
    LeoMediaPlayer *mp = (LeoMediaPlayer *) mallocz(sizeof(LeoMediaPlayer));
    if(!mp)
        goto fail;
    mp->msg_loop = msg_loop;
    
fail:
    leomp_destroy(mp);
    return NULL;
}
void*            leomp_set_inject_opaque(LeoMediaPlayer *mp, void *opaque);
void*            leomp_set_leoio_inject_opaque(LeoMediaPlayer *mp, void *opaque);

void             leomp_set_option(LeoMediaPlayer *mp, int opt_category, const char *name, const char *value);
void             leomp_set_option_int(LeoMediaPlayer *mp, int opt_category, const char *name, int64_t value);

int              leomp_get_video_codec_info(LeoMediaPlayer *mp, char **codec_info);
int              leomp_get_audio_codec_info(LeoMediaPlayer *mp, char **codec_info);
void             leomp_set_playback_rate(LeoMediaPlayer *mp, float rate);
void             leomp_set_playback_volume(LeoMediaPlayer *mp, float rate);

int              leomp_set_stream_selected(LeoMediaPlayer *mp, int stream, int selected);

float            leomp_get_property_float(LeoMediaPlayer *mp, int id, float default_value);
void             leomp_set_property_float(LeoMediaPlayer *mp, int id, float value);
int64_t          leomp_get_property_int64(LeoMediaPlayer *mp, int id, int64_t default_value);
void             leomp_set_property_int64(LeoMediaPlayer *mp, int id, int64_t value);



//

void            leomp_inc_ref(LeoMediaPlayer *mp)
{
    assert(mp);
    __sync_fetch_and_add(&mp->ref_count,1);//linux no locker atomic operation
    
}
