//
// Created by Kelvin on 10/11/2016.
//

#include "Fasta.h"

//Constructor
Fasta::Fasta() : Sequence() {
    this->DB_type = DBType::none;
    this->Extension_type = ExtType::none;
}

Fasta::Fasta(const std::string &header, const std::string &sequence, const DBType db_type,
             const ExtType extension_type) : Sequence(header, sequence) {
    this->DB_type = db_type;
    this->Extension_type = extension_type;
}

Fasta::Fasta(const std::string &header, const char *sequence, const DBType db_type,
             const ExtType extension_type) : Sequence(header, sequence) {
    this->DB_type = db_type;
    this->Extension_type = extension_type;
}

Fasta::Fasta(const std::string &header, const char sequence, const DBType db_type,
             const ExtType extension_type) : Sequence(header, sequence) {
    this->DB_type = db_type;
    this->Extension_type = extension_type;
}

Fasta::Fasta(const Sequence &seq, const DBType db_type, const ExtType extension_type)
        : Sequence(seq) {
    this->DB_type = db_type;
    this->Extension_type = extension_type;
}

Fasta::Fasta(const Fasta &fasta) : Sequence(fasta.getHeader(), fasta.seq()) {
    this->DB_type = fasta.DB_type;
    this->Extension_type = fasta.Extension_type;
}

Fasta &Fasta::operator=(const std::string& sequence) {
    this->sequence = sequence;

    return *this;
}

Fasta &Fasta::operator=(const char* sequence) {
    this->sequence = sequence;

    return *this;
}

Fasta &Fasta::operator=(const char c) {
    this->sequence = c;

    return *this;
}

Fasta &Fasta::operator=(const Sequence& sequence) {
    this->header = sequence.getHeader();
    this->sequence = sequence.seq();

    return *this;
}

Fasta &Fasta::operator=(const Fasta &fasta) {
    this->header = fasta.getHeader();
    this->sequence = fasta.seq();

    this->DB_type = fasta.DB_type;
    this->Extension_type = fasta.Extension_type;

    return *this;
}

//Setter
void Fasta::setDBType(const DBType db_type) {
    this->DB_type = db_type;
}

void Fasta::setExtType(const ExtType extension_type) {
    this->Extension_type = extension_type;
}

void Fasta::append(const std::string& seq) {
    this->sequence += seq;
}

void Fasta::append(const Sequence& seq) {
    this->sequence += seq.seq();
}

void Fasta::append(const char* seq) {
    this->sequence += seq;
}

void Fasta::append(const char c) {
    this->sequence += c;
}

void Fasta::append(const Fasta &fasta) {
    this->sequence += fasta.seq();
}

//Getter
DBType Fasta::getDBType() const {
    return this->DB_type;
}

ExtType Fasta::getExtType() const {
    return this->Extension_type;
}

/*
std::map<std::string, std::string> Fasta::parseHeader() const {
    return __1::map<std::string, std::string>();
}
*/

//Operators
Fasta &Fasta::operator+=(const std::string& sequence) {
    this->sequence += sequence;

    return *this;
}

Fasta &Fasta::operator+=(const char* sequence) {
    this->sequence += sequence;

    return *this;
}

Fasta &Fasta::operator+=(const char c) {
    this->sequence += c;

    return *this;
}

Fasta &Fasta::operator+=(const Sequence& sequence) {
    this->sequence += sequence.seq();

    return *this;
}

Fasta &Fasta::operator+=(const Fasta &fasta) {
    this->sequence += fasta.seq();

    return *this;
}

/*
bool Fasta::charCheck() {
    return false;
}
*/

Fasta Fasta::operator+ (const Fasta& rhs) {
    Fasta new_fasta(*this);
    new_fasta += rhs;

    return new_fasta;
}

Fasta Fasta::operator+ (const Sequence& rhs) {
    Fasta new_fasta(*this);
    new_fasta += rhs;

    return new_fasta;
}

Fasta Fasta::operator+ (const std::string& rhs) {
    Fasta new_fasta(*this);
    new_fasta += rhs;

    return new_fasta;
}

Fasta Fasta::operator+ (const char* rhs) {
    Fasta new_fasta(*this);
    new_fasta += rhs;

    return new_fasta;
}

Fasta Fasta::operator+ (const char rhs) {
    Fasta new_fasta(*this);
    new_fasta += rhs;

    return new_fasta;
}


Fasta operator+ (const Sequence& lhs, const Fasta& rhs) {
    Fasta new_fasta(lhs);
    new_fasta += rhs;

    return new_fasta;
}

Fasta operator+ (const std::string& lhs, const Fasta& rhs) {
    Fasta new_fasta(rhs.getHeader(), lhs);
    new_fasta += rhs;

    return new_fasta;
}

Fasta operator+ (const char* lhs, const Fasta& rhs) {
    Fasta new_fasta(rhs.getHeader(), lhs);
    new_fasta += rhs;

    return new_fasta;
}

Fasta operator+ (const char lhs, const Fasta& rhs) {
    Fasta new_fasta(rhs.getHeader(), lhs);
    new_fasta += rhs;

    return new_fasta;
}
