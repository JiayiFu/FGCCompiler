#ifndef LEXICAl_ANALYSIS_H
#define LEXICAl_ANALYSIS_H

/*
	@brief ��ϣ��ĳ���
*/
#define MAXKEY 1024


/*
	@brief ���ʱ���
*/
enum e_TokenCode{

	TK_PLUS,    //+
	TK_MINUS,   //-
	TK_STAR,    //*
	TK_DIVIDE,  ///
    TK_MOD,     //%
    TK_EQ,      //==
    TK_NEQ,     //!=
    TK_LT,      //<
    TK_LEQ,     //<=
    TK_GT,      //>
    TK_GEQ,     //>=
    TK_ASSIGN,  //=
    TK_POINTSTO,//->
    TK_DOT,     //.
    TK_AND,     //&
    TK_OPENPA,  //(
    TK_CLOSEPA, //)
    TK_OPENBK,  //[
    TK_CLOSEBK, //]
    TK_BEGIN,   //{
    TK_END,     //}
    TK_SEMICOLON,//;
    TK_COMMA,   //,
    TK_ELLIPSIS,//...
    TK_EOF,     //�ļ�������

    /*����*/
    TK_CINT,
    TK_CCHAR,
    TK_CSTR,

    /*�ؼ���*/
    KW_CHAR,
    KW_CHORT,
    KW_INT,
    KW_VOID,
    KW_STRUCT,
    KW_IF,
    KW_ELSE,
    KW_FOR,
    KW_CONTINUE,
    KW_BREAK,
    KW_RETURN,
    KW_SIZEOF,

    KW_ALIGN,
    KW_CDECL,
    KW_STDCALL,

    /*��ʾ��*/
    TK_IDENT,

};

/*
    @brief ��̬�ַ����Ķ���
*/
typedef struct DynString{
    int count;
    int capacity;
    char* data;
}DynString;

/**
    @brief ��̬���鶨��
*/
typedef struct DynArray{

    int count;
    int capacity;
    void ** data;
}DynArray;



/**
	@brief ���ʱ�
*/
typedef struct TkWord
{
	int tkcode;
	struct TkWord* next;
	char * spelling;
	struct Symbol * sym_struct;
	struct Symbol * sym_identifier;
}TkWord;





/********�����Ǵʷ���������*********/

/**
	@brief ȡ����
*/
void get_token();

/**
	@brief ��Դ�����ж�ȡһ���ַ�
*/
void getch();

/**
	@brief Ԥ�������Կհ׷���ע��
*/
void preprocess();

/**
	@brief ����ע��
*/
void parse_comment();

/**
	@brief ���Կո�Tab�ͻس�
*/
void skip_while_space();

/**
	@brief �ж�c�Ƿ�Ϊ��ĸ���»���
	@param c �ַ�
*/
int is_nodigit(char c);

/**
	@brief �ж�c�Ƿ�������
	@param c �ַ�
*/
int is_digit(char c);

/**
	@brief ������ʾ��
*/
void parse_identifier();

/**
	@brief �������ͳ���
*/
void parse_num();

/**
	@brief �����ַ��������ַ�������
	@param sep �ַ����������ʶΪ�����š�
				�ַ������������ʶΪ˫���š�
*/
void parse_string(char sep);

/**
	@brief �ʷ���ɫ
*/
void color_token(int lex_state);

/**
	@brief �ʷ�״̬ö�ٶ���
*/
enum e_LexState{
	LEX_NORMAL,
	LEX_SEP
};

/**
	@brief �ʷ���������ʼ������
*/
void init();

/**
	@brief �ʷ�������ɨβ������
*/
void cleanup();

#endif
