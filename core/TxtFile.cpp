//
// Created by Robin Derenty on 03/12/2024.
//

#include "TxtFile.hpp"

#include <fstream>
#include <iostream>
#include <string>

namespace Utils
{
    TxtFile::TxtFile(std::string m_filePath) : File(m_filePath), file(std::fstream(filePath)) {}

    bool TxtFile::open(std::ios::openmode mode)
    {
        file.open(filePath, mode);
        if (!file.is_open())
        {
            std::cerr << "Error Opening File" << std::endl;
            return false;
        }
        return true;
    }

    void TxtFile::close()
    {
        if(file.is_open())
        {
            file.close();
        }
    }

    void TxtFile::read()
    {
        ;
    }

    std::string TxtFile::readByLine(int targetIndex)
    {
        //this->open(std::ios::in);
        std::string actualLine;
        int currentIndex = 0;
        this->file.clear();
        this->file.seekg(0);

        while(std::getline(this->file, actualLine))
        {
            currentIndex++;
            if (currentIndex == targetIndex) {return actualLine;}
        }
        return "";
    }

    void TxtFile::writeGrid(Grid::AbstractGrid* grid)
    {
        std::string outData;
        for (int i =0; i < grid->getHeight(); i++)
        {
            for (int j = 0; j < grid->getWidth(); j++)
            {
                outData += std::to_string(grid->getCellByPosition(i, j)->getAlive()) + ((j != grid->getWidth()-1) ? ' ' : '\n');
            }
        }
        this->write(outData);
    }



    void TxtFile::write(std::string data)
    {
        this->open(std::ios::out);
        if (!file.is_open())
        {
            std::cerr << "Error : The file isn't open in writing mod." << std::endl;
            return;
        }
        if (!data.empty())
        {
            this->file << data << std::endl;
        }
        else
        {
            std::cerr << "Error : No Data To Write" << std::endl;
        }
    }

    TxtFile::~TxtFile()
    {
        this->TxtFile::close();
    }
}
