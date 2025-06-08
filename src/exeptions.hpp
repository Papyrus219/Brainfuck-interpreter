#ifndef EXEPTIONS
#define EXEPTIONS

#include<string>

struct exeption
{
    std::string reason{};

    exeption(std::string reason): reason{reason}
    {};
};

struct Wrong_open: public exeption
{
    Wrong_open(std::string reason): exeption(reason)
    {};
};

struct Wrong_brackets: public exeption
{
    std::pair<int,int> where;
    std::string what{};

    Wrong_brackets(std::string reason, std::pair<int,int> where, std::string what): exeption(reason), where{where}, what{what}
    {};
};

#endif
