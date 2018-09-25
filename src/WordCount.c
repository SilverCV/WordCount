//
// Created by SilverCV on 2018/9/19.
//
#include "WordCount.h"
char *result = "result.txt";          //定义输入文件名
int flag = 0;                          //表示写入result的模式
int ret[2] = {0};
void WordCount(int argc,char* argv[])
{
    char* fileName;
    if (argc <= 1) {
        Help();
        exit(0);
    }
    GetOptions(argc,argv);
    fileName = argv[ret[1]];
   /* switch(ret[0])
    {
        case 1:
            ReadChar(fileName);
            break;
        case 3:
            ReadWord(fileName);
            break;
        case 5:
            Readlines(fileName);
            break;
        case 4: {
            ReadChar(fileName);
            flag = 1;
            ReadWord(fileName);
            break;
        }
        case 6: {
            ReadChar(fileName);
            flag = 1;
            Readlines(fileName);
            break;
        }
        case 8:{
            ReadWord(fileName);
            flag = 1;
            Readlines(fileName);
            break;
        }
        case 9: {
            CharWordLine(fileName);
            break;
        }
        default:
            Help();
            break;
    }*/
   if (ret[0] == 1)
   {
       ReadChar(fileName);
   }
   if (ret[0] == 3)
   {
       ReadWord(fileName);
   }
   if(ret[0] == 5)
   {
       Readlines(fileName);
   }
   if(ret[0] == 4)
   {
       ReadChar(fileName);
       flag = 1;
       ReadWord(fileName);
   }
   if(ret[0] == 6)
   {
       ReadChar(fileName);
       flag = 1;
       Readlines(fileName);
   }
   if(ret[0] == 8)
   {
       ReadWord(fileName);
       flag = 1;
       Readlines(fileName);
   }
   if(ret[0] == 9)
   {
       CharWordLine(fileName);
   }
   else
   {
       Help();
       exit(-1);
   }

}
int *GetOptions(int argc,char* argv[])
{
    /* 返回0代表参数有错
     *  1 表示读取字母
     * 3 表示读取单词
     *  5 表示读取行数
     *  它们的和代表所要的功能
     */

    char* params;
    if(argc > 0) {
        params = argv[argc - 1];
        if (strcmp("-x", params) == 0) {
            system("start WordCount.exe");
            exit(0);
        }
    }
    for(int i=0;i<argc;i++)
    {
        params = argv[i];
        if(strcmp("-c",params) == 0)
        {
            ret[0] += 1;
        }
        if(strcmp("-w",params) == 0)
        {
            ret[0] += 3;
        }
        if(strcmp("-l",params) == 0)
        {
            ret[0] += 5;
        }
        //启动图形界面，则退出命令行结口

    }
    if(argc > 3) {
        params = argv[argc - 2];
        if (strcmp("-o", params) == 0 && argv[argc - 1] != NULL) {
            result = argv[argc - 1];
            ret[1] = argc - 3;
        }
        else
        {
            ret[1]= argc - 1;
        }
    }else {
        ret[1] = argc - 1;
    }
    //处理 -o之前缺少输入文件
    return  ret;
}
void WriteToFile(char* fileName,int count[],int Csize,char* feature)
{
    /*fileName 表示读取的文件
     * count 表示记录的个数
     * Csize 表示记录数组的大小
     * feature表示记录的内容 单词或者字母或者行数
     * flag 表示只写，还是追加模式,0 表示只写，1表示追加
     */
    char *mode = '\0';
    if (flag == 1)
    {
        mode = "a+";
    }
    else
    {
        mode = "w+";
    }
    int index = 0; //记录字符数
    for(int i=0;i<Csize;i++)
    {
        if(count[i] != 0)
        {
            index += count[i];     //计算总的单词个数
        }
    }
    FILE *fp = NULL;
    fp = fopen(result,mode); //将结果写入文件
    if (fp == NULL)
    {
        printf("Failed when writing the count to file\n");
        exit(-1);
    }
    fprintf(fp,"%s,%s %d\n",fileName,feature,index); //写入文件
    fclose(fp);
}
void *ReadChar(char* fileName)
{
    char* feature = "字符数: ";
    char buf;
    int count[N] = {0}; //用来储存字母出现过的次数
    FILE* fp = fopen(fileName,"r");
    if (fp == NULL)
    {
        printf("Fail to open the file!\n");
        Help();
        exit(-1);
    }
    while(!feof(fp))
    {
        buf = fgetc(fp);
        count[buf] ++;
    }
    fclose(fp);
    WriteToFile(fileName,count,N,feature);

}
void *ReadWord(char* fileName)
{
    /*在记录单词个数 的时候，
    * 我们通过统计逗号和空格的个数
    * 然后通过计算得到单词的个数
     * 假设每个单词的长度不超过256字母
    */
    char* feature = "单词数: ";
    char buf[N];
    FILE* fp = NULL;
    fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        printf("Fail to open the file!\n");
        Help();
        exit(-1);
    }

    int dot = 0;    //记录逗号的个数
    int sum = 0;
    while(!feof(fp))
    {
        fscanf(fp,"%s",buf);//会读到空格结束，所以不需要来找出空格分开的单词只需要逗号分开的就行
        int n = strlen(buf);
        for(int i=1;i<n;i++)
        {
            if(',' == buf[i]) {
                dot++;
            }
        }
        if(n > 0)
        {
            sum += dot +1;
            dot = 0;
        }

    }
    //通过空格和逗号计算单词总数
    int count[1] = {sum};
    WriteToFile(fileName,count,1,feature);
    //关闭文件
    fclose(fp);
}
void *Readlines(char* fileName)
{
    char buf = '\0';
    char* feature  = "行数: ";
    FILE* fp = NULL;
    fp = fopen(fileName,"r");
    if (fp == NULL)
    {
        printf("Fail to open the file!\n");
        Help();
        exit(-1);
    }
    int space[1] = {0}; //记录行数
    while(!feof(fp))
    {
        buf = fgetc(fp);
        if (buf == 10)  //换行符的ASCII码为10 只要找出所有的换行符就好
        {
            space[0] ++;
        }
    }
    space[0] ++; //在最后一个行中会把换行符设置为其他字符，随意需要加1
    WriteToFile(fileName,space,1,feature);
    //关闭文件
    fclose(fp);
}
void Help()
{
    printf("wc.exe [parameter] [input_file_name] [-o] [output_file_name]\n");
    printf("Useage Options:\n");
    printf("    -c   Read the letters in the file\n");
    printf("    -w   Read the words in the file\n");
    printf("    -l   Read the number of rows in a file\n");
    printf("    -o   The Name of output file\n");
    printf("The -o must be at the back of input file. And the back of -o has an output File!\n");

}
void* CharWordLine(char* fileName)
{
    ReadChar(fileName);
    flag = 1;
    ReadWord(fileName);
    Readlines(fileName);
}
