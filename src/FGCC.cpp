#include"LexicalAnalysis.h"
#include<stdio.h>
/**
	@brief ���ʹ�ϣ��
*/
TkWord * tk_hashtable[1024]; 

/**
	@brief ���ʱ�
*/
DynArray tktable; 

/**
	@brief �����ַ���
*/
DynString tkstr;

/**
	@brief ����Դ���ַ���
*/
DynString sourcestr;

/**
	@brief ����ֵ������Ϊ���γ�����
*/
int tkvalue;

/**
	@brief ��ǰȡ����Դ���ַ�
*/
char ch;

/**
	@brief ���ʱ���
*/
int token;

/**
	@brief �к�
*/
int line_num;
char* filename;

FILE* fin;


int main(int argc,char **argv){

	printf("hhhhhhh");
	fin = fopen(argv[1],"rb");
	filename = argv[1];
	if(!fin){
		printf("���ܴ�Դ�ļ���\n");
	}

	init();
	getch();
	do{
		get_token();
		color_token(LEX_NORMAL);
	}while(token != TK_EOF);

	printf("\n����������%d\n",line_num);
	cleanup();
	fclose(fin);
	printf("%s�ʷ������ɹ���",argv[1]);
	return 0;

}