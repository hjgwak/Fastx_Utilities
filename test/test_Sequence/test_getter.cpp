//
// Created by Kelvin on 12/12/2016.
//

#include <iostream>
#include "Sequence.h"

using namespace std;

int main() {
    int ret = 0;
    /*
     * make test Sequence object
     * name="test", seq="AGTCTCGAACGTTAGC"
     */
    string sequence = "AGTCTCGAACGTTAGC";
    Sequence seq = Sequence("test", sequence);

    /*
     * get header from seq
     * result : "test"
     */
    if (seq.getHeader() != "test") {
        cerr << "[FAIL] getHeader() const" << endl;
        ret = -1;
    }

    /*
     * get length from seq
     * result : 16
     */
    if (seq.length() != sequence.length()) {
        cerr << "[FAIL] length() const" << endl;
        ret = -1;
    }

    /*
     * get sequence from seq
     * result : "AGTCTCGAACGTTAGC"
     */
    if (seq.seq() != "AGTCTCGAACGTTAGC") {
        cerr << "[FAIL] seq() const" << endl;
        ret = -1;
    }

    /*
     * get sub-sequence (4 ~ 7) from seq
     * result : "TCGA"
     */
    if (seq.sub_seq(4, 8) != "TCGA") {
        cerr << "[FAIL] sub_seq(const int, const int) const" << endl;
        cerr << "                  >= 0       > 0" << endl;
        ret = -1;
    }

    /*
     * get sub_sequence (8 ~ 11) from seq
     * result : "ACGT"
     */
    if (seq.sub_seq(8, -4) != "ACGT") {
        cerr << "[FAIL] sub_seq(const int, const int) const" << endl;
        cerr << "                  >= 0       <= 0" << endl;
        ret = -1;
    }

    /*
     * get sub_sequence (12 ~ 15) from seq
     * result : "TAGC"
     */
    if (seq.sub_seq(-4, seq.length()) != "TAGC") {
        cerr << "[FAIL] sub_seq(const int, const int) const" << endl;
        cerr << "                  < 0        > 0" << endl;
        ret = -1;
    }

    /*
     * get sub_sequence (8 ~ 11) from seq
     * result : "ACGT"
     */
    if (seq.sub_seq(-8, -4) != "ACGT") {
        cerr << "[FAIL] sub_seq(const int, const int) const" << endl;
        cerr << "                  < 0        <= 0" << endl;
        ret = -1;
    }

    /*
     * error state when start position < length
     * result : "\0"
     */
    if (seq.sub_seq(-(seq.length() + 2), 3) != "\0") {
        cerr << "[FAIL] sub_seq(const int, const int) const" << endl;
        cerr << "       start position < length, but not return \"\\0\"";
        ret = -1;
    }

    /*
     * error state when end position < length
     * result : "\0"
     */
    if (seq.sub_seq(2, -(seq.length() + 2)) != "\0") {
        cerr << "[FAIL] sub_seq(const int, const int) const" << endl;
        cerr << "       end position < length, but not return \"\\0\"";
        ret = -1;
    }

    /*
     * get nucleotide seq[4]
     * result : 'T'
     */
    char ch = seq[4];
    if (ch != 'T') {
        cerr << "[FAIL] operator[] (const int pos)" << endl;
        cerr << "                        >= 0" << endl;
        ret = -1;
    }

    /*
     * get nucleotide seq[-4]
     * result : 'T'
     */
    ch = seq[-4];
    if (ch != 'T') {
        cerr << "[FAIL] operator[] (const int pos)" << endl;
        cerr << "                        < 0" << endl;
        ret = -1;
    }

    /*
     * error state when position > length
     * result = '\0'
     */
    ch = seq[seq.length() + 2];
    if (ch != '\0') {
        cerr << "[FAIL] operator[] (const int pos)" << endl;
        cerr << "       pos > length, but not return '\\0'";
        ret = -1;
    }

    /*
     * error state when position < 0
     * result = '\0'
     */
    ch = seq[-(seq.length() + 2)];
    if (ch != '\0') {
        cerr << "[FAIL] operator[] (const int pos)" << endl;
        cerr << "       pos < 0, but not return '\0'";
        ret = -1;
    }

    /*
     * get const nucleotide seq[4]
     * result : 'T'
     */
    const char ch2 = seq[4];
    if (ch2 != 'T') {
        cerr << "[FAIL] operator[] (const int pos) const" << endl;
        cerr << "                       >= 0" << endl;
        ret = -1;
    }

    /*
     * get nucleotide seq[-4]
     * result : 'T'
     */
    const char ch3 = seq[-4];
    if (ch3 != 'T') {
        cerr << "[FAIL] operator[] (const int pos) const" << endl;
        cerr << "                        < 0" << endl;
        ret = -1;
    }

    /*
     * error state when position > length
     * result = '\0'
     */
    const char ch4 = seq[seq.length() + 2];
    if (ch4 != '\0') {
        cerr << "[FAIL] operator[] (const int pos) const" << endl;
        cerr << "       pos > length, but not return '\\0'";
        ret = -1;
    }

    /*
     * error state when position < 0
     * result = '\0'
     */
    const char ch5 = seq[-(seq.length() + 2)];
    if (ch5 != '\0') {
        cerr << "[FAIL] operator[] (const int pos) const" << endl;
        cerr << "       pos < 0, but not return '\0'";
        ret = -1;
    }

    return ret;
}