#ifndef TCOLORER
#define TCOLORER

#include<string_view>

namespace col
{
    /**
     * Struct to storage consol colors.
     */
    struct TColorer
    {
        constexpr static std::string_view normal{"\033[0m"};
        constexpr static std::string_view black{"\033[30m"};
        constexpr static std::string_view red{"\033[31m"};
        constexpr static std::string_view green{"\033[32m"};
        constexpr static std::string_view yelow{"\033[33m"};
        constexpr static std::string_view blue{"\033[34m"};
        constexpr static std::string_view violet{"\033[35m"};
        constexpr static std::string_view turquoise{"\033[36m"};
        constexpr static std::string_view white{"\033[37m"};
    };
}

#endif
