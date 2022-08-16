/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef _UAPI_SMCINVOKE_H_
#define _UAPI_SMCINVOKE_H_
#include <linux/types.h>
#include <linux/ioctl.h>
#define SMCINVOKE_USERSPACE_OBJ_NULL - 1
struct smcinvoke_buf {
  __u64 addr;
  __u64 size;
};
struct smcinvoke_obj {
  __s64 fd;
  __s32 cb_server_fd;
  __s32 reserved;
};
union smcinvoke_arg {
  struct smcinvoke_buf b;
  struct smcinvoke_obj o;
};
struct smcinvoke_cmd_req {
  __u32 op;
  __u32 counts;
  __s32 result;
  __u32 argsize;
  __u64 args;
};
struct smcinvoke_accept {
  __u32 has_resp;
  __u32 txn_id;
  __s32 result;
  __s32 cbobj_id;
  __u32 op;
  __u32 counts;
  __s32 reserved;
  __u32 argsize;
  __u64 buf_len;
  __u64 buf_addr;
};
struct smcinvoke_server {
  __u32 cb_buf_size;
};
#define SMCINVOKE_IOC_MAGIC 0x98
#define SMCINVOKE_IOCTL_INVOKE_REQ _IOWR(SMCINVOKE_IOC_MAGIC, 1, struct smcinvoke_cmd_req)
#define SMCINVOKE_IOCTL_ACCEPT_REQ _IOWR(SMCINVOKE_IOC_MAGIC, 2, struct smcinvoke_accept)
#define SMCINVOKE_IOCTL_SERVER_REQ _IOWR(SMCINVOKE_IOC_MAGIC, 3, struct smcinvoke_server)
#define SMCINVOKE_IOCTL_ACK_LOCAL_OBJ _IOWR(SMCINVOKE_IOC_MAGIC, 4, __s32)
#define SMCINVOKE_LOG_BUF_SIZE 100
#define SMCINVOKE_IOCTL_LOG _IOC(_IOC_READ | _IOC_WRITE, SMCINVOKE_IOC_MAGIC, 255, SMCINVOKE_LOG_BUF_SIZE)
#endif
