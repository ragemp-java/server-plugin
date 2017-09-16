/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#pragma once
#ifdef WIN32
#include <windows.h>
#endif
#include <iostream>
#include "sdk/rage.hpp"
#include "event/PlayerEventHandler.hpp"
#include "event/EntityEventHandler.hpp"
#include "event/VehicleEventHandler.hpp"
#include "event/ColshapeEventHandler.hpp"
#include "event/CheckpointEventHandler.hpp"
#include "jvm/JVMException.hpp"
#include "jvm/JVM.hpp"