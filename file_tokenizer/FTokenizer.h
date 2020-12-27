/*
 * Author: Brendan Chess
 * Project: File Tokenizer
 * Purpose: Retrieve tokens from a file
 * Notes: None
 */
#ifndef FILE_TOKENIZER_FTOKENIZER_H
#define FILE_TOKENIZER_FTOKENIZER_H

#include <fstream>
#include <iostream>
#include "STokenizer.h"
using namespace std;


class FTokenizer {
public:
    const int MAX_BLOCK = MAX_BUFFER;
    FTokenizer(char* fname);
    Token next_token();
    bool more();        //returns the current value of _more
    int pos();          //returns the value of _pos
    int block_pos();     //returns the value of _blockPos
    friend FTokenizer& operator >> (FTokenizer& f, Token& t);
private:
    bool get_new_block(); //gets the new block from the file
    std::ifstream _f;   //file being tokenized
    STokenizer _stk;     //The STokenizer object to tokenize current block
    int _pos;           //Current position in the file
    int _blockPos;      //Current position in the current block
    bool _more;         //false if last token of the last block
    //  has been processed and now we are at
    //  the end of the last block.
};

FTokenizer::FTokenizer(char *fname) {
    _f.open(fname);
    if(_f.fail()){
        cout << "Failed to open file" << endl;
    } else {
        cout << "Opened file successfully" << endl;
    }

    //get first block
    _more = get_new_block();
}

Token FTokenizer::next_token() {
    return Token();
}

bool FTokenizer::more() {
    return _more;
}

int FTokenizer::pos() {
    return _pos;
}

int FTokenizer::block_pos() {
    return _blockPos;
}

FTokenizer &operator>>(FTokenizer &f, Token &t) {
    //if stk isn't empty yet, insert normally
    //else, retrieve the next block, which refills stk
    if(f._stk.more()){
        f._stk >> t;
    } else {
        f._more = f.get_new_block();
    }

    return f;
}

bool FTokenizer::get_new_block() {
    //buffer stores the block of text in this scope
    char buffer[MAX_BUFFER + 1];

    //move file cursor to the beginning of the next block
    //without this, the file is read from the beginning each time
    _f.seekg(_pos);

    _f.read(buffer, MAX_BUFFER - 1);

    //save file cursor position
    _pos += _f.gcount();

    //add null char to buffer to help processing in stk
    buffer[_f.gcount()] = NULL;

    //refill stk
    _stk.set_string(buffer);

    //true if text was retrieved, false if not
    //used to determine if we hit the end of the file
    return _f.gcount() != 0;
}



#endif //FILE_TOKENIZER_FTOKENIZER_H
