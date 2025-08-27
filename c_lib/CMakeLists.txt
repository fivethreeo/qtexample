add_library(mylib SHARED mylib.c)
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Add definition for Windows DLL export
target_compile_definitions(mylib PRIVATE MYLIB_EXPORTS)

install(TARGETS mylib
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    COMPONENT libmylib)

install(FILES mylib.h DESTINATION include COMPONENT libmylib_dev)
