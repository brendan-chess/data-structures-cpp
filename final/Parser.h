/*
 * Author: Brendan Chess
 * Project: Final Project
 * Purpose: Implement a database that responds to SQL commands on the command
 *      line or from a batch file
 */
#ifndef DATABASE_PARSER_H
#define DATABASE_PARSER_H

#include "Map.h"
#include "MMap.h"
#include "STokenizer.h"

typedef vector<string> vector_str;

class Parser{
public:
    Parser(char* query);
    MMap<string, string> ptree();
    bool is_valid() { return fail; }
private:
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

    //select
    mark_cell(0, matrix, 1, 1);
    mark_cell(1, matrix, 2, 2);
    mark_cell(1, matrix, 13, 2);
    mark_cell(2, matrix, 3, 1);
    mark_cell(2, matrix, 4, 3);
    mark_cell(3, matrix, 13, 4);
    mark_success(matrix, 4);
    mark_cell(4, matrix, 5, 5);
    mark_cell(5, matrix, 13, 6);
    mark_cell(5, matrix, 22, 5); //
    mark_cells(6, matrix, 6, 10, 7);
    mark_cell(7, matrix, 13, 8);
    mark_success(matrix, 8);
    mark_cells(8, matrix, 11, 12, 5);
    mark_cell(8, matrix, 23, 8);

    //insert
    mark_cell(0, matrix, 14, 20);
    mark_cell(20, matrix, 15, 21);
    mark_cell(21, matrix, 13, 22);
    mark_cell(22, matrix, 16, 23);
    mark_cell(23, matrix, 13, 24);
    mark_success(matrix, 24);
    mark_cell(24, matrix, 3, 23);

    //create/make
    mark_cell(0, matrix, 17, 30);
    mark_cell(0, matrix, 18, 30);
    mark_cell(30, matrix, 19, 31);
    mark_cell(31, matrix, 13, 32);
    mark_cell(32, matrix, 20, 33);
    mark_cell(33, matrix, 13, 34);
    mark_success(matrix, 34);
    mark_cell(34, matrix, 3, 33);

    //drop
    mark_cell(0, matrix, 21, 40);
    mark_cell(40, matrix, 19, 41);
    mark_cell(41, matrix, 13, 42);
    mark_success(matrix, 42);

    //batch
    mark_cell(0, matrix, 24, 50);
    mark_cell(50, matrix, 13, 51);
    mark_success(matrix, 51);

    //delete
    mark_cell(0, matrix, 25, 2);
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
    //column 13 is symbol
    keywords.insert("insert", 14);
    keywords.insert("into", 15);
    keywords.insert("values", 16);
    keywords.insert("create", 17);
    keywords.insert("make", 18);
    keywords.insert("table", 19);
    keywords.insert("fields", 20);
    keywords.insert("drop", 21);
    keywords.insert("(", 22);
    keywords.insert(")", 23);
    keywords.insert("batch", 24);
    keywords.insert("delete", 25);
}

void Parser::set_string() {
    //fill input_list with each token in the query
    //i.e. break down the important words in the query
    STokenizer stk(buffer);
    Token t;

    stk >> t;
    while(stk.more()){
        if(t.token_str() != " " && t.token_str() != "\t") //ignore whitespace
            input_list.push_back(t.token_str());
        t = Token();
        stk >> t;
    }

    fail = get_parse_tree(); //check that we received a valid query
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
            case 20:
            case 30:
            case 40:
            case 50:
                parse_tree.insert("command", token);
                break;
            case 2:
                if(token == "delete")
                    parse_tree.insert("command", token);
                else
                    parse_tree.insert("fields", token);
                break;
            case 34:
                parse_tree.insert("fields", token);
                break;
            case 4:
            case 22:
            case 32:
            case 42:
                parse_tree.insert("table", token);
                break;
            case 5:
                if(token == "and" || token == "or")
                    parse_tree.insert("conditions", token);
                else if(token == "where")
                    parse_tree.insert("where", "yes");
                else if(token == "(")
                    parse_tree.insert("conditions", token);
                break;
            case 6:
            case 7:
            case 8:
                parse_tree.insert("conditions", token);
                break;
            case 24:
            case 51:
                parse_tree.insert("data", token);
                break;
        }
    }

    return true;
}

#endif //DATABASE_PARSER_H
