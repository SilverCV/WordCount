//
// Created by SilverCV on 2018/9/19.
//

#ifndef WC_WORDCOUNT_H
#define WC_WORDCOUNT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>
#define N 1024
extern char *result;          //���������ļ���
extern int flag;                          //��ʾд��result��ģʽ
extern int ret[2];
void WriteToFile(char* fileName,int count[],int Csize,char* feature);   //���ڽ���ȡ����ĸ���������� �������ļ�����д���ļ���
void *ReadChar(char* fileName);
void *ReadWord(char* fileName);
void *Readlines(char* fileName);
int *GetOptions(int argc,char* argv[]);                  //���ݲ���ѡȡ������
void Help();                                            // ��ʾ�ĵ�
void WordCount(int argc,char* argv[]);                    //����ģ��
void *CharWordLine(char* fileName);                     //��ȡ��ĸ,����,����

#endif //WC_WordCount_H
