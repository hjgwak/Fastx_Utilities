ENABLE_TESTING ()

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/src)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/test/bin)
IF ("${build}" MATCHES "debug")
	MESSAGE("EXECUTABLE_OUTPUT_PATH=" ${EXECUTABLE_OUTPUT_PATH})
ENDIF ("${build}" MATCHES "debug")

ADD_EXECUTABLE(test_SequenceReader_constructor test_constructor.cpp)
ADD_EXECUTABLE(test_SequenceReader_getter test_getter.cpp)
ADD_EXECUTABLE(test_SequenceReader_setter test_setter.cpp)

TARGET_LINK_LIBRARIES(test_SequenceReader_constructor Sequence SequenceReader)
TARGET_LINK_LIBRARIES(test_SequenceReader_getter Sequence SequenceReader)
TARGET_LINK_LIBRARIES(test_SequenceReader_setter Sequence SequenceReader)

ADD_TEST(test_SequenceReader_constructor ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_constructor)
ADD_TEST(test_SequenceReader_getter ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_getter)
ADD_TEST(test_SequenceReader_setter ${EXECUTABLE_OUTPUT_PATH}/test_Sequence_setter)