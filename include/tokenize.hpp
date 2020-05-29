#ifndef TOKENIZE_HPP
#define TOKENIZE_HPP

#include<vector>

enum {
    TK_NUM = 73947,  //整数トークン
    TK_MEET,
    TK_HELLO,
    TK_TIRED,
    TK_PLUS,
    TK_MINUS,
    TK_EOF,        //入力の終わりを表すトークン
};

typedef struct {
    int ty;         //トークン型
    int val;        //tyがTK_NUMの場合、その数値
    char *str;    //トークン文字列
    int len;
}Token;

extern std::vector<Token> tokens;


void tokenize(char *p);

#endif