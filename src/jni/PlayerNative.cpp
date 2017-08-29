#include"PlayerNative.hpp"
#include <iostream>
#include "../RagePlugin.hpp"
#include "../RageJavaCore.hpp"

jint Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_getType(JNIEnv *env, jclass jClass, jint id) {
//    return (int) pool.GetAt((rage::entityId_t)id)->GetType();
    return 0;
}

jint Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_getDimension(JNIEnv *env, jclass jClass, jint id) {
//    return (int) pool.GetAt((rage::entityId_t)id)->GetDimension();
    return 0;
}

void Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_setDimension(JNIEnv *env, jclass jClass, jint id, jint dimension) {
//    pool.GetAt((rage::entityId_t)id)->SetDimension((rage::dimensionId_t)dimension);
}

jobject Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_getRotation(JNIEnv *env, jclass jClass, jint id) {

    return nullptr;
}

void Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_setRotation(JNIEnv *env, jclass jClass, jint id, jobject vector3) {

}

jint Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_getModel(JNIEnv *env, jclass jClass, jint id) {
//    return (int) pool.GetAt((rage::entityId_t)id)->GetModel();
    return 0;
}

void Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_setModel(JNIEnv *env, jclass jClass, jint id, jint modelId) {
//    pool.GetAt((rage::entityId_t)id)->SetModel((uint16_t)modelId);
}

jobject Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_getVelocity(JNIEnv *env, jclass jClass, jint id) {
    return nullptr;
}

jint Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_getAlpha(JNIEnv *env, jclass jClass, jint id) {
//    return (int) pool.GetAt((rage::entityId_t)id)->GetAlpha();
    return 0;
}

void Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_setAlpha(JNIEnv *env, jclass jClass, jint id, jint alpha) {
//    pool.GetAt((rage::entityId_t)id)->SetAlpha((uint8_t)alpha);
}

void Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_kick(JNIEnv *env, jclass jClass, jint id, jstring reason) {

}

void Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_ban(JNIEnv *env, jclass jClass, jint id, jstring reason) {

}

void Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_outputChatBox(JNIEnv *env, jclass jClass, jint id, jstring message) {
    std::cout << "outputChatBox JNI Call";
    rage::IMultiplayer *mp = RageJavaCore::getInstance().getMultiPlayer();
    if(mp == nullptr) {
        std::cout << "mp is null";
        return;
    }
    rage::IPlayer *player = mp->GetPlayerPool().GetAt(0);
    if(player == nullptr) {
        std::cout << "player is null";
        return;
    }
    std::cout << "player is present";
    player->OutputChatBox(u"outputChatBox called");
    player->OutputChatBox(TypeConverter::fromJStringU16(message));
}

void Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_notify(JNIEnv *env, jclass jClass, jint id, jstring message) {

}
