# Define rules for building the a library of common features

# Set files to be included in the header list
set(HEADERS_LIST "pos2d.hpp")

# Set files to be included in the source list
set(SOURCES_LIST "pos2d.cpp")

# Make static library
# We are literally just structuring our code here, so we don't need to worry about other users
add_library(common STATIC ${SOURCES_LIST} ${HEADERS_LIST})

# Define minimal language level
# Require at least C++14
target_compile_features(common PRIVATE cxx_std_14)
