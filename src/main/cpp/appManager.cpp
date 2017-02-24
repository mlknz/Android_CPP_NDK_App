#include <jni.h>

#include <GLES2/gl2.h>
#include <sys/time.h>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <math.h>
// #include <png.h>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "customDefines.h"
#include "shaderProgram.h"

static AAssetManager* assetManager;

long long currentTimeInMilliseconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
double col = 0.0;
double x = 1;


extern "C" {
    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceCreated(JNIEnv *env, jclass cls) {
        glClearColor(0.8, 0.5f, 0.9f, 0.0f);

    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onSurfaceChanged(JNIEnv *env, jclass cls,
                                                                                jint w, jint h) {
        x = w;
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onDrawFrame(JNIEnv *env, jclass cls) {
        double t = currentTimeInMilliseconds();

        glClearColor(col, col, col, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_passAssetManager(JNIEnv *env, jclass cls,
                                                                                jobject aMng) {

        glm::vec2* a = new glm::vec2(0.55, 1);
        LOGI("TAAAAAAAAAAAA, %f", a->x);

        env->NewGlobalRef(aMng);
        assetManager = AAssetManager_fromJava(env, aMng);

        AAsset* file = AAssetManager_open(assetManager, "shaders/test.vert", AASSET_MODE_BUFFER);
        size_t fileLength = AAsset_getLength(file);

        char* fileContent = new char[fileLength + 1];

        AAsset_read(file, fileContent, fileLength);
        fileContent[fileLength] = '\0';

        // use file content

        GLuint sh = compileShader(GL_VERTEX_SHADER, fileContent);
        LOGI("aaaaaaaaaaaaaaaaa %d", sh);

        delete [] fileContent;

    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchStart(JNIEnv *env, jclass cls, float posX) {
        col = posX / x;
        LOGI("The value of 1 + 1 is %d", 1+1);
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchMove(JNIEnv *env, jclass cls) {
    }

    JNIEXPORT void JNICALL Java_mlkn_testapp_GameLibJNIWrapper_onTouchEnd(JNIEnv *env, jclass cls) {
    }
}

