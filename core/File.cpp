//
// Created by Robin Derenty on 03/12/2024.
//

#include "File.hpp"

#include <iostream>
#include <filesystem>

namespace Utils
{
    File::File(std::string m_filePath) : filePath(m_filePath){}

    void File::createDirectory(std::string folderName)
    {
        try {
            if (std::filesystem::create_directory(folderName)) {
                std::cout << "Folder created : " << folderName << std::endl;
            } else {
                std::cout << "The folder already exist." << std::endl;
            }
        } catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Erreur : " << e.what() << std::endl;
        }
    }

}
