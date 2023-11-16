//
// Created by company on 2023-11-15.
//

#ifndef ANDROIDSDLTHREAD_LOGGER_H
#define ANDROIDSDLTHREAD_LOGGER_H

#endif //ANDROIDSDLTHREAD_LOGGER_H
#include <android/log.h>

#define LOGD(format, ...)  __android_log_print(ANDROID_LOG_DEBUG, "JNI_MANAGER", format, ##__VA_ARGS__)
#define LOGE(format, ...)  __android_log_print(ANDROID_LOG_ERROR, "JNI_MANAGER", format, ##__VA_ARGS__)
#define LOGI(format, ...)  __android_log_print(ANDROID_LOG_INFO,  "JNI_MANAGER", format, ##__VA_ARGS__)