#ifndef COLLECTIONPART_H
#define COLLECTIONPART_H
#include <string>
class CollectionPart
{
public:
    CollectionPart();
    std::string _image;
    void setImage(std::string image);
    const std::string getImage() const;

};

#endif // COLLECTIONPART_H
