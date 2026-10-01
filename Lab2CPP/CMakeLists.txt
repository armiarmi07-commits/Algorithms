 add_executable(Lab2CPP task.cpp)
 target_include_directories(Lab2CPP PUBLIC ../LibraryCPP)
 target_link_libraries(Lab2CPP LibraryCPP)

 add_test(NAME Lab2_Test1 COMMAND sh -c "./Lab2CPP '${CMAKE_CURRENT_SOURCE_DIR}/input.txt' output1.txt && cat output1.txt")
 set_property(TEST Lab2_Test1 PROPERTY PASS_REGULAR_EXPRESSION "YES")

 add_test(NAME Lab2_Test2 COMMAND sh -c "./Lab2CPP '${CMAKE_CURRENT_SOURCE_DIR}/input2.txt' output2.txt && cat output2.txt")
 set_property(TEST Lab2_Test2 PROPERTY PASS_REGULAR_EXPRESSION "NO")

 add_test(NAME Lab2_Test3 COMMAND sh -c "./Lab2CPP '${CMAKE_CURRENT_SOURCE_DIR}/tests/tests1.txt' output_tests1.txt && cat output_tests1.txt")
 set_property(TEST Lab2_Test3 PROPERTY PASS_REGULAR_EXPRESSION "NO")

 add_test(NAME Lab2_Test4 COMMAND sh -c "./Lab2CPP '${CMAKE_CURRENT_SOURCE_DIR}/tests/tests2.txt' output_tests2.txt && cat output_tests2.txt")
 set_property(TEST Lab2_Test4 PROPERTY PASS_REGULAR_EXPRESSION "NO")

 add_test(NAME Lab2_Test5 COMMAND sh -c "./Lab2CPP '${CMAKE_CURRENT_SOURCE_DIR}/tests/tests3.txt' output_tests3.txt && cat output_tests3.txt")
 set_property(TEST Lab2_Test5 PROPERTY PASS_REGULAR_EXPRESSION "NO")

 add_test(NAME Lab2_Test6 COMMAND sh -c "./Lab2CPP '${CMAKE_CURRENT_SOURCE_DIR}/tests/tests4.txt' output_tests4.txt && cat output_tests4.txt")
set_property(TEST Lab2_Test6 PROPERTY PASS_REGULAR_EXPRESSION "YES")