//
// Created by Robin Derenty on 04/12/2024.
//

#include "TxtParser.hpp"

#include <sstream>

#include "TxtFile.hpp"

namespace Utils
{
    TxtParser::TxtParser(Params* m_params, TxtFile& m_file): Parser(m_params), file(m_file) {}

    void TxtParser::parseParams()
    {
        int fileHeight;
        int fileWidth;
        int fileMaxIteration;
        int fileGridTypeAsString;
        int fileExactNeighborToBorn;
        int fileMinNeighborToDie;
        int fileMaxNeighborToDie;
        int fileIterationDelay;
        Grid::GridType fileGridType;

        file.open();
        std::string paramsLine = file.readByLine(1);

        std::istringstream iss(paramsLine);

        iss >> fileHeight >> fileWidth >> fileMaxIteration >> fileGridTypeAsString >> fileExactNeighborToBorn >> fileMinNeighborToDie >> fileMaxNeighborToDie >> fileIterationDelay;

        switch (toupper(fileGridTypeAsString))
        {
            case "CLASSIC":
                fileGridType = Grid::CLASSIC;
            case "TORIC":
                fileGridType = Grid::TORIC;
            default:
                fileGridType = Grid::CLASSIC;
        }


        this->params = new Params(fileHeight, fileWidth, fileMaxIteration, fileGridType, fileExactNeighborToBorn, fileMinNeighborToDie, fileMaxNeighborToDie, fileIterationDelay);
    }
}
