#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY(array)    (sizeof(array)/sizeof(array[0]))


// コマンド
enum Cmd_tag {
    CMD_PRE_ORDER,
    CMD_IN_ORDER,
    CMD_POST_ORDER,
    CMD_EXIT,

    CMD_NUM
};

// コマンド文字列の種類
enum CmdStr_tag {
    CMD_STR_SHORT,
    CMD_STR_LONG,

    CMD_STR_NUM
};

// コマンドの戻り値
enum CmdRetValue_tag {
    CMD_RET_VALUE_CONTINUE,
    CMD_RET_VALUE_EXIT,
};

// コマンド文字列
static const char* const CMD_STR[CMD_NUM][CMD_STR_NUM] = {
    { "r", "pre" },
    { "i", "in" },
    { "p", "post" },
    { "e", "exit" }
};


// 二分木
struct Node_tag {
    int                   value;
    struct Node_tag*      left;
    struct Node_tag*      right;
};
typedef struct Node_tag* BinaryTree;


static BinaryTree create_binary_tree(void);
static void delete_binary_tree(BinaryTree tree);
static void print_explain(void);
static void print_blank_lines(void);
static enum CmdRetValue_tag get_cmd(void);
static enum CmdRetValue_tag cmd_pre_order(void);
static enum CmdRetValue_tag cmd_in_order(void);
static enum CmdRetValue_tag cmd_post_order(void);
static enum CmdRetValue_tag cmd_exit(void);
static void pre_order(BinaryTree tree);
static void in_order(BinaryTree tree);
static void post_order(BinaryTree tree);
static void get_line(char* buf, size_t size);


// コマンド実行関数
typedef enum CmdRetValue_tag (*cmd_func)(void);
static const cmd_func CMD_FUNC[CMD_NUM] = {
    cmd_pre_order,
    cmd_in_order,
    cmd_post_order,
    cmd_exit
};


static BinaryTree gTree;


int main(void)
{
    gTree = create_binary_tree();

    while( 1 ){
        print_explain();

        if( get_cmd() == CMD_RET_VALUE_EXIT ){
            break;
        }

        print_blank_lines();
    }

    delete_binary_tree( gTree );

    return 0;
}

/*
    二分木を作成

    ここでは、
    という形の二分木を作っている。

     node[0]->left = node[1]; のように表記すると根の左側に0を代入できる。
*/
BinaryTree create_binary_tree(void)
{
    BinaryTree node[8];

    for( size_t i = 0; i < SIZE_OF_ARRAY(node); ++i ){
        node[i] = malloc( sizeof(struct Node_tag) );
        node[i]->value = (int)i;
    }

    node[0]->left = node[1];
    node[0]->right = node[5];

    node[1]->left = node[2];
    node[1]->right = node[3];

    node[2]->left=NULL;
    node[2]->right=NULL;

    node[3]->left=NULL;
    node[3]->right=node[4];

    node[5]->left=node[6];
    node[5]->right=NULL;

    node[4]->left=NULL;
    node[4]->right=NULL;

    node[6]->left=NULL;
    node[6]->right=node[7];

    node[7]->left=NULL;
    node[7]->right=NULL;

    return node[0];
}

/*
    二分木を削除
*/
void delete_binary_tree(BinaryTree tree)
{
    if( tree == NULL ){
        return;
    }

    delete_binary_tree( tree->left );
    delete_binary_tree( tree->right );
    free( tree );
}

/*
    説明文を出力
*/
void print_explain(void)
{
    puts( "コマンドを入力してください。" );
    printf( "　行きがけ順探索: %s (%s)\n", CMD_STR[CMD_PRE_ORDER][CMD_STR_SHORT], CMD_STR[CMD_PRE_ORDER][CMD_STR_LONG] );
    printf( "　通りがけ順探索: %s (%s)\n", CMD_STR[CMD_IN_ORDER][CMD_STR_SHORT], CMD_STR[CMD_IN_ORDER][CMD_STR_LONG] );
    printf( "　帰りがけ順探索: %s (%s)\n", CMD_STR[CMD_POST_ORDER][CMD_STR_SHORT], CMD_STR[CMD_POST_ORDER][CMD_STR_LONG] );
    printf( "　終了する: %s(%s)\n", CMD_STR[CMD_EXIT][CMD_STR_SHORT], CMD_STR[CMD_EXIT][CMD_STR_LONG] );
    puts( "" );
}

/*
    空白行を出力
*/
void print_blank_lines(void)
{
    puts( "" );
    puts( "" );
}

/*
    コマンドを受け付ける
*/
enum CmdRetValue_tag get_cmd(void)
{
    char buf[20];
    get_line( buf, sizeof(buf) );

    enum Cmd_tag cmd = CMD_NUM;
    for( int i = 0; i < CMD_NUM; ++i ){
        if( strcmp( buf, CMD_STR[i][CMD_STR_SHORT] ) == 0
         || strcmp( buf, CMD_STR[i][CMD_STR_LONG] ) == 0
        ){
            cmd = i;
            break;
        }
    }

    if( 0 <= cmd && cmd < CMD_NUM ){
        return CMD_FUNC[cmd]();
    }
    else{
        puts( "そのコマンドは存在しません。" );
    }

    return CMD_RET_VALUE_CONTINUE;
}

/*
    preコマンドの実行
*/
enum CmdRetValue_tag cmd_pre_order(void)
{
    puts( "行きがけ順探索で、節の値を書き出します。" );
    pre_order( gTree );

    return CMD_RET_VALUE_CONTINUE;
}

/*
    inコマンドの実行
*/
enum CmdRetValue_tag cmd_in_order(void)
{
    puts( "通りがけ順探索で、節の値を書き出します。" );
    in_order( gTree );

    return CMD_RET_VALUE_CONTINUE;
}

/*
    postコマンドの実行
*/
enum CmdRetValue_tag cmd_post_order(void)
{
    puts( "帰りがけ順探索で、節の値を書き出します。" );
    post_order( gTree );

    return CMD_RET_VALUE_CONTINUE;
}

/*
    exitコマンドの実行
*/
enum CmdRetValue_tag cmd_exit(void)
{
    puts( "終了します。" );

    return CMD_RET_VALUE_EXIT;
}

/*
    行きがけ順探索でトラバース
*/
void pre_order(BinaryTree tree)
{
    if( tree == NULL ){
        return;
    }

    printf( "%d\n", tree->value );
    pre_order( tree->left );
    pre_order( tree->right );
}

/*
    通りがけ順探索でトラバース
*/
void in_order(BinaryTree tree)
{
    if( tree == NULL ){
        return;
    }
    printf("(");
    in_order( tree->left );
    printf( "%d", tree->value );
    in_order( tree->right );
    printf(")");
}

/*
    帰りがけ順探索でトラバース
*/
void post_order(BinaryTree tree)
{
    if( tree == NULL ){
        return;
    }

    post_order( tree->left );
    post_order( tree->right );
    printf( "%d\n", tree->value );
}

/*
    標準入力から１行分受け取る

    受け取った文字列の末尾には '\0' が付加される。
    そのため、実際に受け取れる最大文字数は size - 1 文字。

    引数：
        buf:    受け取りバッファ
        size:   buf の要素数
    戻り値：
        buf が返される
*/
void get_line(char* buf, size_t size)
{
    fgets(buf, size, stdin);

    // 末尾に改行文字があれば削除する
    char* p = strchr(buf, '\n');
    if (p != NULL) {
        *p = '\0';
    }
}
