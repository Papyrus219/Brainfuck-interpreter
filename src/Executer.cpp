#include"declarations.hpp"
#include"globals.hpp"
#include<iostream>

void Execute_Code(std::vector<std::string> CODE)
{
    int now{};

    for(int line=0;line<CODE.size();line++)
    {
        for(int position=0;position<CODE[line].size();position++)
        {
            switch(CODE[line][position])
            {
                case '<':
                    if(ptr == Table)
                        ptr = &Table[TABLE_SIZE-1];
                    else
                        ptr--;
                    break;
                case '>':
                    if(ptr == &Table[TABLE_SIZE-1])
                        ptr = Table;
                    else
                        ptr++;
                    break;
                case '+':
                    (*ptr)++;
                    break;
                case '-':
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
