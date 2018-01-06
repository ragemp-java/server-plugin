/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "CheckpointNative.hpp"
#include "../RageJavaCore.hpp"
#include "../game/Checkpoint.hpp"
#include "../game/Player.hpp"

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_create(JNIEnv *env, jclass, jint type, jfloat x, jfloat y, jfloat z,
                                                              jfloat nX, jfloat nY, jfloat nZ, jfloat radius, jint red,
                                                              jint green, jint blue,
                                                              jint alpha, jboolean visible, jint dimension) {
    rage::IMultiplayer *mp = RageJavaCore::getInstance().getMultiPlayer();
    if (mp == nullptr) {
        return -1;
    }
    rage::vector3 position = {x, y, z};
    rage::vector3 nextPosition = {nX, nY, nZ};
    rage::rgba_t color = {(uint8_t) red, (uint8_t) green, (uint8_t) blue, (uint8_t) alpha};
    return (jint) mp->GetCheckpointPool().New((uint8_t) type, position, nextPosition, radius, color, (bool) visible,
                                              (rage::dimensionId_t) dimension)->GetId();
}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_getType(JNIEnv *env, jclass, jint checkpointId) {
    return (jint) rage::entity_t::Checkpoint;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_destroy(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        checkpoint->Destroy();
    }
}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_getDimension(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        return jint(checkpoint->GetDimension());
    }
    return 0;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setDimension(JNIEnv *env, jclass, jint, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        checkpoint->SetDimension((uint32_t) checkpointId);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getPosition(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        rage::vector3 position = checkpoint->GetPosition();
        return JVM::Object::vector3(env, position.x, position.y, position.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setPosition(JNIEnv *env, jclass, jint checkpointId, jfloat x, jfloat y, jfloat z) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        rage::vector3 position = {x, y, z};
        checkpoint->SetPosition(position);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getRotation(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        rage::vector3 rotation = checkpoint->GetRotation();
        return JVM::Object::vector3(env, rotation.x, rotation.y, rotation.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setRotation(JNIEnv *env, jclass, jint checkpointId, jfloat x, jfloat y, jfloat z) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        rage::vector3 rotation = {x, y, z};
        checkpoint->SetRotation(rotation);
    }
}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_getModel(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        return (jint) checkpoint->GetModel();
    }
    return -1;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setModel(JNIEnv *env, jclass, jint checkpointId, jint model) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        checkpoint->SetModel((uint32_t) model);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getVelocity(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        rage::vector3 velocity = checkpoint->GetVelocity();
        return JVM::Object::vector3(env, velocity.x, velocity.y, velocity.x);
    }
    return nullptr;
}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_getAlpha(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        return (jint) checkpoint->GetAlpha();
    }
    return -1;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setAlpha(JNIEnv *env, jclass, jint checkpointId, jint alpha) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        checkpoint->SetAlpha((uint8_t) alpha);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getColour(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        rage::rgba_t color = checkpoint->GetColour();
        return JVM::Object::rgbaColor(env, color.rgba[0], color.rgba[1], color.rgba[2], color.rgba[3]);
    }
    return nullptr;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setColour(JNIEnv *env, jclass, jint checkpointId, jint r, jint g, jint b, jint a) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        checkpoint->SetColour((uint8_t) r, (uint8_t) g, (uint8_t) b, (uint8_t) a);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getDirection(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        rage::vector3 direction = checkpoint->GetDirection();
        return JVM::Object::vector3(env, direction.x, direction.y, direction.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setDirection(JNIEnv *env, jclass, jint checkpointId, jfloat x, jfloat y, jfloat z) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        rage::vector3 direction = {x, y, z};
        checkpoint->SetDirection(direction);
    }
}

jfloat Java_mp_rage_launcher_checkpoint_CheckpointNative_getRadius(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        return checkpoint->GetRadius();
    }
    return 0;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setRadius(JNIEnv *env, jclass, jint checkpointId, jfloat radius) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        checkpoint->SetRadius(radius);
    }
}

jboolean Java_mp_rage_launcher_checkpoint_CheckpointNative_isVisible(JNIEnv *env, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        return (jboolean) checkpoint->IsVisible();
    }
    return 0;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setVisible(JNIEnv *env, jclass, jint checkpointId, jboolean visible) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        checkpoint->SetVisible((bool)visible);
    }
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_ShowFor(JNIEnv *env, jclass, jint checkpointId, jintArray playerArray) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        std::vector<int> playerIds = JVM::Converter::toIntVector(env, playerArray);
        std::vector<rage::IPlayer*> players;
        for(int id : playerIds) {
            players.push_back(Game::Player::getPlayerById(env, id));
        }
        checkpoint->ShowFor(players);
    }
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_HideFor(JNIEnv *env, jclass, jint checkpointId, jintArray playerArray) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(env, checkpointId);
    if (checkpoint) {
        std::vector<int> playerIds = JVM::Converter::toIntVector(env, playerArray);
        std::vector<rage::IPlayer*> players;
        for(int id : playerIds) {
            players.push_back(Game::Player::getPlayerById(env, id));
        }
        checkpoint->HideFor(players);
    }
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_showFor(JNIEnv *env, jclass, jint, jintArray) {

}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_hideFor(JNIEnv *env, jclass, jint, jintArray) {

}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_length(JNIEnv *env, jclass) {
    return 0;
}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_count(JNIEnv *env, jclass) {
    return 0;
}

jobject
Java_mp_rage_launcher_checkpoint_CheckpointNative_getInRange(JNIEnv *env, jclass, jfloat, jfloat, jfloat, jfloat, jint) {
    return nullptr;
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getInDimension(JNIEnv *env, jclass, jint) {
    return nullptr;
}
