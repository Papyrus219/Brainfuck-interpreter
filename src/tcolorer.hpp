#ifndef TCOLORER
#define TCOLORER

#include<string>

/**
 * @todo write docs
 */

namespace col
{
    struct TColorer
    {
        std::string normal{"\033[0m"};
        std::string black{"\033[30m"};
        std::string red{"\033[31m"};
        std::string green{"\033[32m"};
        std::string yelow{"\033[33m"};
        std::string blue{"\033[34m"};
        std::string violet{"\033[35m"};
        std::string turquoise{"\033[36m"};
        std::string white{"\033[37m"};
    };

    TColorer colors;
}

#endif
