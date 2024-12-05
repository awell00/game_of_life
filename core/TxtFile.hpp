//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef TXTFILE_HPP
#define TXTFILE_HPP
#include <fstream>

#include "File.hpp"


namespace Utils
{
    class TxtFile : public File {
    private:
        std::fstream file;
    public:
        explicit TxtFile(std::string m_filePath);
        bool open(std::ios::openmode mode) override;
        void close() override;
        void read() override;
        std::string readByLine(int targetIndex) override;
        void write(std::string data) override;
        void writeGrid(Grid::AbstractGrid* grid) override;
        ~TxtFile() override;
    };
}




#endif //TXTFILE_HPP
