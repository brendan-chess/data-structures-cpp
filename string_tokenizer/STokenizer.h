/*
 * Author: Brendan Chess
 * Project: String Tokenizer
 * Purpose: Recover every token from a string for processing
 * Notes: Does not support extended ASCII characters
 */

#ifndef STRING_TOKENIZER_STOKENIZER_H
#define STRING_TOKENIZER_STOKENIZER_H

#include <string>
#include "Token.h"
#include "table.h"

using namespace std;

//const int MAX_ROWS = 60;
//const int MAX_COLUMNS = 128;
//const int MAX_BUFFER = 5000;

class STokenizer
{
public:
    STokenizer();
    STokenizer(char str[]);
    bool done();            //true: there are no more tokens
    bool more();            //true: there are more tokens
    //

    //---------------
    //extract one token (very similar to the way cin >> works)
    friend STokenizer& operator >> (STokenizer& s, Token& t);
//
    //set a new string as the input string
    void set_string(char str[]);

private:
    //create table for all the tokens we will recognize
    //                      (e.g. doubles, words, etc.)
    void make_table(int _table[][MAX_COLUMNS]);

    //extract the longest string that match
    //     one of the acceptable token types
    bool get_token(int &start_state, string& token);
    //---------------------------------
    int _buffer_length;
    char _buffer[MAX_BUFFER];       //input string
    int _pos;                       //current position in the string
    static int _table[MAX_ROWS][MAX_COLUMNS];
};

int STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

STokenizer::STokenizer() {
    _pos = 0;
    init_table(_table);
    make_table(_table);
}

STokenizer::STokenizer(char *str) {
    _pos = 0;
    init_table(_table);
    make_table(_table);

    strcpy(_buffer, str);
    _buffer_length = strlen(_buffer);
}

bool STokenizer::done() {
    if(_pos > _buffer_length) return true;
    return false;
}

bool STokenizer::more() {
    if(_pos > _buffer_length) return false;
    return true;
}

STokenizer &operator>>(STokenizer &s, Token &t) {
    string token = "";
    int state = 0;
    s.get_token(state, token);
    t = Token(token, state);
    return s;
}

void STokenizer::set_string(char *str) {
    strcpy(_buffer, str);
    _buffer_length = strlen(_buffer);
}

void STokenizer::make_table(int _table[][MAX_COLUMNS]) {
    //letters
    mark_cells(0, _table, 'A', 'Z', 10);
    mark_cells(10, _table, 'A', 'Z', 10);
    mark_cells(0, _table, 'a', 'z', 10);
    mark_cells(10, _table, 'a', 'z', 10);
    mark_cell(10, _table, '\'', 11);
    mark_cells(11, _table, 'A', 'Z', 10);
    mark_cells(11, _table, 'a', 'z', 10);
    mark_success(_table, 10);

    //spaces
    mark_cell(0, _table, ' ', 30);
    mark_cell(30, _table, ' ', 30);
    mark_success(_table, 30);

    //punctuation
    char punctuation[] = "!\"\',.:;?";
    mark_cells(0, _table, punctuation, 20);
    mark_success(_table, 20);

    //numbers
    mark_cells(0, _table, '0', '9', 40);
    mark_cells(40, _table, '0', '9', 40);
    mark_cell(40,_table, '.', 41);
    mark_cells(41, _table, '0', '9', 55);
    mark_cells(55, _table, '0', '9', 55);
    mark_success(_table, 40);
    mark_success(_table, 55);

    //symbols
    char symbols[] = "@#$%^&*()_-+=`~[{]}|\\<>/";
    mark_cells(0, _table, symbols, 50);
    mark_success(_table, 50);

}

bool STokenizer::get_token(int &start_state, string &token) {
    string current_token = "";
    int state = start_state;
    int last_success_position = -1;
    char current_char;
    bool success = false;

    for(int i = _pos; i < MAX_BUFFER; ++i){
        //Get next character in buffer
        current_char = _buffer[i];

        if((int) current_char > 127 || (int) current_char < 0){
            current_char = '?';
        }

        state = _table[state][current_char];

        //If we hit the null char, and have a token, break
        //Else, we reached the end of the buffer, increment pos past null
        if(current_char == 0 && last_success_position != -1){
            break;
        } else if (current_char == 0){
            _pos++;
            break;
        }

        //Break at a fail state
        if(state == -1) break;

        //Add passing characters to the potential token
        current_token += current_char;

        //If success state, write to token
        if(is_success(_table, state)){
            //Record if we had a success yet
            last_success_position = i;
            token = current_token;
            success = true;
            start_state = state;
            _pos = i + 1;
        }
    }


    return success;
}

#endif //STRING_TOKENIZER_STOKENIZER_H
