#include<iostream>
#include<array>
#include"./Bracket.hpp"
#include"declarations.hpp"



void Execute_Code(std::vector<std::string> &CODE)
{
    std::array<char,30000> Table{};
    char *ptr{Table.data()};
    std::stack<Bracket> Brackets{};
    int bracket_level{};

    int now{};

    for(int line=0;line<CODE.size();line++)
    {
        for(int position=0;position<CODE[line].size();position++)
        {
            switch(CODE[line][position])
            {
                case '<':
                    if(ptr == Table.begin())
                        ptr = Table.end()-1;
                    else
                        ptr--;
                    break;
                case '>':
                    if(ptr == Table.end()-1)
                        ptr = Table.begin();
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
                        Brackets.push(Bracket{'[',{line,position}});
                    else //If loop is false, we must find coresponding brascet.
                    {
                        do
                        {
                            if(CODE[line][position] == '[') //We increase level if we enter another loop.
                                bracket_level++;
                            else if(CODE[line][position] == ']') //We decrease level if we leave a loop.
                                bracket_level--;

                            position++;
                            if(position >= CODE[line].size())
                            {
                                line++;
                                position=0;
                            }
                        } while(bracket_level != 0); //If we are at level 0 it mean we at coresponding brascet.
                    }
                    break;
                case ']':
                    if(!Brackets.empty()) //If there was brascet before we go to closest one (coresponding)
                    {
                        line = Brackets.top().possition.first;
                        position = Brackets.top().possition.second - 1;
                        Brackets.pop();
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
