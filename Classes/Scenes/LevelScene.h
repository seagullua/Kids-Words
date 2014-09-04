#ifndef LEVELSCENE_H
#define LEVELSCENE_H
#include "SceneStyle.h"
#include "Logic/Collection.h"
#include "Logic/OneGame.h"
#include "Logic/OneSeason.h"
#include "Draw/GameNode.h"

class LevelScene: public SceneStyle
{
public:
    LevelScene(CollectionID id, int difficult);
    static cocos2d::CCScene* scene(CollectionID id, int difficult);
    static LevelScene* create(CollectionID id, int difficult);
void selectOneGame();
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
    GameNode* _game_node;
    OneSeason _current_one_season;

};

#endif // LEVELSCENE_H
