// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/base/android/mock_media_codec_bridge.h"

#include "media/base/subsample_entry.h"

using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgPointee;

namespace media {

MockMediaCodecBridge::MockMediaCodecBridge() {
  ON_CALL(*this, DequeueInputBuffer(_, _))
      .WillByDefault(Return(MediaCodecResult::Codes::kTryAgainLater));
  ON_CALL(*this, DequeueOutputBuffer(_, _, _, _, _, _, _))
      .WillByDefault(Return(MediaCodecResult::Codes::kTryAgainLater));
}

MockMediaCodecBridge::~MockMediaCodecBridge() = default;

void MockMediaCodecBridge::AcceptOneInput(IsEos eos) {
  EXPECT_CALL(*this, DequeueInputBuffer(_, _))
      .WillOnce(DoAll(SetArgPointee<1>(42), Return(OkStatus())))
      .WillRepeatedly(Return(MediaCodecResult::Codes::kTryAgainLater));
  if (eos == kEos)
    EXPECT_CALL(*this, QueueEOS(_));

  // We're not drained until the eos arrives at the output.
  is_drained_ = false;
}

void MockMediaCodecBridge::ProduceOneOutput(IsEos eos) {
  is_drained_ = (eos == kEos);
  EXPECT_CALL(*this, DequeueOutputBuffer(_, _, _, _, _, _, _))
      .WillOnce(DoAll(SetArgPointee<5>(eos == kEos ? true : false),
                      Return(OkStatus())))
      .WillRepeatedly(Return(MediaCodecResult::Codes::kTryAgainLater));
}

bool MockMediaCodecBridge::IsDrained() const {
  return is_drained_;
}

CodecType MockMediaCodecBridge::GetCodecType() const {
  return codec_type_;
}

// static
std::unique_ptr<MediaCodecBridge> MockMediaCodecBridge::CreateVideoDecoder(
    const VideoCodecConfig& config) {
  auto bridge = std::make_unique<MockMediaCodecBridge>();
  bridge->codec_type_ = config.codec_type;
  return bridge;
}

}  // namespace media
