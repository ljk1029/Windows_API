// MulLineInput.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// ��������
int MulLineInput()
{
	using namespace std;

	//input���ڱ���һ������
	string input, minput;
	//result���ڱ��������ַ���
	vector<string> result;
	char ch;

	do{
		cin>>input;//��ȡ��һ������
		cin.get(ch);//����հ׷�����' ','\t','\n'
		//cout<<input;//�����һ������
		result.push_back(input);
		if(ch!='\n')//δ����βʱ������֮������ո�
			//cout<<" ";
			//���뱣��ո�Ļ�,������Բ���Ҫ
			result.push_back(" ");
	}while(ch!='\n');

	//���result�еĽ��
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

