#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstdio>
#include <iomanip>
#define MAX 10
using namespace std;
struct nama{
	char nama_pemain[100];
	char posisi_pemain[100];
};

struct queu{
	int front,rear;
	struct nama namap[MAX];
};
struct queu q;

bool isfull(){
	return q.rear == MAX; 
}

bool isempty(){
	return q.rear == 0;
}

void printqueu(){
	if(isempty()){
		cout << "ANTRIAN KOSONG !!!";
	}
	else{
		cout << "QUEU= \n" ;
		for(int i = q.front;i < q.rear; i++){
			cout << "data[" << i+1 << "]=" << q.namap[i].nama_pemain << " , " << q.namap[i].posisi_pemain << endl;
		}
	}
}

void push(){
	if(isfull()){
		cout << "ANTRIAN PENUH!!!";
	}
	else{
	char nama[100];
	char posisi[30];
		cout << "Nama pemain:";
		cin.ignore(1,'\n');
		cin.getline(nama,sizeof(nama));
		cout << "posisi pemain:";
		cin.ignore(0,'\n');
		gets(posisi);
		strcpy(q.namap[q.rear].nama_pemain,nama);
		strcpy(q.namap[q.rear].posisi_pemain,posisi);
		q.rear++;		
		cout << "(" << "pemain :" << nama << ")" "| ditambahkan \n" ;
		cout << "(" << "posisi :" << posisi << ") | ditambahkan \n" ;
		
	}
}
	
void pop(){
	cout << "Mengambil data= " << q.namap[q.front].nama_pemain << ":" << q.namap[q.front].posisi_pemain << endl;
	for(int i = q.front;i < q.rear; i++){
		q.namap[i] = q.namap[i+1];
	}
	q.rear--;
	
}

int main(){
	int choose;
	do{
		cout << "==================================\n"
			<< "Menu Pilihan \n"
			<< "[1] push \n"
			<< "[2] pop \n"
			<< "[3] print \n"
			<< "[4] keluar \n"
			<< "masukkan pilihan:";cin >> choose;
		switch(choose){
			case 1:
				push();
			break;
			case 2:
				pop();
			break;
			case 3:
				printqueu();
			break;
		}
	}while(choose != 4);
	return 0;
}

