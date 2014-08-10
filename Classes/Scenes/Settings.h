#ifndef SETTINGS_H
#define SETTINGS_H
#include "cocos2d-A.h"
#include "SceneStyle.h"

class Settings: public SceneStyle
{
public:
    Settings();
    static cocos2d::CCScene* scene();
    static Settings* create();

private:


    bool init();
    void onBackClick();
    void onMusicOnClick();
    void onSoundsOnClick();
    void onDevelopersClick();
    void onRestorePurchaseClick();
    void onTurnOffAdsClick();
    void onX4EnjoyClick();
};

#endif // MAINSCENE_H
