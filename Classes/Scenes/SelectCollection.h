#ifndef SELECTCOLLECTION_H
#define SELECTCOLLECTION_H
#include "SceneStyle.h"
#include "cocos2d-A.h"

class SelectCollection: public SceneStyle
{
public:
    SelectCollection();
    static cocos2d::CCScene* scene();
    static SelectCollection* create();
private:
    bool init();
    void onBackClick();

    void hideEverything(ADCallFunc::Action action);

    cocos2d::CCLabelTTF* _title_select_collection;
    std::vector<ADMenuItem*> _cards;
};

#endif // SELECTCOLLECTION_H
