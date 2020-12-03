#include"List.h"
const int MAX_SIZE = 100;//����ʵ�ʶ��� 
template <class T>
class SeqList:public List<T>{
	public:
		SeqList();
		SeqList(T data[], int length);//���캯�������ʼ�� 
		~SeqList();
		virtual int getLength();
        virtual int locate(T data);
        virtual T get(int index);
        virtual void insert(T data, int index);
        virtual T deleteByIndex(int index);
        virtual bool isEmpty();
        virtual void printList();
        void quickSwapList();
	private:
		T data[MAX_SIZE]; 
		int length = 0;
};
