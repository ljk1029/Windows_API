// MulLineInput.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// 多行输入
int MulLineInput()
{
	using namespace std;

	//input用于保存一个单词
	string input, minput;
	//result用于保存整个字符串
	vector<string> result;
	char ch;

	do{
		cin>>input;//读取第一个单词
		cin.get(ch);//捕获空白符，如' ','\t','\n'
		//cout<<input;//输出第一个单词
		result.push_back(input);
		if(ch!='\n')//未到结尾时，单词之间输出空格
			//cout<<" ";
			//不想保存空格的话,这里可以不需要
			result.push_back(" ");
	}while(ch!='\n');

	//输出result中的结果
	for (std::vector<string>::iterator it = result.begin(); it != result.end(); ++it) {
		std::cout << *it;
	}

	getline(cin, minput);
	return 0;
}

int main()
{
	MulLineInput();
	system("pause");
	return 0;
}

