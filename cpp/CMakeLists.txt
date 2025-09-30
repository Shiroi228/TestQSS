cmake_minimum_required(VERSION 3.16)

project(TestQSS 
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

find_package(Qt5 REQUIRED Core Gui Widgets LinguistTools)

add_subdirectory(src)

set(SOURCES main.cpp)

set(TRANSLATIONS_TS
    res/translations/app_ru.ts)

qt5_create_translation(QM_FILES ${TRANSLATIONS_TS})
add_custom_target(app_translations ALL DEPENDS ${QM_FILES})

qt5_add_resources(APP_RESOURCES 
    res/translations/app_resources.qrc
    res/style/style.qrc
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

target_sources(${PROJECT_NAME} PRIVATE ${APP_RESOURCES})
add_dependencies(${PROJECT_NAME} app_translations)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${Qt5Widgets_INCLUDE_DIRS}
    src
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Source_lib
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${PROJECT_NAME}>/translations
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/app_ru.qm
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/translations
)

if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE OFF)
endif()