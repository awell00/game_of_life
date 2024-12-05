cmake_minimum_required(VERSION 3.29)
project(game_of_life)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/nativefiledialog-extended-1.2.1)

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

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
        core/TxtParser.cpp
        view/GUIView.hpp
        view/GUIView.cpp
        view/ConsoleView.hpp
        view/ConsoleView.cpp
        utils/Slider.cpp
        utils/Slider.hpp
)

target_link_libraries(game_of_life
        PRIVATE nfd
        nfd sfml-graphics sfml-window sfml-system)

configure_file(${CMAKE_SOURCE_DIR}/utils/files/font.otf ${CMAKE_BINARY_DIR}/utils/files/font.otf COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/utils/files/play.png ${CMAKE_BINARY_DIR}/utils/files/play.png COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/utils/files/pause.png ${CMAKE_BINARY_DIR}/utils/files/pause.png COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/utils/files/slide.png ${CMAKE_BINARY_DIR}/utils/files/slide.png COPYONLY)

if(APPLE)
    set_target_properties(game_of_life PROPERTIES
            MACOSX_BUNDLE TRUE
            MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/Info.plist"
    )
endif()