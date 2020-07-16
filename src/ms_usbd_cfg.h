/*
 * Copyright (c) 2015-2020 ACOINFO Co., Ltd.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_usbd_conf.h ST usb device stack configuration.
 *
 * Author: Jiao.jinxing <jiaojinxing@acoinfo.com>
 *
 */

#ifndef MS_USBD_CFG_H
#define MS_USBD_CFG_H

#define USBD_MAX_NUM_INTERFACES             1U
#define USBD_MAX_NUM_CONFIGURATION          1U
#define USBD_MAX_STR_DESC_SIZ               0x100U
#define USBD_SUPPORT_USER_STRING            0U
#define USBD_SELF_POWERED                   1U
#define USBD_DEBUG_LEVEL                    2U

/* MSC Class Config */
#define MSC_MEDIA_PACKET                    8192U

/* CDC Class Config */
#define USBD_CDC_INTERVAL                   2000U

/* DFU Class Config */
#define USBD_DFU_MAX_ITF_NUM                1U
#define USBD_DFU_XFERS_IZE                  1024U

/* AUDIO Class Config */
#define USBD_AUDIO_FREQ                     22100U

#endif /* MS_USBD_CFG_H */
