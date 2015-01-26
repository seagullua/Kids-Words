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

    void correctMusicEffects(EffectsType type);
    void hideEverything(ADCallFunc::Action action);

    CCSprite* _button_music_on_image ;
    CCSprite* _button_music_off_image ;
    CCSprite* _button_sounds_on_image;
    CCSprite* _button_sounds_off_image;

    ADMenuItem* _button_x4enjoy;
    cocos2d::CCLabelTTF* _author_of_music_title;

    ADMenuItem* _button_music_on;
    ADMenuItem* _button_sounds_on;
    ADMenuItem* _button_developers;
    ADMenuItem* _button_restore_purchase;
    ADMenuItem* _button_turn_off_ads;

};

#endif // SETTINGS_H
