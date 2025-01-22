// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/modules/cobalt/h5vcc/h5vcc_system.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"

namespace blink {

H5vccSystem* H5vccSystem::Create(ExecutionContext* context) {
  return MakeGarbageCollected<H5vccSystem>(context);
}

H5vccSystem* H5vccSystem::Create(Document* document) {
  return MakeGarbageCollected<H5vccSystem>(document->GetExecutionContext());
}

H5vccSystem::H5vccSystem(ExecutionContext* context)
    : ExecutionContextLifecycleObserver(context), advertising_id_("Colin_Test_AdvertisingId_Here") {}

// void H5vccSystem::ContextDestroyed() {}

const String& H5vccSystem::advertisingId() const {
  // TODO populate the value here.
  return advertising_id_;
}

void H5vccSystem::Trace(Visitor* visitor) const {
  ScriptWrappable::Trace(visitor);
  ContextLifecycleObserver::Trace(visitor);
}

}  // namespace blink