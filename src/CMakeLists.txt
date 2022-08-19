# Define the application entry point
add_executable(raychess main.cpp main.hpp)

# Require at least C++17
target_compile_features(raychess PRIVATE cxx_std_17)

# Link raylib to the executable
target_link_libraries(raychess PRIVATE raylib)
