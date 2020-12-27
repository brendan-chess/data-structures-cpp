#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ROWS = 4;
const int MAX_COLUMNS = 128;
int table[MAX_ROWS][MAX_COLUMNS];

void init_table(int _table[][MAX_COLUMNS]);
void mark_success(int _table[][MAX_COLUMNS], int state);
void mark_fail(int _table[][MAX_COLUMNS], int state);
bool is_success(int _table[][MAX_COLUMNS], int state);
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state);
//void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state);
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state);
void print_table(int _table[][MAX_COLUMNS]);
void get_token(int _table[][MAX_COLUMNS], string input, int &position);

int main() {
    init_table(table);
    mark_success(table, 1);
    mark_success(table, 3);
    mark_cell(0, table, 97, 1);
    mark_cell(0, table, 98, 2);
    mark_cell(1, table, 97, 1);
    mark_cell(1, table, 98, 2);
    mark_cell(2, table, 97, 3);
    mark_cell(3, table, 97, 3);
    print_table(table);

    int position = 0;
    string phrase = "aaabaaaccccaabaa";

    get_token(table, phrase, position);
    get_token(table, phrase, position);
}

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
    //assert(state < MAX_ROWS);
    if(_table[state][0] == 1) return true;
    return false;
}

//Mark a range of cells in the array.
void mark_cells(int row, int _table[][MAX_COLUMNS], int from, int to, int state){
    for (int column = from; column < to; ++column) {
        _table[row][column] = state;
    }
}

//Mark columns represented by the string columns[] for this row
void mark_cells(int row, int _table[][MAX_COLUMNS], const char columns[], int state);

//Mark this row and column
void mark_cell(int row, int _table[][MAX_COLUMNS], int column, int state){
    _table[row][column] = state;
}

//This can realistically be used on a small table
void print_table(int _table[][MAX_COLUMNS]){
    const char separator = ' ';
    const int cellWidth = 3;

    //print column titles
//    cout << " " << left << setw(cellWidth) << setfill(separator) << "S? |";
//    for (char header = 32; header < 127; ++header) {
//        cout << " " << left << setw(cellWidth) << setfill(separator) << header << "|";
//    }
//    cout << endl;

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

void get_token(int _table[][MAX_COLUMNS], string input, int &position){

    string token = "";
    string success_token = "";
    int state = 0;
    //int last_success_position;
    int last_success_position = -1;
    char current_char;
    for (int i = position; i < input.length(); ++i) {
        current_char = input[i];
        if(state == -1) state = 0;
        state = _table[state][current_char];
        if(state == -1 && last_success_position != -1) break;
        if(state != -1) token += current_char;
        position++;
        if(is_success(_table, state)){
            last_success_position = i;
            success_token = token;
        }
    }

    cout<<token<<endl;
    cout<<success_token<<endl;
    cout<<position<<endl;
    cout<<last_success_position<<endl;
}