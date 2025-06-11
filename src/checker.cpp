#include<string>
#include<vector>
#include<stack>
#include"./exeptions.hpp"
#include"./Bracket.hpp"

/*
 * @Throw exeption: Wrong_brackets,
 */
void Correct_check(std::vector<std::string> &CODE)
{
    std::stack<Bracket> Brackets{};
    int bracket_level{};


    for(int line=0;line<CODE.size();line++)
    {
        for(int position=0;position<CODE[line].size();position++)
        {
            switch(CODE[line][position])
            {
                case '[':
                    Brackets.push(Bracket{'[',{line,position}});
                    break;
                case ']':
                    if(Brackets.empty())
                    {
                        Wrong_brackets x{"Bracket don't have pair!\n",{line,position},CODE[line]};
                        throw x;
                    }

                    Brackets.pop();
                    break;
            }
        }

        if(!Brackets.empty())
        {
            Wrong_brackets x{"Bracket don't have pair!\n", Brackets.top().possition, CODE[Brackets.top().possition.first]};
            throw x;
        }
    }
}
