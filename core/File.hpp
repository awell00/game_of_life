//
// Created by Robin Derenty on 03/12/2024.
//

#ifndef FILE_HPP
#define FILE_HPP
#include <string>

#include "AbstractGrid.hpp"
namespace Grid
{
    class AbstractGrid;
}
namespace Utils
{
    class File {
    protected:
        std::string filePath;
        bool isOpen;
        explicit File(std::string m_filePath);
    public:
        virtual bool open(std::ios::openmode mode) = 0;
        virtual void close() = 0;
        virtual void read() = 0;
        virtual void write(std::string data) = 0;
        virtual void writeGrid(Grid::AbstractGrid* grid) = 0;
        virtual std::string readByLine(int targetIndex) = 0;
        static void createDirectory(std::string folderName);
        virtual ~File() = default;
    };
}





#endif //FILE_HPP
