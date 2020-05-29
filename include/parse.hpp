#ifndef PARSE_HPP
#define PARSE_HPP


#include<vector>

enum{
    ND_NUM = 4334,
    ND_MEET,
    ND_HELLO,
    ND_TIRED,
    ND_PLUS,
    ND_MINUS,
    ND_EOF,  
};


typedef struct Node Node;
typedef struct LVar LVar;
typedef struct LFunc LFunc;
typedef struct Type Type;

struct Node{
    int ty;
    int val;
    int offset;
    int len;
    std::vector<Node*> stmts;
    Node *lhs;
    Node *rhs;
    char *str;
};

struct Type{
    int type;
    Type *ptr_to;
    int array_size;
};

struct LVar{
    Type *lvar_type;  // 変数の型
    char *name; //変数名
    int len;    //name.len()
    int val;
    int offset; //
};

struct LFunc{
    Type *lvar_type;  // 関数の型
    int len;
    int val;
    // 構文木がここにはいっている
    Node *code;
    // ローカル変数リスト
    std::vector<LVar*> lvar_locals;
    char *name;
};

// ローカル関数リスト
extern std::vector<LVar*> locals;
// 関数リスト
extern std::vector<LFunc*> funcs;

#endif 