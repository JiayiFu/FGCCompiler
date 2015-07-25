#ifndef GLOBALVAR_H
#define GLOBALVAR_H
#include"LexicalAnalysis.h"

/**
	@brief ���ʹ�ϣ��
*/
extern TkWord * tk_hashtable[1024]; 

/**
	@brief ���ʱ�
*/
extern DynArray tktable; 

/**
	@brief �����ַ���
*/
extern DynString tkstr;

/**
	@brief ����Դ���ַ���
*/
extern DynString sourcestr;

/**
	@brief ����ֵ������Ϊ���γ�����
*/
extern int tkvalue;

/**
	@brief ��ǰȡ����Դ���ַ�
*/
extern char ch;

/**
	@brief ���ʱ���
*/
extern int token;

/**
	@brief �к�
*/
extern int line_num;
extern FILE* fin;
extern char* filename;

#endif
