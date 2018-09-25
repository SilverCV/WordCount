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
extern char *result;          //定义输入文件名
extern int flag;                          //表示写入result的模式
extern int ret[2];
void WriteToFile(char* fileName,int count[],int Csize,char* feature);   //用于将读取的字母个数，单词 个数，文件行数写入文件中
void *ReadChar(char* fileName);
void *ReadWord(char* fileName);
void *Readlines(char* fileName);
int *GetOptions(int argc,char* argv[]);                  //根据参数选取功能项
void Help();                                            // 提示文档
void WordCount(int argc,char* argv[]);                    //处理模块
void *CharWordLine(char* fileName);                     //读取字母,单词,行数

#endif //WC_WordCount_H
