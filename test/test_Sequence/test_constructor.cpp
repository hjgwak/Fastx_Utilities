//
// Created by Kelvin on 12/12/2016.
//
#include <iostream>
#include "Sequence.h"

using namespace std;

bool verifySequence(Sequence& obj, string header, string seq) {
    return (obj.getHeader() == header && obj.seq() == seq);
}

int main() {
    int ret = 0;

    /*
     * make empty Sequence object
     * using Sequence() constructor.
     */
    Sequence seq1 = Sequence();
    if (not verifySequence(seq1, "", "")) {
        cerr << "[FAIL] Sequence() constructor." << endl;
        ret = -1;
    }

    /*
     * make Sequence object
     * name : test1, seq : ACGTACGT
     */
    Sequence seq2 = Sequence("test1", "ACGTACGT");
    if (not verifySequence(seq2, "test1", "ACGTACGT")) {
        cerr << "[FAIL] Sequence(const std::string&, const std::string&) constructor." << endl;
        ret = -1;
    }

    /*
     * copy Sequence object
     * target : seq2
     */
    Sequence seq3 = Sequence(seq2);
    if (not verifySequence(seq3, "test1", "ACGTACGT")) {
        cerr << "[FAIL] Sequence(const Sequence&) constructor." << endl;
        ret = -1;
    }

    /*
     * string assignment
     * result : name="", seq="ACGTTCGA"
     */
    string test_seq1 = "ACGTTCGA";
    seq1 = test_seq1;
    if (not verifySequence(seq1, "", "ACGTTCGA")) {
        cerr << "[FAIL] operator= (const std::string&)" << endl;
        ret = -1;
    }

    /*
     * character array assignment
     * result : name="", seq="TCGAAGTC"
     */
    char test_seq2[9] = "TCGAAGTC";
    seq1 = test_seq2;
    if (not verifySequence(seq1, "", "TCGAAGTC")) {
        cerr << "[FAIL] operator= (const char*)" << endl;
        ret = -1;
    }

    /*
     * character assignment
     * result : name="", seq="A"
     */
    char test_seq3 = 'A';
    seq1 = test_seq3;
    if (not verifySequence(seq1, "", "A")) {
        cerr << "[FAIL] operator= (const char)" << endl;
        ret = -1;
    }

    /*
     * Sequence object assignment
     * result : name="test1", seq="ACGTACGT"
     */
    seq1 = seq2;
    if (not verifySequence(seq1, "test1", "ACGTACGT")) {
        cerr << "[FAIL] operator= (const Sequence&)" << endl;
        ret = -1;
    }

    return ret;
}
