/*
 **************************************************************************************
 *       Filename:  omx_log.h
 *    Description:   header file
 *
 *        Version:  1.0
 *        Created:  2012-11-27 00:03:43
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#ifndef OMX_LOG_H_INCLUDED
#define OMX_LOG_H_INCLUDED

#ifndef LOG_TAG
#define LOG_TAG ""
#endif

#define OMX_LOGV(fmt, ...) printf("[V/"LOG_TAG"]"fmt"\n", ##__VA_ARGS__);
#define OMX_LOGD(fmt, ...) printf("[D/"LOG_TAG"]"fmt"\n", ##__VA_ARGS__);
#define OMX_LOGI(fmt, ...) printf("[I/"LOG_TAG"]"fmt"\n", ##__VA_ARGS__);
#define OMX_LOGW(fmt, ...) printf("[W/"LOG_TAG"]"fmt"\n", ##__VA_ARGS__);
#define OMX_LOGE(fmt, ...) printf("[E/"LOG_TAG"]"fmt"\n", ##__VA_ARGS__);


#endif /*OMX_LOG_H_INCLUDED*/

/********************************* END ***********************************************/

