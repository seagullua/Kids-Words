#ifndef LEVELSCENE_H
#define LEVELSCENE_H
#include "SceneStyle.h"
#include "Logic/Collection.h"
#include "Logic/OneGame.h"
#include "Logic/OneSeason.h"
#include "Draw/GameNode.h"
#include "Draw/TopPanell.h"

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
    int _current_number_of_word;
    int _number_of_word;
    const OneGame* _one_game;
    GameNode* _game_node;
    OneSeason _current_one_season;
    float _use_h;
    float _use_w;
    TopPanell* _top_panel;

};

#endif // LEVELSCENE_H
