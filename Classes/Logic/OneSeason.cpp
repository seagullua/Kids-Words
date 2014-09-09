#include "OneSeason.h"
#include "Collection.h"
#include "LevelSaves.h"
#include <vector>
#include <algorithm>
#include "OneGame.h"
#include "InfoStyles.h"
#include <stdlib.h>

OneSeason::OneSeason(CollectionID id, int difficult):
    _collection_id(id),
    _difficult(difficult),
    _set_task_number(-1)
{
    srand(time(0)*(10+id)*(10+difficult));

    const Collection* current_collection;
    current_collection =LevelSaves::getInstance().getCollectionById(
                _collection_id);
    std::vector<Level> current_levels;

    current_levels =current_collection->getCollectionLevels();
    std::random_shuffle(current_levels.begin(), current_levels.end());
    int number_of_word = 1 ;
    number_of_word = getNumberWord(difficult);
    for (int i = 0 ; i < number_of_word; ++i )
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
    _set_task_number= _set_task_number + 1;
    return &_seasons_games[_set_task_number];
}
int OneSeason::getNumberWord(int difficult)
{
    int number_of_word = 1 ;

    if (difficult == 0)
    {
        number_of_word = InfoStyles::EASY_WORD;
    }
    else if (difficult == 1)
    {
        number_of_word = InfoStyles::MIDDLE_WORD;
    }
    else if (difficult == 2)
    {
        number_of_word = InfoStyles::DIFFICULT_WORD;
    }

    return number_of_word;
}
void OneSeason::setTaskNumber()
{

    _set_task_number = _set_task_number + 1;
}
int OneSeason::getSetTaskNumber()
{
    return _set_task_number + 1;
}
