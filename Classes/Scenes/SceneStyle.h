#ifndef SCENESTYLE_H
#define SCENESTYLE_H
#include "cocos2d.h"
#include <ADLib.h>

#ifndef WIN32
#define final
#endif
enum class BackgroundType
{
    Dark,
    Light,
    LevelScene,
    None
};

class SceneStyle : public cocos2d::CCLayerColor, public HasSlots
{
public:
    void simulateBackClick();
protected:
    SceneStyle();
    bool init();
    void showBackground(const BackgroundType );
    void showButtonBack(const BackgroundType type=BackgroundType::None);
    ADPopUpWindowManager _pop_up_manager;
    virtual void onBackClick()=0;

private:
    void keyBackClicked() final;
};

#endif // SCENESTYLE_H
