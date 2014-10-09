#ifndef CARD_H
#define CARD_H
#include "cocos2d.h"
enum class CardType
{
    WithBorder,
    WithoutBorder
};

enum class BorderType
{
    None,
    Easy,
    Middle,
    Difficult
};

class Card : public cocos2d::CCNode
{
public:
    static Card* create(cocos2d::CCSprite* image,
                        std::string title,
                        int stars_number,
                        CardType _card_type);
    void setCardColor(cocos2d::ccColor3B color);
    void setTitleColor(cocos2d::ccColor3B color);
    void setBorderType(BorderType type);
private:
    Card(cocos2d::CCSprite* image,
         std::string title,
         int stars_number,
         CardType _card_type);
    cocos2d::CCSprite* _line_image;
    cocos2d::CCLabelTTF* _line_image_title;
    cocos2d::CCSprite* _border_image;
};

#endif // CARD_H
