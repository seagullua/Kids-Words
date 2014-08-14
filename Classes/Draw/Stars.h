#ifndef STARS_H
#define STARS_H
#include "cocos2d.h"
class Stars : public cocos2d::CCNode
{
public:
    static Stars* create(int stars_number);

    Stars(int stars_number);
};

#endif // STARS_H
