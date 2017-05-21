# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (textAdventure)

# delete CMakeCache.txt from the build directory when you edit these options
####################################################################
OPTION(MAKE_TEXT "Create Text Adventure" ON)
####################################################################

####################################################################
# textAdventure                                                        #
####################################################################
IF(MAKE_TEXT)
    add_executable(text
      TextAdventure/command.cpp
      TextAdventure/command.h
      TextAdventure/commandwords.cpp
      TextAdventure/commandwords.h
      TextAdventure/game.cpp
      TextAdventure/game.h
      TextAdventure/main.cpp
      TextAdventure/parser.cpp
      TextAdventure/parser.h
      TextAdventure/room.cpp
      TextAdventure/room.h
      TextAdventure/player.cpp
      TextAdventure/player.h
      TextAdventure/item.cpp
      TextAdventure/item.h
      TextAdventure/backpack.cpp
      TextAdventure/backpack.h
      TextAdventure/key.cpp
      TextAdventure/key.h
      TextAdventure/rlutil.h
      )


ENDIF()
