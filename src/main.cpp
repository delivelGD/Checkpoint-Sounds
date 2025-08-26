#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <filesystem>

using namespace geode::prelude;

class $modify(PlayLayer) {
    CheckpointObject* createCheckpoint() {

        auto ret = PlayLayer::createCheckpoint();
        if (!ret) return nullptr;

        auto customFile1 = Mod::get()->getSettingValue<std::filesystem::path>("choose-custom-sound-for-creating");
        auto enableCSounds = Mod::get()->getSettingValue<bool>("enable-creating-sounds");
        if (customFile1 == "YourSound" && enableCSounds == true) {

        FMODAudioEngine::sharedEngine()->playEffect("checkpointSound.ogg"_spr);
        }
        else {
            if (enableCSounds == true) {
                FMODAudioEngine::sharedEngine()->playEffect(customFile1.string().c_str());
            }
        }

        return ret;
    }

    void removeCheckpoint(bool p0) {

        PlayLayer::removeCheckpoint(p0);

        auto customFile2 = Mod::get()->getSettingValue<std::filesystem::path>("choose-custom-sound-for-deleting");
        auto enableDSounds = Mod::get()->getSettingValue<bool>("enable-deleting-sounds");
        if (customFile2 == "YourSound" && enableDSounds == true) {

        FMODAudioEngine::sharedEngine()->playEffect("checkpointSound1.ogg"_spr);
        }
        else {
            if (enableDSounds == true) {
                FMODAudioEngine::sharedEngine()->playEffect(customFile2.string().c_str());
            }
        }
    }
};