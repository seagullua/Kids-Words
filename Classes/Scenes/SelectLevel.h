#ifndef SELECTLEVEL_H
#define SELECTLEVEL_H
#include "SceneStyle.h"
#include "Logic/Collection.h"
#include "cocos2d-A.h"

class SelectLevel: public SceneStyle
{
public:
    SelectLevel(CollectionID id);
    static cocos2d::CCScene* scene(CollectionID id);
    static SelectLevel* create(CollectionID id);
private:

    bool init();
    void onBackClick();

    void hideEverything(ADCallFunc::Action action);


    CollectionID _collection_id;
};

#endif // SELECTLEVEL_H
