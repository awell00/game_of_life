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
        Params* params;
        Parser(Params* m_params);
    public:
        virtual ~Parser() = default;
        virtual void parseParams() = 0;
    };
}




#endif //PARSER_HPP
