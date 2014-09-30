#ifndef ALPHABETE_H
#define ALPHABETE_H
#include <vector>
#include <string>
#include "cocos2d.h"
class Alphabete
{
public:
    static Alphabete& getInstance();
    void setApphabete(std::string current_alphabete);
    const std::vector<std::string>& getAlphabete();
    std::vector<cocos2d::ccColor3B> _alphabete_color;
    void setAlphabeteColor();
     cocos2d::ccColor3B  getColorLetterById(int id);
    const std::vector<cocos2d::ccColor3B >& getAlphabeteColor();
    const std::vector<int> getNumberLetterFromAlphabete(int number_of_letter);
    std::string getLetterById(int id);

private:

    Alphabete();
    std::vector<std::string> _alphabete;


};

#endif // ALPHABETE_H
