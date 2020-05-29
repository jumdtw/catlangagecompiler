#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include "../include/tokenize.hpp"




int lvar_len(char *p){
    int len = 0;
    for(;;){
        if(('a' <= *p && *p <= 'z')||('A'<=*p && *p<='Z'||'0'<=*p && *p <= '9')){
            p++;
            len++;
        }else{
            return len;
        }
    }
}

int is_alnum(char c){
    return  ('a' <= c && c <= 'z') ||
            ('A' <= c && c <= 'Z') ||
            ('0' <= c && c <= '9') ||
            (c == '_');
}

//pが指名しているボジ列をトークンに分割してtokensに保存する
void tokenize(char *p){
    int i = 0;
    Token end;
    char sete[] = "==",setne[] = "!=",setle[] = "<=",setle_re[] = ">=",hex[] = "0x",bin[] = "0b";
    while(*p){
        Token token;
        //空白文字をスキップ
        if(isspace(*p)||*p=='\n'||*p=='\t'){
            p++;
            continue;
        }

        // ステーキの判別
        if(strncmp(p,"purrmeowmeow",12)==0&&!is_alnum(p[12])){
            token.ty = TK_MEET;
            token.str = p;
            p+=12;
            tokens.push_back(token);
            continue;
        }
        // hello文の判別
        if(strncmp(p,"purrmeowpurr",12)==0&&!is_alnum(p[12])){
            token.ty = TK_HELLO;
            token.str = p;
            p+=12;
            tokens.push_back(token);
            continue;
        }
        // 疲れたの判別
        if(strncmp(p,"purrpurrpurr",12)==0&&!is_alnum(p[12])){
            token.ty = TK_TIRED;
            token.str = p;
            p+=12;
            tokens.push_back(token);
            continue;
        }

        // +の判別
        if(strncmp(p,"roarmeow",8)==0&&!is_alnum(p[8])){
            token.ty = TK_PLUS;
            token.str = p;
            p+=8;
            tokens.push_back(token);
            continue;
        }
        // -の判別
        if(strncmp(p,"roarpurr",8)==0&&!is_alnum(p[8])){
            token.ty = TK_MINUS;
            token.str = p;
            p+=8;
            tokens.push_back(token);
            continue;
        }
        
        // 数値の判別
        // 0
        if(strncmp(p,"meowmeowmeowmeow",16)==0&&!is_alnum(p[16])){
            token.ty = TK_NUM;
            token.val = 0;
            token.str = p;
            p+=16;
            tokens.push_back(token);
            continue;
        }
        // 1
        if(strncmp(p,"meowmeowmeowpurr",16)==0&&!is_alnum(p[16])){
            token.ty = TK_NUM;
            token.val = 1;
            token.str = p;
            p+=16;
            tokens.push_back(token);
            continue;
        }
        // 2
        if(strncmp(p,"meowmeowpurrmeow",16)==0&&!is_alnum(p[16])){
            token.ty = TK_NUM;
            token.val = 2;
            token.str = p;
            p+=16;
            tokens.push_back(token);
            continue;
        }
        // 3
        if(strncmp(p,"meowmeowpurrpurr",16)==0&&!is_alnum(p[16])){
            token.ty = TK_NUM;
            token.val = 3;
            token.str = p;
            p+=16;
            tokens.push_back(token);
            continue;
        }
        // 4
        if(strncmp(p,"meowpurrmeowmeow",16)==0&&!is_alnum(p[16])){
            token.ty = TK_NUM;
            token.val = 4;
            token.str = p;
            p+=16;
            tokens.push_back(token);
            continue;
        }
        // 5
        if(strncmp(p,"meowpurrmeowpurr",16)==0&&!is_alnum(p[16])){
            token.ty = TK_NUM;
            token.val = 5;
            token.str = p;
            p+=16;
            tokens.push_back(token);
            continue;
        }
        // 6
        if(strncmp(p,"meowpurrpurrmeow",16)==0&&!is_alnum(p[16])){
            token.ty = TK_NUM;
            token.val = 6;
            token.str = p;
            p+=16;
            tokens.push_back(token);
            continue;
        }
        // 7
        if(strncmp(p,"meowpurrpurrpurr",16)==0&&!is_alnum(p[16])){
            token.ty = TK_NUM;
            token.val = 7;
            token.str = p;
            p+=16;
            tokens.push_back(token);
            continue;
        }


        fprintf(stderr,"トークンナイズできません: %s\n",p);
        exit(1);
    }
    end.ty = TK_EOF;
    tokens.push_back(end);
    
    return;
}
