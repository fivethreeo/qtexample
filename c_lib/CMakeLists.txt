add_library(mylib SHARED mylib.c)
target_include_directories(mylib PUBLIC \${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS mylib
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    COMPONENT libmylib)

install(FILES mylib.h DESTINATION include COMPONENT libmylib-dev)
