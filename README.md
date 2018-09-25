# WordCount

#### 项目介绍
WordCount的需求可以概括为：对程序设计语言源文件统计字符数、单词数、行数，统计结果以指定格式输出到默认文件中，以及其他扩展功能，并能够快速地处理多个文件。

可执行程序命名为：wc.exe，该程序处理用户需求的模式为：

wc.exe [parameter] [input_file_name]

存储统计结果的文件默认为result.txt，放在与wc.exe相同的目录下。

#### 软件架构
CMakeLists.txt 使用cmake工具


#### 安装教程

1. linux下：
       
```
wget https://cmake.org/files/v3.10/cmake-3.10.0-rc2-Linux-x86_64.sh
sudo +x cmake-3.10.0-rc2-Linux-x86_64.sh
./cmake-3.10.0-rc2-Linux-x86_64.sh
git clone https://gitee.com/SenLinJ/WordCount.git
cd WordCount && make 
```

2. windows
在cmake官网下载，然后配置mingw就可以使用
具体mingw的配置，请参照网上的教程
#### 注意
wc.exe [parameter] [input_file_name] [-o] [output_file_name]

Useage Options:

    -c   Read the letters in the file

    -w   Read the words in the file

    -l   Read the number of rows in a file

    -o   The Name of output file

The -o must be at the back of input_file_name. And the back of -o has an output File!

file_name] [-o] [output_file_name]

Useage Options:

    -c   Read the letters in the file

    -w   Read the words in the file

    -l   Read the number of rows in a file

    -o   The Name of output file

The -o must be at the back of input_file_name. And the back of -o has an output File!


