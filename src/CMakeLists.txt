# Define the application entry point
add_executable(raychess main.cpp main.hpp)

# Define minimal language level
# Require at least C++14
target_compile_features(raychess PRIVATE cxx_std_14)

# Link raylib to the executable
target_link_libraries(raychess PRIVATE raylib)
