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
     * header="", seq=""
     */
    Sequence seq = Sequence();

    /*
     * set new header
     * result : header="test", seq=""
     */
    seq.setHeader("test");
    if (not verifySequence(seq, "test", "")) {
        cerr << "[FAIL] setHeader(const std::string&)" << endl;
        ret = -1;
    }

    /*
     * string append
     * result : header="test", seq="AGTC"
     */
    seq.append("AGTC");
    if (not verifySequence(seq, "test", "AGTC")) {
        cerr << "[FAIL] append(const std::string&)" << endl;
        ret = -1;
    }

    /*
     * character array append
     * result : header="test", seq="AGTCTCGA"
     */
    char tmp1[5] = "TCGA";
    seq.append(tmp1);
    if (not verifySequence(seq, "test", "AGTCTCGA")) {
        cerr << "[FAIL] append(const char*)" << endl;
        ret = -1;
    }

    /*
     * character append
     * result : header="test", seq="AGTCTCGAA"
     */
    char ch = 'A';
    seq.append(ch);
    if (not verifySequence(seq, "test", "AGTCTCGAA")) {
        cerr << "[FAIL] append(const char)" << endl;
        ret = -1;
    }

    /*
     * Sequence object append
     * result : header="test", seq="AGTCTCGAAACGT"
     */
    Sequence seq2 = Sequence("test2", "ACGT");
    seq.append(seq2);
    if (not verifySequence(seq, "test", "AGTCTCGAAACGT")) {
        cerr << "[FAIL] append(const Sequence&)" << endl;
        ret = -1;
    }

    return ret;
}
