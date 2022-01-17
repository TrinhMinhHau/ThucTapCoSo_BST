#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<graphics.h>
using namespace std;
//khai báo cau truc cua 1 node
struct node{
	int data; // du lieu cua node
	struct node *pLeft; //tao cay con trai
	struct node *pRight; //tao cay con phai
};
typedef struct node NODE;
typedef NODE* TREE;

//Khoi tao cay nhi phan
void KhoiTaoCay(TREE &t){
	t=NULL; //cay rong
} 
//Ham them phan tu x vao cay nhi phan
void ThemNodeVaoCay(TREE &t, int x){
	if(t==NULL){
		NODE *p= new NODE; // Khoi tao 1 node de them vao cay
		p->data=x;
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p; //Node p chinh la node goc <==> x la node goc
	}
	else{
		if(t->data>x){
			ThemNodeVaoCay(t->pLeft,x);
		}
		else if(t->data <x){
			ThemNodeVaoCay(t->pRight,x);
		}
		
	}
}
//Ham tim kiem 1 node bat ki
NODE* TimKiem(TREE t,int x){
	// neu cay rong tra ve NULL
	if(t==NULL){
		return NULL;
	}
	else{
		//neu phan tu nho hon goc thi duyet sang trai de tin
		if(x<t->data){
			TimKiem(t->pLeft,x);
		}
		else if(x>t->data){
			TimKiem(t->pRight,x);
		}
		else{
			return t;
		}
		
	}
}
void TimnodeXoa(TREE &X,TREE &Y){
	if(Y->pLeft!=NULL) { //Y=t->pRight
	TimnodeXoa(X,Y->pLeft);//Tim ra node trai nhat
	}
	else{
		X->data=Y->data;//Cap nhat data cua node can xoa thanh data cua node the mang
		X=Y;//Cho node X tro den Y de sau nay xoa X 
		Y=Y->pRight;//Cap nhat lai moi lien ket cho node cha cua node ma chung ta se xoa den NULL. 
	}
}
//Ham xoa mot node bat ki
void XoaNode(TREE &t,int data){
	if(t==NULL){
		return;
	}
	else{
		//Qua trinh tim kiem node can xoa
		if(data<t->data){
			XoaNode(t->pLeft,data);
		}
		else if(data>t->data){
			XoaNode(t->pRight,data);
		}
		else{
			//Da tim thay node can xoa
			NODE *X=t;
			//Xoa node co cay con phai
			if(t->pLeft==NULL){
				t=t->pRight;
			}
			//Xoa node co cay con trai
			else if(t->pRight==NULL){
				t=t->pLeft;
			}
			//Xoa node vua co cay con phai va cay con trai
			else{
				//Tim node trai nhat cua cay con phai
				//NODE *Y=t->pRight;
				TimnodeXoa(X,t->pRight);
			}
			delete X;
			
		}
	}
	
}
void Xuat(TREE t){
	if(t!=NULL){
		cout<<t->data<<" ";
		Xuat(t->pLeft);
		Xuat(t->pRight);
	}
}
//Ham nhap du lieu
//Nhap du lieu tu file
void Taofile(TREE &t,ifstream &filein){
	
	int n;
	filein>>n;
	for(int i=1;i<=n;i++){
		int x;
		filein>>x;
		ThemNodeVaoCay(t,x);
	}
}
void Graphics(int a[],char b[]){
		for(int i=1;i<=7;i++){
		setcolor(5);
		itoa(a[i],b,10);
		// Ve node goc
		delay(1000);
		if(a[i]==a[1]){
		circle(289,89,30);
		outtextxy(295,100,b);
	}
	//Ve node thu 2
	delay(1000);
		if(a[1]<a[2]){
			line(300,120,360,180);
			itoa(a[2],b,10);
			circle(370,210,30);
			outtextxy(380,220,b);
		}
		else
		{
			line(270,117,213,180);
			itoa(a[2],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
			
		}
// Ve node thu 3

		delay(1000);
		if(a[3]>a[1]&&a[1]>a[2]){
		line(300,120,360,180);
		itoa(a[3],b,10);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[3]<a[1]&&a[1]<a[2]){
			line(270,117,213,180);
			itoa(a[3],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		else if(a[3]>a[2] && a[3]>a[1]){
		 line(380,240,400,300);
		itoa(a[3],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[3]<a[2] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[3],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[3]>a[2] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[3],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[3]<a[2] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[3],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	//Ve node thu 4 
	if(a[2]<a[1]){
	delay(1000);
		if(a[4]>a[1]&&a[3]<a[1]&&a[2]<a[1]){
		line(300,120,360,180);
		itoa(a[4],b,10);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[4]<a[1]&&a[3]>a[1]&&a[2]>a[1]){
			line(270,117,213,180);
			itoa(a[4],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		//
		
		else if(a[4]<a[2]&&a[4]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[4]>a[2]&&a[4]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
	
		 else if(a[4]>a[3] && a[3]>a[1] ){
		 line(380,240,400,300);
		itoa(a[4],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[4]<a[3] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[4],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[4]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[4]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		}
		else if(a[2] > a[1]){
			delay(1000);
					
		 if(a[4]<a[3]&&a[4]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[4]>a[3]&&a[4]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
	
		 else if(a[4]>a[2] && a[2]>a[1] ){
		 line(380,240,400,300);
		itoa(a[4],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[4]<a[2] && a[2]>a[1]){
		 line(370,240,340,300);
		 itoa(a[4],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[4]>a[2] && a[2]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[4]<a[2] && a[2]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		}	
		
	//Ve node thu 5
		//
		//kiem tra xem node nhap thu 4 co lon hon tat ca khong
		if(a[4]>a[1]&&a[4]>a[2]&&a[4]>a[3]){
			delay(1000);
			if(a[5]>a[4]){
		 line(380,240,400,300);
		 itoa(a[5],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
			}
			else if(a[5]<a[4]){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
			}
		}
	  else {
	  	if(a[2]>a[1])
	  	{
	  	delay(1000);
		if(a[5]>a[2] && a[5]>a[1] ){
		 line(380,240,400,300);
		itoa(a[5],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[5]<a[2] && a[5]>a[1]){
		 line(370,240,340,300);
		 itoa(a[6],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[5]>a[2] && a[5]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		
		else if(a[5]<a[2] && a[5]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
	  	}
	  	
	  		} 
	  	else if(a[2] <a[1]){
		delay(1000);
		if(a[5]>a[3] && a[5]>a[1] ){
		 line(380,240,400,300);
		itoa(a[5],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[5]<a[3] && a[5]>a[1]){
		 line(370,240,340,300);
		 itoa(a[6],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[5]>a[3] && a[5]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[5]<a[3] && a[5]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
	  	}
	  }
	}
		
	//Ve node thu 6
	if(a[2]>a[1])
	{a[3]=a[2];} 
		delay(1000);
		if(a[6]>a[3] && a[6]>a[1] ){
		 line(380,240,400,300);
		itoa(a[6],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[6]<a[3] && a[6]>a[1]){
		 line(370,240,340,300);
		 itoa(a[6],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[6]>a[3] && a[6]<a[1]){
		 line(200,240,220,300);
		 itoa(a[6],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[6]<a[3] && a[6]<a[1]){
		 line(190,240,170,300);
		 itoa(a[6],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	// Ve node thu 7
	if(a[2]>a[1]){a[3]=a[2];}
		delay(1000);
		if(a[7]>a[3] && a[7]>a[1]  ){
		 line(380,240,400,300);
		itoa(a[7],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[7]<a[3] && a[7]>a[1]){
		 line(370,240,340,300);
		 itoa(a[7],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[7]>a[3] && a[7]<a[1]){
		 line(200,240,220,300);
		 itoa(a[7],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[7]<a[3] && a[7]<a[1]){
		 line(190,240,170,300);
		 itoa(a[7],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	}

	}

void taocay(int a[],char b[]){
	settextstyle(1,1,1);
	setcolor(RED);
	outtextxy(50,50,"Graphics for BST");
	setcolor(RED);
	settextstyle(3,1,3);
	int x=300,y=50;
	for(int i=1;i<=7;i++){
		itoa(a[i],b,10);
		outtextxy(x,y,b);
		x=x+30;
		if(i<7){
		outtextxy(x,50,"->");
		x=x+20;
	}
}
	Graphics(a,b);

	}
//ham tim kiem
void Timkiem(int a[],char b[]){
	settextstyle(1,1,1);
	setcolor(RED);
	outtextxy(50,50,"Graphics for BST");
	setcolor(RED);
	settextstyle(3,1,3);
	int x=300,y=50;
	outtextxy(x,y,"Tim Kiem");
	int q;
	cout<<"\nNhap so can tim: ";
	cin>>q;
		for(int i=1;i<=7;i++){
		setcolor(5);
		itoa(a[i],b,10);
		// Ve node goc
		delay(1000);
		if(a[i]==a[1]){
		circle(289,89,30);
		outtextxy(295,100,b);
	}
	//Ve node thu 2
	delay(1000);
		if(a[1]<a[2]){
			line(300,120,360,180);
			itoa(a[2],b,10);
			circle(370,210,30);
			outtextxy(380,220,b);
		}
		else
		{
			line(270,117,213,180);
			itoa(a[2],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
			
		}
// Ve node thu 3
		delay(1000);
		if(a[3]>a[1]&&a[1]>a[2]){
		line(300,120,360,180);
		itoa(a[3],b,10);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[3]<a[1]&&a[1]<a[2]){
			line(270,117,213,180);
			itoa(a[3],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		else if(a[3]>a[2] && a[3]>a[1]){
		 line(380,240,400,300);
		itoa(a[3],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[3]<a[2] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[3],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[3]>a[2] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[3],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[3]<a[2] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[3],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		
	//Ve node thu 4 
	
	
			delay(1000);
		if(a[4]>a[1]&&a[3]<a[1]&&a[2]<a[1]){
		line(300,120,360,180);
		itoa(a[4],b,10);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[4]<a[1]&&a[3]>a[1]&&a[2]>a[1]){
			line(270,117,213,180);
			itoa(a[4],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		//
		else if(a[4]<a[2]&&a[4]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[4]>a[2]&&a[4]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
	
		 else if(a[4]>a[3] && a[3]>a[1] ){
		 line(380,240,400,300);
		itoa(a[4],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[4]<a[3] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[4],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[4]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[4]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		
	//Ve node thu 5
		delay(1000);
		 if(a[5]<a[2]&&a[5]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[5]>a[2]&&a[5]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		//kiem tra xem node nhap thu 4 co lon hon tat ca khong
		if(a[4]>a[1]&&a[4]>a[2]&&a[4]>a[3]){
			if(a[5]>a[4]){
		 line(380,240,400,300);
		 itoa(a[5],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
			}
			else if(a[5]<a[4]){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
			}
		}
		
	
	  else{
	  	if(a[5]>a[3] && a[5]>a[1] ){
		 line(380,240,400,300);
		itoa(a[5],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[5]<a[3] && a[5]>a[1] ){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[5]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[5]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	  }
		
	//Ve node thu 6
		delay(1000);
		if(a[6]>a[3] && a[6]>a[1] ){
		 line(380,240,400,300);
		itoa(a[6],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[6]<a[3] && a[6]>a[1]){
		 line(370,240,340,300);
		 itoa(a[6],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[6]>a[3] && a[6]<a[1]){
		 line(200,240,220,300);
		 itoa(a[6],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[6]<a[3] && a[6]<a[1]){
		 line(190,240,170,300);
		 itoa(a[6],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	// Ve node thu 7
		delay(1000);
			if(a[7]>a[3] && a[7]>a[1] ){
		 line(380,240,400,300);
		itoa(a[7],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[7]<a[3] && a[7]>a[1]){
		 line(370,240,340,300);
		 itoa(a[7],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[7]>a[3] && a[7]<a[1]){
		 line(200,240,220,300);
		 itoa(a[7],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[7]<a[3] && a[7]<a[1]){
		 line(190,240,170,300);
		 itoa(a[7],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		//tim a[1]
			if(a[1]==q){
			setcolor(RED);
			circle(289,89,30);
			itoa(a[1],b,10);
			outtextxy(295,100,b);
	}
		//tim a[2]
			if(a[2]==q){
			if(a[1]<a[2]){
			line(300,120,360,180);
			itoa(a[2],b,10);
			setcolor(RED);
			circle(370,210,30);
			outtextxy(380,220,b);
		}
		else
		{	
			line(270,117,213,180);
			itoa(a[2],b,10);
			setcolor(RED);
			circle(200,210,30);
			outtextxy(210,220,b);
			
		}
			
			if(a[1]<a[2]){
			line(300,120,360,180);
			itoa(a[2],b,10);
			setcolor(RED);
			circle(370,210,30);
			outtextxy(380,220,b);
		}
		else
		{
			line(270,117,213,180);
			itoa(a[2],b,10);
			setcolor(RED);
			circle(200,210,30);
			outtextxy(210,220,b);
			
		}
			}
			//tim a[3]
		if(a[3]==q){

			if(a[3]>a[1]&&a[1]>a[2]){
		line(300,120,360,180);
		itoa(a[3],b,10);
		setcolor(RED);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[3]<a[1]&&a[1]<a[2]){
			line(270,117,213,180);
			itoa(a[3],b,10);
			setcolor(RED);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		else if(a[3]>a[2] && a[3]>a[1]){
		 line(380,240,400,300);
		itoa(a[3],b,10);
		setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[3]<a[2] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[3],b,10);
		 setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[3]>a[2] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[3],b,10);
		 setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[3]<a[2] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[3],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
			
		}
		//tim a[4]
	if(q==a[4]){
		if(a[4]>a[1]&&a[3]<a[1]&&a[2]<a[1]){
		line(300,120,360,180);
		itoa(a[4],b,10);
		setcolor(RED);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[4]<a[1]&&a[3]>a[1]&&a[2]>a[1]){
			line(270,117,213,180);
			itoa(a[4],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		//
		else if(a[4]<a[2]&&a[4]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[4]>a[2]&&a[4]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
	
		 else if(a[4]>a[3] && a[3]>a[1] ){
		 line(380,240,400,300);
		itoa(a[4],b,10);
		setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[4]<a[3] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[4]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[4]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	}
	//tim a[5]
	if(q==a[5]){
		if(a[5]<a[2]&&a[5]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[5]>a[2]&&a[5]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		//kiem tra xem node nhap thu 4 co lon hon tat ca khong
		if(a[4]>a[1]&&a[4]>a[2]&&a[4]>a[3]){
			if(a[5]>a[4]){
		 line(380,240,400,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
			}
			else if(a[5]<a[4]){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
			}
		}
		
	  else{
	  	if(a[5]>a[3] && a[5]>a[1] ){
		 line(380,240,400,300);
		itoa(a[5],b,10);
		 setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[5]<a[3] && a[5]>a[1] ){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[5]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[5]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	  }
	}
	//tim a[6]
	if(q==a[6]){
		if(a[6]>a[3] && a[6]>a[1] ){
		 line(380,240,400,300);
		itoa(a[6],b,10);
		setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[6]<a[3] && a[6]>a[1]){
		 line(370,240,340,300);
		 itoa(a[6],b,10);
		setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[6]>a[3] && a[6]<a[1]){
		 line(200,240,220,300);
		 itoa(a[6],b,10);
		 	setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[6]<a[3] && a[6]<a[1]){
		 line(190,240,170,300);
		 itoa(a[6],b,10);
		 	setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}	
	}
	//tim a[7]
	if(q==a[7]){
		delay(1000);
			if(a[7]>a[3] && a[7]>a[1] ){
		 line(380,240,400,300);
		itoa(a[7],b,10);
			setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[7]<a[3] && a[7]>a[1]){
		 line(370,240,340,300);
		 itoa(a[7],b,10);
		 	setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[7]>a[3] && a[7]<a[1]){
		 line(200,240,220,300);
		 itoa(a[7],b,10);
		setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[7]<a[3] && a[7]<a[1]){
		 line(190,240,170,300);
		 itoa(a[7],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	}
	}
	}
void Xoa(int a[],char b[]){
		settextstyle(1,1,1);
	setcolor(RED);
	outtextxy(50,50,"Graphics for BST");
	setcolor(RED);
	settextstyle(3,1,3);
	int x=300,y=50;
	outtextxy(x,y,"Xoa Node");
	int q;
	cout<<"\nNhap node can xoa: ";
	cin>>q;
		for(int i=1;i<=7;i++){
		setcolor(5);
		itoa(a[i],b,10);
		// Ve node goc
		delay(1000);
		if(a[i]==a[1]){
		circle(289,89,30);
		outtextxy(295,100,b);
	}
	//Ve node thu 2
	delay(1000);
		if(a[1]<a[2]){
			line(300,120,360,180);
			itoa(a[2],b,10);
			circle(370,210,30);
			outtextxy(380,220,b);
		}
		else
		{
			line(270,117,213,180);
			itoa(a[2],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
			
		}
// Ve node thu 3
		delay(1000);
		if(a[3]>a[1]&&a[1]>a[2]){
		line(300,120,360,180);
		itoa(a[3],b,10);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[3]<a[1]&&a[1]<a[2]){
			line(270,117,213,180);
			itoa(a[3],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		else if(a[3]>a[2] && a[3]>a[1]){
		 line(380,240,400,300);
		itoa(a[3],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[3]<a[2] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[3],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[3]>a[2] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[3],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[3]<a[2] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[3],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		
	//Ve node thu 4 
	
	
			delay(1000);
		if(a[4]>a[1]&&a[3]<a[1]&&a[2]<a[1]){
		line(300,120,360,180);
		itoa(a[4],b,10);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[4]<a[1]&&a[3]>a[1]&&a[2]>a[1]){
			line(270,117,213,180);
			itoa(a[4],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		//
		else if(a[4]<a[2]&&a[4]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[4]>a[2]&&a[4]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
	
		 else if(a[4]>a[3] && a[3]>a[1] ){
		 line(380,240,400,300);
		itoa(a[4],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[4]<a[3] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[4],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[4]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[4]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		
	//Ve node thu 5
		delay(1000);
		 if(a[5]<a[2]&&a[5]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[5]>a[2]&&a[5]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		//kiem tra xem node nhap thu 4 co lon hon tat ca khong
		if(a[4]>a[1]&&a[4]>a[2]&&a[4]>a[3]){
			if(a[5]>a[4]){
		 line(380,240,400,300);
		 itoa(a[5],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
			}
			else if(a[5]<a[4]){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
			}
		}
		
	
	  else{
	  	if(a[5]>a[3] && a[5]>a[1] ){
		 line(380,240,400,300);
		itoa(a[5],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[5]<a[3] && a[5]>a[1] ){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[5]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[5]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	  }
		
	//Ve node thu 6
		delay(1000);
		if(a[6]>a[3] && a[6]>a[1] ){
		 line(380,240,400,300);
		itoa(a[6],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[6]<a[3] && a[6]>a[1]){
		 line(370,240,340,300);
		 itoa(a[6],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[6]>a[3] && a[6]<a[1]){
		 line(200,240,220,300);
		 itoa(a[6],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[6]<a[3] && a[6]<a[1]){
		 line(190,240,170,300);
		 itoa(a[6],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	// Ve node thu 7
		delay(1000);
			if(a[7]>a[3] && a[7]>a[1] ){
		 line(380,240,400,300);
		itoa(a[7],b,10);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[7]<a[3] && a[7]>a[1]){
		 line(370,240,340,300);
		 itoa(a[7],b,10);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[7]>a[3] && a[7]<a[1]){
		 line(200,240,220,300);
		 itoa(a[7],b,10);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[7]<a[3] && a[7]<a[1]){
		 line(190,240,170,300);
		 itoa(a[7],b,10);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		//Tim a[1]
			if(a[1]==q){
			setcolor(RED);
			circle(289,89,30);
			itoa(a[1],b,10);
			outtextxy(295,100,b);
	}
		//tim a[2]
			if(a[2]==q){
			setcolor(RED);
			if(a[1]<a[2]){
			line(300,120,360,180);
			itoa(a[2],b,10);
			circle(370,210,30);
			outtextxy(380,220,b);
		}
		else
		{
			line(270,117,213,180);
			itoa(a[2],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
			
		}
			
			if(a[1]<a[2]){
			line(300,120,360,180);
			itoa(a[2],b,10);
			setcolor(RED);
			circle(370,210,30);
			outtextxy(380,220,b);
		}
		else
		{
			line(270,117,213,180);
			itoa(a[2],b,10);
			setcolor(RED);
			circle(200,210,30);
			outtextxy(210,220,b);
			
		}
			}
			//Xoa a[3]
		if(a[3]==q){

			if(a[3]>a[1]&&a[1]>a[2]){
		line(300,120,360,180);
		itoa(a[3],b,10);
		setcolor(RED);
		circle(370,210,30);
		outtextxy(380,220,b);
		delay(1000);
		setcolor(BLACK);
		line(300,120,360,180);
		circle(370,210,30);
		outtextxy(380,220,b);
		
		}
		else if(a[3]<a[1]&&a[1]<a[2]){
			line(270,117,213,180);
			itoa(a[3],b,10);
			setcolor(RED);
			circle(200,210,30);
			outtextxy(210,220,b);
			delay(1000);
		    setcolor(BLACK);
		    line(270,117,213,180);
		    circle(200,210,30);
			outtextxy(210,220,b);
		}
		else if(a[3]>a[2] && a[3]>a[1]){
		 line(380,240,400,300);
		itoa(a[3],b,10);
		setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		 	delay(1000);
		    setcolor(BLACK);
		    line(380,240,400,300);
		    circle(400,330,30);
		    outtextxy(410,340,b);
		}
		else if(a[3]<a[2] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[3],b,10);
		 setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		 delay(1000);
		    setcolor(BLACK);
		    line(370,240,340,300);
		    circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[3]>a[2] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[3],b,10);
		 setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		  delay(1000);
		    setcolor(BLACK);
		    line(200,240,220,300);
		     circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[3]<a[2] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[3],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		   delay(1000);
		setcolor(BLACK);
		line(190,240,170,300);
		    circle(160,330,30);
		 outtextxy(165,340,b);
		 
		}
		}
		//Xoa a[4]
	if(q==a[4]){
		if(a[4]>a[1]&&a[3]<a[1]&&a[2]<a[1]){
		line(300,120,360,180);
		itoa(a[4],b,10);
		setcolor(RED);
		circle(370,210,30);
		outtextxy(380,220,b);
		delay(1000);
		setcolor(BLACK);
		line(300,120,360,180);
		circle(370,210,30);
		outtextxy(380,220,b);
		}
		else if(a[4]<a[1]&&a[3]>a[1]&&a[2]>a[1]){
			line(270,117,213,180);
			itoa(a[4],b,10);
			circle(200,210,30);
			outtextxy(210,220,b);
			delay(1000);
			setcolor(BLACK);
			line(270,117,213,180);
			circle(200,210,30);
			outtextxy(210,220,b);
		}
		//
		else if(a[4]<a[2]&&a[4]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		 delay(1000);
		 setcolor(BLACK);
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[4]>a[2]&&a[4]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		  delay(1000);
		 setcolor(BLACK);
		 line(200,240,220,300);
		  circle(225,330,30);
		 outtextxy(230,340,b);
		}
	
		 else if(a[4]>a[3] && a[3]>a[1] ){
		 line(380,240,400,300);
		itoa(a[4],b,10);
		setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(380,240,400,300);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[4]<a[3] && a[3]>a[1]){
		 line(370,240,340,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(370,240,340,300);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[4]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(200,240,220,300);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[4]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[4],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	}
	//Xoa a[5]
	if(q==a[5]){
		if(a[5]<a[2]&&a[5]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
		else if(a[5]>a[2]&&a[5]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(200,240,220,300);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		//kiem tra xem node nhap thu 4 co lon hon tat ca khong
		if(a[4]>a[1]&&a[4]>a[2]&&a[4]>a[3]){
			if(a[5]>a[4]){
		 line(380,240,400,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(380,240,400,300);
		 circle(400,330,30);
		 outtextxy(410,340,b);
			}
			else if(a[5]<a[4]){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(370,240,340,300);
		  circle(330,330,30);
		 outtextxy(340,340,b);
			}
			
		}
	  else{
	  	if(a[5]>a[3] && a[5]>a[1] ){
		 line(380,240,400,300);
		itoa(a[5],b,10);
		 setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(380,240,400,300);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[5]<a[3] && a[5]>a[1] ){
		 line(370,240,340,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(370,240,340,300);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[5]>a[3] && a[3]<a[1]){
		 line(200,240,220,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(200,240,220,300);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[5]<a[3] && a[3]<a[1]){
		 line(190,240,170,300);
		 itoa(a[5],b,10);
		  setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	  }
	}
	//Xoa a[6]
	if(q==a[6]){
		if(a[6]>a[3] && a[6]>a[1] ){
		 line(380,240,400,300);
		itoa(a[6],b,10);
		setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(380,240,400,300);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[6]<a[3] && a[6]>a[1]){
		 line(370,240,340,300);
		 itoa(a[6],b,10);
		setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(370,240,340,300);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[6]>a[3] && a[6]<a[1]){
		 line(200,240,220,300);
		 itoa(a[6],b,10);
		 	setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(200,240,220,300);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[6]<a[3] && a[6]<a[1]){
		 line(190,240,170,300);
		 itoa(a[6],b,10);
		 	setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}	
	}
	//Xoa a[7]
	if(q==a[7]){
		delay(1000);
			if(a[7]>a[3] && a[7]>a[1] ){
		 line(380,240,400,300);
		itoa(a[7],b,10);
			setcolor(RED);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(380,240,400,300);
		 circle(400,330,30);
		 outtextxy(410,340,b);
		}
		else if(a[7]<a[3] && a[7]>a[1]){
		 line(370,240,340,300);
		 itoa(a[7],b,10);
		 	setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(370,240,340,300);
		 circle(330,330,30);
		 outtextxy(340,340,b);
		}
		else if(a[7]>a[3] && a[7]<a[1]){
		 line(200,240,220,300);
		 itoa(a[7],b,10);
		setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(200,240,220,300);
		  circle(225,330,30);
		 outtextxy(230,340,b);
		}
		else if(a[7]<a[3] && a[7]<a[1]){
		 line(190,240,170,300);
		 itoa(a[7],b,10);
		 setcolor(RED);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		   delay(1000);
		 setcolor(BLACK);
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,b);
		}
	}
	}
}		
//Doc file de mo phong do hoa
void docfile(int a[],int &n)
{
    FILE *f;
    f=fopen("C://Users//HP//Documents//TRINHMINHHAU_61133622_TTCS//Input.txt","rt");
    fscanf(f,"%d",&n);
    for(int i=1;i<=n;i++)
        fscanf(f,"%d",&a[i]);
    fclose(f);
}
void Menu(TREE &t)
{ 
	while(true){
	system("cls");
	cout<<"\n\t============= MENU=============\t";
	cout<<"\n\t\t1.Nhap du lieu";
	cout<<"\n\t\t2.Xuat du lieu";
	cout<<"\n\t\t3.Tim kiem phan tu";
	cout<<"\n\t\t4.Xoa 1 node bat ki";
	cout<<"\n\t\t5.Doc du lieu tu file";
	cout<<"\n\t\t6.Mo Phong Tao Cay ( 7 node va 3 muc) ";
	cout<<"\n\t\t7.Mo Phong Tim Kiem Node ( 7 node va 3 muc) ";
	cout<<"\n\t\t8.Mo Phong Xoa Cay ( Chi Xoa node la va Node 1 con) ";
	cout<<"\n\t\t0.Ket thuc";
	cout<<"\n\t===============================\t";
	int luachon;
	cout<<"\n\t\t\nVui long nhap lua chon:";
	cin>>luachon;
	if(luachon <0|| luachon>8){
		cout<<"\nLua chon khong hop le";
		system("pause");
	}
	else if(luachon==1){
		int x;
		cout<<"\nNhap 1 so nguyen\n";
		cin>>x;
		ThemNodeVaoCay(t,x);
	}
	else if(luachon==2){
		cout<<"\n\t\tDu lieu xuat ra\n";
		Xuat(t);
		system("pause");
	}
	else if(luachon==3){
		cout<<"\n\tNhap so can tim kiem: ";
		int x;
		cin>>x;
		NODE* p=TimKiem(t,x);
		if(p==NULL){
			cout<<"\nPhan tu "<<x<<" khong ton tai trong cay ";
		}
		else{
			cout<<"\nDa tim thay: "<<x;
		}
		system("pause");
	}
	else if(luachon==4){
		cout<<"\n\tNhap node can xoa: ";
		int x;
		cin>>x;
		XoaNode(t,x);
		cout<<"Phan tu "<<x<<" da duoc xoa";
		system("pause");
	}
	else if(luachon==5){
		ifstream filein;
		filein.open("C://Users//HP//Documents//TRINHMINHHAU_61133622_TTCS//Input.txt",ios::in);
		Taofile(t,filein);
		filein.close();
		
	}
	else if(luachon==6){
	int a[100];
	char b[20];
	/*
	int n;
	docfile(a,n);
	for(int i=1;i<=n;i++)
        printf("%3d",a[i]);
        */
	
	cout<<"Nhap so node can mo ta (7 node va 3 muc): ";
	int n;
	cin>>n;
	 for(int i = 1;i <= n; i++){
        scanf("%d", &a[i]);
    }
    
    
    int gd=0,gm=0;
		initgraph(&gd,&gm,"");
		taocay(a,b);
		getch();
		closegraph();
	}
	else if(luachon==7){
		int a[100];
		char b[20];
		int n;
		docfile(a,n);
		for(int i=1;i<=n;i++)
        printf("%3d",a[i]);
	/*
	cout<<"Nhap so node can mo ta (7 node va 3 muc): ";
	int n;
	cin>>n;
	 for(int i = 1;i <= n; i++){
        scanf("%d", &a[i]);
    }
    */
    
    	int gd=0,gm=0;
		initgraph(&gd,&gm,"");
		Timkiem(a,b);
		getch();
		closegraph();
	}
	else if(luachon==8){
		int a[100];
		char b[20];
		int n;
		docfile(a,n);
		for(int i=1;i<=n;i++)
        printf("%3d",a[i]);
	/*
	cout<<"Nhap so node can mo ta (7 node va 3 muc): ";
	int n;
	cin>>n;
	 for(int i = 1;i <= n; i++){
        scanf("%d", &a[i]);
    }
    */
    
    	int gd=0,gm=0;
		initgraph(&gd,&gm,"");
		Xoa(a,b);
		getch();
		closegraph();
	}
	else{
		break;
	}
}
}
int main(){
	
	TREE t;
	KhoiTaoCay(t);
	Menu(t);
	system("pause");
	return 0;
}

