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
        TxtFile& file;
    public:
        TxtParser(Params* m_params, TxtFile& m_file);
        void parseParams() override;
    };
}




#endif //TXTPARSER_HPP
