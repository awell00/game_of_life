//
// Created by Robin Derenty on 04/12/2024.
//

#ifndef PARSER_HPP
#define PARSER_HPP
#include "File.hpp"
#include "Params.hpp"


namespace Utils
{
    class Parser {
    protected:
        Parser();
    public:
        virtual ~Parser() = default;
        virtual Params* parseParams() = 0;
    };
}




#endif //PARSER_HPP
