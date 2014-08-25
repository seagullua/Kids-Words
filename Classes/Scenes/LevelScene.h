#ifndef LEVELSCENE_H
#define LEVELSCENE_H
#include "SceneStyle.h"
#include "Logic/Collection.h"

class LevelScene: public SceneStyle
{
public:
    LevelScene(CollectionID id, int difficult);
    static cocos2d::CCScene* scene(CollectionID id, int difficult);
    static LevelScene* create(CollectionID id, int difficult);
private:

    bool init();
    void onBackClick();
    CollectionID _collection_id;
    int _difficult;
};

#endif // LEVELSCENE_H
