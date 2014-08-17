#include "CollectionPart.h"

CollectionPart::CollectionPart()
{
}
void CollectionPart::setImage(std::string image)
{
    _image = image;
}

const std::string CollectionPart::getImage() const
{
    return _image;
}
