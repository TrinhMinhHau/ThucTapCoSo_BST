#include<iostream>
#include<fstream>
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
		Y=Y->pRight;//Cap nhat lai moi lien ket cho node cha cua node ma chung ta se xoa den NULL. Y->pRight = NULL
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
	cout<<"\n\t\t0.Ket thuc";
	cout<<"\n\t===============================\t";
	int luachon;
	cout<<"\n\t\t\nVui long nhap lua chon:";
	cin>>luachon;
	if(luachon <0|| luachon>5){
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

