#include "OneSeason.h"
#include "Collection.h"
#include "LevelSaves.h"
#include <vector>
#include <algorithm>
#include "OneGame.h"

OneSeason::OneSeason(CollectionID id, int difficult):
    _collection_id(id),
    _difficult(difficult),
  _set_task_number(0)
  {
    const Collection* current_collection;
    current_collection =LevelSaves::getInstance().getCollectionById(
                _collection_id);
    std::vector<Level> current_levels;

    current_levels =current_collection->getCollectionLevels();
    std::random_shuffle(current_levels.begin(), current_levels.end());

    for (int i = 0 ; i<10; ++i )
    {
        Task current_task(current_levels[i],difficult);
        _seasons_games.push_back(OneGame(current_task));
    }

}
void OneSeason::setSeasonsGame(OneGame current_one_game)
{
    _seasons_games.push_back(current_one_game);
}

const OneGame* OneSeason::getNextLevel()
{
    return &_seasons_games[_set_task_number];
}
