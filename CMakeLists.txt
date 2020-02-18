cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 14)

project (topology-geometry)
find_package(Protobuf REQUIRED)

set(CATALOG here-hdlm-protobuf-weu-2)
set(LAYER topology-geometry)
set(PARTITION 327031896)

# check if protobuf was found
if(PROTOBUF_FOUND)
    message ("protobuf found")
else()
    message (FATAL_ERROR "Cannot find Protobuf")
endif()

add_subdirectory(protobuf/${CATALOG}/${LAYER})

# Add an executable
add_executable(topology-geometry main.cpp)

target_include_directories(topology-geometry
    PUBLIC
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}/protobuf/${CATALOG}/${LAYER})

# link the exe against the libraries
target_link_libraries(topology-geometry
    PUBLIC
    ${PROTOBUF_LIBRARIES}
    hd-topoloy-geometry)
# copy map data tile to build folder
file(COPY 
    ${CMAKE_SOURCE_DIR}/map-data/${CATALOG}/${LAYER}/${PARTITION}
    DESTINATION 
    ${CMAKE_BINARY_DIR}/map-data/${CATALOG}/${LAYER})