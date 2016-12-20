#include "Sequence.h"
#include "SequenceReader.h"
#include <iostream>
#include <map>

using namespace std;

bool verifySequence(Sequence& obj, string header, string seq) {
	return (obj.getHeader() == header && obj.seq() == seq);
}

int main() {
	int ret = 0;

	SequenceReader reader("../test_data/test_seq.fasta");

	if (!reader.is_open()) {
		cerr << "[FAIL] SeqeunceReader::is_open() const" << endl;
		ret -= 1;
	}

	if (!reader.hasNext()) {
		cerr << "[FAIL] SequenceReader::hasNext() const" << endl;
		ret -= 1;
	}

	Sequence seq = reader.getNext();
	string answer_header = "test1";
	string answer_seq = "CTACATTAACACTTTGTTTTGTAACGCAAATTAGGCCGCGGTATCGACTACGTCGGAGGACTTTCTCTGCATCGGAACGCGCCGAAAGAGGGCCCTTGCG";
	if (!verifySequence(seq, answer_header, answer_seq)) {
		cerr << "[FAIL] SequenceReader::getNext() or SequenceReader::readNext()" << endl;
		ret -= 1;
	}

	vector<Sequence> v = reader.getAll();
	map<string, string> answer;
	answer[">test2"] = "TGATGGAACTCAAGATATCACGAGGGTGTGGTTTGTGGAGTATTGGCAGAGGGTATAGGATAGAAACCCACCCAGGTGCC";
	answer[">test3"] = "AAGTCGCTCGCTTCTTTAAGAACATTCCAACGAAGTACGCGTCCCCTAAACGCTCGCTCCCTATGTCGAGCAGATTGTTA";
	answer[">test3"] += "GAGAACTGCGCGTCGTTGTGCCCGGGTCACGGACGCGATGCTGATAGAACGGAACGGATGTCCGGCAATTGAAGATCGTA";
	answer[">test4"] = "CGCCTTCTATGGGGGAAAAAAAGTGGTGTATTGCCCTGACGTACTCTTGAGTACTACTGAAGCAGATGTTAATATGGAAG";
	answer[">test4"] += "GTACTTACTAAGCAGGGTCTATGAGGCGGCGGAGGGATTTAGTGAGCAATGAAACTCCTATTATCACCCATTCGTACGGC";
	answer[">test4"] += "CGTGACTGAAACGTATACTTCGGCTGAAAGAGTGGGCGGTTGTTGCGGTGAAATATATCTCCAAGTACCTCAGCCCGTTC";
	answer[">test4"] += "CGTGAAGTGTCAATTCATAAGCCGATGCCTGCCCAGTATACTTTGCCGCCTTTTTCTATGGAATTCAGTAAGCGCCACTT";
	answer[">test4"] += "AAGGTGACCGCAGTTTACTGCCTCAGATTTCGTTGAGACGGCTGCCCACGTCCGACCTATTGTTATCACGAACGCCAGAT";
	answer[">test5"] = "GCGGGATCGAAGCATCTTACAACCTACGGATTAATGTACTCGTCCTTAGC";

	if (v.size() != answer.size()) {
		cerr << "[FAIL] SequenceReader::getAll() or SequenceReader::readAll()" << endl;
		ret -= 1;
	}
	else {
		vector<Sequence>::iterator v_it = v.begin();
		map<string, string>::iterator m_it = answer.begin();

		for (; v_it != v.end() && m_it != answer.end(); ++v_it, ++m_it) {
			if (!verifySequence(*v_it, m_it->first, m_it->second)) {
				cerr << "[FAIL] SequenceReader::getAll() or SequenceReader::readAll()" << endl;
				ret -= 1;
				break;
			}
		}
	}

	return ret;
}