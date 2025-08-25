#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/fmod/fmod.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
    CheckpointObject* createCheckpoint() {

        auto ret = PlayLayer::createCheckpoint();
        if (!ret) return nullptr;

        auto soundPath = Mod::get()->getResourcesDir() / "checkpointSound.ogg";
        FMODAudioEngine::sharedEngine()->playEffect(soundPath.string().c_str());

        return ret;
    }

    void removeCheckpoint(bool p0) {

        PlayLayer::removeCheckpoint(p0);

        auto soundPath1 = Mod::get()->getResourcesDir() / "checkpointSound1.ogg";
        FMODAudioEngine::sharedEngine()->playEffect(soundPath1.string().c_str());
    }
};