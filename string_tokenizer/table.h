/*
 * Author: Brendan Chess
 * Project: String Tokenizer
 * Purpose: Recover every token from a string for processing
 * Notes: Does not support extended ASCII characters
 */

#ifndef STRING_TOKENIZER_TABLE_H
#define STRING_TOKENIZER_TABLE_H

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ROWS = 60;
const int MAX_COLUMNS = 128;
const int MAX_BUFFER = 5000;

void init_table(int _table[][MAX_COLUMNS]);
void mark_success(int _table[][MAX_COLUMNS], int state);
void mark_fail(int _table[][MAX_COLUMNS], int state);
bool is_success(int _table[][MAX_COLUMNS], int state);
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state);
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state);
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state);
void print_table(int _table[][MAX_COLUMNS]);
void get_token(int _table[][MAX_COLUMNS], string input, int &position);

//Fill all cells of the array with -1
void init_table(int _table[][MAX_COLUMNS]){
    for (int row = 0; row < MAX_ROWS; ++row) {
        for (int column = 0; column < MAX_COLUMNS; ++column) {
            if(column == 0){
                _table[row][column] = 0;
            } else {
                _table[row][column] = -1;
            }
        }
    }
}

//Mark this state (row) with a 1 (success)
void mark_success(int _table[][MAX_COLUMNS], int state){
    assert(state < MAX_ROWS);
    _table[state][0] = 1;
}

//Mark this state (row) with a 0 (fail)
void mark_fail(int _table[][MAX_COLUMNS], int state){
    assert(state < MAX_ROWS);
    _table[state][0] = 0;
}

//true if state is a success state
bool is_success(int _table[][MAX_COLUMNS], int state){
    if(_table[state][0] == 1) return true;
    return false;
}

//Mark a range of cells in the array.
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state){
    for (int column = from; column <= to; ++column) {
        _table[row][column] = state;
    }
}

//Mark columns represented by the string columns[] for this row
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state){
    int size = strlen(columns);
    for (int i = 0; i < size; ++i) {
        _table[row][columns[i]] = state;
    }
}

//Mark this row and column
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state){
    _table[row][column] = state;
}

//This can realistically be used on a small table
void print_table(int _table[][MAX_COLUMNS]){
    const char separator = ' ';
    const int cellWidth = 3;

    //print cells
    for (int row = 0; row < MAX_ROWS; ++row) {
        for (int column = 0; column < MAX_COLUMNS; ++column) {
            cout << " " << left << setw(cellWidth) << setfill(separator) << _table[row][column] << "|";
        }
        cout << endl;
    }
}

//show string s and mark this position on the string:
//hello world   pos: 7
//       ^
void show_string(char s[], int _pos);

#endif //STRING_TOKENIZER_TABLE_H
