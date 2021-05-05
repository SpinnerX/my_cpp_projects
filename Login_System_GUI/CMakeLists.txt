cmake_minimum_required(VERSION 3.19)
project(Login_System_GUI)

set(CMAKE_CXX_STANDARD 17)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED)

add_executable(Login_System_GUI
        main.cpp
        Login_Window.h
        Login_Window.cpp
        Accounts/Account.h
        Accounts/Account.cpp
        Accounts/Register/Register_Account.h
        Accounts/Register/Register_Account.cpp)

if (NOT_CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it"
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif()

find_package(Qt5Widgets CONFIG
        PATHS /Users/aaronher/CLionProjects/Libraries/Qt/5.15.2/clang_64/lib/cmake/Qt5Widgets
        NO_DEFAULT_PATH)

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        )