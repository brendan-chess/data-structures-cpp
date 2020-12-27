/*
 * Author: Brendan Chess
 * Project: String Tokenizer
 * Purpose: Recover every token from a string for processing
 * Notes: Does not support extended ASCII characters
 */

#include <iostream>
#include "STokenizer.h"
#include <iomanip>

int main() {
    char s[] = "it was the night of òctober 17th. pi was still 3.14.";
    STokenizer stk(s);
    Token t;
    //The all too familiar golden while loop:
    stk>>t;
    while(stk.more()){
        //process token here...
        cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;

        t = Token();
        stk>>t;
    }
}
