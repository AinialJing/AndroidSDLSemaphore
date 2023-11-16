#include <jni.h>
#include <string>

extern "C" {
#include <SDL_thread.h>
#include "logger.h"

SDL_sem *g_sem = NULL;
int g_task_exit = 0;
int task1(void *data);
int task2(void *data);
int number=0;

JNIEXPORT void JNICALL
Java_com_anniljing_androidsdlthread_MainActivity_startSDLThread(JNIEnv *env, jobject thiz) {
    g_task_exit=0;
    g_sem = SDL_CreateSemaphore(0);
    SDL_CreateThread(task1, "task1", NULL);
    SDL_CreateThread(task2, "task2", NULL);
}
JNIEXPORT void JNICALL
Java_com_anniljing_androidsdlthread_MainActivity_postSDL(JNIEnv *env, jobject thiz) {
    if (g_sem) {
        SDL_SemPost(g_sem);
    }
}

JNIEXPORT void JNICALL
Java_com_anniljing_androidsdlthread_MainActivity_releaseSDL(JNIEnv *env, jobject thiz) {
    g_task_exit = 1;
    SDL_DestroySemaphore(g_sem);
    g_sem = NULL;
}
int task1(void *data) {
    while (!g_task_exit) {
        if (g_sem) {
            LOGD("task1 SemWait");
            SDL_SemWait(g_sem);
            number++;
            LOGD("task1 number:%d\n",number);
        }
    }
    return 0;
}
int task2(void *data) {
    while (!g_task_exit) {
        if (g_sem) {
            LOGD("task2 SemWait");
            SDL_SemWait(g_sem);
            number++;
            LOGD("task2 number:%d\n",number);
        }
    }
    return 0;
}
}

