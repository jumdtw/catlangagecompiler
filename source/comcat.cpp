
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <random>
#include "../include/tokenize.hpp"
#include "../include/parse.hpp"
#include "../include/file_controller.hpp"

Node *expr();
Node *add();

// ローカル関数リスト
std::vector<LVar*> locals;
// 関数リスト
std::vector<LFunc*> funcs;
// tokenizeの結果がここに入る
std::vector<Token> tokens;
int pos = 0;
int random_label = 0;
bool array_exist = false;


Node *new_node(int ty,Node *lhs, Node *rhs){
    Node *node = (Node *)malloc(sizeof(Node));
    node->ty = ty;
    node->lhs = lhs;
    node->rhs = rhs;
    return node;
}
 
Node *new_node_num(int val){
    Node *node = (Node *)malloc(sizeof(Node));
    node->ty = ND_NUM;
    node->val = val;
    node->lhs = NULL;
    node->rhs = NULL;
    return node;
}


bool consume(char *op){
    if(memcmp(tokens[pos].str,op,tokens[pos].len)){
        //printf("false %s\n",tokens[pos].str);
        return false;
    }
    pos++;
    return true;
}

void expect(char *p){
    if(!memcmp(tokens[pos].str,p,tokens[pos].len)){
        return;
    }
    printf("error expect %s is not %s\n",p,tokens[pos].str);
    exit(1);
}


Node *primary(){

    if(tokens[pos].ty == TK_NUM){
        return new_node_num(tokens[pos++].val);
    }

    printf("%s\n",tokens[pos].str);

    printf("error gen node\n");
    exit(1);
}

Node *add(){

    if(tokens[pos].ty==TK_MEET){
        return new_node(ND_MEET,NULL,NULL);
    }else if(tokens[pos].ty==TK_HELLO){
        return new_node(ND_HELLO,NULL,NULL);
    }else if(tokens[pos].ty==TK_TIRED){
        return new_node(ND_TIRED,NULL,NULL);
    }

    Node *node = primary();
    
    for(;;){
        if(tokens[pos].ty==TK_PLUS){
            pos++;
            node = new_node(ND_PLUS,node,primary());
        }else if(tokens[pos].ty==TK_MINUS){
            pos++;
            node = new_node(ND_MINUS,node,primary());
        }else{
            return node;
        }
    }

}

Node *expr(){
    return add();
}

void gen(Node *node){

    if(node->ty == ND_MEET){
        printf("    .text\n");
        printf(".LC0:\n");
        printf("	.ascii ");
        printf("\"");
        printf("I want meet.\\0");
        printf("\"");
        printf("\n");
        printf("	.globl	main\n");
        printf("	.def	main;	.scl	2;	.type	32;	.endef\n");
        printf("	.seh_proc	main\n");
        printf("main:\n");
        printf("	pushq	%%rbp\n");
        printf("	.seh_pushreg	%%rbp\n");
        printf("	movq	%%rsp, %%rbp\n");
        printf("	.seh_setframe	%%rbp, 0\n");
        printf("	subq	$32, %%rsp\n");
        printf("	.seh_stackalloc	32\n");
        printf("	.seh_endprologue\n");
        printf("	call	__main\n");
        printf("	leaq	.LC0(%%rip), %%rcx\n");
        printf("	call	puts\n");
        printf("	movl	$0, %%eax\n");
        printf("	addq	$32, %%rsp\n");
        printf("    popq	%%rbp\n");
        printf("	ret\n");
        printf("	.seh_endproc\n");
        return;
    }

    if(node->ty == ND_HELLO){
        printf("    .text\n");
        printf(".LC0:\n");
        printf("	.ascii ");
        printf("\"");
        printf("goodmorning.\\0");
        printf("\"");
        printf("\n");
        printf("	.globl	main\n");
        printf("	.def	main;	.scl	2;	.type	32;	.endef\n");
        printf("	.seh_proc	main\n");
        printf("main:\n");
        printf("	pushq	%%rbp\n");
        printf("	.seh_pushreg	%%rbp\n");
        printf("	movq	%%rsp, %%rbp\n");
        printf("	.seh_setframe	%%rbp, 0\n");
        printf("	subq	$32, %%rsp\n");
        printf("	.seh_stackalloc	32\n");
        printf("	.seh_endprologue\n");
        printf("	call	__main\n");
        printf("	leaq	.LC0(%%rip), %%rcx\n");
        printf("	call	puts\n");
        printf("	movl	$0, %%eax\n");
        printf("	addq	$32, %%rsp\n");
        printf("    popq	%%rbp\n");
        printf("	ret\n");
        printf("	.seh_endproc\n");
        return;
    }

    if(node->ty == ND_TIRED){
        printf("    .text\n");
        printf(".LC0:\n");
        printf("	.ascii ");
        printf("\"");
        printf("Im tired.\\0");
        printf("\"");
        printf("\n");
        printf("	.globl	main\n");
        printf("	.def	main;	.scl	2;	.type	32;	.endef\n");
        printf("	.seh_proc	main\n");
        printf("main:\n");
        printf("	pushq	%%rbp\n");
        printf("	.seh_pushreg	%%rbp\n");
        printf("	movq	%%rsp, %%rbp\n");
        printf("	.seh_setframe	%%rbp, 0\n");
        printf("	subq	$32, %%rsp\n");
        printf("	.seh_stackalloc	32\n");
        printf("	.seh_endprologue\n");
        printf("	call	__main\n");
        printf("	leaq	.LC0(%%rip), %%rcx\n");
        printf("	call	puts\n");
        printf("	movl	$0, %%eax\n");
        printf("	addq	$32, %%rsp\n");
        printf("    popq	%%rbp\n");
        printf("	ret\n");
        printf("	.seh_endproc\n");
        return;
    }

    if(node->ty == ND_NUM){
        printf("    push    $%%d\n",node->val);
        return;
    }

    printf("    .text\n");
    printf("	.def	__main;	.scl	2;	.type	32;	.endef\n");
    printf("	.globl	main\n");
    printf("	.def	main;	.scl	2;	.type	32;	.endef\n");
    printf("	.seh_proc	main\n");
    printf("main:\n");
    printf("	pushq	%%rbp\n");
    printf("	.seh_pushreg	%%rbp\n");
    printf("	movq	%%rsp, %%rbp\n");
    printf("	.seh_setframe	%%rbp, 0\n");
    printf("	subq	$32, %%rsp\n");
    printf("	.seh_stackalloc	32\n");
    printf("	.seh_endprologue\n");
    printf("	call	__main\n");

    gen(node->lhs);
    gen(node->rhs);

    printf("    pop     %%rdi\n");
    printf("    pop     %%rax\n");

    switch(node->ty){
        case ND_PLUS:
            printf("    add     %%rdi, %%rax\n");
            break;
        case ND_MINUS:
            printf("    sub     %%rdi, %%rax\n");
            break;
    }

    printf("	addq	$32, %%rsp\n");
    printf("    popq	%%rbp\n");
    printf("	ret\n");
    printf("	.seh_endproc\n");
}



int main(int argc,char **argv){
    if(argc != 2){
        fprintf(stderr,"引数の個数が正しくありません\n");
        return 1;
    }
    
    char *code = read_file(argv[1]);

    //トークンナイズ
    tokenize(code);
            
    gen(expr());

    return 0;
}