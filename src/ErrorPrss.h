#ifndef ERROR_PROCESSING_H
#define ERROR_PROCESSING_H
#include<stdarg.h>
/**
	@brief ���󼶱�
*/
enum e_ErrorLevel
{
	LEVEL_WARNING,
	LEVEL_ERROR
};

/**
	@brief �����׶�
*/
enum e_WorkStage
{
	STAGE_COMPILE,
	STAGE_LINK
};

/**
	@brief �쳣����
	@param stage ����׶λ������ӽ׶�
	@param level ���󼶱�
	@param fmt ��������ĸ�ʽ
	@param ap �ɱ�����б�
*/
void handle_exception(int stage,int level, char* fmt,va_list ap);

/**
	@brief ���뾯�洦��
	@param fmt ���������ʽ
	@param ap �ɱ�����б�
*/
void warning(char* fmt,...);

/**
	@brief ����������������
	@param fmt ���������ʽ
	@param ap �ɱ�����б�
*/
void error(char* fmt,...);

/**
	@brief ��ʾ���󣬴˴�ȱ��ĳ���﷨�ɷ�
	@param msg:��Ҫʲô�﷨�ɷ�
*/
void expect(char *msg);

/**
	@brief ��������c��ȡ��һ�����ʣ������ǰ���ʲ���c,��ʾ����
	@param c Ҫ�����ĵ���
*/
void skip(int c);

/**
	@brief ȡ�õ���v�������Դ���ַ���
	@param v ���ʱ��
*/
char * get_tkstr(int v);

/**
	@brief ���Ӵ�����
	@param fmt ���������ʽ
	@param ap �ɱ�����б�
*/
void link_error(char* fmt,...);



#endif