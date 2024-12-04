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
        std::ifstream file;
    public:
        explicit TxtFile(std::string m_filePath);
        void open() override;
        void close() override;
        void read() override;
        std::string readByLine(int targetIndex) override;
        void write() override;
        ~TxtFile() override;
    };
}




#endif //TXTFILE_HPP
