//
// Created by Kelvin on 12/12/2016.
//

#include <iostream>
#include "Sequence.h"

using namespace std;

bool verifySequence(const Sequence& obj, const string& header, const string& seq) {
    return (obj.getHeader() == header && obj.seq() == seq);
}

void checkAnswer(const Sequence& obj, const string& header, const string& seq,
	const string& msg, int* ret) {
	if (!verifySequence(obj, header, seq)) {
		cerr << msg << endl;
		cerr << "       result : header=" + obj.getHeader() + ", seq=" + obj.seq() << endl;
		cerr << "       answer : header=" + header + ", seq=" + seq << endl;
		ret -= 1;
	}
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
	checkAnswer(seq3, "", "AGTCTCGAAACGTACGT",
		"[FAIL] operator+ (const Sequence&, const Sequence&)", &ret);

    /*
     * seq2 + string "TAGC"
     * result : header="adder", seq="ACGTTAGC"
     */
    Sequence seq4 = seq2 + "TAGC";
	checkAnswer(seq4, "adder", "ACGTTAGC",
		"[FAIL] operator+ (const Sequence&, const std::string&)", &ret);

    /*
     * seq4 + character array "ATGC"
     * result : header="adder", seq="ACGTTAGCATGC"
     */
    char tmp2[5] = "ATGC";
    Sequence seq5 = seq4 + tmp2;
	checkAnswer(seq5, "adder", "ACGTTAGCATGC",
		"[FAIL] operator+ (const Sequence&, const char *)", &ret);

    /*
     * seq5 + chracter 'C'
     * result : header="adder", seq="ACGTTAGCATGCC"
     */
    Sequence seq6 = seq5 + 'C';
	checkAnswer(seq6, "adder", "ACGTTAGCATGCC",
		"[FAIL] operator+ (const Sequence&, const char)", &ret);

    /*
     * string "TAGC" + seq2
     * result : header="adder", seq="TAGCACGT"
     */
    Sequence seq7 = "TAGC" + seq2;
	checkAnswer(seq7, "adder", "TAGCACGT", 
		"[FAIL] operator+ (const std::string&, const Sequence&)", &ret);

    /*
     * character array "ATGC" + seq7
     * result : header="adder", "ATGCTAGCACGT"
     */
    Sequence seq8 = tmp2 + seq7;
	checkAnswer(seq8, "adder", "ATGCTAGCACGT",
		"[FAIL] operator+ (const char *, const Sequence&)", &ret);

    /*
     * cheacter 'A' + seq8
     * result : header="adder", "AATGCTAGCACGT"
     */
    Sequence seq9 = 'A' + seq8;
	checkAnswer(seq9, "adder", "AATGCTAGCACGT",
		"[FAIL] operator+ (const char, const Sequence&)", &ret);

    return ret;
}
