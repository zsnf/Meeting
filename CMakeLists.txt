cmake_minimum_required(VERSION 3.29)
project(Meeting)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.7.2/msvc2019_64")

set(SOLUTION_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")
# 指定SDK的头文件目录
include_directories(${SOLUTION_DIR}/sdk/high_level_api/include)

# 指定SDK的库文件目录
link_directories(${SOLUTION_DIR}/sdk/x86_64)

# 设置库文件路径
set(shengwang ${SOLUTION_DIR}/sdk/x86_64/agora_rtc_sdk.dll.lib)

find_package(ZLIB REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        WebSockets
        REQUIRED)

add_executable(Meeting main.cpp
        View/StartView.cpp
        View/StartView.h
        View/SettingView.cpp
        View/SettingView.h
        Data/SettingData.h
        Controller.cpp
        Controller.h
        Data/SDKcall.cpp
        Data/SDKcall.h
        Data/Client.cpp
        Data/Client.h
)
add_executable(TokenServer TokenServer/servermain.cpp
        TokenServer/Server.cpp
        TokenServer/Server.h
        TokenServer/TokenSDK/utils.h
        TokenServer/TokenSDK/AccessToken2.h
        TokenServer/TokenSDK/RtcTokenBuilder2.h)

target_link_libraries(Meeting
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::WebSockets
        ${shengwang}
)

target_link_libraries(TokenServer
        Qt::Core
        Qt::WebSockets
        OpenSSL::SSL
        OpenSSL::Crypto
        ZLIB::ZLIB
)
file(GLOB AGORA_DLLS "${SOLUTION_DIR}/sdk/x86_64/*.dll")
foreach(DLL ${AGORA_DLLS})
    add_custom_command(
            TARGET Meeting POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${DLL}  # 逐个 DLL 文件复制
            ${CMAKE_CURRENT_BINARY_DIR}  # 复制到构建目录
    )
endforeach()


if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()



message(STATUS "Agora SDK Library Path: ${agora_rtc_sdk_lib}")
message(STATUS "Solution Directory: ${SOLUTION_DIR}")