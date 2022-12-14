/*
 * Copyright (C) 2018 The Android Open Source Project
 * Copyright (C) 2022 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef HARDWARE_SONY_CHARGER_UEVENTLISTENER_H
#define HARDWARE_SONY_CHARGER_UEVENTLISTENER_H

#include <android-base/chrono_utils.h>
#include "Charger.h"

namespace aidl {
namespace vendor {
namespace sony {
namespace charger {

/**
 * A class to listen for uevents and report reliability events to
 * the Sony Charger HAL.
 * Runs in a background thread if created with ListenForeverInNewThread().
 * Alternatively, process one message at a time with ProcessUevent().
 */
class UeventListener {
  public:
    UeventListener();
    bool ProcessUevent();  // Process a single Uevent
    void ListenForever();  // Process Uevents forever
    void handlePowerSupplyChange();

  private:
    int uevent_fd_;
};
}  // namespace charger
}  // namespace sony
}  // namespace vendor
}  // namespace aidl

#endif  // HARDWARE_SONY_CHARGER_UEVENTLISTENER_H
