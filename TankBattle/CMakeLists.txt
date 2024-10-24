cmake_minimum_required(VERSION 3.28)

add_executable(TankBattle)
target_sources(TankBattle PRIVATE Main.cpp)
target_compile_features(TankBattle PRIVATE cxx_std_20)
set_target_properties(TankBattle PROPERTIES
    CXX_STANDARD_REQUIRED On
    CXX_EXTENSIONS Off
    EXPORT_COMPILE_COMMANDS On)
target_link_libraries(TankBattle PRIVATE Eqx_Pul Eqx_Lib Eqx_TPL)

add_custom_command(TARGET TankBattle PRE_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/Resources
        $<TARGET_FILE_DIR:TankBattle>/Resources
    COMMENT "Copying Resources!")
