cmake_minimum_required(VERSION 3.1.3)

project(albertcore)

add_definitions(-DCORE) #export branch

find_package(Qt5 5.5.0 REQUIRED COMPONENTS
    Widgets
    Concurrent
    Network
    Sql
)

file(GLOB_RECURSE SRC include/* src/*)

add_library(${PROJECT_NAME} SHARED ${SRC} resources.qrc)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        include/
    PRIVATE
        include/core
        include/util
        src/
        src/core/
        src/core/settingswidget/
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${Qt5Widgets_LIBRARIES}
        ${Qt5Concurrent_LIBRARIES}
        ${Qt5Network_LIBRARIES}
        ${Qt5Sql_LIBRARIES}
        globalshortcut
        xdg
)

# Set the RPATH for the library lookup
set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib/albert")

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION lib/albert)
