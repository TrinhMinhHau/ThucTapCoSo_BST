#include<iostream>
#include<fstream>
#include<graphics.h>
using namespace std;
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
void Graphics_Taocay(){
	settextstyle(1,1,1);
	setcolor(RED);
	outtextxy(50,50,"Graphics for BST");
	setcolor(RED);
	settextstyle(3,1,3);
	outtextxy(400,50,"5->2->8->7->9->4->1");
	delay(1000);
	setcolor(5);
	settextstyle(3,1,3);
		circle(289,89,30);
		outtextxy(295,100,"5");
		delay(1000);
		 line(270,117,213,180);
		 delay(1000);
		 circle(200,210,30);
		 outtextxy(210,220,"2");
		 delay(1000);
		 line(300,120,360,180);
		 delay(1000);
		 circle(370,210,30);
		 outtextxy(380,220,"8");
		 delay(1000);
		 line(370,240,340,300);
		 delay(1000);
		 circle(330,330,30);
		 outtextxy(340,340,"7");
		delay(1000);
		 line(380,240,400,300);
		 delay(1000);
		 circle(400,330,30);
		 outtextxy(410,340,"9");
		 delay(1000);
		 line(200,240,220,300);
		 delay(1000);
		 circle(225,330,30);
		 outtextxy(230,340,"4");
		 delay(1000);
		 line(190,240,170,300);
		 delay(1000);
		 circle(160,330,30);
		 outtextxy(165,340,"1");
}
void Graphics_Timkiem(){
   //thiet lap mot mau sac, kieu chu
	settextstyle(1,1,1);
	setcolor(RED);
	outtextxy(50,50,"Graphics for BST");
	setcolor(RED);
	settextstyle(3,1,3);
	outtextxy(400,50,"Find node number 4");
	delay(1000);
	setcolor(5);
	settextstyle(3,1,3);
	//ham mo ta 1 cay
		circle(289,89,30);
		outtextxy(295,100,"5");
		 line(270,117,213,180);
		 circle(200,210,30);
		 outtextxy(210,220,"2");
		 line(300,120,360,180);
		 circle(370,210,30);
		 outtextxy(380,220,"8");
		 line(370,240,340,300);
		 circle(330,330,30);
		 outtextxy(340,340,"7");
		 line(380,240,400,300);
		 circle(400,330,30);
		 outtextxy(410,340,"9");
		 line(200,240,220,300);
		 circle(225,330,30);
		 outtextxy(230,340,"4");
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,"1");
	//tim kiem phan tu bat ki
		 setcolor(BLUE);
		 circle(289,89,30);
		 outtextxy(295,100,"5");
		 delay(1000);
		 setcolor(5);
		 circle(289,89,30);
		 setcolor(BLUE);
		 line(270,117,213,180);
		 circle(200,210,30);
		 outtextxy(210,220,"2");
		 delay(1000);
		 setcolor(5);
		 line(270,117,213,180);
		 circle(200,210,30);
	     setcolor(BLUE);
		 line(200,240,220,300);
		 setcolor(5);
		 line(200,240,220,300);
		 setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,"4");
}
void Graphics_Xoa1con(){
	settextstyle(1,1,1);
	setcolor(RED);
	outtextxy(50,50,"Graphics for BST");
	setcolor(RED);
	settextstyle(3,1,3);
	outtextxy(400,50,"Delete node number 4");
	setcolor(5);
	settextstyle(3,1,3);
		delay(1000);
		circle(289,89,30);
		outtextxy(295,100,"5");
		 line(270,117,213,180);
		 circle(200,210,30);
		 outtextxy(210,220,"2");
		 line(300,120,360,180);
		 circle(370,210,30);
		 outtextxy(380,220,"8");
		 line(370,240,340,300);
		 circle(330,330,30);
		 outtextxy(340,340,"7");
		 line(380,240,400,300);
		 circle(400,330,30);
		 outtextxy(410,340,"9");
		 line(200,240,220,300);
		 circle(225,330,30);
		 outtextxy(230,340,"4");
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,"1");
		 //tim kiem phan tu sô 4
		 setcolor(BLUE);
		 circle(289,89,30);
		 outtextxy(295,100,"5");
		 delay(1000);
		 setcolor(5);
		 circle(289,89,30);
		 setcolor(BLUE);
		 line(270,117,213,180);
		 circle(200,210,30);
		 outtextxy(210,220,"2");
		 delay(1000);
		 setcolor(5);
		 line(270,117,213,180);
		 circle(200,210,30);
	     setcolor(BLUE);
		 line(200,240,220,300);
		 setcolor(5);
		 line(200,240,220,300);
		 setcolor(RED);
		 circle(225,330,30);
		 outtextxy(230,340,"4");
		 //Xoa node so 4
		 setcolor(0);
		 delay(1000);
		 line(200,240,220,300);
		 delay(1000);
		 circle(225,330,30);
		 outtextxy(230,340,"4");
		
}
void Graphics_Xoa2con(){
	settextstyle(1,1,1);
	setcolor(RED);
	outtextxy(50,50,"Graphics for BST");
	setcolor(RED);
	settextstyle(3,1,3);
	outtextxy(400,50,"Delete node number 5");
		setcolor(5);
		circle(289,89,30);
		outtextxy(295,100,"5");
		 line(270,117,213,180);
		 circle(200,210,30);
		 outtextxy(210,220,"2");
		 line(300,120,360,180);
		 circle(370,210,30);
		 outtextxy(380,220,"8");
		 line(370,240,340,300);
		 circle(330,330,30);
		 outtextxy(340,340,"7");
		 line(380,240,400,300);
		 circle(400,330,30);
		 outtextxy(410,340,"9");
		 line(200,240,220,300);
		 circle(225,330,30);
		 outtextxy(230,340,"4");
		 line(190,240,170,300);
		 circle(160,330,30);
		 outtextxy(165,340,"1");
		 //tim kiem phan tu bat ki
		 setcolor(BLUE);
		 circle(289,89,30);
		 outtextxy(295,100,"5");
		 delay(1000);
		 setcolor(RED);
		 circle(289,89,30);
		 outtextxy(295,100,"5");
		 setcolor(BLUE);
		 line(300,120,360,180);
		 delay(1000);
		 circle(370,210,30);
		 outtextxy(380,220,"8");
		 setcolor(5);
		 line(300,120,360,180);
		 delay(1000);
		 circle(370,210,30);
		 setcolor(BLUE);
		 line(370,240,340,300);
		 delay(1000);
		 circle(330,330,30);
		 outtextxy(340,340,"7");
		 setcolor(5);
		 delay(1000);
		 line(370,240,340,300);
		 setcolor(RED);
		 circle(330,330,30);
		 outtextxy(340,340,"7");
		 delay(1000);
		 setcolor(RED);
		 circle(289,89,30);
		 outtextxy(295,100,"7");
		 delay(1000);
		 setcolor(0);
		 circle(330,330,30);
		 outtextxy(340,340,"7");
		 line(370,240,340,300);
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
	cout<<"\n\t\t6.Mo phong them du lieu vao cay";
	cout<<"\n\t\t7.Mo phong tim kiem tren cay";
	cout<<"\n\t\t8.Mo phong xoa node('node la,node co 1 con')";
	cout<<"\n\t\t9.Mo phong xoa node('node co 2 con')";
	cout<<"\n\t\t0.Ket thuc";
	cout<<"\n\t===============================\t";
	int luachon;
	cout<<"\n\t\t\nVui long nhap lua chon:";
	cin>>luachon;
	if(luachon <0|| luachon>9){
		cout<<"/nLua chon khong hop le";
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
		int gd=0,gm=0;
		initgraph(&gd,&gm,"");
		Graphics_Taocay();
		getch();
		closegraph();
		
	}
	else if(luachon==7){
		int gd=0,gm=0;
		initgraph(&gd,&gm,"");
		Graphics_Timkiem();
		getch();
		closegraph();
		
	}
	else if(luachon==8){
		int gd=0,gm=0;
		initgraph(&gd,&gm,"");
		Graphics_Xoa1con();
		getch();
		closegraph();
		
	}
	else if(luachon==9){
		int gd=0,gm=0;
		initgraph(&gd,&gm,"");
		Graphics_Xoa2con();
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

