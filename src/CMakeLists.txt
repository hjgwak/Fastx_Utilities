ADD_LIBRARY(Sequence Sequence.cpp)
ADD_LIBRARY(Fasta Fasta.cpp)
ADD_LIBRARY(SequenceReader SequenceReader.cpp)
TARGET_LINK_LIBRARIES(SequenceReader Sequence)