 add_executable(Lab3CPP task.cpp)
 target_include_directories(Lab3CPP PUBLIC ../LibraryCPP)
 target_link_libraries(Lab3CPP LibraryCPP)

 add_test(NAME Test_input COMMAND Lab3CPP ${CMAKE_CURRENT_SOURCE_DIR}/input.txt)
 set_property(TEST Test_input PROPERTY PASS_REGULAR_EXPRESSION "3")

 add_test(NAME Test_Labirint1 COMMAND Lab3CPP ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_input1)
 set_property(TEST Test_Labirint1 PROPERTY PASS_REGULAR_EXPRESSION "0")

 add_test(NAME Test_Labirint2 COMMAND Lab3CPP ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_input2)
 set_property(TEST Test_Labirint2 PROPERTY PASS_REGULAR_EXPRESSION "4")

 add_test(NAME Test_Labirint3 COMMAND Lab3CPP ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_input3)
 set_property(TEST Test_Labirint3 PROPERTY PASS_REGULAR_EXPRESSION "3")

 add_test(NAME Test_Labirint4 COMMAND Lab3CPP ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_input4)
 set_property(TEST Test_Labirint4 PROPERTY PASS_REGULAR_EXPRESSION "1")

 add_test(NAME Test_Labirint5 COMMAND Lab3CPP ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_input5)
 set_property(TEST Test_Labirint5 PROPERTY PASS_REGULAR_EXPRESSION "1")

 add_test(NAME Test_Labirint6 COMMAND Lab3CPP ${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_input6)
 set_property(TEST Test_Labirint6 PROPERTY PASS_REGULAR_EXPRESSION "1")