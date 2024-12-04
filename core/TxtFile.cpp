//
// Created by Robin Derenty on 03/12/2024.
//

#include "TxtFile.hpp"

#include <fstream>
#include <iostream>
#include <string>

namespace Utils
{
    TxtFile::TxtFile(std::string m_filePath) : File(m_filePath), file(std::ifstream(filePath)) {}

    void TxtFile::open()
    {
        if (!file.is_open())
        {
        }
    }


    void TxtFile::close()
    {
        file.close();
    }

    void TxtFile::read()
    {
        ;
    }

    std::string TxtFile::readByLine(int targetIndex)
    {
        std::string actualLine;
        int currentIndex = 0;
        while(std::getline(this->file, actualLine))
        {
            currentIndex++;
            if (currentIndex == targetIndex) {return actualLine;}
        }
        return nullptr;
    }


    void TxtFile::write()
    {
        ;
    }

    TxtFile::~TxtFile()
    {
        this->TxtFile::close();
    }
}
