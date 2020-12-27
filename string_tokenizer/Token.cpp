/*
 * Author: Brendan Chess
 * Project: String Tokenizer
 * Purpose: Recover every token from a string for processing
 * Notes: Does not support extended ASCII characters
 */

#include "Token.h"

Token::Token() {
    _token = "";
    _type = -1;
}

Token::Token(string str, int type) {
    _token = str;
    _type = type;
}

ostream& operator<<(ostream &outs, const Token &t) {
    outs << "|" + t._token + "|";
    return outs;
}

int Token::type() {
    return _type;
}

string Token::type_string() {
    switch (_type){
        case 10:
            return "ALPHA";
        case 20:
            return "PUNCT";
        case 30:
            return "SPACE";
        case 40:
        case 55:
            return "NUMBER";
        case 50:
            return "SYMBOL";
        default:
            return "UNKNOWN";
    }
}

string Token::token_str() {
    return _token;
}
