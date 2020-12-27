/*
 * Author: Brendan Chess
 * Project: File Tokenizer
 * Purpose: Retrieve tokens from a file
 * Notes: None
 */

#include <iostream>
#include "FTokenizer.h"
#include <iomanip>

int main() {
    Token t;
    FTokenizer ftk("testing.txt");

    ftk>>t;

    int token_count = 0;
    while (ftk.more()){
        if (t.type_string()=="ALPHA" ){
            token_count++;
            cout<<setw(10)<<token_count
                <<setw(3)<<left<<":"<<setw(25)<<left<<t.token_str()
                <<t.type_string()<<endl;
        }
        ftk>>t;
    }
    cout<<"Tokens Found: "<<token_count<<endl;
    cout<<"=========="<<endl;
}
