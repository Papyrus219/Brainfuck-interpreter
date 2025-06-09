#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"./declarations.hpp"
#include"./tcolorer.hpp"
#include"./exeptions.hpp"

void Load_file_to_string(std::vector<std::string> &string_vector, std::ifstream &file);

int main(int argc, char** argv)
{
    std::vector<std::string> CODE{};
    try
    {
        for(int i=1;i<argc;i++)
        {
            std::ifstream file{argv[i]};
            Load_file_to_string(CODE, file);
            file.close();
        }
        Correct_check(CODE);
        for(auto el : CODE)
        {
            std::cout << el;
        }
    }
    catch(Wrong_open x)
    {
        std::cout << col::colors.red << x.reason << col::colors.normal;
        return 0;
    }
    catch(Wrong_brackets x)
    {
        std::cout << col::colors.red << x.reason;
        std::cout << "line: " << x.where.first << " possition: " << x.where.second << " :: ";

        for(int i=0;i<x.what.size();i++)
        {
            if(i == x.where.second)
                std::cout << col::colors.blue;

            std::cout << x.what[i] << col::colors.red;
        }
        std::cout << col::colors.normal;
    }

    return 0;
}

void Load_file_to_string(std::vector<std::string> &string_vector, std::ifstream &file)
{
    if(!file.is_open())
    {
        Wrong_open x{"Error! File does not exist!\n"};
        throw x;
    }

    std::string line{};
    while(std::getline(file,line))
        string_vector.push_back(line + '\n');
}
