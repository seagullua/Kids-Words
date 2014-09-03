#ifndef LEVELSCENE_H
#define LEVELSCENE_H
#include "SceneStyle.h"
#include "Logic/Collection.h"
#include "Logic/OneGame.h"

class LevelScene: public SceneStyle
{
public:
    LevelScene(CollectionID id, int difficult);
    static cocos2d::CCScene* scene(CollectionID id, int difficult);
    static LevelScene* create(CollectionID id, int difficult);
private:
    void onOneGameEnd();
    bool init();
    void onBackClick();
    void onSignalAudioClicked();
    void onSignalUseHintClicked();
    void setOneGame(const OneGame *one_game);
    CollectionID _collection_id;
    int _difficult;
    const OneGame* _one_game;

};

#endif // LEVELSCENE_H
