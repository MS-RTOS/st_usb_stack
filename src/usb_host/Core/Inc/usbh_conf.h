/*
 * Copyright (c) 2019 MS-RTOS Team.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: usbh_conf.h ST usb host stack configuration and porting.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#ifndef USBH_CONF_H
#define USBH_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ms_kern.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../ms_usbh_cfg.h"

#undef NULL

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

/*
 * Memory management macros
 */
#define USBH_malloc         ms_kmalloc
#define USBH_free           ms_kfree
#define USBH_memset         memset
#define USBH_memcpy         memcpy

/*
 * DEBUG macros
 */
#if (USBH_DEBUG_LEVEL > 0)
#define USBH_UsrLog(...)   ms_printk(MS_PK_INFO, __VA_ARGS__);\
                           ms_printk(MS_PK_INFO, "\n");
#else
#define USBH_UsrLog(...)
#endif


#if (USBH_DEBUG_LEVEL > 1)

#define USBH_ErrLog(...)   ms_printk(MS_PK_ERR, "ERROR: ") ;\
                           ms_printk(MS_PK_ERR, __VA_ARGS__);\
                           ms_printk(MS_PK_ERR, "\n");
#else
#define USBH_ErrLog(...)
#endif

#if (USBH_DEBUG_LEVEL > 2)
#define USBH_DbgLog(...)   ms_printk(MS_PK_DEBUG,"DEBUG : ") ;\
                           ms_printk(MS_PK_DEBUG,__VA_ARGS__);\
                           ms_printk(MS_PK_DEBUG,"\n");
#else
#define USBH_DbgLog(...)
#endif

#ifdef __cplusplus
}
#endif

#endif /* USBH_CONF_H */
