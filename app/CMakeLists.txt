find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(MyQt6App
    main.cpp
    Worker.cpp
    Worker.h
)

target_link_libraries(MyQt6App PRIVATE Qt6::Core Qt6::Widgets mylib)

# Install app
install(TARGETS MyQt6App
    RUNTIME DESTINATION bin
    BUNDLE DESTINATION .
    COMPONENT app)

# macOS: run macdeployqt
if(APPLE)
    add_custom_command(TARGET MyQt6App POST_BUILD
        COMMAND ${Qt6_DIR}/../../../bin/macdeployqt
                "$<TARGET_BUNDLE_DIR:MyQt6App>"
                -dmg
        COMMENT "Running macdeployqt")
endif()

# Windows: run windeployqt
if(WIN32)
    add_custom_command(TARGET MyQt6App POST_BUILD
        COMMAND ${Qt6_DIR}/../../../bin/windeployqt
                "$<TARGET_FILE:MyQt6App>"
        COMMENT "Running windeployqt")
endif()
