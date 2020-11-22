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
chars++;//字符统计
if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || ((c >= '0') && (c <= '9')))
{
words++;//单词统计
while ((c = fgetc(file)) != EOF)
{
chars++;
if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || ((c >= '0') && (c <= '9')))
{
}
else if (c == '\n')
{
s[lines] = 1;
lines++;//行数统计
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
b = getchar();
b = getchar();
system("cls");
return 0;
}