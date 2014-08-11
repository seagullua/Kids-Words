#ifndef DEVELOPERS_H
#define DEVELOPERS_H
#include "cocos2d-A.h"
#include "SceneStyle.h"

class Developers: public SceneStyle
{
public:
    Developers();
    static cocos2d::CCScene* scene();
    static Developers* create();

private:

    bool init();
    void onBackClick();
    void onX4EnjoyClick();
};

#endif // DEVELOPERS_H
