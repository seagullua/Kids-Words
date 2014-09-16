#ifndef EXITGAMEPOPUP_H
#define EXITGAMEPOPUP_H
#include <ADLib/PopUp/IADStandardWindow.h>

class ExitGamePopUp: public IADStandardWindow
{
public:
    ExitGamePopUp(cocos2d::CCNode* parent);
private:

    cocos2d::CCNode* _parent;

    void onNo();
    void onYes();

    void onCreate(cocos2d::CCNode *parent);
};

#endif // EXITGAMEPOPUP_H
