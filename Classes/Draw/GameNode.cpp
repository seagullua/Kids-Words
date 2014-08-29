#include "GameNode.h"
#include "Logic/OneGame.h"
#include "Logic/Task.h"
using namespace cocos2d;
GameNode* GameNode::create(const OneGame *one_game)
{
    GameNode* obj = new GameNode( one_game);
    obj->autorelease();
    obj->init();
    return obj;
}


GameNode::GameNode(const OneGame *one_game):
    _one_game(one_game)
{
    const float SCALE = ADScreen::getScaleFactor();
    float padding = 25/SCALE;
    const CCPoint ORIGIN = ADScreen::getOrigin();
    const CCSize VISIBLE_SIZE = ADScreen::getVisibleSize();

    Task task = _one_game->getTask();
    std::vector<Letter> solution;
    std::vector<Letter> in_use_letters;
    std::vector<Letter> qiuz_word;
    solution = task.getSolution();
    in_use_letters = task.getInUseLetters();
    qiuz_word = task.getQiuzWord();
    std::string word_image_name = task.getImageFile();

    CCNode* node_qiuz_word = CCNode::create();

    float padding_node_y = 0;
    float node_width=0;
    float letter_width=0;
    for (int i = 0 ; i < qiuz_word.size(); ++i )
    {
        LetterNode* letter_node = LetterNode:: create(qiuz_word[i]);
        letter_node->setAnchorPoint(ccp(0,0));
        letter_node->setPositionX(letter_node->getContentSize().width*i*1.2f+padding);
        letter_node->setPositionY(0);
        node_qiuz_word->addChild(letter_node);
        letter_width=letter_node->getContentSize().width;
        node_width = node_width+letter_width+padding;
        padding_node_y= letter_node->getContentSize().height;
    }
    node_width = node_width;
    node_qiuz_word->setContentSize(ccp(node_width, padding_node_y));
    float node_scale = VISIBLE_SIZE.width/node_width;
    if(node_scale < 1)
    {
        node_qiuz_word->setScale(node_scale);

    }
    else
    {
        node_scale = 1;
    }
    node_qiuz_word->setAnchorPoint(ccp(0.5f,0));
    node_qiuz_word->setPositionX(ORIGIN.x+ VISIBLE_SIZE.width*0.5f );
    node_qiuz_word->setPositionY(ORIGIN.y +padding);

    this->addChild(node_qiuz_word);


    CCSprite* word_image = CCSprite::create(word_image_name.c_str());
    word_image->setAnchorPoint(ccp(0,0));

    word_image->setPositionX(ORIGIN.x+ VISIBLE_SIZE.width*0.5f );
    float word_image_y = ORIGIN.y + padding*2 + node_qiuz_word->getContentSize().height* node_scale;
    float word_image_height = word_image->getContentSize().height;
    float word_image_width = word_image->getContentSize().width;

    word_image->setPositionY(word_image_y);

    float word_image_scale_y = (VISIBLE_SIZE.height- node_qiuz_word->getContentSize().height* node_scale-padding*9 )/word_image_height;
    if(word_image_scale_y < 1)
    {
        word_image->setScaleY(word_image_scale_y);

    }
    float word_image_scale_x = (VISIBLE_SIZE.width*0.5f-padding)/word_image_width;
    if(word_image_scale_x < 1)
    {
        word_image->setScaleX(word_image_scale_x);

    }

     this->addChild(word_image);




}
