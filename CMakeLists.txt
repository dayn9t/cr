cmake_minimum_required(VERSION 3.5)
project(cr)

message(STATUS "HIK_HEOP: " ${HIK_HEOP})


#add_definitions(-DBOOST_ALL_DYN_LINK)
set(Boost_USE_STATIC_LIBS ON)

#find_package(Boost COMPONENTS url log log_setup filesystem thread REQUIRED)
find_package(Boost COMPONENTS url REQUIRED)

#link_libraries(boost_url)

find_package(RapidJSON REQUIRED)
if(DEFINED HIK_HEOP)
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR aarch64)

    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

    if (${HIK_HEOP} STREQUAL KT2)
        set(PATH_3RD /home/jiang/ws/hik/d/3rd) # 第三方库路径

        set(CMAKE_PREFIX_PATH ${PATH_3RD}) # 交叉编译库搜索路径
        set(CMAKE_STAGING_PREFIX ${PATH_3RD})
        #set(CMAKE_SYSROOT /home/devel/rasp-pi-rootfs)
        #set(tools /home/jiang/ws/hik/gcc-linaro-6.2.1-2016.11-x86_64_aarch64-linux-gnu)
        #set(CMAKE_C_COMPILER ${tools}/bin/aarch64-linux-gnu-gcc)
        #set(CMAKE_CXX_COMPILER ${tools}/bin/aarch64-linux-gnu-g++)
    endif()
else()
    set(PATH_3RD /usr/local) # 第三方库路径
endif()

include_directories(${PATH_3RD}/include)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(main)
