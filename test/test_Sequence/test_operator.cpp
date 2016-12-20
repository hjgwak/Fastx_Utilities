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
     * append string "AGTC" using operator+=
     * result : header="", seq="AGTC"
     */
    seq += "AGTC";
    if (seq.seq() != "AGTC") {
        cerr << "[FAIL] operator+= (const std::string&)" << endl;
        ret = -1;
    }

    /*
     * append character array "TCGA" using operator+=
     * result : header="", seq="AGTCTCGA"
     */
    char tmp[5] = "TCGA";
    seq += tmp;
    if (seq.seq() != "AGTCTCGA") {
        cerr << "[FAIL] operator+= (const char *)" << endl;
        ret = -1;
    }

    /*
     * append character 'A' using operator+=
     * result : header="", seq="AGTCTCGAA"
     */
    char ch = 'A';
    seq += ch;
    if (seq.seq() != "AGTCTCGAA") {
        cerr << "[FAIL] operator+= (const char)" << endl;
        ret = -1;
    }

    /*
     * append Sequence object using operator+=
     * result : header="", seq="AGTCTCGAAACGT"
     */
    Sequence seq2 = Sequence("adder", "ACGT");
    seq += seq2;
    if (seq.getHeader() != "" || seq.seq() != "AGTCTCGAAACGT") {
        cerr << "[FAIL] operator+= (const Sequence&)" << endl;
        ret = -1;
    }

    /*
     * seq + seq2
     * result : header="", seq="AGTCTCGAAACGTACGT"
     */
    Sequence seq3 = seq + seq2;
    if (!verifySequence(seq3, "", "AGTCTCGAAACGTACGT")) {
        cerr << "[FAIL] operator+ (const Sequence&, const Sequence&)" << endl;
        ret = -1;
    }

    /*
     * seq2 + string "TAGC"
     * result : header="adder", seq="ACGTTAGC"
     */
    Sequence seq4 = seq2 + "TAGC";
    if (!verifySequence(seq4, "adder", "ACGTTAGC")) {
        cerr << "[FAIL] operator+ (const Sequence&, const std::string&)" << endl;
        ret = -1;
    }

    /*
     * seq4 + character array "ATGC"
     * result : header="adder", seq="ACGTTAGCATGC"
     */
    char tmp2[5] = "ATGC";
    Sequence seq5 = seq4 + tmp2;
    if (!verifySequence(seq5, "adder", "ACGTTAGCATGC")) {
        cerr << "[FAIL] operator+ (const Sequence&, const char *)" << endl;
        ret = -1;
    }

    /*
     * seq5 + chracter 'C'
     * result : header="adder", seq="ACGTTAGCATGCC"
     */
    Sequence seq6 = seq5 + 'C';
    if (!verifySequence(seq6, "adder", "ACGTTAGCATGCC")) {
        cerr << "[FAIL] operator+ (const Sequence&, const char)" << endl;
        ret = -1;
    }

    /*
     * string "TAGC" + seq2
     * result : header="adder", seq="TAGCACGT"
     */
    Sequence seq7 = "TAGC" + seq2;
    if (!verifySequence(seq7, "adder", "TAGCACGT")) {
        cerr << "[FAIL] operator+ (const std::string&, const Sequence&)" << endl;
        ret = -1;
    }

    /*
     * character array "ATGC" + seq7
     * result : header="adder", "ATGCTAGCACGT"
     */
    Sequence seq8 = tmp2 + seq7;
    if (!verifySequence(seq8, "adder", "ATGCTAGCACGT")) {
        cerr << "[FAIL] operator+ (const char *, const Sequence&)" << endl;
        ret = -1;
    }

    /*
     * cheacter 'A' + seq8
     * result : header="adder", "AATGCTAGCACGT"
     */
    Sequence seq9 = 'A' + seq8;
    if (!verifySequence(seq9, "adder", "AATGCTAGCACGT")) {
        cerr << "[FAIL] operator+ (const char, const Sequence&)" << endl;
        ret = -1;
    }

    return ret;
}
