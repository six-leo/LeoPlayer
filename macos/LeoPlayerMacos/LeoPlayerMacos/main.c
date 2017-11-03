//
//  main.c
//  LeoPlayerMacos
//
//  Created by leo.liufu on 2017/9/28.
//  Copyright © 2017年 leo.liufu. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}


// FFP_MERGE: stream_cycle_channel
// FFP_MERGE: toggle_full_screen
// FFP_MERGE: toggle_audio_display
// FFP_MERGE: refresh_loop_wait_event
// FFP_MERGE: event_loop
// FFP_MERGE: opt_frame_size
// FFP_MERGE: opt_width
// FFP_MERGE: opt_height
// FFP_MERGE: opt_format
// FFP_MERGE: opt_frame_pix_fmt
// FFP_MERGE: opt_sync
// FFP_MERGE: opt_seek
// FFP_MERGE: opt_duration
// FFP_MERGE: opt_show_mode
// FFP_MERGE: opt_input_file
// FFP_MERGE: opt_codec
// FFP_MERGE: dummy
// FFP_MERGE: options
// FFP_MERGE: show_usage
// FFP_MERGE: show_help_default
//compatiblity
//
//int ff_play_init_env(void *player)
//{
//    int flags;
//    ddffplayer = player;
//    av_log_set_flags(AV_LOG_SKIP_REPEATED);
//
//    av_register_all();
//    avformat_network_init();
//
//
//
//    if (display_disable) {
//        video_disable = 1;
//    }
//    flags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER;
//    if (audio_disable)
//        flags &= ~SDL_INIT_AUDIO;
//    else {
//        /* Try to work around an occasional ALSA buffer underflow issue when the
//         * period size is NPOT due to ALSA resampling by forcing the buffer size. */
//        /*  if (!SDL_getenv("SDL_AUDIO_ALSA_SET_BUFFER_SIZE"))
//         SDL_setenv("SDL_AUDIO_ALSA_SET_BUFFER_SIZE", "1", 1);*/
//    }
//    if (display_disable)
//        flags &= ~SDL_INIT_VIDEO;
//    if (SDL_Init(flags)) {
//        av_log(NULL, AV_LOG_FATAL, "Could not initialize SDL - %s\n", SDL_GetError());
//        av_log(NULL, AV_LOG_FATAL, "(Did you set the DISPLAY variable?)\n");
//
//    }
//    if (av_lockmgr_register(lockmgr)) {
//        av_log(NULL, AV_LOG_FATAL, "Could not initialize lock manager!\n");
//        do_exit(NULL);
//        return -2;
//    }
//
//    av_init_packet(&flush_pkt);
//    flush_pkt.data = (uint8_t *)&flush_pkt;
//    return 0;
//}
//
//void * ff_play_create_videostate()
//{
//    VideoState *is= av_mallocz(sizeof(VideoState));
//    //ddffplayer = player;
//    return is;
//}
//void ff_play_set_url(const char *url)
//{
//    input_filename = url;
//}
//int ff_play_get_video_info(void * arg,int type)
//{
//    double pos;
//    VideoState *is = arg;
//    if (is&&is->ic)
//    {
//        switch (type)
//        {
//            case 0:
//                return (is->ic->duration / AV_TIME_BASE)*DD_BASE_TIME;
//            case 1:
//                return is->width;
//            case 2:
//                return is->height;
//            case 3:
//                pos = get_master_clock(is);
//                return pos*DD_BASE_TIME;
//            default:
//                break;
//        }
//
//
//    }
//    return 0;
//}
//
//
//void ff_play_set_callback(OnDDFFplayEvent onPlayEvent,
//                          DDFFplayDecoderInit decoderInitEvent,
//                          DDFFplayDecoderUninit decoderUninitEvent,
//                          DDFFplayDecoderCheck decoderCheckEvent,
//                          DDFFplayDecoderUpdateDisplay decoderUpdateEvent,
//                          DDFFplayDecoderSendPacket decoderSendPacketEvent,
//                          DDFFplayerDecoderReceiveFrame decoderReceveFrame)
//{
//    play_event = onPlayEvent;
//    decoder_init_event = decoderInitEvent;
//    decoder_uninit_event = decoderUninitEvent;
//    decoder_check_event = decoderCheckEvent;
//    decoder_update_event = decoderUpdateEvent;
//    decoder_send_packet_event = decoderSendPacketEvent;
//    decoder_receive_frame_event = decoderReceveFrame;
//}
//
//int ff_play_loop(void *arg)
//{
//    VideoState *is = arg;
//    VideoState * tmp=stream_open(is,input_filename, file_iformat);
//    if (!tmp)
//    {
//        av_log(NULL, AV_LOG_FATAL, "Failed to initialize VideoState!\n");
//        do_exit(NULL);
//        return -1;
//    }
//    event_loop(is);
//    return 0;
//}
//
//int ff_test_mutil_window(void *arg)
//{
//
//    VideoState *is =ff_play_create_videostate();
//    ff_play_set_url("/Users/leo.liufumac/Desktop/test1.mp4");
//     ff_play_loop(is);
//
//    return 0;
//}
//
///* Called from the main */
//int main(int argc, char **argv) //test main ffplay
//{
//    ff_play_init_env(NULL);
//    ff_test_mutil_window(NULL);
////    SDL_CreateThread(ff_test_mutil_window,"window1" , NULL);
//
//    for(;;)
//    {
//        av_usleep(1000);
//    }
//    return 0;
//}
