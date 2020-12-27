#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include "../bplustree/Map.h"
#include "../bplustree/MMap.h"
#include "../string_tokenizer/STokenizer.h"

typedef vector<string> vector_str;

class Parser{
public:
    Parser(char* query);
    MMap<string, string> ptree();
private:
    //static const int ROWS = 5, COLS = 5;
    //enum matrix_indices { select = 0, star = 1, from = 2, symbol = 3 };
    int matrix[MAX_ROWS][MAX_COLUMNS];

    MMap<string, string> parse_tree;
    Map<string, int> keywords; //which columns in the matrix match each reserved word
    vector<string> input_list;
    char* buffer;
    bool fail;

    void make_matrix();
    void build_keyword_map();
    void set_string();
    bool get_parse_tree();
};

Parser::Parser(char* query) {
    //save query to buffer
    buffer = new char[strlen(query)]; //allocate memory before copying
    strcpy(buffer, query);

    //build state machine
    make_matrix();

    //build keywords map
    build_keyword_map();

    //tokenize buffer
    set_string();
}

MMap<string, string> Parser::ptree() {
    return parse_tree;
}

void Parser::make_matrix() {
    init_table(matrix);

    mark_cell(0, matrix, 1, 1);
    mark_cell(1, matrix, 2, 2);
    mark_cell(1, matrix, 13, 2);
    mark_cell(2, matrix, 3, 1);
    mark_cell(2, matrix, 4, 3);
    mark_cell(3, matrix, 13, 4);
    mark_success(matrix, 4);
    mark_cell(4, matrix, 5, 5);
    mark_cell(5, matrix, 13, 6);
    mark_cells(6, matrix, 6, 10, 7);
    mark_cell(7, matrix, 13, 8);
    mark_success(matrix, 8);
    mark_cells(8, matrix, 11, 12, 5);
}

void Parser::build_keyword_map() {
    keywords.insert("select", 1);
    keywords.insert("*", 2);
    keywords.insert(",", 3);
    keywords.insert("from", 4);
    keywords.insert("where", 5);
    keywords.insert("=", 6);
    keywords.insert(">", 7);
    keywords.insert("<", 8);
    keywords.insert(">=", 9);
    keywords.insert("<=", 10);
    keywords.insert("or", 11);
    keywords.insert("and", 12);
}

void Parser::set_string() {
    //fill input_list with each token in the query
    //i.e. break down the important words in the query
    STokenizer stk(buffer);
    Token t;

    stk >> t;
    while(stk.more()){
        if(t.token_str() != " ") //ignore whitespace
            input_list.push_back(t.token_str());
        t = Token();
        stk >> t;
    }

    fail = get_parse_tree(); //check that we recieved a valid query
}

bool Parser::get_parse_tree() {
    int state = 0;

    //process each token in the query
    for (int i = 0; i < input_list.size(); ++i) {
        string token = input_list[i];
        //check if the token is a reserved word (keyword) or a symbol before getting the new state
        if(keywords.contains(token)){
            state = matrix[state][keywords[token]];
        } else {
            state = matrix[state][13]; //col 13 is symbol
        }

        if(state == -1) { //invalid queries go here
            parse_tree.clear();
            return false;
        }

        //each case is the column in the matrix
        switch (state){
            case 1:
                parse_tree.insert("command", token);
                break;
            case 2:
                parse_tree.insert("fields", token);
                break;
            case 4:
                parse_tree.insert("table", token);
                break;
            case 5:
                if(token == "and" || token == "or")
                    parse_tree.insert("conditions", token);
                else
                    parse_tree.insert("where", "yes");
                break;
            case 6:
            case 7:
            case 8:
                parse_tree.insert("conditions", token);
                break;
        }
    }

    return true;
}

#endif //PARSER_PARSER_H
