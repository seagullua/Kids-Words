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
    std::vector<LetterNode*> qiuz_letter;

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
        qiuz_letter.push_back(letter_node);
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
    word_image->setAnchorPoint(ccp(0,0.5f));

    word_image->setPositionX(ORIGIN.x+ VISIBLE_SIZE.width*0.5f );
    float word_image_y = ORIGIN.y + padding*2 + node_qiuz_word->getContentSize().height* node_scale;
    float word_image_height = word_image->getContentSize().height;
    float word_image_width = word_image->getContentSize().width;

    float word_image_scale_y = (VISIBLE_SIZE.height- node_qiuz_word->getContentSize().height* node_scale-padding*9 )/word_image_height;
    float word_image_scale = 1;
    float word_image_scale_x = (VISIBLE_SIZE.width*0.5f-padding)/word_image_width;

    if(word_image_scale_y < 1)
    {
        if (word_image_scale_x < word_image_scale_y)
        {
            word_image_scale =  word_image_scale_x;

        }
        else
        {
            word_image_scale =  word_image_scale_y;

        }

    }
    if(word_image_scale_x < 1)
    {
        if (word_image_scale_x < word_image_scale_y)
        {
            word_image_scale =  word_image_scale_x;
        }
        else
        {
            word_image_scale =  word_image_scale_y;

        }

    }
    word_image->setScale(word_image_scale);

    //  word_image->setPositionY(ORIGIN.y + padding*2 + node_qiuz_word->getContentSize().height* node_scale+word_image->getContentSize().height*0.5f*word_image_scale);
    word_image->setPositionY(ORIGIN.y + VISIBLE_SIZE.height*0.5f);

    this->addChild(word_image);

    float w_node = VISIBLE_SIZE.width*0.5f;
    float h_node = VISIBLE_SIZE.height -2*node_qiuz_word->getContentSize().height* node_scale;
    float hn = node_qiuz_word->getContentSize().height* node_scale;
    CCNode* node_in_use_letters = CCNode::create();
    node_in_use_letters->setContentSize(ccp(w_node, h_node));
    node_in_use_letters->setAnchorPoint(ccp(0,0.5f));
    node_in_use_letters->setPositionX(ORIGIN.x);
    node_in_use_letters->setPositionY(ORIGIN.y + VISIBLE_SIZE.height*0.5f+padding);

    int f_x = 0;
    int f_y = 0;
    int n_letter = in_use_letters.size();
    float max_size = 0;
    float size_letter = 0;
    for (int x = 1; x <=10; ++x)
    {
        for (int y = 1; y <=10; ++y)
        {
            if ( x * y >= n_letter)
            {
                if ((h_node/ x) * y <= w_node )
                {

                    //float area = h_node * h_node / (x * y);
                    size_letter = h_node / x;
                    if (size_letter >= max_size )
                    {
                        max_size = size_letter;
                        f_x = x;
                        f_y = y;

                    }
                }
            }
        }
    }

    std::swap(f_x, f_y);
    size_letter = max_size;
    int size_use =  in_use_letters.size();
    for (int x = 0 ; x < f_x; ++x )
    {
        for(int y = 0; y < f_y; ++y)
        {
            int i = y*f_x + x;
            if(i < in_use_letters.size())
            {
                //for
                LetterNode* letter_node = LetterNode:: create(in_use_letters[i]);
                letter_node->setAnchorPoint(ccp(0,1));
                letter_node->setPositionX(size_letter*x);
                letter_node->setPositionY(h_node - size_letter*y);
                //letter_node->setContentSize(ccp(size_letter, size_letter));
                letter_node->setScale(size_letter/letter_node->getContentSize().height);
                node_in_use_letters->addChild(letter_node);
            }

        }
    }
    node_in_use_letters->setContentSize(ccp(w_node, h_node));

    this->addChild(node_in_use_letters);
}
bool GameNode::isSetEnd()
{
    return true;
}
void GameNode::playAudio()
{

}


void GameNode::addLeter(int position, Letter letter)
{
    emit signalAddLetter(position, letter);
}

void GameNode::signalGameEndOn()
{
    emit signalGameEnd();
}


void GameNode::signallStarsChangedOn(int number_of_stars)
{
    emit signallStarsChanged(number_of_stars);
}
