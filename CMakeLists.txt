cmake_minimum_required(VERSION 3.29)
project(game_of_life)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/nativefiledialog-extended-1.2.1)

find_package(SFML 2.6.2 COMPONENTS graphics window system REQUIRED)

add_executable(game_of_life main.cpp
        main.cpp
        core/AbstractCell.cpp
        core/ClassicCell.cpp
        core/ObstacleCell.cpp
        core/CellFactory.cpp
        core/AbstractGrid.cpp
        core/ClassicGrid.cpp
        core/ToricGrid.cpp
        core/GridFactory.cpp
        core/Params.cpp
        core/File.cpp
        core/TxtFile.cpp
        core/Algorithm.cpp
        view/AbstractView.cpp
        controller/AbstractController.cpp
        controller/ConsoleController.cpp
        controller/GUIController.cpp
        core/Parser.cpp
        core/TxtParser.cpp)

target_link_libraries(game_of_life
        PRIVATE nfd
        nfd sfml-graphics sfml-window sfml-system)

if(APPLE)
    set_target_properties(game_of_life PROPERTIES
            MACOSX_BUNDLE TRUE
            MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/Info.plist"
    )
endif()