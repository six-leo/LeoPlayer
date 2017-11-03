//
//  leoplayer.h
//  LeoPlayerMacos
//
//  Created by leo.liufu on 2017/11/1.
//  Copyright © 2017年 leo.liufu. All rights reserved.
//

#ifndef leoplayer_h
#define leoplayer_h

#include <stdio.h>
#include <stdbool.h>
#include "ff_inc.h"
#include "ff_msg_queue.h"

typedef struct LeoMediaPlayer  LeoMediaPlayer;
struct FFPlayer;
/*-
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_IDLE);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_INITIALIZED);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_ASYNC_PREPARING);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_PREPARED);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_STARTED);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_PAUSED);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_COMPLETED);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_STOPPED);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_ERROR);
 MPST_CHECK_NOT_RET(mp->mp_state, MP_STATE_END);
 */

/*-
 * leomp_set_data_source()  -> MP_STATE_INITIALIZED
 *
 * leomp_reset              -> self
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_IDLE               0

/*-
 * leomp_prepare_async()    -> MP_STATE_ASYNC_PREPARING
 *
 * leomp_reset              -> MP_STATE_IDLE
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_INITIALIZED        1

/*-
 *                   ...    -> MP_STATE_PREPARED
 *                   ...    -> MP_STATE_ERROR
 *
 * leomp_reset              -> MP_STATE_IDLE
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_ASYNC_PREPARING    2

/*-
 * leomp_seek_to()          -> self
 * leomp_start()            -> MP_STATE_STARTED
 *
 * leomp_reset              -> MP_STATE_IDLE
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_PREPARED           3

/*-
 * leomp_seek_to()          -> self
 * leomp_start()            -> self
 * leomp_pause()            -> MP_STATE_PAUSED
 * leomp_stop()             -> MP_STATE_STOPPED
 *                   ...    -> MP_STATE_COMPLETED
 *                   ...    -> MP_STATE_ERROR
 *
 * leomp_reset              -> MP_STATE_IDLE
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_STARTED            4

/*-
 * leomp_seek_to()          -> self
 * leomp_start()            -> MP_STATE_STARTED
 * leomp_pause()            -> self
 * leomp_stop()             -> MP_STATE_STOPPED
 *
 * leomp_reset              -> MP_STATE_IDLE
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_PAUSED             5

/*-
 * leomp_seek_to()          -> self
 * leomp_start()            -> MP_STATE_STARTED (from beginning)
 * leomp_pause()            -> self
 * leomp_stop()             -> MP_STATE_STOPPED
 *
 * leomp_reset              -> MP_STATE_IDLE
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_COMPLETED          6

/*-
 * leomp_stop()             -> self
 * leomp_prepare_async()    -> MP_STATE_ASYNC_PREPARING
 *
 * leomp_reset              -> MP_STATE_IDLE
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_STOPPED            7

/*-
 * leomp_reset              -> MP_STATE_IDLE
 * leomp_release            -> MP_STATE_END
 */
#define MP_STATE_ERROR              8

/*-
 * leomp_release            -> self
 */
#define MP_STATE_END                9



#define LEOMP_IO_STAT_READ 1



void            leomp_global_init();
void            leomp_global_uninit();
void            leomp_global_set_log_report(int use_report);
void            leomp_global_set_log_level(int log_level);   // log_level = AV_LOG_xxx
void            leomp_global_set_inject_callback(leo_inject_callback cb);
const char     *leomp_version();
void            leomp_io_stat_register(void (*cb)(const char *url, int type, int bytes));
void            leomp_io_stat_complete_register(void (*cb)(const char *url,
                                                           int64_t read_bytes, int64_t total_size,
                                                           int64_t elpased_time, int64_t total_duration));

// ref_count is 1 after open
LeoMediaPlayer * leomp_create(int (*msg_loop)(void*));
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

// must be freed with free();
//LeoMediaMeta   *leomp_get_meta_l(LeoMediaPlayer *mp);

// preferred to be called explicity, can be called multiple times
// NOTE: leomp_shutdown may block thread
void            leomp_shutdown(LeoMediaPlayer *mp);

void            leomp_inc_ref(LeoMediaPlayer *mp);

// call close at last release, also free memory
// NOTE: leomp_dec_ref may block thread
void            leomp_dec_ref(LeoMediaPlayer *mp);
void            leomp_dec_ref_p(LeoMediaPlayer **pmp);

int             leomp_set_data_source(LeoMediaPlayer *mp, const char *url);
int             leomp_prepare_async(LeoMediaPlayer *mp);
int             leomp_start(LeoMediaPlayer *mp);
int             leomp_pause(LeoMediaPlayer *mp);
int             leomp_stop(LeoMediaPlayer *mp);
int             leomp_seek_to(LeoMediaPlayer *mp, long msec);
int             leomp_get_state(LeoMediaPlayer *mp);
bool            leomp_is_playing(LeoMediaPlayer *mp);
long            leomp_get_current_position(LeoMediaPlayer *mp);
long            leomp_get_duration(LeoMediaPlayer *mp);
long            leomp_get_playable_duration(LeoMediaPlayer *mp);
void            leomp_set_loop(LeoMediaPlayer *mp, int loop);
int             leomp_get_loop(LeoMediaPlayer *mp);

void           *leomp_get_weak_thiz(LeoMediaPlayer *mp);
void           *leomp_set_weak_thiz(LeoMediaPlayer *mp, void *weak_thiz);

/* return < 0 if aborted, 0 if no packet and > 0 if packet.  */
/* need to call msg_free_res for freeing the resouce obtained in msg */
int             leomp_get_msg(LeoMediaPlayer *mp, AVMessage *msg, int block);
void            leomp_set_frame_at_time(LeoMediaPlayer *mp, const char *path, int64_t start_time, int64_t end_time, int num, int definition);




#endif /* leoplayer_h */
