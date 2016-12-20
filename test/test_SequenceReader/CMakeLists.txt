ENABLE_TESTING ()

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/src)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/test/bin)
IF ("${build}" MATCHES "debug")
	MESSAGE("EXECUTABLE_OUTPUT_PATH=" ${EXECUTABLE_OUTPUT_PATH})
ENDIF ("${build}" MATCHES "debug")

ADD_EXECUTABLE(test_Sequence_constructor test_constructor.cpp)
ADD_EXECUTABLE(test_Sequence_getter test_getter.cpp)
ADD_EXECUTABLE(test_Sequence_operator test_operator.cpp)
ADD_EXECUTABLE(test_Sequence_setter test_setter.cpp)

TARGET_LINK_LIBRARIES(test_Sequence_constructor Sequence)
TARGET_LINK_LIBRARIES(test_Sequence_getter Sequence)
TARGET_LINK_LIBRARIES(test_Sequence_operator Sequence)
TARGET_LINK_LIBRARIES(test_Sequence_setter Sequence)

ADD_TEST(test_Sequence_constructor ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_constructor)
ADD_TEST(test_Sequence_getter ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_getter)
ADD_TEST(test_Sequence_operator ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_operator)
ADD_TEST(test_Sequence_setter ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_setter)