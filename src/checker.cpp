#include<string>
#include<vector>
#include<stack>
#include"./exeptions.hpp"

/*
 * @Throw exeption: Wrong_brackets,
 */

struct Bracket
{
    char rep{};
    std::pair<int,int> possition{};

    Bracket(char rep, std::pair<int,int> possition): rep{rep}, possition{possition}
    {};
};

void Correct_check(std::vector<std::string> CODE)
{
    std::stack<Bracket> Brackets{};

    for(int i=0;i<CODE.size();i++)
    {
        for(int j=0;j<CODE[i].size();j++)
        {
            switch(CODE[i][j])
            {
                case '[':
                    Brackets.push(Bracket{'[',{i,j}});
                    break;
                case ']':
                    if(Brackets.empty())
                    {
                        Wrong_brackets x{"Bracket don't have pair!\n",{i,j},CODE[i]};
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
