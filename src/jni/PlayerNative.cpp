#include "PlayerNative.hpp"
#include <iostream>
#include "../RagePlugin.hpp"
#include "../rage/Player.hpp"

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_kick(JNIEnv *, jclass, jint playerId, jstring reason) {
    rage::IPlayer* player = Player::getPlayerById(TypeConverter::fromJInt(playerId));
    if(player) {
        player->Kick(TypeConverter::fromJString(reason).c_str());
    }
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_ban(JNIEnv *, jclass, jint playerId, jstring reason) {
    rage::IPlayer* player = Player::getPlayerById(TypeConverter::fromJInt(playerId));
    if(player) {
        player->Ban(TypeConverter::fromJString(reason).c_str());
    }
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_outputChatBox(JNIEnv *, jclass, jint playerId, jstring message) {
    rage::IPlayer* player = Player::getPlayerById(TypeConverter::fromJInt(playerId));
    if(player) {
        player->OutputChatBox(TypeConverter::fromJStringU16(message));
    }
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_notify(JNIEnv *, jclass, jint, jstring) {

}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_spawn(JNIEnv *, jclass, jint, jobject, jfloat) {

}

void
Java_mp_rage_plugin_java_launcher_player_PlayerNative_playAnimation(JNIEnv *, jclass, jint, jstring, jstring, jfloat,
                                                                    jint) {

}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_playScenario(JNIEnv *, jclass, jint, jstring) {

}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_stopAnimation(JNIEnv *, jclass, jint) {

}

jobject Java_mp_rage_plugin_java_launcher_player_PlayerNative_getClothes(JNIEnv *, jclass, jint, jint) {
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setClothes(JNIEnv *, jclass, jint, jint, jobject) {

}

jobject Java_mp_rage_plugin_java_launcher_player_PlayerNative_getProp(JNIEnv *, jclass, jint, jint) {
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setProp(JNIEnv *, jclass, jint, jint, jobject) {

}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_eval(JNIEnv *, jclass, jint, jstring) {

}

jstring Java_mp_rage_plugin_java_launcher_player_PlayerNative_getName(JNIEnv *, jclass, jint) {
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setName(JNIEnv *, jclass, jint, jstring) {

}

jboolean Java_mp_rage_plugin_java_launcher_player_PlayerNative_isAiming(JNIEnv *, jclass, jint) {
    return 0;
}

jfloat Java_mp_rage_plugin_java_launcher_player_PlayerNative_getHeading(JNIEnv *, jclass, jint) {
    return 0;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setHeading(JNIEnv *, jclass, jint, jfloat) {

}

jfloat Java_mp_rage_plugin_java_launcher_player_PlayerNative_getMoveSpeed(JNIEnv *, jclass, jint) {
    return 0;
}

jfloat Java_mp_rage_plugin_java_launcher_player_PlayerNative_getHealth(JNIEnv *, jclass, jint) {
    return 0;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setHealth(JNIEnv *, jclass, jint, jfloat) {

}

jfloat Java_mp_rage_plugin_java_launcher_player_PlayerNative_getArmor(JNIEnv *, jclass, jint) {
    return 0;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setArmor(JNIEnv *, jclass, jint, jfloat) {

}

jobject Java_mp_rage_plugin_java_launcher_player_PlayerNative_getAimingAt(JNIEnv *, jclass, jint) {
    return nullptr;
}

jint Java_mp_rage_plugin_java_launcher_player_PlayerNative_getPing(JNIEnv *, jclass, jint) {
    return 0;
}

jstring Java_mp_rage_plugin_java_launcher_player_PlayerNative_getKickReason(JNIEnv *, jclass, jint) {
    return nullptr;
}

jstring Java_mp_rage_plugin_java_launcher_player_PlayerNative_getIp(JNIEnv *, jclass, jint) {
    return nullptr;
}

jboolean Java_mp_rage_plugin_java_launcher_player_PlayerNative_isJumping(JNIEnv *, jclass, jint) {
    return 0;
}

jboolean Java_mp_rage_plugin_java_launcher_player_PlayerNative_isInCover(JNIEnv *, jclass, jint) {
    return 0;
}

jboolean Java_mp_rage_plugin_java_launcher_player_PlayerNative_isEnteringVehicle(JNIEnv *, jclass, jint) {
    return 0;
}

jboolean Java_mp_rage_plugin_java_launcher_player_PlayerNative_isLeavingVehicle(JNIEnv *, jclass, jint) {
    return 0;
}

jboolean Java_mp_rage_plugin_java_launcher_player_PlayerNative_isClimbing(JNIEnv *, jclass, jint) {
    return 0;
}

jstring Java_mp_rage_plugin_java_launcher_player_PlayerNative_getActionString(JNIEnv *, jclass, jint) {
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_removeFromVehicle(JNIEnv *, jclass, jint) {

}

jint Java_mp_rage_plugin_java_launcher_player_PlayerNative_getSeat(JNIEnv *, jclass, jint) {
    return 0;
}

jint Java_mp_rage_plugin_java_launcher_player_PlayerNative_getEyeColor(JNIEnv *, jclass, jint) {
    return 0;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setEyeColor(JNIEnv *, jclass, jint, jint) {

}

jint Java_mp_rage_plugin_java_launcher_player_PlayerNative_getHairColor(JNIEnv *, jclass, jint) {
    return 0;
}

jint Java_mp_rage_plugin_java_launcher_player_PlayerNative_getHairHighlightColor(JNIEnv *, jclass, jint) {
    return 0;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setHairColor(JNIEnv *, jclass, jint, jint, jint) {

}

jfloat Java_mp_rage_plugin_java_launcher_player_PlayerNative_getFaceFeature(JNIEnv *, jclass, jint, jint) {
    return 0;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_setFaceFeature(JNIEnv *, jclass, jint, jint, jfloat) {

}

jobject Java_mp_rage_plugin_java_launcher_player_PlayerNative_getHeadBlend(JNIEnv *, jclass, jint) {
    return nullptr;
}

void
Java_mp_rage_plugin_java_launcher_player_PlayerNative_setHeadBlend(JNIEnv *, jclass, jint, jint, jint, jint, jint, jint,
                                                                   jint, jfloat, jfloat, jfloat) {

}

void
Java_mp_rage_plugin_java_launcher_player_PlayerNative_updateHeadBlend(JNIEnv *, jclass, jint, jfloat, jfloat, jfloat) {

}

jint Java_mp_rage_plugin_java_launcher_player_PlayerNative_getWeapon(JNIEnv *, jclass, jint) {
    return 0;
}

void Java_mp_rage_plugin_java_launcher_player_PlayerNative_giveWeapon(JNIEnv *, jclass, jint, jint, jint) {

}

jstring Java_mp_rage_plugin_java_launcher_player_PlayerNative_getSerial(JNIEnv *, jclass, jint) {
    return nullptr;
}
