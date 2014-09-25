#ifndef SAVESTARSMANAGER_H
#define SAVESTARSMANAGER_H
#include <ADLib/Storage.h>
#include "Logic/Collection.h"

class SaveStarsManager: public HasSlots
{
    static const int BLOCK_SAVE_STARS = 50001;
public:
    static SaveStarsManager* getInstance();
    void setStars(CollectionID collection_id, int level_difficulty, int stars);
    int getStars(CollectionID collection_id, int level_difficulty);
    int getStarsCollection(CollectionID collection_id);
private:
    static SaveStarsManager instance;

    SaveStarsManager();
    SaveStarsManager(SaveStarsManager const&);


    void initStorageBlocks();
    void initDefaultValues();
};

#endif // SAVESTARSMANAGER_H
