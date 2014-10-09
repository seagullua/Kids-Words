#ifndef LEVELSAVES_H
#define LEVELSAVES_H
#include <vector>
#include "Collection.h"
#include "Level.h"

class LevelSaves
{
public:
    static LevelSaves& getInstance();
    const std::vector<Collection>& getCollections();
    const Collection* getCollectionById(CollectionID coll_id);
    void readLevels();
    void addCollection(Collection collect);

private:
    LevelSaves();
    std::vector<Collection> _collections;
    std::vector<Level> _levels;

};

#endif // LEVELSAVES_H
