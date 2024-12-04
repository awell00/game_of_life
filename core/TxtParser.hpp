//
// Created by Robin Derenty on 04/12/2024.
//

#ifndef TXTPARSER_HPP
#define TXTPARSER_HPP
#include "Parser.hpp"
#include "TxtFile.hpp"


namespace Utils
{
    class TxtParser : public Parser {
    private:
        TxtFile* file;
    public:
        TxtParser(TxtFile* m_file);
        Params* parseParams() override;
    };
}




#endif //TXTPARSER_HPP
