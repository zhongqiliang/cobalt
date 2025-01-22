// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_H5VCC_H5VCC_SYSTEM_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_H5VCC_H5VCC_SYSTEM_H_

#include "third_party/blink/renderer/core/execution_context/execution_context_lifecycle_observer.h"
#include "third_party/blink/renderer/modules/modules_export.h"
#include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"

#include "third_party/blink/renderer/platform/heap/garbage_collected.h"

#include "third_party/blink/renderer/core/dom/dom_exception.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

class ExecutionContext;

class MODULES_EXPORT H5vccSystem final : public ScriptWrappable,
                          // public ActiveScriptWrappable<H5vccSystem>,
                          public ExecutionContextLifecycleObserver {
  DEFINE_WRAPPERTYPEINFO();

 public:
  static H5vccSystem* Create(ExecutionContext*);
  static H5vccSystem* Create(Document*);

  H5vccSystem(ExecutionContext*);
  H5vccSystem(const H5vccSystem&) = delete;
  H5vccSystem& operator=(const H5vccSystem&) = delete;
  ~H5vccSystem() override;

  // void ContextDestroyed() override;

  const String& advertisingId() const;

  void Trace(Visitor*) const override;

 private:
  String advertising_id_;
};

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_MODULES_H5VCC_H5VCC_SYSTEM_H_