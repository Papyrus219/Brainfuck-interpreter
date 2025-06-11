#include<iostream>
#include<array>
#include"./Bracket.hpp"
#include"declarations.hpp"



void Execute_Code(std::vector<std::string> &code)
{
    std::array<char,30000> table{};
    char *ptr{table.data()};
    std::stack<Bracket> brackets{};
    int bracketLevel{};

    int now{};

    for(int line=0;line<code.size();line++)
    {
        for(int position=0;position<code[line].size();position++)
        {
            switch(code[line][position])
            {
                case '<':
                    if(ptr == table.begin())
                        ptr = table.end()-1;
                    else
                        ptr--;
                    break;
                case '>':
                    if(ptr == table.end()-1)
                        ptr = table.begin();
                    else
                        ptr++;
                    break;
                case '+':
                    if(static_cast<int>(*ptr) == 255)
                        *ptr = static_cast<char>(0);
                    else
                        (*ptr)++;
                    break;
                case '-':
                    if(static_cast<int>(*ptr) == 0)
                        *ptr = static_cast<char>(255);
                    else
                        (*ptr)--;
                    break;
                case '[':
                    if((*ptr) != 0)
                        brackets.push(Bracket{'[',{line,position}});
                    else //If loop is false, we must find coresponding brascet.
                    {
                        do
                        {
                            if(code[line][position] == '[') //We increase level if we enter another loop.
                                bracketLevel++;
                            else if(code[line][position] == ']') //We decrease level if we leave a loop.
                                bracketLevel--;

                            position++;
                            if(position >= code[line].size())
                            {
                                line++;
                                position=0;
                            }
                        } while(bracketLevel != 0); //If we are at level 0 it mean we at coresponding brascet.
                    }
                    break;
                case ']':
                    if(!brackets.empty()) //If there was brascet before we go to closest one (coresponding)
                    {
                        line = brackets.top().possition.first;
                        position = brackets.top().possition.second - 1;
                        brackets.pop();
                    }
                    break;
                case ',':
                    (*ptr) = getchar();
                    break;
                case '.':
                    std::cout << *ptr;
                    break;
            }
        }
    }
}
