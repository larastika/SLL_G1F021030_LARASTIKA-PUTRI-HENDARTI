//=======================//
//==SINGLE LINKED LIST==//
//=====================//
#include<iostream>
using namespace std;

struct Tanggal_Lahir{
  //Tipe Data//
  string Bulan;
  int Tanggal, Tahun;

  Tanggal_Lahir*next;
};
  Tanggal_Lahir*head,*tail,*cur,*newNode,*del, *before;
	//Create Sll//
void createSingleLinkedList(int Tanggal,string Bulan, int Tahun){
	head = new Tanggal_Lahir();
	head->Tanggal=Tanggal;
	head->Bulan=Bulan;
	head->Tahun=Tahun;
	head->next=NULL;
	tail=head;
}
	//Sequential SLL//
	int countSingleLinkedList(){
		cur=head;
		int jumlah=0;
		while(cur!=NULL){
			jumlah++;
			cur=cur->next;
		}
		return jumlah;
}
	//Insert First//
void addFirst(int Tanggal,string Bulan, int Tahun){
	newNode = new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;
	newNode->next=head;
	head=newNode;
}
	//Insert Last//
void addLast(int Tanggal,string Bulan, int Tahun){
	newNode = new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;
	newNode->next=NULL;
	tail->next=newNode;
	tail=newNode;	
}
	//Insert Before/After//
void addMiddle(int Tanggal, string Bulan, int Tahun,int posisi){
	newNode=new Tanggal_Lahir();
	newNode->Tanggal=Tanggal;
	newNode->Bulan=Bulan;
	newNode->Tahun=Tahun;
		
	//Tranversing
	cur=head;
	int nomor=1;
	while (nomor < posisi-1){
		cur=cur->next;
		nomor++;
	}
	
	newNode->next= cur->next;
	cur->next=newNode;
		
	}

	//Delete First//
void DeleteFirst(){
	
	del=head;
	head=head->next;
	delete del;
}
	//Delete Last//
void DeleteLast(){
	del= tail;
	cur= head;
	while(cur->next != tail){
		cur=cur->next;
	}
	tail=cur;
	tail->next=NULL;
	delete del;
}

	//Delete Middle//
void DeleteMiddle(int posisi){
	if(posisi < 1||posisi > countSingleLinkedList() ){
		cout<<"Posisi diluar jangkauan"<<endl;
	}else if(posisi==1||posisi== countSingleLinkedList() ){
		cout <<"Posisi Bukan Posisi Tengah"<<endl;
	}else{
	int nomor=1;
		cur=head;
	while(nomor<=posisi){
		if(nomor== posisi -1){
			before=cur;				
			}
		if(nomor == posisi){
			del=cur;
			}
		cur= cur ->next;
		nomor++;
		}
		before->next=cur;
		delete del;	
	}
}

	//Print SLL
void printSingleLinkedList(){
	cout<<"Jumlah data ada:"<< countSingleLinkedList()<< endl;
	cur=head;
	while(cur!=NULL){
		cout<<"Tanggal Lahir:"<<cur->Tanggal<<endl;
		cout<<"Bulan Lahir:"<<cur->Bulan<<endl;
		cout<<"Tahun Lahir:"<<cur->Tahun<<endl;
		
		cur=cur->next;
	}
}
int main (){

  createSingleLinkedList(14,"februari", 2004);
  printSingleLinkedList();
  
  cout<<"\n\n"<<endl;
  	//insert first//
  addFirst(26,"Juli",2003);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
 	 //insert Last//
  addLast(01,"Januari",2004);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
 	 //insert middle//
  addMiddle(1,"Juni",2003,2);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  	//Deletion First//
  DeleteFirst();
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  addLast(01,"Maret", 2022);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  	//Deletion Last//
  DeleteLast();
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  cout<<"\n\n"<<endl;
  
  DeleteMiddle(1);
  printSingleLinkedList();
  cout<<"\n\n"<<endl;
  
  
}
