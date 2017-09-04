cmake_minimum_required(VERSION 3.0)
project(practice-cpp)


FOREACH(folder 
        # helloworld
        # bstree
        hrAttributeParser
    )

    ADD_SUBDIRECTORY(${folder})

ENDFOREACH(folder)


# SET(CMAKE_CXX_FLAGS_DEBUG  "${CMAKE_CXX_FLAGS_DEBUG} /ZI")

# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY )
# set(SOURCE )