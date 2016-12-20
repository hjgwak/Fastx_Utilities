#include "Sequence.h"
#include "SequenceReader.h"
#include <iostream>

using namespace std;

int main() {
	int ret = 0;

	SequenceReader reader1;
	if (reader1.is_open()) {
		cerr << "[FAIL] SequenceReader() constructor" << endl;
		ret -= 1;
	}

	SequenceReader reader2("../test_data/test_seq.fasta");
	if (!reader2.is_open()) {
		cerr << "[FAIL] SequenceReader(const char*) constructor" << endl;
		ret -= 1;
	}

	reader2.close();

	string file_name = "../test_data/test_seq.fasta";
	SequenceReader reader3(file_name);
	if (reader3.is_open()) {
		cerr << "[FAIL] SequenceReader(const string&) constructor" << endl;
		ret -= 1;
	}

	reader3.close();

	return ret;
}