#include<iostream>
#include<stdio.h>
#include<string>
 
using namespace std;
FILE *file;
int chars = 0, words = 0, lines = 1, s[500];
char c;
 
void T()
{
while ((c = fgetc(file)) != EOF)
{
chars++;
if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || ((c >= '0') && (c <= '9')))
{
words++;
while ((c = fgetc(file)) != EOF)
{
chars++;
if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || ((c >= '0') && (c <= '9')))
{
}
else if (c == '\n')
{
s[lines] = 1;
lines++;
break;
}
else if (c == ' ')
break;
else
{
break;
}
}
}
else if (c == '/')
{
if ((c = fgetc(file)) == '/')
{
s[lines] = 2;
fseek(file, -1L, SEEK_CUR);
}
}
else if (c == '\n')
{
if (s[lines] != 2)
s[lines] = 1;
lines++;
}
}
if (s[lines] != 2)
s[lines] = 1;
}
 
int main()
{
char name[30], b;
int i;
cout << " * 请输入源文件名:";
for (;;)
{
cin >> name;
if ((file = fopen(name, "r")) != NULL)
break;
else
cout << " * 文件路径错误！请重新输入源文件名:";
}
T();
fclose(file);
cout << " 字符数：" << chars << endl;
cout << " 单词数：" << words << endl;
cout << " 行数 ：" << lines << endl;
for (i = 1; i <= lines; i++)
{
if (s[i] == 1)
{
if (i<10)
cout << " 第" << i << "行为 代码行" << endl;
else if (i<100)
cout << " 第" << i << "行为 代码行" << endl;
else
cout << " 第" << i << "行为 代码行" << endl;
}
else if (s[i] == 2)
{
if (i<10)
cout << " 第" << i << "行为 注释行" << endl;
else if (i<100)
cout << " 第" << i << "行为 注释行" << endl;
else
cout << " 第" << i << "行为 注释行" << endl;
}
}
 
b = getchar();
b = getchar();
system("cls");
return 0;
}