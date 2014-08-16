#ifndef LEVELSAVES_H
#define LEVELSAVES_H
#include <vector>
#include "Collection.h"
#include "Level.h"

class LevelSaves
{
public:
    LevelSaves();
    const std::vector<Collection>& getCollections();
    const std::vector<Level>& getLevels(CollectionID coll_id);
    void readLevels();

private:
    std::vector<Collection> _collections;
    std::vector<Level> _levels;
};

#endif // LEVELSAVES_H
