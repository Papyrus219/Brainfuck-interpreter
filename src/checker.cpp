#include<string>
#include<vector>
#include<stack>
#include"./exeptions.hpp"
#include"./Bracket.hpp"

/*
 * @Throw exeption: Wrong_brackets,
 */
void Correct_check(std::vector<std::string> &code)
{
    std::stack<Bracket> brackets{};
    int bracket_level{};


    for(int line=0;line<code.size();line++)
    {
        for(int position=0;position<code[line].size();position++)
        {
            switch(code[line][position])
            {
                case '[':
                    brackets.push(Bracket{'[',{line,position}});
                    break;
                case ']':
                    if(brackets.empty())
                    {
                        Wrong_brackets x{"Bracket don't have pair!\n",{line,position},code[line]};
                        throw x;
                    }

                    brackets.pop();
                    break;
            }
        }

        if(!brackets.empty())
        {
            Wrong_brackets x{"Bracket don't have pair!\n", brackets.top().possition, code[brackets.top().possition.first]};
            throw x;
        }
    }
}
