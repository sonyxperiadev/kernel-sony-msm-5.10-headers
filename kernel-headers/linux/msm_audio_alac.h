/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef _UAPI_MSM_AUDIO_ALAC_H
#define _UAPI_MSM_AUDIO_ALAC_H
#include <linux/types.h>
#define AUDIO_GET_ALAC_CONFIG _IOR(AUDIO_IOCTL_MAGIC, (AUDIO_MAX_COMMON_IOCTL_NUM + 0), struct msm_audio_alac_config)
#define AUDIO_SET_ALAC_CONFIG _IOW(AUDIO_IOCTL_MAGIC, (AUDIO_MAX_COMMON_IOCTL_NUM + 1), struct msm_audio_alac_config)
struct msm_audio_alac_config {
  __u32 frameLength;
  __u8 compatVersion;
  __u8 bitDepth;
  __u8 pb;
  __u8 mb;
  __u8 kb;
  __u8 channelCount;
  __u16 maxRun;
  __u32 maxSize;
  __u32 averageBitRate;
  __u32 sampleRate;
  __u32 channelLayout;
};
#endif
