#include"ErrorPrss.h"
#include"LexicalAnalysis.h"
#include<stdio.h>
#include<stdlib.h>
#include"GlobalVar.h"

/**
	@brief �쳣����
	@param stage ����׶λ������ӽ׶�
	@param level ���󼶱�
	@param fmt ��������ĸ�ʽ
	@param ap �ɱ�����б�
*/
void handle_exception(int stage,int level, char* fmt,va_list ap){
	char buf[1024];
	vsprintf(buf,fmt,ap);
	if(stage == STAGE_COMPILE){
	
		if(level == LEVEL_WARNING){
			printf("%s(��%d��)�����뾯�棺%s!\n",filename,line_num,buf);
		}else{
			printf("%s(��%d��)���������%s!\n",filename,line_num,buf);
			exit(-1);
		}
	}else{
	
		printf("���Ӵ���%s!\n",buf);
		exit(-1);
	}
}

/**
	@brief ���뾯�洦��
	@param fmt ���������ʽ
	@param ap �ɱ�����б�
*/
void warning(char* fmt,...){

	va_list ap;
	va_start(ap,fmt);
	handle_exception(STAGE_COMPILE,LEVEL_WARNING,fmt,ap);
	va_end(ap);
}

/**
	@brief ����������������
	@param fmt ���������ʽ
	@param ap �ɱ�����б�
*/
void error(char* fmt,...){
	va_list ap;
	va_start(ap,fmt);
	handle_exception(STAGE_COMPILE,LEVEL_ERROR,fmt,ap);
	va_end(ap);
}

/**
	@brief ��ʾ���󣬴˴�ȱ��ĳ���﷨�ɷ�
	@param msg:��Ҫʲô�﷨�ɷ�
*/
void expect(char *msg){

	error("ȱ��%s",msg);
}

/**
	@brief ��������c��ȡ��һ�����ʣ������ǰ���ʲ���c,��ʾ����
	@param c Ҫ�����ĵ���
*/
void skip(int c){

	if(token!=c){
		error("ȱ��'%s'",get_tkstr(c));
	}
}

/**
	@brief ȡ�õ���v�������Դ���ַ���
	@param v ���ʱ��
*/
char * get_tkstr(int v){
	if(v>tktable.count){
		return NULL;
	}else if(v>TK_CINT && v<TK_CSTR){
		return sourcestr.data;
	}else{
		return ((TkWord*)tktable.data[v])->spelling;
	}
}

/**
	@brief ���Ӵ�����
	@param fmt ���������ʽ
	@param ap �ɱ�����б�
*/
void link_error(char* fmt,...){

	va_list ap;
	va_start(ap,fmt);
	handle_exception(STAGE_LINK,LEVEL_ERROR,fmt,ap);
	va_end(ap);
}