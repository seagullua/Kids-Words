#ifndef STARSCOLLECTIONMANAGER_H
#define STARSCOLLECTIONMANAGER_H
#include <ADLib/Storage.h>
#include "Logic/Collection.h"




class StarsCollectionManager: public HasSlots
{
    static const int BLOCK_COLLECTION_STARS = 60001;
public:
    static StarsCollectionManager* getInstance();
    void setStars(CollectionID collection_id, int stars);
    int getStars(CollectionID collection_id);
private:
    static StarsCollectionManager instance;

    StarsCollectionManager();
    StarsCollectionManager(StarsCollectionManager const&);


    void initStorageBlocks();
    void initDefaultValues();
};



#endif // STARSCOLLECTIONMANAGERR_H
