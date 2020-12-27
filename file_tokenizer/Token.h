/*
 * Author: Brendan Chess
 * Project: File Tokenizer
 * Purpose: Retrieve tokens from a file
 * Notes: None
 */
#ifndef FILE_TOKENIZER_TOKEN_H
#define FILE_TOKENIZER_TOKEN_H


#include <string>

using namespace std;

class Token
{
public:
    Token();
    Token(string str, int type);
    //output the value of the token
    friend ostream& operator <<(ostream& outs, const Token& t){
        outs << "|" + t._token + "|";
        return outs;
    }
    int type();
    string type_string();
    string token_str();
private:
    string _token;
    int _type;
};

Token::Token() {
    _token = "";
    _type = -1;
}

Token::Token(string str, int type) {
    _token = str;
    _type = type;
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



#endif //FILE_TOKENIZER_TOKEN_H
