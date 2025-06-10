#include"globals.hpp"

char Table[30000]{};
char *ptr{Table};
std::stack<Bracket> Brackets{};
int bracket_level{};
