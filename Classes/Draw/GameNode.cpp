#include "GameNode.h"
#include "Logic/OneGame.h"
#include "Logic/Task.h"
using namespace cocos2d;
GameNode* GameNode::create(const OneGame *one_game, int use_h)
{
    GameNode* obj = new GameNode( one_game,use_h);
    obj->autorelease();
    obj->init();
    return obj;
}


GameNode::GameNode(const OneGame *one_game, int use_h):
    _one_game(one_game),
    _is_tracking_touch(false),
    _selected_letter(nullptr),
    _use_h(use_h)
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
    _letters_qiuz=qiuz_letter;
    _node_qiuz_word = node_qiuz_word;

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

    word_image_scale = MIN(word_image_scale_x, word_image_scale_y);

    word_image->setScale(word_image_scale);


    float hn = node_qiuz_word->getContentSize().height* node_scale;
    float word_image_h = (_use_h -hn-padding)*0.5f;
    word_image->setPositionY(ORIGIN.y + word_image_h+hn+padding);

    this->addChild(word_image);

    float w_node = VISIBLE_SIZE.width*0.5f;
    float h_node = _use_h -hn;
     CCNode* node_in_use_letters = CCNode::create();
    node_in_use_letters->setContentSize(ccp(w_node, h_node));
    node_in_use_letters->setAnchorPoint(ccp(0,0.5f));
    node_in_use_letters->setPositionX(ORIGIN.x);
    node_in_use_letters->setPositionY(ORIGIN.y + word_image_h+hn+padding);

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

    _letters_in_row = f_x;
    _letter_size = size_letter;
    _letter_zone_size = CCSize(w_node, h_node);
    _letters_to_insert.resize(in_use_letters.size());
    for (int x = 0 ; x < f_x; ++x )
    {
        for(int y = 0; y < f_y; ++y)
        {
            int i = y*f_x + x;
            if(i < in_use_letters.size())
            {
                //for
                LetterNode* letter_node = LetterNode:: create(in_use_letters[i]);
                letter_node->setAnchorPoint(ccp(0.5f,0.5f));
                letter_node->setPosition(getLetterCordinates(i));
                //letter_node->setPositionX(size_letter*x);
                //letter_node->setPositionY(h_node - size_letter*y);
                //letter_node->setContentSize(ccp(size_letter, size_letter));
                letter_node->setScale(size_letter/letter_node->getContentSize().height);
                node_in_use_letters->addChild(letter_node);
                _letters_to_insert[i] = letter_node;
            }

        }
    }
    node_in_use_letters->setContentSize(ccp(w_node, h_node));
    _node_in_use_letters = node_in_use_letters;

    this->addChild(node_in_use_letters);
    startTrackingTouch();
}
CCPoint GameNode::getLetterCordinates(int index)
{
    int y = index / _letters_in_row;
    int x = index % _letters_in_row;

    CCPoint position(_letter_size*x + _letter_size*0.5f,
                     _letter_zone_size.height - _letter_size*y - _letter_size*0.5f);
    return position;
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

void GameNode::startTrackingTouch()
{
    if(!_is_tracking_touch)
    {
        _selected_letter = nullptr;
        _is_tracking_touch = true;
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, kCCMenuHandlerPriority, false);

    }
}
void GameNode::onExit()
{
    CCNode::onExit();
    stopTrackingTouch();
}

void GameNode::stopTrackingTouch()
{
    if(_is_tracking_touch)
    {
        _selected_letter = nullptr;
        _is_tracking_touch = false;
        CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    }
}

cocos2d::CCPoint GameNode::touchToInsertCords(cocos2d::CCTouch* touch)
{
    //Get touch point in local cordinates
    cocos2d::CCPoint touchLocation = touch->getLocation();
    cocos2d::CCPoint local_cords = _node_in_use_letters->convertToNodeSpace(touchLocation);
    return local_cords;
}

cocos2d::CCPoint GameNode::touchToQuizCords(cocos2d::CCTouch* touch)
{
    //Get touch point in local cordinates
    cocos2d::CCPoint touchLocation = touch->getLocation();
    cocos2d::CCPoint local_cords = _node_qiuz_word->convertToNodeSpace(touchLocation);
    return local_cords;
}

bool GameNode::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent*)
{
    if(_is_tracking_touch && _selected_letter == nullptr)
    {
        cocos2d::CCPoint local = touchToInsertCords(pTouch);
        LetterNode* current_node = nullptr;
        for(size_t i = 0; i < _letters_to_insert.size(); ++i)
        {
            LetterNode* node = _letters_to_insert[i];
            if(node->boundingBox().containsPoint(local))
            {
                current_node = node;
                break;
            }
        }


        _selected_letter = current_node;
        if(_selected_letter && _selected_letter->isVisible())
        {
            _selected_letter->stopAllActions();
            _selected_letter->setZOrder(1000);
            return true;
        }
    }
    return false;
}
void GameNode::moveLetterNodeBack(LetterNode* node)
{
    int index = -1;
    for(size_t i=0; i<_letters_to_insert.size(); ++i)
    {
        if(node == _letters_to_insert[i])
        {
            index = i;
            break;
        }
    }

    if(index >= 0)
    {
        //LetterNode* node = _letters_to_insert[index];
        CCPoint target_position = getLetterCordinates(index);
        node->stopAllActions();
        node->runAction(
                    CCMoveTo::create(0.2f, target_position)
                    );
        //node->setPosition(getLetterCordinates(index));
    }
}

void GameNode::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent*)
{
    if(_is_tracking_touch && _selected_letter)
    {
        cocos2d::CCPoint local = touchToInsertCords(pTouch);
        _selected_letter->setPosition(local);
    }
}

void GameNode::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent*)
{
    if(_is_tracking_touch && _selected_letter)
    {
        cocos2d::CCPoint local = touchToInsertCords(pTouch);
        _selected_letter->setPosition(local);

        cocos2d::CCPoint quiz = touchToQuizCords(pTouch);
        LetterNode* current_node = nullptr;
        for(size_t i = 0; i < _letters_qiuz.size(); ++i)
        {
            LetterNode* node = _letters_qiuz[i];
            if(node->boundingBox().containsPoint(quiz))
            {
                current_node = node;
                break;
            }
        }

        if(current_node && current_node->canInsertLetter(_selected_letter->getActiveLetter()))
        {
            current_node->setSelectedLetter(_selected_letter->getActiveLetter());
            _selected_letter->setVisible(false);
            //TODO: додати _selected_letter в масив щоб знати в які клітинці вона стоїть
        }
        else
        {
            moveLetterNodeBack(_selected_letter);
        }


        _selected_letter->setZOrder(0);
        _selected_letter = nullptr;

    }
}

void GameNode::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent*)
{
    if(_is_tracking_touch && _selected_letter)
    {
        cocos2d::CCPoint local = touchToInsertCords(pTouch);
        _selected_letter->setPosition(local);

        moveLetterNodeBack(_selected_letter);
        _selected_letter->setZOrder(0);
        _selected_letter = nullptr;
    }
}
