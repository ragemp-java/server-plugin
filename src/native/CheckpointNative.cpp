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

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_create(JNIEnv *, jclass, jint type, jfloat x, jfloat y, jfloat z,
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

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_getType(JNIEnv *, jclass, jint checkpointId) {
    return JVM::Converter::toJInt((int) rage::entity_t::Checkpoint);
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_destroy(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        checkpoint->Destroy();
    }
}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_getDimension(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        JVM::Converter::toJInt(
                checkpoint->GetDimension()
        );
    }
    return 0;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setDimension(JNIEnv *, jclass, jint, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        checkpoint->SetDimension((uint32_t) checkpointId);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getPosition(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        rage::vector3 position = checkpoint->GetPosition();
        return JVM::Object::vector3(position.x, position.y, position.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setPosition(JNIEnv *, jclass, jint checkpointId, jfloat x, jfloat y, jfloat z) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        rage::vector3 position = {x, y, z};
        checkpoint->SetPosition(position);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getRotation(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        rage::vector3 rotation = checkpoint->GetRotation();
        return JVM::Object::vector3(rotation.x, rotation.y, rotation.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setRotation(JNIEnv *, jclass, jint checkpointId, jfloat x, jfloat y, jfloat z) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        rage::vector3 rotation = {x, y, z};
        checkpoint->SetRotation(rotation);
    }
}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_getModel(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        return (jint) checkpoint->GetModel();
    }
    return -1;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setModel(JNIEnv *, jclass, jint checkpointId, jint model) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        checkpoint->SetModel((uint32_t) model);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getVelocity(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        rage::vector3 velocity = checkpoint->GetVelocity();
        return JVM::Object::vector3(velocity.x, velocity.y, velocity.x);
    }
    return nullptr;
}

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_getAlpha(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        return (jint) checkpoint->GetAlpha();
    }
    return -1;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setAlpha(JNIEnv *, jclass, jint checkpointId, jint alpha) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        checkpoint->SetAlpha((uint8_t) alpha);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getColour(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        rage::rgba_t color = checkpoint->GetColour();
        return JVM::Object::rgbaColor(color.rgba[0], color.rgba[1], color.rgba[2], color.rgba[3]);
    }
    return nullptr;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setColour(JNIEnv *, jclass, jint checkpointId, jint r, jint g, jint b, jint a) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        checkpoint->SetColour((uint8_t) r, (uint8_t) g, (uint8_t) b, (uint8_t) a);
    }
}

jobject Java_mp_rage_launcher_checkpoint_CheckpointNative_getDirection(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        rage::vector3 direction = checkpoint->GetDirection();
        return JVM::Object::vector3(direction.x, direction.y, direction.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setDirection(JNIEnv *, jclass, jint checkpointId, jfloat x, jfloat y, jfloat z) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        rage::vector3 direction = {x, y, z};
        checkpoint->SetDirection(direction);
    }
}

jfloat Java_mp_rage_launcher_checkpoint_CheckpointNative_getRadius(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        return JVM::Converter::toJFloat(checkpoint->GetRadius());
    }
    return 0;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setRadius(JNIEnv *, jclass, jint checkpointId, jfloat radius) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        checkpoint->SetRadius(JVM::Converter::toFloat(radius));
    }
}

jboolean Java_mp_rage_launcher_checkpoint_CheckpointNative_isVisible(JNIEnv *, jclass, jint checkpointId) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        return (jboolean) checkpoint->IsVisible();
    }
    return 0;
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_setVisible(JNIEnv *, jclass, jint checkpointId, jboolean visible) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        checkpoint->SetVisible((bool)visible);
    }
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_ShowFor(JNIEnv *, jclass, jint checkpointId, jintArray playerArray) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        std::vector<int> playerIds = JVM::Converter::toIntVector(playerArray);
        std::vector<rage::IPlayer*> players;
        for(int id : playerIds) {
            players.push_back(Game::Player::getPlayerById(id));
        }
        checkpoint->ShowFor(players);
    }
}

void Java_mp_rage_launcher_checkpoint_CheckpointNative_HideFor(JNIEnv *, jclass, jint checkpointId, jintArray playerArray) {
    rage::ICheckpoint *checkpoint = Game::Checkpoint::getCheckpointById(checkpointId);
    if (checkpoint) {
        std::vector<int> playerIds = JVM::Converter::toIntVector(playerArray);
        std::vector<rage::IPlayer*> players;
        for(int id : playerIds) {
            players.push_back(Game::Player::getPlayerById(id));
        }
        checkpoint->HideFor(players);
    }
}
