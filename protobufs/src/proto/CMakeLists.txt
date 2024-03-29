find_package(Protobuf REQUIRED)

#
# Protobuf/Grpc source files
#
set(PROTO_FILES
    address_book.proto
    date_pkg.proto
    person.proto
)

#
# Add Library target with protobuf sources
#

add_library(myproto ${PROTO_FILES} )
target_include_directories(myproto INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(myproto
    PUBLIC
        protobuf::libprotobuf
)

protobuf_generate(TARGET myproto LANGUAGE cpp)

