#ifndef GLOBALS
#define GLOBALS

#include<stack>

extern char Tabble[30000];
constexpr short int TABBLE_SIZE{30000};
extern char *ptr;
extern int bracket_level;

struct Bracket
{
    char representation{};
    std::pair<int,int> possition{};

    Bracket(char representtion, std::pair<int,int> possition): representation{representation}, possition{possition}
    {};
};
extern std::stack<Bracket> Brackets;

#endif
