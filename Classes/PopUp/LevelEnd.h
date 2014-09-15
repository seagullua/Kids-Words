#ifndef LEVELEND_H
#define LEVELEND_H
#include <ADLib/PopUp/IADStandardWindow.h>
#include "Logic/Collection.h"
#include <ADLib/ADSignals.h>

class LevelEnd: public IADStandardWindow
{
public:
    LevelEnd(cocos2d::CCNode* parent,CollectionID collection_id,int stars_number, int difficult);
 //   Signal<> signalNextLesson;
private:

    cocos2d::CCNode* _parent;
    CollectionID _collection_id;
    int _stars_number;
    int _difficult;
    void onCollection();
    void onNextLesson();
    void onCreate(cocos2d::CCNode *parent);
};

#endif // LEVELEND_H
