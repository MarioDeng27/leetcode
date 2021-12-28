PROJECT(vsomeip_event)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

set (CMAKE_CXX_FLAGS "-g -std=c++0x")

find_package( Boost 1.55 COMPONENTS system thread log REQUIRED )

include_directories (
    ${Boost_INCLUDE_DIR}
    ${VSOMEIP_INCLUDE_DIRS}
)

add_executable(service-event-example service-event-example.cpp)
add_executable(client-event-example client-event-example.cpp)
target_link_libraries(service-event-example vsomeip3 ${Boost_LIBRARIES})
target_link_libraries(client-event-example vsomeip3 ${Boost_LIBRARIES})
