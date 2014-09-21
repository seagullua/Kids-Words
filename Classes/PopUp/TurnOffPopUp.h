#ifndef TURNOFFPOPUP_H
#define TURNOFFPOPUP_H
#include <ADLib/PopUp/IADStandardWindow.h>

class TurnOffPopUp: public IADStandardWindow
{
public:
    TurnOffPopUp(cocos2d::CCNode* parent);
private:

    cocos2d::CCNode* _parent;
    void onCreate(cocos2d::CCNode *parent);
    void onNo();
    void onAdd();
};

#endif // TURNOFFPOPUP_H
