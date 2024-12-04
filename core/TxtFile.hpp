//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef TXTFILE_HPP
#define TXTFILE_HPP
#include "File.hpp"


namespace Utils
{
    class TxtFile : public File {
    public:
        explicit TxtFile(std::string m_filePath);
        void open() override;
        void close() override;
        void read() override;
        void write() override;
    };
}




#endif //TXTFILE_HPP
