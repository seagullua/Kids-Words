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
int SaveStarsManager::getStarsCollection(CollectionID collection_id)
{
    //    if(ADStorage::hasMapValue(BLOCK_COLLECTION_STARS,getID(collection_id)))
    //    {
    //        return ADStorage::getMapValue<int>(
    //                    BLOCK_COLLECTION_STARS,
    //                    getID(collection_id),
    //                    0);
    //    }
    //    else
    //    {
    int star_number_0 = SaveStarsManager::getInstance()->getStars(
                collection_id, 0);
    int star_number_1 = SaveStarsManager::getInstance()->getStars(
                collection_id, 1);
    int star_number_2 = SaveStarsManager::getInstance()->getStars(
                collection_id, 2);
    int star_number_0_1 = MIN(star_number_0,star_number_1);
    int star_number = MIN(star_number_0_1,star_number_2);
    return  star_number;
    //    }
}

