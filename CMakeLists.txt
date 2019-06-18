Cmake_minimum_required (VERSION 3.0)

Project (Bomberman)

include_directories(${IRRLICHT_PATH_INCLUDE})

link_directories(${IRRLICHT_PATH_LIB})

set (LIB
  include/Core.hpp
  include/Assets.hpp
  include/Bomb.hpp
  include/Cursor.hpp
  include/Exception.hpp
  include/FileNotFoundException.hpp
  include/Game.hpp
  include/Map.hpp
  include/Menu.hpp
  include/Object.hpp
  include/Character.hpp
  include/Event.hpp
  include/Sounds.hpp
  include/saveData.hpp
  )

set (SRC
  src/Core.cpp
  src/Assets.cpp
  src/Bomb.cpp
  src/Cursor.cpp
  src/Exception.cpp
  src/FileNotFoundException.cpp
  src/Game.cpp
  src/main.cpp
  src/Map.cpp
  src/Menu.cpp
  src/Object.cpp
  src/Character.cpp
  src/Event.cpp
  src/Sounds.cpp
  src/saveData.cpp
  )

add_executable(bomberman ${SRC} ${LIB})

target_include_directories(bomberman PRIVATE include)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
target_include_directories(bomberman PRIVATE ${SFML_LIBRARIES})
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(bomberman ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

find_library (IRRLICHT Irrlicht)

if (NOT IRRLICHT)
  message(WARNING "Irrlicht not installed")
  message(WARNING "Irrlicht installation in process")
  add_custom_command(TARGET bomberman
    POST_BUILD
    COMMAND /bin/sh ./install.sh -global
    )
else()
  message(WARNING "Irrlicht found")
endif()

target_link_libraries(
  bomberman
  Irrlicht
  pthread
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
#  opengl
#  xlib
#  xrandr
  freetype
#  glew
  jpeg
#  sndfile
  openal
)
