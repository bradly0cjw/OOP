#include <gtest/gtest.h>
#include "Device/Loudspeaker.hpp"

// --- Constructor Tests ---

TEST(LoudspeakerTest, Constructor_DefaultVolumeIs0) {
    Loudspeaker spk("Speaker1", 30);

    EXPECT_EQ(spk.getDeviceType(), DeviceType::Loudspeaker);
    EXPECT_EQ(spk.getName(), "Speaker1");
    EXPECT_EQ(spk.getPower(), 30);
    EXPECT_EQ(spk.getVolume(), 0);
}

TEST(LoudspeakerTest, Constructor_WithVolume_SetsVolume) {
    Loudspeaker spk("Speaker2", 40, 75);

    EXPECT_EQ(spk.getVolume(), 75);
}

// --- SetVolume Tests ---

TEST(LoudspeakerTest, SetVolume_ValidValue_UpdatesCorrectly) {
    Loudspeaker spk("Speaker3", 50);

    spk.setVolume(20);
    EXPECT_EQ(spk.getVolume(), 20);

    spk.setVolume(100);
    EXPECT_EQ(spk.getVolume(), 100);
}

TEST(LoudspeakerTest, SetVolume_InvalidTooLow_Throws) {
    Loudspeaker spk("Speaker4", 35);

    EXPECT_THROW(spk.setVolume(-1), std::invalid_argument);
}

TEST(LoudspeakerTest, SetVolume_InvalidTooHigh_Throws) {
    Loudspeaker spk("Speaker5", 35);

    EXPECT_THROW(spk.setVolume(101), std::invalid_argument);
}
