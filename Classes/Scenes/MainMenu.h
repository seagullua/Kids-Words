#ifndef MAINSCENE_H
#define MAINSCENE_H
#include "cocos2d-A.h"
#include "SceneStyle.h"

class MainMenu: public SceneStyle
{
public:
    MainMenu();
    static cocos2d::CCScene* scene();
    static MainMenu* create();

private:
    bool init();
    void onBackClick();
    void onPlayClick();
    void onSettingsClick();

    void hideEverything(ADCallFunc::Action action);

    cocos2d::CCSprite* _english_logo ;
    cocos2d::CCSprite* _l;
    cocos2d::CCSprite* _e;
    cocos2d::CCSprite* _a;
    cocos2d::CCSprite* _r;
    cocos2d::CCSprite* _n;

    ADMenuItem* _button_play;
    ADMenuItem* _button_settings;
};

#endif // MAINSCENE_H
