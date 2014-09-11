#include "Hint.h"
#include "Letter.h"
#include "StatusLetter.h"
#include <ADLib.h>

Hint::Hint(Task task):
    _task(task)
{
    std::vector<Letter> in_use_letters;
    std::vector<Letter> qiuz_word;

    in_use_letters = _task.getInUseLetters();
    qiuz_word = _task.getQiuzWord();
    for (int i = 0 ; i < qiuz_word.size(); ++i )
    {

        LetterStatus status = qiuz_word[i].getLetterStatus();
        if (status == LetterStatus::Empty)
        {
            for (int j = 0; j < in_use_letters.size(); ++j )
            {

                std::string letter_string_q = qiuz_word[i].getLetterString();
                std::string letter_string_u = in_use_letters[j].getLetterString();

                if (letter_string_q == letter_string_u)
                {
                    //_hint_pairs.push_back(i,j);
                    break;
                }

            }
        }


    }

}

void Hint::setTask(Task task)
{

}

OneHint Hint::getOneHint()
{
    OneHint current_pair_hint;
    return current_pair_hint;
}
