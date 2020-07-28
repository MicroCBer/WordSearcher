#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctime>
#include <string.h>
using namespace std;
string dicpath="dic.txt",inStr;
bool openOpt=1;
vector<string> dic;
string toLowerCase(string str) {
	string tmp="";
	for(int x=0; x<str.length(); x++) {
		tmp+=tolower(str[x]);
	}
	return tmp;
}
bool calcStrLetters(string str1,string str2) {
	if(str1.length()!=str2.length())return 0;
	str1=toLowerCase(str1);
	str2=toLowerCase(str2);
	int letterBuckets[2][26]= {};
	for(int x=0; x<str1.length(); x++)letterBuckets[0][str1[x]-'a']++;
	for(int x=0; x<str2.length(); x++)letterBuckets[1][str2[x]-'a']++;
	for(int x=0; x<26; x++)if(letterBuckets[0][x]!=letterBuckets[1][x])return 0;
	return 1;
}
int countPer(string str) {
	int n=1;
	for(int x=2; x<=str.length(); x++)n*=x;
	return n;
}
int main(int argc,char *argv[]) {
	if(argc!=4&&argc!=3&&argc!=2) {
		cout<<"Too few or much args!\n   Usage:\n   searchword <word: string> [OpenOptimization: bool] [dictionaryPath: string]";
		return 0;
	}
	if(argc==4)dicpath=argv[3];
	if(argc>=3)openOpt=(argv[2][0]=='1');
	ifstream fin(dicpath.c_str());
	sort(argv[1],argv[1]+strlen(argv[1]));
	inStr=argv[1];
	std::time_t t = std::time(0);
	if(openOpt)
		while(!fin.eof()) {
			string tmp;
			fin>>tmp;
			if(calcStrLetters(tmp,inStr))dic.push_back(tmp);
		}
	else
		while(!fin.eof()) {
			string tmp;
			fin>>tmp;
			dic.push_back(tmp);
		}
	std::time_t t2 = std::time(0);
	if(openOpt)cout<<"\n读取完成!\n优化后词典个数："<<dic.size()<<"\n读取&优化用时："<<t2-t<<"s\n";
	else cout<<"\n读取完成!\n词典个数："<<dic.size()<<"\n读取用时："<<t2-t<<"s\n开始查找：\n";
	int count=countPer(inStr);
	do {
		for(int x=0;x<dic.size();x++)if(dic[x]==inStr)cout<<inStr<<endl; 
	} while(next_permutation(inStr.begin(),inStr.end()));
	std::time_t t3 = std::time(0);
	cout<<"\n\n查找用时:"<<t3-t2<<"s";
}
