LOCAL_SRC_FILES := \
	omx_utils/omx_condition.cpp 						\
	omx_utils/omx_list.cpp								\
	omx_utils/omx_loader.cpp							\
	omx_utils/omx_mutex.cpp								\
	omx_utils/omx_sem.cpp								\
	omx_utils/omx_thread.cpp							\
	omx_core/omx_core.cpp								\
	omx_component/omx_base/omx_component.cpp			\
	omx_component/omx_base/omx_interface.cpp			\
	omx_component/omx_base/omx_stateinterface.cpp		\
	omx_component/omx_base/omx_stateimpl.cpp			\

LOCAL_AVC_SRC_FILES := \
	omx_component/omx_video/dec/omx_avcdec_component/omx_avc_lib.cpp			\
	omx_component/omx_video/dec/omx_avcdec_component/omx_component_avcdec.cpp

LOCAL_MODULE := libomx_cavium.so
LOCAL_MODULE_AVC := libcnc_omxdecoder_avc.so
LOCAL_TEST_MODULE := a.out

all:$(LOCAL_MODULE) $(LOCAL_MODULE_AVC) $(LOCAL_TEST_MODULE)

$(LOCAL_MODULE):$(LOCAL_SRC_FILES)
	g++ -shared -fPIC $(LOCAL_SRC_FILES) -o $(LOCAL_MODULE) -lpthread -ldl -I omx_utils/ -I omx_core/ -I openmax_header/ -I omx_component/omx_base

$(LOCAL_MODULE_AVC):$(LOCAL_AVC_SRC_FILES)
	g++ -shared -fPIC $(LOCAL_AVC_SRC_FILES) -o $(LOCAL_MODULE_AVC) -lpthread -ldl -I omx_utils/ -I omx_core/ -I openmax_header/ -I omx_component/omx_base
#############################################################
LOCAL_TEST_SRC_FILES := omx_test/omx_test.cpp

$(LOCAL_TEST_MODULE):$(LOCAL_TEST_SRC_FILES)
	g++ $(LOCAL_TEST_SRC_FILES) -I omx_utils/ -I omx_core/ -I openmax_header libomx_cavium.so -o $(LOCAL_TEST_MODULE)

#############################################################
clean:
	 @rm -f $(LOCAL_MODULE) $(LOCAL_TEST_MODULE) $(LOCAL_MODULE_AVC)
