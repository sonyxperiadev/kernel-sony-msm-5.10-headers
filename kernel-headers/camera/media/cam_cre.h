/*
 * This file is auto-generated. Modifications will be lost.
 *
 * See https://android.googlesource.com/platform/bionic/+/master/libc/kernel/
 * for more information.
 */
#ifndef __UAPI_CAM_CRE_H__
#define __UAPI_CAM_CRE_H__
#include <media/cam_defs.h>
#include <media/cam_cpas.h>
#define CAM_CRE_DEV_NAME_SIZE 128
#define CAM_CRE_HW_TYPE_CRE 0x1
#define CAM_CRE_HW_TYPE_MAX 0x1
#define CAM_CRE_OPCODE_CONFIG 0x1
#define CAM_CRE_INPUT_IMAGE 0x1
#define CAM_CRE_INPUT_IMAGES_MAX (CAM_CRE_INPUT_IMAGE + 1)
#define CAM_CRE_OUTPUT_IMAGE 0x1
#define CAM_CRE_OUTPUT_IMAGES_MAX (CAM_CRE_OUTPUT_IMAGE + 1)
#define CAM_CRE_MAX_PLANES 0x2
#define CRE_MAX_BATCH_SIZE 0x10
#define CAM_CRE_DEV_TYPE_NRT 0x1
#define CAM_CRE_DEV_TYPE_RT 0x2
#define CAM_CRE_DEV_TYPE_MAX 0x3
#define CAM_CRE_CMD_META_GENERIC_BLOB 0x1
#define CAM_CRE_CMD_GENERIC_BLOB_CLK_V2 0x1
struct cam_cre_hw_ver {
  struct cam_hw_version hw_ver;
};
struct cam_cre_query_cap_cmd {
  struct cam_iommu_handle dev_iommu_handle;
  __u32 num_dev;
  __u32 reserved;
  struct cam_cre_hw_ver dev_ver[CAM_CRE_HW_TYPE_MAX];
};
struct cam_cre_io_buf_info {
  __u32 direction;
  __u32 res_id;
  __u32 num_planes;
  __u32 width;
  __u32 height;
  __u32 stride;
  __u32 fence;
  __u32 format;
  __u32 alignment;
  __u32 reserved;
};
struct cam_cre_acquire_dev_info {
  char dev_name[CAM_CRE_DEV_NAME_SIZE];
  __u32 dev_type;
  __u32 secure_mode;
  __u32 batch_size;
  __u32 num_in_res;
  __u32 num_out_res;
  __u32 reserved;
  struct cam_cre_io_buf_info in_res[CAM_CRE_INPUT_IMAGES_MAX];
  struct cam_cre_io_buf_info out_res[CAM_CRE_OUTPUT_IMAGES_MAX];
} __attribute__((__packed__));
struct cre_clk_bw_request_v2 {
  __u64 budget_ns;
  __u32 frame_cycles;
  __u32 rt_flag;
  __u32 reserved;
  __u32 num_paths;
  struct cam_axi_per_path_bw_vote axi_path[1];
};
#endif
