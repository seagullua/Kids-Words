#ifndef SETTINGS_H
#define SETTINGS_H
#include "cocos2d-A.h"
#include "SceneStyle.h"
using namespace cocos2d;

enum EffectsType
{
    Music,
    Sound
};
class Settings: public SceneStyle
{
public:
    Settings();
    static cocos2d::CCScene* scene();
    static Settings* create();

private:
    void onAdsWasDisabled();
    bool init();
    void onBackClick();
    void onMusicOnClick();
    void onSoundsOnClick();
    void onDevelopersClick();
    void onRestorePurchaseClick();
    void onTurnOffAdsClick();
    void onX4EnjoyClick();

    CCSprite* _button_music_on_image ;
    CCSprite* _button_music_off_image ;
    CCSprite* _button_sounds_on_image;
    CCSprite* _button_sounds_off_image;
    void correctMusicEffects(EffectsType type);
};

#endif // SETTINGS_H
