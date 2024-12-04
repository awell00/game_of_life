//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef FILE_HPP
#define FILE_HPP
#include <string>

namespace Utils
{
    class File {
    protected:
        std::string filePath;
        bool isOpen;
        explicit File(std::string m_filePath);
    public:
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void read() = 0;
        virtual void write() = 0;
        virtual ~File() = default;
    };
}





#endif //FILE_HPP
