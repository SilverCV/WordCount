//
// Created by SilverCV on 2018/9/19.
//
#include "WordCount.h"
char *result = "result.txt";          //���������ļ���
int flag = 0;                          //��ʾд��result��ģʽ
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
    /* ����0��������д�
     *  1 ��ʾ��ȡ��ĸ
     * 3 ��ʾ��ȡ����
     *  5 ��ʾ��ȡ����
     *  ���ǵĺʹ�����Ҫ�Ĺ���
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
        //����ͼ�ν��棬���˳������н��

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
    //���� -o֮ǰȱ�������ļ�
    return  ret;
}
void WriteToFile(char* fileName,int count[],int Csize,char* feature)
{
    /*fileName ��ʾ��ȡ���ļ�
     * count ��ʾ��¼�ĸ���
     * Csize ��ʾ��¼����Ĵ�С
     * feature��ʾ��¼������ ���ʻ�����ĸ��������
     * flag ��ʾֻд������׷��ģʽ,0 ��ʾֻд��1��ʾ׷��
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
    int index = 0; //��¼�ַ���
    for(int i=0;i<Csize;i++)
    {
        if(count[i] != 0)
        {
            index += count[i];     //�����ܵĵ��ʸ���
        }
    }
    FILE *fp = NULL;
    fp = fopen(result,mode); //�����д���ļ�
    if (fp == NULL)
    {
        printf("Failed when writing the count to file\n");
        exit(-1);
    }
    fprintf(fp,"%s,%s %d\n",fileName,feature,index); //д���ļ�
    fclose(fp);
}
void *ReadChar(char* fileName)
{
    char* feature = "�ַ���: ";
    char buf;
    int count[N] = {0}; //����������ĸ���ֹ��Ĵ���
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
    /*�ڼ�¼���ʸ��� ��ʱ��
    * ����ͨ��ͳ�ƶ��źͿո�ĸ���
    * Ȼ��ͨ������õ����ʵĸ���
     * ����ÿ�����ʵĳ��Ȳ�����256��ĸ
    */
    char* feature = "������: ";
    char buf[N];
    FILE* fp = NULL;
    fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        printf("Fail to open the file!\n");
        Help();
        exit(-1);
    }

    int dot = 0;    //��¼���ŵĸ���
    int sum = 0;
    while(!feof(fp))
    {
        fscanf(fp,"%s",buf);//������ո���������Բ���Ҫ���ҳ��ո�ֿ��ĵ���ֻ��Ҫ���ŷֿ��ľ���
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
    //ͨ���ո�Ͷ��ż��㵥������
    int count[1] = {sum};
    WriteToFile(fileName,count,1,feature);
    //�ر��ļ�
    fclose(fp);
}
void *Readlines(char* fileName)
{
    char buf = '\0';
    char* feature  = "����: ";
    FILE* fp = NULL;
    fp = fopen(fileName,"r");
    if (fp == NULL)
    {
        printf("Fail to open the file!\n");
        Help();
        exit(-1);
    }
    int space[1] = {0}; //��¼����
    while(!feof(fp))
    {
        buf = fgetc(fp);
        if (buf == 10)  //���з���ASCII��Ϊ10 ֻҪ�ҳ����еĻ��з��ͺ�
        {
            space[0] ++;
        }
    }
    space[0] ++; //�����һ�����л�ѻ��з�����Ϊ�����ַ���������Ҫ��1
    WriteToFile(fileName,space,1,feature);
    //�ر��ļ�
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
