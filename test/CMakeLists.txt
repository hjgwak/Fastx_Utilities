ENABLE_TESTING ()

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/src)

ADD_SUBDIRECTORY(test_Sequence)
ADD_SUBDIRECTORY(test_SequenceReader)