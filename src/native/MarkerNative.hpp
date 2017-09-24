/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class mp_rage_launcher_marker_MarkerNative */

#ifndef _Included_mp_rage_launcher_marker_MarkerNative
#define _Included_mp_rage_launcher_marker_MarkerNative
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    getType
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_mp_rage_launcher_marker_MarkerNative_getType
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    destroy
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_destroy
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    getDimension
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_mp_rage_launcher_marker_MarkerNative_getDimension
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    setDimension
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_setDimension
        (JNIEnv *, jclass, jint, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    getPosition
 * Signature: (I)Lmp/rage/api/vector/Vector3;
 */
JNIEXPORT jobject JNICALL Java_mp_rage_launcher_marker_MarkerNative_getPosition
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    setPosition
 * Signature: (IFFF)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_setPosition
        (JNIEnv *, jclass, jint, jfloat, jfloat, jfloat);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    getRotation
 * Signature: (I)Lmp/rage/api/vector/Vector3;
 */
JNIEXPORT jobject JNICALL Java_mp_rage_launcher_marker_MarkerNative_getRotation
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    setRotation
 * Signature: (IFFF)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_setRotation
        (JNIEnv *, jclass, jint, jfloat, jfloat, jfloat);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    getModel
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_mp_rage_launcher_marker_MarkerNative_getModel
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    setModel
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_setModel
        (JNIEnv *, jclass, jint, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    getVelocity
 * Signature: (I)Lmp/rage/api/vector/Vector3;
 */
JNIEXPORT jobject JNICALL Java_mp_rage_launcher_marker_MarkerNative_getVelocity
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    getAlpha
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_mp_rage_launcher_marker_MarkerNative_getAlpha
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    setAlpha
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_setAlpha
        (JNIEnv *, jclass, jint, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    GetColour
 * Signature: (I)Lmp/rage/api/color/RGBColor;
 */
JNIEXPORT jobject JNICALL Java_mp_rage_launcher_marker_MarkerNative_GetColour
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    SetColour
 * Signature: (IIIII)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_SetColour
        (JNIEnv *, jclass, jint, jint, jint, jint, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    GetDirection
 * Signature: (I)Lmp/rage/api/vector/Vector3;
 */
JNIEXPORT jobject JNICALL Java_mp_rage_launcher_marker_MarkerNative_GetDirection
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    SetDirection
 * Signature: (ILmp/rage/api/vector/Vector3;)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_SetDirection
        (JNIEnv *, jclass, jint, jobject);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    GetScale
 * Signature: (I)F
 */
JNIEXPORT jfloat JNICALL Java_mp_rage_launcher_marker_MarkerNative_GetScale
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    SetScale
 * Signature: (IF)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_SetScale
        (JNIEnv *, jclass, jint, jfloat);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    IsVisible
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_mp_rage_launcher_marker_MarkerNative_IsVisible
        (JNIEnv *, jclass, jint);

/*
 * Class:     mp_rage_launcher_marker_MarkerNative
 * Method:    SetVisible
 * Signature: (IZ)V
 */
JNIEXPORT void JNICALL Java_mp_rage_launcher_marker_MarkerNative_SetVisible
        (JNIEnv *, jclass, jint, jboolean);

#ifdef __cplusplus
}
#endif
#endif
