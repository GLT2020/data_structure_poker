#include"ServerContext.h"
#include<iostream>
#include<string>
#include"Poker.h"

using namespace std;

void printPoker(string);
int main() {
	ServerContext a;
	string pokerStr = "1C";
	Poker* pokers = a.getPokers();
	for(int i=0; i<52; i++) {
		cout<<to_string(pokers[i].getPointNumber()) + pokers[i].getFlowerColor()<<endl;
	}
	//printPoker(pokerStr);
	return 0;
}

void printPoker(string pokerStr) {
	return ;
	if(pokerStr.length() > 3 || pokerStr.length() < 2)
		throw "�������Ĳ����ַ���pokerStr����Υ����Ӧ��2 <= length <=3"; 
	char flowerColor = pokerStr[pokerStr.length() - 1];
	if(flowerColor > 'D' || flowerColor < 'A')
		throw "δʶ��Ļ�ɫ���ַ���" + flowerColor;
	if(pokerStr.length() == 2 && (pokerStr[0] > '9' || pokerStr[0] < '1'))
		throw "����Υ����Ӧ��1 <= pointNumber <= 9";
	else if (pokerStr.length() == 3 && (pokerStr[0] != '1' || pokerStr[1] > '3' || pokerStr[1] < '0' ))
		throw "����Υ����Ӧ��1 <= pointNumber <= 9";
	cout<<"------------"<<endl;//14��*
	string strs[] = {"10", "J ", "Q ", "K "};
	string flowerColors[] = {"����", "÷��", "����", "����"};
	
	                            cout<<"| " + flowerColors[flowerColor - 'A'] + "  "<<(pokerStr.length() >= 3 ? strs[pokerStr[1] - '0'] : pokerStr.substr(0, 1) + " ")<<" |"<<endl;
	cout<<"------------"<<endl;
}

