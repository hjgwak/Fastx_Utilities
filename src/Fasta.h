//
// Created by hjgwak(Kelvin) on 10/11/2016.
//

#ifndef SCL_FASTA_H
#define SCL_FASTA_H

#include "Sequence.h"
#include <map>

enum class DBType {
    gb, emb, dbj, pir, prf, sp, pdb, pat, bbs, gnl, ref, lcl, none
};

enum class ExtType {
    fasta, fna, ffn, faa, frn, none
};

class Fasta: public Sequence {
public:
    //Constructors
    Fasta();
    Fasta(const std::string& header, const std::string& sequence,
          const DBType db_type = DBType::none, const ExtType extension_type = ExtType::none);
    Fasta(const Sequence& seq, const DBType db_type = DBType::none, const ExtType extension_type = ExtType::none);
    Fasta(const Fasta& fasta);

    Fasta& operator=(const std::string& sequence);
    Fasta& operator=(const char* sequence);
    Fasta& operator=(const char c);
    Fasta& operator=(const Sequence& sequence);
    Fasta& operator=(const Fasta& fasta);

    //Setters
    void setDBType(const DBType db_type);
    void setExtType(const ExtType extension_type);
    void append(const std::string& seq);
    void append(const Sequence& seq);
    void append(const char* seq);
    void append(const char c);
    void append(const Fasta& fasta);

    //Getters
    /*
    std::map<std::string, std::string> parseHeader() const;
     */
    DBType getDBType() const;
    ExtType getExtType() const;

    //Operators
    Fasta& operator+=(const std::string& sequence);
    Fasta& operator+=(const char* sequence);
    Fasta& operator+=(const char c);
    Fasta& operator+=(const Sequence& sequence);
    Fasta& operator+=(const Fasta& fasta);

    Fasta operator+ (const Fasta& rhs);
    Fasta operator+ (const Sequence& rhs);
    Fasta operator+ (const std::string& rhs);
    Fasta operator+ (const char* rhs);
    Fasta operator+ (const char rhs);
private:
    /*
    bool charCheck();
     */

    DBType DB_type;
    ExtType Extension_type;
};

// Another operators
Fasta operator+ (const Sequence& lhs, const Fasta& rhs);
Fasta operator+ (const std::string& lhs, const Fasta& rhs);
Fasta operator+ (const char* lhs, const Fasta& rhs);
Fasta operator+ (const char lhs, const Fasta& rhs);
#endif //SCL_FASTA_H
