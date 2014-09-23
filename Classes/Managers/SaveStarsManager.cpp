#include "SaveStarsManager.h"
#include <ADLib/Storage.h>

SaveStarsManager SaveStarsManager::instance;

SaveStarsManager* SaveStarsManager::getInstance( )
{
    return &instance;
}
inline int getID(CollectionID collection_id, int level_difficulty)
{
    return collection_id*10 + level_difficulty;
}

void SaveStarsManager::setStars(CollectionID collection_id, int level_difficulty, int stars)
{
    ADStorage::setMapValue<int>(
                BLOCK_SAVE_STARS,
                getID(collection_id, level_difficulty),
                stars);
}

int SaveStarsManager::getStars(CollectionID collection_id, int level_difficulty)
{
    if(ADStorage::hasMapValue(BLOCK_SAVE_STARS,getID(collection_id, level_difficulty)))
    {
    return ADStorage::getMapValue<int>(
                BLOCK_SAVE_STARS,
                getID(collection_id, level_difficulty),
                0);
    }
    else
    {
        return 10;
    }
}

SaveStarsManager::SaveStarsManager()
{

    //Add blocks to storage
    CONNECT(ADStorage::signalCreateBlocks, this,
            &SaveStarsManager::initStorageBlocks);

    //Check if first launch and add bonuses
    CONNECT(ADStorage::signalInitialDataLoaded, this,
            &SaveStarsManager::initDefaultValues);

}

void SaveStarsManager::initStorageBlocks()
{
    ADStorage::createMapBlock<int>(BLOCK_SAVE_STARS, KeyType::Int);
}

void SaveStarsManager::initDefaultValues()
{

}

