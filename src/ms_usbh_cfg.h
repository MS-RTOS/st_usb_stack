/*
 * Copyright (c) 2019 MS-RTOS Team.
 * All rights reserved.
 *
 * Detailed license information can be found in the LICENSE file.
 *
 * File: ms_usbh_conf.h ST usb host stack configuration.
 *
 * Author: Jiao.jinxing <jiaojixing@acoinfo.com>
 *
 */

#ifndef MS_USBH_CFG_H
#define MS_USBH_CFG_H

#define USBH_MAX_NUM_ENDPOINTS              2
#define USBH_MAX_NUM_INTERFACES             2
#define USBH_MAX_NUM_CONFIGURATION          1
#define USBH_MAX_NUM_SUPPORTED_CLASS        1
#define USBH_KEEP_CFG_DESCRIPTOR            0
#define USBH_MAX_SIZE_CONFIGURATION         0x200
#define USBH_MAX_DATA_BUFFER                0x200
#define USBH_DEBUG_LEVEL                    2
#define USBH_USE_OS                         1
#define USBH_PROCESS_PRIO                   10
#define USBH_PROCESS_STACK_SIZE             2048

#define USBH_PROCESS_TIME_SLICE             0

#endif /* MS_USBH_CFG_H */
