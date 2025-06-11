#ifndef EXEPTIONS
#define EXEPTIONS

#include<string>

struct Exeption
{
    std::string reason{};

    Exeption(std::string reason): reason{reason}
    {};
};

struct Wrong_open: public Exeption
{
    Wrong_open(std::string reason): Exeption(reason)
    {};
};

struct Wrong_brackets: public Exeption
{
    std::pair<int,int> where;
    std::string what{};

    Wrong_brackets(std::string reason, std::pair<int,int> where, std::string what): Exeption(reason), where{where}, what{what}
    {};
};

#endif
