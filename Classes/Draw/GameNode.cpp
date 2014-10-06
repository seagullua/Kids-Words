#include "GameNode.h"
#include "Logic/OneGame.h"
#include "Logic/Task.h"
#include "Logic/Letter.h"
#include  "InfoStyles.h"
#include <algorithm>

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
    _current_node_in_use(nullptr),
    _node(nullptr),
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

    // _letters_qiuz
    CCNode* node_qiuz_word = CCNode::create();

    float padding_node_y = 0;
    float node_width=0;
    float letter_width=0;
    for (int i = 0 ; i < qiuz_word.size(); ++i )
    {
        LetterNode* letter_node = LetterNode:: create(qiuz_word[i]);
        letter_node->setAnchorPoint(ccp(0.5f,0.5f));
        letter_node->setPositionX(letter_node->getContentSize().width*0.5f+
                    letter_node->getContentSize().width*i*1.15f+padding);
        letter_node->setPositionY(letter_node->getContentSize().height*0.4f);
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
    node_qiuz_word->setPositionY(ORIGIN.y+padding );

    this->addChild(node_qiuz_word);

    // word_image
    CCSprite* word_image = CCSprite::create(word_image_name.c_str());
    word_image->setAnchorPoint(ccp(0.5f,0.5f));

       float word_image_y = ORIGIN.y + padding + node_qiuz_word->getContentSize().height* node_scale;
    float word_image_height = word_image->getContentSize().height;
    float word_image_width = word_image->getContentSize().width;

    float word_image_scale_y = (use_h- node_qiuz_word->getContentSize().height* node_scale-padding )/word_image_height;
    float word_image_scale = 1;
    float word_image_scale_x = (VISIBLE_SIZE.width*0.5f-padding)/word_image_width;

    word_image_scale = MIN(word_image_scale_x, word_image_scale_y);

    word_image->setScale(word_image_scale);


    float hn = node_qiuz_word->getContentSize().height* node_scale;
    float word_image_h = (_use_h -hn)*0.5f;
    float word_image_w = (VISIBLE_SIZE.width*0.5f-padding)*0.5f;
    word_image->setPositionX(ORIGIN.x+word_image_w+ VISIBLE_SIZE.width*0.5f );
    word_image->setPositionY(ORIGIN.y + word_image_h+hn+padding*0.5f);
    _word_image = word_image;
    this->addChild(word_image);



    // node_in_use_letters

    float w_node = VISIBLE_SIZE.width*0.5f;
    float h_node = _use_h -hn-padding;
    CCNodeRGBA* node_in_use_letters = CCNodeRGBA::create();
    node_in_use_letters->setCascadeOpacityEnabled(true);
//    node_in_use_letters->setContentSize(ccp(w_node, h_node));
    node_in_use_letters->setAnchorPoint(ccp(0,0.5f));
    node_in_use_letters->setPositionX(ORIGIN.x);
    node_in_use_letters->setPositionY(ORIGIN.y + word_image_h+hn+padding*0.5f);

    int f_x = 0;
    int f_y = 0;
    int n_letter = in_use_letters.size();
    float max_size = 0;
    float size_letter = 0;
    float MAX_LETTER_SIZE = 250/SCALE;
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
                    if (size_letter >= max_size && size_letter < MAX_LETTER_SIZE)
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
    _index_in_use_letter.resize(qiuz_word.size());
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
void GameNode::onGameEnd()
{

    CCSize visible_size = ADScreen::getVisibleSize();
    CCPoint ORIGIN = ADScreen::getOrigin();
    //_node_in_use_letters->setOpacity(255);
    _node_in_use_letters->runAction(CCScaleTo::create(0.2, 0));
    CCPoint target = ccp(ORIGIN.x+ visible_size.width*0.5f,
                         _word_image->getPositionY());
    _word_image->runAction(
                               CCMoveTo::create(0.2,
                                            target
                                            ));
    stopTrackingTouch();
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
    bool word_true = true;
    for(size_t i = 0; i < _letters_qiuz.size(); ++i)
    {

        LetterNode* node = _letters_qiuz[i];

        Letter active_letter = node->getActiveLetter();
        LetterStatus status = active_letter.getLetterStatus();
        Letter  selected_letter = node->getSelectedLetter();
        std::string active_letter_str = active_letter.getLetterString().c_str();
        std::string selected_letter_str = selected_letter.getLetterString().c_str();

        if (status != LetterStatus::Frozen)
        {
            if (node->isSelectedLetter())
            {

                if (active_letter_str  != selected_letter_str)
                {
                    word_true = false;
                }
            }
            else
            {
                word_true = false;
            }
        }
    }
    return word_true;
}
void GameNode::playAudio()
{

}


void GameNode::addLeter(int position, Letter letter)
{
    emit signalAddLetter(position, letter);
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
        _is_quiz_letter_selected = false;
        cocos2d::CCPoint local = touchToInsertCords(pTouch);
        LetterNode* current_node = nullptr;
        for(size_t i = 0; i < _letters_to_insert.size(); ++i)
        {
            LetterNode* node = _letters_to_insert[i];
            if(node->isVisible() && node->boundingBox().containsPoint(local))
            {
                current_node = node;
                current_node->setIndexSelectedLetter(i);
                break;
            }
        }


        if (current_node == nullptr)
        {
            CCPoint quiz_local =  _node_qiuz_word->convertToNodeSpace(pTouch->getLocation());
            for(size_t i = 0; i < _letters_qiuz.size(); ++i)
            {
                LetterNode* node = _letters_qiuz[i];
                if(node->boundingBox().containsPoint(quiz_local))
                {
                    int index = node->getIndexSelectedLetter();
                    if(index < _letters_to_insert.size())
                    {
                        //Letter is here
                        _is_quiz_letter_selected = true;
                        _quiz_selection_index = i;
                        current_node = _letters_to_insert[index];
                        current_node->setVisible(true);
                        removeLetter(node);
                        current_node->setPosition(local);
                    }

                    break;
                }
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
        //        std::string active_letter_node = node->getActiveLetter().getLetterString().c_str();
        //        std::string active_letter_to_insert = _letters_to_insert[i]->getActiveLetter().getLetterString().c_str();
        //        if(active_letter_node == active_letter_to_insert)
        if(node == _letters_to_insert[i]  )
        {
            index = i;
            //
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
void GameNode::moveLetterNodeBackByIndex(LetterNode* node,int index)
{
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
void GameNode::moveBack(LetterNode* quiz_node)
{
    int old_node = quiz_node->getIndexSelectedLetter();
    LetterNode* node = _letters_to_insert[old_node];
    node->setVisible(true);
    CCPoint p = quiz_node->getParent()->convertToWorldSpace(quiz_node->getPosition());
    node->setPosition(node->getParent()->convertToNodeSpace(p));
    moveLetterNodeBackByIndex(node,old_node);
}
void GameNode::removeLetter(LetterNode* node)
{
    node->setLetterIsSelected(false);
    node->setIndexSelectedLetter(_letters_to_insert.size());
}
void GameNode::removeLetterAndMoveBack(LetterNode* node)
{
    moveBack(node);
    removeLetter(node);
}

void GameNode::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent*)
{
    bool game_end = false;
    if(_is_tracking_touch && _selected_letter)
    {
        cocos2d::CCPoint local = touchToInsertCords(pTouch);
        _selected_letter->setPosition(local);

        cocos2d::CCPoint quiz = touchToQuizCords(pTouch);
        LetterNode* current_node = nullptr;
        int new_letter_insertion = 0;
        for(size_t i = 0; i < _letters_qiuz.size(); ++i)
        {
            LetterNode* node = _letters_qiuz[i];
            if(node->boundingBox().containsPoint(quiz))
            {
                new_letter_insertion = i;
                current_node = node;
                _index_in_use_letter[i] = current_node->getIndexSelectedLetter();
                break;
            }
        }

        if(current_node && current_node->canInsertLetter(_selected_letter->getActiveLetter()))
        {
            bool cn_is_selected_selected = current_node->isSelectedLetter();
            if (cn_is_selected_selected)

            {
                //int old_node = current_node->getIndexSelectedLetter();
                //LetterNode* node = _letters_to_insert[old_node];
                if(_is_quiz_letter_selected && new_letter_insertion != _quiz_selection_index)
                {
                    LetterNode* previous_node = _letters_qiuz[_quiz_selection_index];
                    previous_node->setLetterIsSelected(true);
                    previous_node->setSelectedLetter(current_node->getSelectedLetter());
                    previous_node->setIndexSelectedLetter(current_node->getIndexSelectedLetter());

                }
                else
                {

                    //Letter  cn_selected_Letter = current_node->getSelectedLetter();
                    //int index_selected_letter = current_node->getIndexSelectedLetter();
                    //LetterNode* cn_letter_node = LetterNode:: create(cn_selected_Letter);
                    //node->setVisible(true);
                    //node->setPosition(local);
                    //moveLetterNodeBackByIndex(node,old_node);
                    moveBack(current_node);
                }


            }
            current_node->setLetterIsSelected(true);
            current_node->setSelectedLetter(_selected_letter->getActiveLetter());
            current_node->setIndexSelectedLetter(_selected_letter->getIndexSelectedLetter());
            _selected_letter->setVisible(false);
            if (isSetEnd())
            {
                game_end = true;
                //
            }



            //TODO: додати _selected_letter в масив щоб знати в які клітинці вона стоїть
        }
        else
        {
            moveLetterNodeBack(_selected_letter);
        }


        _selected_letter->setZOrder(0);
        _selected_letter = nullptr;
        if (_node && _current_node_in_use)
        {
            //_node->setNodeColor(InfoStyles::COLOR_WHITE);
            //_current_node_in_use->setNodeColor(InfoStyles::COLOR_WHITE);
            _current_node_in_use->stopAllActions();
            _node->stopAllActions();
            _current_node_in_use->setScale(_base_scale);
            _node->setScale(_base_scale_n);
            _node = nullptr;
            _current_node_in_use = nullptr;

        }


    }
    if(game_end)
    {
        emit signalGameEnd();
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
void GameNode::showHint()
{
    if (_node && _current_node_in_use)
    {
        //        _node->setNodeColor(InfoStyles::COLOR_WHITE);
        //        _current_node_in_use->setNodeColor(InfoStyles::COLOR_WHITE);
        _current_node_in_use->stopAllActions();
        _node->stopAllActions();
        _current_node_in_use->setScale(_base_scale);
        _node->setScale(_base_scale_n);

        //        _node->ShowLetter();
        //        _current_node_in_use->ShowLetter();

        _node = nullptr;
        _current_node_in_use = nullptr;

    }
    if (_one_game->isCanUseHint())
    {

        LetterNode* current_node = nullptr;
        LetterNode* current_node_in_use = nullptr;
        LetterNode* node = nullptr;

        std::vector<int> index_letter_for_hint;
        int new_letter_insertion = 0;
        for(size_t i = 0; i < _letters_qiuz.size(); ++i)
        {
            current_node = _letters_qiuz[i];
            if(current_node->isLetterTrueforHint())
            {
                index_letter_for_hint.push_back(i);

            }
        }
        //        for(size_t i = 0; i < index_letter_for_hint.size(); ++i)
        //        {

        //            CCLog("Purchase %d failed", index_letter_for_hint[i]);

        //        }
        //         CCLog("_");

        if (index_letter_for_hint.size() > 0)
        {
            std::random_shuffle(index_letter_for_hint.begin(), index_letter_for_hint.end());

            //            for(size_t i = 0; i < index_letter_for_hint.size(); ++i)
            //            {

            //                CCLog("Purchase %d failed", index_letter_for_hint[i]);

            //            }

            node = _letters_qiuz[index_letter_for_hint[0]];

            if (node->isSelectedLetter())
            {
                removeLetterAndMoveBack(node);
            }
            int index_in_use_node = getIndexInUseLetterNode(node);
            if (index_in_use_node == -1)
            {
                int index_in_quiz_node = getIndexQuizWrongNode(node);
                if (index_in_quiz_node >=0)
                {

                    LetterNode* old_node = _letters_qiuz[index_in_quiz_node];

                    //                            int old_node_index = old_node->getIndexSelectedLetter();
                    //                            moveLetterNodeBackByIndex(node,old_node_index);
                    removeLetterAndMoveBack(old_node);

                    index_in_use_node = getIndexInUseLetterNode(node);
                }

            }


            if (index_in_use_node >= 0 && index_in_use_node <= _letters_to_insert.size() )
            {
                current_node_in_use = _letters_to_insert[index_in_use_node];
            }



            if(node && current_node_in_use)
            {
                //            node->setNodeColor(InfoStyles::COLOR_RED_LIGHT);
                _base_scale = current_node_in_use->getScale();
                _base_scale_n = node->getScale();
                float duration = 0.4f;
                //current_node_in_use->runAction(CCTintTo::create(5.5f, 255, 0, 0));
                //current_node_in_use->stopAllActions();
                //current_node_in_use->setNodeColor(InfoStyles::COLOR_MAGENTA);
                _node = node;
                _current_node_in_use = current_node_in_use;
                _current_node_in_use->runAction(
                            CCRepeatForever::create(
                                CCSequence::create(
                                    CCScaleTo::create(duration, _base_scale*1.4f),
                                    CCScaleTo::create(duration, _base_scale),
                                    NULL
                                    )
                                )
                            );
                _node->runAction(
                            CCRepeatForever::create(
                                CCSequence::create(
                                    CCScaleTo::create(duration, _base_scale_n*1.4f),
                                    CCScaleTo::create(duration, _base_scale_n),
                                    NULL
                                    )
                                )
                            );

            }
        }

    }

}
int GameNode::getIndexInUseLetterNode(LetterNode* node)
{
    int number_found_letter = -1;
    Letter active_letter = node->getActiveLetter();

    std::string active_letter_str = active_letter.getLetterString().c_str();
    for(size_t i = 0; i < _letters_to_insert.size(); ++i)
    {

        LetterNode* in_use_node = _letters_to_insert[i];
        if (in_use_node->isVisible())
        {

            Letter in_use_active_letter = in_use_node->getActiveLetter();

            std::string in_use_letter_str = in_use_active_letter.getLetterString().c_str();

            if (active_letter_str == in_use_letter_str)
            {
                number_found_letter = i;
                break;
            }
        }
    }

    return number_found_letter;
}
int GameNode::getIndexQuizWrongNode(LetterNode* node)
{

    Letter letter = node->getActiveLetter();

    std::string letter_str = letter.getLetterString().c_str();
    int number_found_letter = -1;
    std::string active_letter_str = "";
    for(size_t i = 0; i < _letters_qiuz.size(); ++i)
    {

        LetterNode* quiz_node = _letters_qiuz[i];
        Letter quiz_selected = quiz_node->getSelectedLetter();
        Letter quiz_active = quiz_node->getActiveLetter();

        std::string quiz_selected_str = quiz_selected.getLetterString().c_str();
        std::string quiz_active_str = quiz_active.getLetterString().c_str();

        if ( (letter_str  == quiz_selected_str) && (quiz_selected_str != quiz_active_str) )
        {
            number_found_letter = i;
        }

    }

    return number_found_letter;
}
