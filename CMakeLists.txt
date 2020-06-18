cmake_minimum_required(VERSION 3.1)
project(MyDoodle)
#
#
set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)
#
#
if (UNIX)
    set ( CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
endif(UNIX)
#
#
if (WIN32)
    set( SFML_STATIC_LIBRARIES TRUE )
    set ( SFML_DIR "C:/SFML-2.5/SFML-2.5.1/lib/cmake/SFML/")
endif(WIN32)
#
#
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
#
#
add_executable(MyDoodle main.cpp StaticView.cpp StaticView.h GameController.cpp GameController.h Jumper.cpp Jumper.h Tiles.cpp Tiles.h Entity.cpp Entity.h Subtitles.cpp Subtitles.h GameHandler.cpp GameHandler.h Scores.cpp Scores.h Manager.cpp Manager.h MovingTiles.cpp MovingTiles.h Items.cpp Items.h Menu.cpp Menu.h)
#
#
target_link_libraries(MyDoodle sfml-graphics sfml-audio)

