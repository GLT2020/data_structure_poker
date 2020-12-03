#include"SeqList.h"
#include<iostream>
#include<stack>
using namespace std;


//�޲ι��캯��
template <class T>
SeqList<T>::SeqList() {
	this->length = 0;
}

//���в������캯��
template <class T>
SeqList<T>::SeqList(T data[], int len) {
	if(len > MAX_SIZE) {
		throw "length is longer than MAX_SIZE";
	}
	//this->data = data;//�����Ǽ򵥵Ĵ���ַ, Ҫ�Լ������ڴ�, ʵ�ַ�װ
	for(int i=0; i<len; i++) {
		this->data[i] = data[i];
	}
	length = len;

}

//��������
template <class T>
SeqList<T>::~SeqList() {

}

//length
template <class T>
int SeqList<T>::getLength() {
	return length;
}

//locate
template <class T>
int SeqList<T>::locate(T data) {
	for(int i=0; i<length; i++) {
		if(this->data[i] == data)
			return i+1;
	}
	return 0;
}

//get
template <class T>
T SeqList<T>::get(int index) {
	if(index >0 && index <= length) {
		return data[index-1];
	}
	throw "function named \"get\": invalid index";
}

//insert
template <class T>
void SeqList<T>::insert(T data, int index) {
	if(length == MAX_SIZE) {
		throw "seqList`s length is equal MAX_SIZE";
	}
	if(index <=0 || index > length+1) {
		throw "function named \"insert\": invalid index";
	}
	//�Ӻ��濪ʼ, ���Ԫ�� ����һλֱ��index
	for(int i=length; i >= index; i--) {
		this->data[i] = this->data[i-1];
	}
	this->data[index-1] = data;
	//lengthͬ��+1
	length++;
}

//delete
template <class T>
T SeqList<T>::deleteByIndex(int index) {
	if(index < 1 || index > length) {
		throw "function named \"ideleteByIndex\": nvalid index";
	}
	//ɾ��ǰ�ȱ���
	T data = this->data[index-1];
	//ɾ��Ȼ��ÿ��Ԫ����ǰ�ƶ�һ��λ��
	for(int i=index-1; i < length-1; i++) {
		this->data[i] = this->data[i+1];
	}
	//lengthͬ��-1
	length--;
	return data;
}

//isEmpty
template <class T>
bool SeqList<T>::isEmpty() {
	return length == 0;
}

//printList
template <class T>
void SeqList<T>::printList() {
	for(int i=0; i<length; i++) {
		cout<<data[i]<<"\t";
	}
	cout<<endl;
}

template <class T>
void SeqList<T>::quickSwapList() {
	int i = 0;
	int j = length - 1;
	stack<int> zeroI;//��¼I�ƶ�����������0
	stack<int> zeroJ;//��¼jɨ�赽��0
	while(i < j) {
		while(data[i] <= 0 && i != j) {
			if(data[i] == 0) zeroI.push(i);
			i++;
		}
		while(data[j] >= 0 && i != j) {
			if(data[j] == 0) zeroJ.push(j);
			j--;
		}
		data[j] ^= data[i] ^= data[j] ^= data[i];
	}
	//��i == jʱ��i��j���ݣ�������0�Ķ�����
	if(data[i] >0) {
		j++;
	} else if(data[i] < 0) {
		i--;
	} else {
		i--;
		j++;
	}
	while(!zeroI.empty()) {
		if(data[i] != 0) {
			data[i] ^= data[zeroI.top()] ^= data[i] ^= data[zeroI.top()];
		}
		i--;
		zeroI.pop();
	}
	while(!zeroJ.empty()) {
		if(data[j] != 0) {
			data[j] ^= data[zeroJ.top()] ^= data[j] ^= data[zeroJ.top()];
		}
		j++;
		zeroJ.pop();
	}
}

void merge(SeqList<int> list1, SeqList<int> list2) {
	
}
/*int main() {
	int data[] = {30,20,19,18,17,4,3,2,1};
	SeqList<int> seqList1(data, 9);
	SeqList<int> seqList2(data, 9);
	merge(seqList1, seqList2); 
	/*list->insert(11, 1);
	list->printList();
	int deletedData = list->deleteByIndex(1);
	//		list->deleteByIndex(1);
	//		list->deleteByIndex(1);
	//		list->deleteByIndex(1);
	//		list->deleteByIndex(1);
	//		list->deleteByIndex(1);
	list->printList();
	cout<<"the data deleted: "<<deletedData<<endl;
	cout<<"list is empty?"<<list->isEmpty()<<endl;
	list->printList();
	int getedData = list->get(3);
	cout<<"get the data which index is "<<list->locate(getedData)<<" :"<<getedData<<endl;
	cout<<"length is "<<list->getLength()<<endl;
	} catch (const char* e) {
	cout<<endl<<e;
	}
	return 0;
}*/
