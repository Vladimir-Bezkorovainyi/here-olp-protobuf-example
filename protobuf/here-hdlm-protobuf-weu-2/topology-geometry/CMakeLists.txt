# Select HERE OLP .proto files.
# Skip Google .proto files. 
file(GLOB_RECURSE PROTOBUF_FILELIST ${CMAKE_CURRENT_SOURCE_DIR}/com/*.proto)

# Generate c++ classes for selected .proto files.
set(PROTOBUF_GENERATE_CPP_APPEND_PATH OFF)
PROTOBUF_GENERATE_CPP(PROTO_SRC PROTO_HEADER ${PROTOBUF_FILELIST})

include_directories(
    ${PROTOBUF_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR})

add_library(hd-topoloy-geometry ${PROTO_HEADER} ${PROTO_SRC})