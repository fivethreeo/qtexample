cmake_minimum_required(VERSION 3.16)
project(MyProject LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(c_lib)
add_subdirectory(app)

# --- Packaging settings ---
set(CPACK_MONOLITHIC_INSTALL OFF)
set(CPACK_COMPONENTS_ALL myqt6app libmylib libmylib_dev)

# Component descriptions
set(CPACK_COMPONENT_LIBMYLIB_DISPLAY_NAME "MyLib Runtime")
set(CPACK_COMPONENT_LIBMYLIB_DESCRIPTION "Runtime library for MyLib")

set(CPACK_COMPONENT_LIBMYLIB_DEV_DISPLAY_NAME "MyLib Development Files")
set(CPACK_COMPONENT_LIBMYLIB_DEV_DESCRIPTION "Headers and CMake config for building with MyLib")
set(CPACK_COMPONENT_LIBMYLIB_DEV_DEPENDS libmylib)

set(CPACK_COMPONENT_MYQT6APP_DISPLAY_NAME "MyProject GUI App")
set(CPACK_COMPONENT_MYQT6APP_DESCRIPTION "Qt6 GUI application using MyLib")
set(CPACK_COMPONENT_MYQT6APP_DEPENDS libmylib)

# WiX for Windows
if(WIN32)
    set(CPACK_GENERATOR "WIX")
    set(CPACK_WIX_UPGRADE_GUID "BF521FEC-F95C-45AF-B79E-9361049FA388")
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "MyProject")
    set(CPACK_WIX_COMPONENT_GROUP_LIBMYLIB "libmylib")
    set(CPACK_WIX_COMPONENT_GROUP_LIBMYLIB_DEV "libmylib_dev")
    set(CPACK_WIX_COMPONENT_GROUP_MYQT6APP "myqt6app")
endif()

# macOS app bundling handled by macdeployqt
if(APPLE)
    set(CPACK_GENERATOR "DragNDrop")
endif()

if(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Your Name") # Required

    # Optional dependencies
    set(CPACK_DEBIAN_LIBMYLIB_PACKAGE_DEPENDS "libc6 (>= 2.31)")
    set(CPACK_DEBIAN_MYPROJECT_PACKAGE_DEPENDS "libqt6core6 (>= 6.2), libqt6widgets6 (>= 6.2)")
endif(UNIX AND NOT APPLE)

include(CPack)
