#include "StarsCollectionManager.h"
#include <ADLib/Storage.h>
#include "SaveStarsManager.h"


StarsCollectionManager StarsCollectionManager::instance;

StarsCollectionManager* StarsCollectionManager::getInstance( )
{
    return &instance;
}
inline int getID(CollectionID collection_id)
{
    return collection_id;
}

void StarsCollectionManager::setStars(CollectionID collection_id, int stars)
{
    ADStorage::setMapValue<int>(
                BLOCK_COLLECTION_STARS,
                getID(collection_id),
                stars);
}

int StarsCollectionManager::getStars(CollectionID collection_id)
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
    int star_number = MIN(star_number_0,star_number_1,star_number_2);
    setStars(collection_id,star_number);
    return  star_number;
    //    }
}

StarsCollectionManager::StarsCollectionManager()
{

    //Add blocks to storage
    CONNECT(ADStorage::signalCreateBlocks, this,
            &StarsCollectionManager::initStorageBlocks);

    //Check if first launch and add bonuses
    CONNECT(ADStorage::signalInitialDataLoaded, this,
            &StarsCollectionManager::initDefaultValues);

}

void StarsCollectionManager::initStorageBlocks()
{
    ADStorage::createMapBlock<int>(BLOCK_COLLECTION_STARS, KeyType::Int);
}

void StarsCollectionManager::initDefaultValues()
{

}

