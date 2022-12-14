# Define rules for building the core game library

# Set files to be included in the header list
file(GLOB HEADERS_LIST "game.hpp" "game_areas/*.hpp" "pieces/*.hpp")

# Set files to be included in the source list
file(GLOB SOURCES_LIST "game.cpp" "game_areas/*.cpp" "pieces/*.cpp")

# Make static library
# We are literally just structuring our code here, so we don't need to worry about other users
add_library(raychess_core STATIC ${SOURCES_LIST} ${HEADERS_LIST})

# Define minimal language level
# Require at least C++14
target_compile_features(raychess_core PRIVATE cxx_std_14)

# Link raylib to this libaray (in a future)
#target_link_libraries(raychess_core PRIVATE raylib)

# Link the shared (common) types library to this library
target_link_libraries(raychess_core PRIVATE common)
target_include_directories(raychess_core PRIVATE "../common")

# I'm not sure how correct this is, but it allows me to include in source without relative paths
target_include_directories(raychess_core PRIVATE "./pieces")
target_include_directories(raychess_core PRIVATE "./game_areas")
