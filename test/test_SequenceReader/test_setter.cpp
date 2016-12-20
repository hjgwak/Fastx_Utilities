#include "Sequence.h"
#include "SequenceReader.h"
#include <iostream>

using namespace std;

int main() {
	int ret = 0;

	SequenceReader reader;

	reader.open("../test_data/test_seq.fasta");
	if (!reader.is_open()) {
		cerr << "[FAIL] SequenceReader::open(const char*)" << endl;
		ret -= 1;
	}

	reader.close();
	if (reader.is_open()) {
		cerr << "[FAIL] SequenceReader::close()" << endl;
		ret -= 1;
	}

	string file_name = "../test_date/test_seq.fasta";
	reader.open(file_name);
	if (!reader.is_open()) {
		cerr << "[FAIL] SequenceReader::open(const string&)" << endl;
		ret -= 1;
	}

	reader.close();

	return ret;
}