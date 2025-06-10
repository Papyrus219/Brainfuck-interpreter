#include"declarations.hpp"
#include"globals.hpp"
#include<iostream>

void Execude_Code(std::vector<std::string> CODE)
{
    int now{};

    for(int i=0;i<CODE.size();i++)
    {
        for(int j=0;j<CODE[i].size();j++)
        {
            switch(CODE[i][j])
            {
                case '<':
                    if(ptr == Tabble)
                        ptr = &Tabble[TABBLE_SIZE-1];
                    else
                        ptr--;
                    break;
                case '>':
                    if(ptr == &Tabble[TABBLE_SIZE-1])
                        ptr = Tabble;
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
                        Brackets.push(Bracket{'[',{i,j}});
                    else
                    {
                        do
                        {
                            if(CODE[i][j] == '[')
                                bracket_level++;
                            else if(CODE[i][j] == ']')
                                bracket_level--;

                            j++;
                            if(j >= CODE[i].size())
                            {
                                i++;
                                j=0;
                            }
                        } while(bracket_level != 0);
                    }
                    break;
                case ']':
                    if(!Brackets.empty())
                    {
                        i = Brackets.top().possition.first;
                        j = Brackets.top().possition.second - 1;
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
