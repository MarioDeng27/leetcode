PROJECT(vsomeip_method)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set (CMAKE_CXX_FLAGS "-g -std=c++0x -O0")

find_package( Boost 1.55 COMPONENTS system thread log REQUIRED )

include_directories (
    ${Boost_INCLUDE_DIR}
    ${VSOMEIP_INCLUDE_DIRS}
)

add_executable(service-method-example service-method-example.cpp)
add_executable(client-method-example client-method-example.cpp)
target_link_libraries(service-method-example vsomeip3 ${Boost_LIBRARIES})
target_link_libraries(client-method-example vsomeip3 ${Boost_LIBRARIES})
