// Copyright 2024 The Cobalt Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "cobalt/cobalt_main_delegate.h"
#include "cobalt/cobalt_content_browser_client.h"
#include "content/public/browser/render_frame_host.h"
#include "starboard/media.h"
#include "starboard/player.h"
// #include "base/android/jni_android.h"
// #include "starboard/android/shared/jni_env_ext.h"

namespace cobalt {

void PlayerDeallocateSampleFunc(SbPlayer player,
                                void* context,
                                const void* sample_buffer) {}

void PlayerDecoderStatusFunc(SbPlayer player,
                             void* context,
                             SbMediaType type,
                             SbPlayerDecoderState state,
                             int ticket) {}

void PlayerStatusFunc(SbPlayer player,
                      void* context,
                      SbPlayerState state,
                      int ticket) {}

void PlayerErrorFunc(SbPlayer player,
                     void* context,
                     SbPlayerError error,
                     const char* message) {}

CobaltMainDelegate::CobaltMainDelegate(bool is_content_browsertests)
    : content::ShellMainDelegate(is_content_browsertests) {}

CobaltMainDelegate::~CobaltMainDelegate() {}

content::ContentBrowserClient*
CobaltMainDelegate::CreateContentBrowserClient() {
  browser_client_ = std::make_unique<CobaltContentBrowserClient>();
  return browser_client_.get();
}

absl::optional<int> CobaltMainDelegate::PostEarlyInitialization(
    InvokedIn invoked_in) {
  content::RenderFrameHost::AllowInjectingJavaScript();

  // Debug code just to attempt SbPlayerCreation on Startup
  SbPlayerCreationParam creation_param = {};

  creation_param.drm_system = kSbDrmSystemInvalid;

  creation_param.audio_stream_info.codec = kSbMediaAudioCodecOpus;
  creation_param.audio_stream_info.mime = "";
  creation_param.audio_stream_info.number_of_channels = 2;
  creation_param.audio_stream_info.samples_per_second = 48000;
  creation_param.audio_stream_info.bits_per_sample = 16;
  creation_param.audio_stream_info.audio_specific_config_size = 0;
  creation_param.audio_stream_info.audio_specific_config = "";

  creation_param.video_stream_info.codec = kSbMediaVideoCodecVp9;
  creation_param.video_stream_info.mime = "";
  creation_param.video_stream_info.max_video_capabilities = "";
  creation_param.video_stream_info.frame_width = 1920;
  creation_param.video_stream_info.frame_height = 1080;
  creation_param.output_mode = kSbPlayerOutputModePunchOut;

  void* context = nullptr;
  SbDecodeTargetGraphicsContextProvider* provider = nullptr;
  SbPlayer player =
      SbPlayerCreate(kSbWindowInvalid, &creation_param,
                     PlayerDeallocateSampleFunc, PlayerDecoderStatusFunc,
                     PlayerStatusFunc, PlayerErrorFunc, context, provider);
  DCHECK(player);
  SbPlayerDestroy(player);
  SbDrmSystemIsValid(nullptr);
  SbDrmTicketIsValid(0);

  LOG(INFO) << "Colin DCHECK(player) passed";

  return ShellMainDelegate::PostEarlyInitialization(invoked_in);
}

}  // namespace cobalt
