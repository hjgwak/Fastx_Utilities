ENABLE_TESTING ()

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/src)

SET(EXECUTABLE_OUTPUT_PATH "tests")
MESSAGE("EXECUTABLE_OUTPUT_PATH=" ${EXECUTABLE_OUTPUT_PATH})

SET(SEQUENCE_TEST_DIR ./test_Sequence)
SET(FASTA_TEST_DIR ./test_Fasta)

ADD_EXECUTABLE(test_Sequence_constructor ${SEQUENCE_TEST_DIR}/test_constructor.cpp)
ADD_EXECUTABLE(test_Sequence_setter ${SEQUENCE_TEST_DIR}/test_setter.cpp)
ADD_EXECUTABLE(test_Sequence_getter ${SEQUENCE_TEST_DIR}/test_getter.cpp)
ADD_EXECUTABLE(test_Sequence_operator ${SEQUENCE_TEST_DIR}/test_operator.cpp)

TARGET_LINK_LIBRARIES(test_Sequence_constructor Sequence)
TARGET_LINK_LIBRARIES(test_Sequence_setter Sequence)
TARGET_LINK_LIBRARIES(test_Sequence_getter Sequence)
TARGET_LINK_LIBRARIES(test_Sequence_operator Sequence)

ADD_TEST(unittest1 ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_constructor)
ADD_TEST(unittest2 ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_setter)
ADD_TEST(unittest3 ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_getter)
ADD_TEST(unittest4 ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_operator)