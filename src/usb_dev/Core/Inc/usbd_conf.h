/*
 * Copyright (c) 2015-2020 ACOINFO Co., Ltd.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: usbd_conf.h ST usb device stack configuration and porting.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#ifndef USBD_CONF_H
#define USBD_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ms_kern.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../ms_usbd_cfg.h"

#undef NULL

#define UNUSED(var)         (void)(var)

#define __IO                volatile

#define osCMSIS             0x20000
#define osOK                MS_ERR_NONE
#define osWaitForever       MS_TIMEOUT_FOREVER

typedef ms_handle_t         osThreadId_t;
typedef ms_handle_t         osMessageQueueId_t;
typedef ms_err_t            osStatus_t;

static inline osStatus_t osMessageQueueGet(osMessageQueueId_t mq_id, void *msg_ptr, uint8_t *msg_prio, uint32_t timeout)
{
    if (msg_prio != MS_NULL) {
        *msg_prio = 0U;
    }

    return ms_mqueue_wait(mq_id, msg_ptr, timeout);
}

static inline osStatus_t osMessageQueuePut(osMessageQueueId_t mq_id, const void *msg_ptr, uint8_t msg_prio, uint32_t timeout)
{
    return ms_mqueue_post(mq_id, msg_ptr, timeout);
}

static inline osStatus_t osDelay(uint32_t ticks)
{
   return ms_thread_sleep_ms(ticks);
}

extern void NVIC_SystemReset(void);
extern void USBD_Delay(uint32_t Delay);

/*
 * Memory management macros
 */
#define USBD_malloc         ms_kmalloc
#define USBD_free           ms_kfree
#define USBD_memset         memset
#define USBD_memcpy         memcpy

/*
 * DEBUG macros
 */
#if (USBD_DEBUG_LEVEL > 0U)
#define  USBD_UsrLog(...)   do { \
                                ms_printk(MS_PK_INFO, __VA_ARGS__); \
                                ms_printk(MS_PK_INFO, "\n"); \
                            } while (0)
#else
#define USBD_UsrLog(...)    do {} while (0)
#endif

#if (USBD_DEBUG_LEVEL > 1U)

#define  USBD_ErrLog(...)   do { \
                                ms_printk(MS_PK_ERR, "ERROR: ") ; \
                                ms_printk(MS_PK_ERR, __VA_ARGS__); \
                                ms_printk(MS_PK_ERR, "\n"); \
                            } while (0)
#else
#define USBD_ErrLog(...)    do {} while (0)
#endif

#if (USBD_DEBUG_LEVEL > 2U)
#define  USBD_DbgLog(...)   do { \
                                ms_printk(MS_PK_DEBUG, "DEBUG : ") ; \
                                ms_printk(MS_PK_DEBUG, __VA_ARGS__); \
                                ms_printk(MS_PK_DEBUG, "\n"); \
                            } while (0)
#else
#define USBD_DbgLog(...)    do {} while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif /* USBD_CONF_H */
