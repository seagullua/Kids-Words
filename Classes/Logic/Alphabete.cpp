#include "Alphabete.h"

Alphabete::Alphabete()
{
}
Alphabete& Alphabete::getInstance()
{
    static Alphabete obj;
    return obj;
}
void Alphabete::setApphabete()
{
    std::string current_alphabete;
    current_alphabete="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0 ; i<current_alphabete.size(); ++i )
    {
        std::string ch = " ";
        ch[0] = current_alphabete[i];
        _alphabete.push_back(ch);
    }


}
const std::vector<std::string>& Alphabete::getAlphabete()
{
    return _alphabete;
}
void Alphabete::setAlphabeteColor()
{
    cocos2d::ccColor3B _current_color ;

    // green 1/1
    _alphabete_color.push_back(cocos2d::ccc3(0,254,6));
    // green 2/2
    _current_color=cocos2d::ccc3(53,174,0);
    _alphabete_color.push_back(_current_color);
    // green 3/3
    _current_color=cocos2d::ccc3(31,100,0);
    _alphabete_color.push_back(_current_color);
    // magenta 1/4
    _current_color=cocos2d::ccc3(255,0,180);
    _alphabete_color.push_back(_current_color);
    // magenta 2/5
    _current_color=cocos2d::ccc3(135,0,100);
    _alphabete_color.push_back(_current_color);
    // dark blue 1/6
    _current_color=cocos2d::ccc3(0,15,206);
    _alphabete_color.push_back(_current_color);
    // dark blue 2/7
    _current_color=cocos2d::ccc3(0,0,100);
    _alphabete_color.push_back(_current_color);
    // light blue 1/8
    _current_color=cocos2d::ccc3(0,167,254);
    _alphabete_color.push_back(_current_color);
    // light blue 2/9
    _current_color=cocos2d::ccc3(9,122,180);
    _alphabete_color.push_back(_current_color);
    // red 1/10
    _current_color=cocos2d::ccc3(255,0,0);
    _alphabete_color.push_back(_current_color);
    // red 2/11
    _current_color=cocos2d::ccc3(170,8,8);
    _alphabete_color.push_back(_current_color);
    // pink 1/12
    _current_color=cocos2d::ccc3(233,61,61);
    _alphabete_color.push_back(_current_color);
    // pink 2/13
    _current_color=cocos2d::ccc3(248,58,58);
    _alphabete_color.push_back(_current_color);
    // yellow 1/14
    _current_color=cocos2d::ccc3(255,255,0);
    _alphabete_color.push_back(_current_color);
    // yellow 2/15
    _current_color=cocos2d::ccc3(255,174,0);
    _alphabete_color.push_back(_current_color);
    // yellow 3/16
    _current_color=cocos2d::ccc3(222,255,0);
    _alphabete_color.push_back(_current_color);
    // magenta 3/17
    _current_color=cocos2d::ccc3(255,0,138);
    _alphabete_color.push_back(_current_color);
    // light blue 3/18
    _current_color=cocos2d::ccc3(0,255,162);
    _alphabete_color.push_back(_current_color);
    // yellow green 1/19
    _current_color=cocos2d::ccc3(180,255,0);
    _alphabete_color.push_back(_current_color);
    // orange 1/20
    _current_color=cocos2d::ccc3(255,90,0);
    _alphabete_color.push_back(_current_color);
    // orange 2/20
    _current_color=cocos2d::ccc3(255,168,0);
    _alphabete_color.push_back(_current_color);
    // dark blue 3/21
    _current_color=cocos2d::ccc3(5,69,102);
    _alphabete_color.push_back(_current_color);
    // dark blue green 1/22
    _current_color=cocos2d::ccc3(5,102,73);
    _alphabete_color.push_back(_current_color);
    // pink 3/23
    _current_color=cocos2d::ccc3(178,116,182);
    _alphabete_color.push_back(_current_color);
    // pink 4/24
    _current_color=cocos2d::ccc3(126,5,148);
    _alphabete_color.push_back(_current_color);
    // green 4/25
    _current_color=cocos2d::ccc3(5,148,5);
    _alphabete_color.push_back(_current_color);
    // green 5/26
    _current_color=cocos2d::ccc3(4,76,4);
    _alphabete_color.push_back(_current_color);
    // dark blue 4/27
    _current_color=cocos2d::ccc3(4,16,76);
    _alphabete_color.push_back(_current_color);
    // magenta 4/28
    _current_color=cocos2d::ccc3(72,0,93);
    _alphabete_color.push_back(_current_color);
    // magenta 5/29
    _current_color=cocos2d::ccc3(93,0,61);
    _alphabete_color.push_back(_current_color);

    // dark blue 5/30
    _current_color=cocos2d::ccc3(67,54,239);
    _alphabete_color.push_back(_current_color);

    // dark blue 6/31
    _current_color=cocos2d::ccc3(12,4,11);
    _alphabete_color.push_back(_current_color);
    // orange 3/32
    _current_color=cocos2d::ccc3(182,52,0);
    _alphabete_color.push_back(_current_color);
    // yellow 4/33
    _current_color=cocos2d::ccc3(222,255,65);
    _alphabete_color.push_back(_current_color);

}
cocos2d::ccColor3B  Alphabete::getColorLetterById(int id)
{
    return _alphabete_color[id];
}
const std::vector<cocos2d::ccColor3B>& Alphabete::getAlphabeteColor()
{
    return _alphabete_color;
}

