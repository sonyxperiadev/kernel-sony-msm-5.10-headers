CLEAN_HEADER=bionic/libc/kernel/tools/clean_header.py

KERNEL_PATH=kernel/sony/msm-5.10
HEADER_SRC=$KERNEL_PATH/kernel/include
HEADER_ORI=$KERNEL_PATH/common-headers/original-kernel-headers
HEADER_SAN=$KERNEL_PATH/common-headers/kernel-headers

LINUX_HEADERS="\
    linux/hdmi.h"

UAPI_HEADERS="\
    asm-generic/ioctls.h\
    drm/drm.h\
    drm/drm_fourcc.h\
    drm/drm_mode.h\
    drm/msm_drm.h\
    linux/esoc_ctrl.h\
    linux/fb.h\
    linux/fuse.h\
    linux/ion.h\
    linux/ipa_qmi_service_v01.h\
    linux/mmc/ioctl.h\
    linux/msm_dsps.h\
    linux/msm_ion.h\
    linux/msm_ion_ids.h\
    linux/msm_ipa.h\
    linux/msm_kgsl.h\
    linux/msm_rmnet.h\
    linux/netlink.h\
    linux/qseecom.h\
    linux/rmnet_data.h\
    linux/rmnet_ipa_fd_ioctl.h\
    linux/socket.h\
    linux/spcom.h\
    linux/smcinvoke.h\
    linux/v4l2-common.h\
    linux/v4l2-controls.h\
    linux/v4l2-mediabus.h\
    linux/videodev2.h\
    misc/adsp_sleepmon.h\
    scsi/ufs/ioctl.h\
    scsi/ufs/ufs.h\
    sound/asound.h\
    sound/compress_offload.h\
    sound/compress_params.h"

TECHPACK_AUDIO_UAPI_HEADERS="\
    linux/avtimer.h\
    linux/msm_audio.h\
    linux/msm_audio_aac.h\
    linux/msm_audio_ac3.h\
    linux/msm_audio_alac.h\
    linux/msm_audio_amrnb.h\
    linux/msm_audio_amrwb.h\
    linux/msm_audio_amrwbplus.h\
    linux/msm_audio_ape.h\
    linux/msm_audio_calibration.h\
    linux/msm_audio_g711.h\
    linux/msm_audio_g711_dec.h\
    linux/msm_audio_mvs.h\
    linux/msm_audio_qcp.h\
    linux/msm_audio_sbc.h\
    linux/msm_audio_voicememo.h\
    linux/msm_audio_wma.h\
    linux/msm_audio_wmapro.h\
    linux/wcd-spi-ac-params.h\
    sound/audio_compressed_formats.h\
    sound/audio_effects.h\
    sound/audio_slimslave.h
    sound/devdep_params.h\
    sound/lsm_params.h\
    sound/msmcal-hwdep.h\
    sound/voice_params.h\
    sound/wcd-dsp-glink.h"

TECHPACK_CAMERA_UAPI_HEADERS="\
    camera/media/cam_cpas.h\
    camera/media/cam_cre.h\
    camera/media/cam_custom.h\
    camera/media/cam_defs.h\
    camera/media/cam_fd.h\
    camera/media/cam_icp.h\
    camera/media/cam_isp.h\
    camera/media/cam_isp_ife.h\
    camera/media/cam_isp_sfe.h\
    camera/media/cam_isp_tfe.h\
    camera/media/cam_isp_vfe.h\
    camera/media/cam_jpeg.h\
    camera/media/cam_lrme.h\
    camera/media/cam_ope.h\
    camera/media/cam_req_mgr.h\
    camera/media/cam_sensor.h\
    camera/media/cam_sync.h\
    camera/media/cam_tfe.h"

TECHPACK_DISPLAY_UAPI_HEADERS="\
    display/drm/msm_drm_pp.h\
    display/drm/sde_drm.h\
    display/hdcp/msm_hdmi_hdcp_mgr.h\
    display/media/mmm_color_fmt.h\
    display/media/msm_sde_rotator.h"

TECHPACK_VIDEO_UAPI_HEADERS="\
    msm_media_info.h"

HEADER_OVERRIDES="\
    display/media/mmm_color_fmt.h\
    linux/socket.h\
    media/msm_media_info.h"

cd ../../../..

> out/cp_headers_5.10.log

source build/envsetup.sh
lunch aosp_xqes54-ap2a-userdebug

process_headers() {
    local headers=$1
    local src=$2
    local dest=$3

    for x in $headers; do
        mkdir -p $(dirname "$HEADER_ORI/$dest$x")
        cp "$HEADER_SRC/$src$x" "$HEADER_ORI/$dest$x"
        $CLEAN_HEADER -u -v -k "$HEADER_ORI" -d "$HEADER_SAN" "$dest$x" &>> out/cp_headers_5.10.log
    done
}

process_headers "$LINUX_HEADERS" "" ""

process_headers "$UAPI_HEADERS" "uapi/" ""

process_headers "$TECHPACK_AUDIO_UAPI_HEADERS" "../techpack/audio/include/uapi/audio/" ""

process_headers "$TECHPACK_CAMERA_UAPI_HEADERS" "../techpack/camera/include/uapi/" ""

process_headers "$TECHPACK_DISPLAY_UAPI_HEADERS" "../techpack/display/include/uapi/" ""

process_headers "$TECHPACK_VIDEO_UAPI_HEADERS" "../techpack/video/driver/vidc/inc/" "media/"

for x in $HEADER_OVERRIDES; do \
cp $HEADER_ORI/$x $HEADER_SAN/$x
done

echo "Copy complete!"
