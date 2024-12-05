//
// Created by Robin Derenty on 04/12/2024.
//

#include "TxtParser.hpp"

#include <iostream>
#include <sstream>

#include "TxtFile.hpp"

namespace Utils
{
    TxtParser::TxtParser(TxtFile* m_file): file(m_file) {}

    Params* TxtParser::parseParams()
    {
        int fileHeight;
        int fileWidth;
        int fileMaxIteration;
        std::string fileGridTypeAsString;
        int fileExactNeighborToBorn;
        int fileMinNeighborToDie;
        int fileMaxNeighborToDie;
        int fileIterationDelay;
        Grid::GridType fileGridType;

        std::string paramsLine = file->readByLine(1);

        std::istringstream iss(paramsLine);

        iss >> fileHeight >> fileWidth >> fileMaxIteration >> fileGridTypeAsString >> fileExactNeighborToBorn >> fileMinNeighborToDie >> fileMaxNeighborToDie >> fileIterationDelay;

        if (fileGridTypeAsString == "CLASSIC"){fileGridType = Grid::CLASSIC;}
        else if (fileGridTypeAsString == "TORIC"){fileGridType = Grid::TORIC;}
        else {fileGridType = Grid::CLASSIC;}
        return new Params(fileHeight, fileWidth, fileMaxIteration, fileGridType, fileExactNeighborToBorn, fileMinNeighborToDie, fileMaxNeighborToDie, fileIterationDelay);
    }
}
