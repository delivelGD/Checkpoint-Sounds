#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/fmod/fmod.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    CheckpointObject* createCheckpoint() {

        auto ret = PlayLayer::createCheckpoint();
        if (!ret) return nullptr;

        FMODAudioEngine::sharedEngine()->playEffect("checkpointSound.ogg"_spr);

        return ret;
    }

    void removeCheckpoint(bool p0) {

        PlayLayer::removeCheckpoint(p0);

        FMODAudioEngine::sharedEngine()->playEffect("checkpointSound1.ogg"_spr);
    }
};