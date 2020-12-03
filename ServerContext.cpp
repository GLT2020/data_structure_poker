#include"ServerContext.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

//Լ��A:���� B:÷�� C������ D������ 
ServerContext::ServerContext() {
	//1. ��ʼ���ƶ�
	char flowerColers[] = {'A', 'B', 'C', 'D'};
	for(int i=0; i<52; i++) {
		pokers[i].setPointNumber(i % 13 + 1);
		pokers[i].setFlowerColor(flowerColers[i / 13]);
		//pokers[i].print();
	}
	shufflePokers();
}

void ServerContext::shufflePokers() {
	unsigned seed = time(0);
	 srand(seed);
	 int number = rand() % 32 + 8; //8-39
	 int swapPosition = rand() % (52 - number) + 1;//1-44
	 
	 
}
ServerContext::~ServerContext() {

}

int ServerContext::settlementScore(){
	Node<Player> *p = playerList.getFirst();
	Node<Player> *q;		//����ָ�� 
	q = p;					//��ʼ������ָ�� 
	HashTable HT;
	int PlayerLength = playerList.getLength();//��ȡ��Ҹ��� 
	string RankingList[PlayerLength][2];//���ص��ַ������� 
	int sum[PlayerLength] ={0}; 
	int max = 22,min = 0,j=0; 
	//����ֵ������װ���ϣ���� 
	while(q->getNext() != nullptr){
		if(q->getData().getPointNumberTotal() > 21){
			HT.Insert(22,p->getData().getName());
		}
		else{
			HT.Insert(p->getData().getPointNumberTotal(),p->getData().getName());
		}
		q = q->getNext();
	}
	//����ֵ����
	for(int i = 0;i < PlayerLength;i++){
		q = p;
		while(q->getNext() != nullptr){
			if(q->getData().getPointNumberTotal() < max && q->getData().getPointNumberTotal() > min){
				min = q->getData().getPointNumberTotal();
			}
			q = q->getNext();
		}
		max = min;
		//��maxΪ0ʱ֤��21���µķ�ֵ�Ѿ��ź��� 
		if(max == 0){
			q = p;
			while(q->getNext() != nullptr){
				if(q->getData().getPointNumberTotal() > 21){
					sum[i] = 22;
					break;
				}
				q = q->getNext();
			}
			break;
		}
		sum[i] = min;
		min = 0;
	} 
	//����sum��д���ַ������� 
	while(sum[j] != 0 && j < PlayerLength) {
		RankingList[j][0] = to_string(sum[j]);
		RankingList[j][1] = HT.SearchName(sum[j]);
		j++;
	}
}


