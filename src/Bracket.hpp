#ifndef BRACKET
#define BRACKET

#include<stack>

struct Bracket
{
    char representation;
    std::pair<int,int> possition;

    Bracket(char representation, std::pair<int,int> possition): representation{representation}, possition{possition}
    {};
};

#endif
