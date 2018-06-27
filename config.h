#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include <mylib.h>
const int ENTER =13;
const int SPACE=32;
const int ESC=27;
const int BACK=8;
using namespace std;

//KHAI BAO DANH SACH MAY BAY TUYEN TINH
const int MAXMB=100; 
struct MayBay
{
	char sohieu[15];
	char loai[40];
	int cho;   //  >= 20
};
struct listmb
{
	int n;
	MayBay mb[MAXMB];
};
listmb dsmb;

//KHAI BAO THONG TIN VE;
struct Ve
{
	int stt;
	char macb[15];
	int cmnd;
};
struct ListVe
{
	int n;
	Ve dsve[300];
};
 ListVe ds;
 
//KHAI BAO DANH SACH CAC CHUYEN BAY DS LIEN KET DON
struct giobay
{
	int gio;
	int phut;
};
struct ngaybay
{
	int ngay;
	int thang;
	int nam;
};
struct ChuyenBay
{
	char macb[15];
	char sohieu_mb[15];
	ngaybay ngay_cb;
	giobay gio_cb;
	char sanbay_den[50]; 
	int trangthai;
	ListVe ds;
};
struct Node
{
	ChuyenBay data;
	Node *pnext;
};
typedef struct Node *PTRCB;
struct ListCB 
{
	PTRCB pHead;
	PTRCB pTail;
};
typedef struct ListCB *LISTCB;

struct HanhKhach
{
	int CMND;
	char HoTen[30];
	char Phai[5];
};
struct node
{
	HanhKhach data;
	struct node *pLeft;
	struct node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;


//---other functions
void BaoLoi(char *S)
{
	int x=wherex(),y=wherey();
	gotoxy(6,y+4);
	cout<<S;
	Sleep(500);
	gotoxy(6,wherey());
	cout<<"                                                   ";
	gotoxy(x,y);
}
void ClearRow(int x,int y)
{
	gotoxy(x,y);
	cout<<"                                                                             ";
}
char *InputWord()
{
	char c;
	char *temp=new char[30];
	char *result=new char[30];
	for(int vt=0; vt<30; vt++)
	{
		int x=wherex(),y=wherey();
		c=getch();
		if (c== ENTER)
		{
			strncpy(result,temp,strlen(temp));
			return result;
			break;
		} 
		else if(vt==0&&c==SPACE){
				BaoLoi("Dau day khong dc khoang trang!");
				vt--;	 
				continue;
			}
		if(c==ESC)
		{
			ClearRow(0,0);
			delete temp;
			BaoLoi("Da xoa");
			break;
		}else if((c>=65 && c<=90)||(c>=90 && c<=122)||(c>=48 && c<=57)||c==SPACE)
				{ 
					strncpy(&temp[vt],&c,1);
					cout<<temp[vt];
				}else if(vt>0 && c==BACK)
						{
							gotoxy(x-1,y);
							cout<<" ";
							gotoxy(x-1,y);
							vt--;
						}else
							BaoLoi("Nhap loi!");
	}
	delete temp;
}
//int InputNumber(int n)
//{
//		c=getch();
//		if(c==ENTER) break;
//		else if(vt==0 && c==SPACE)
//			{
//				BaoLoi("Dau day khong duoc khoang trang !");
//				vt--;
//				continue;
//			}
//			if(c==ESC)
//			{
//				ClearRow(0,0);
//				delete temp;
//				BaoLoi("Da xoa");
//				break;
//			}else if(c>=48 && c<=57)
//				{ 
//					strcpy(&temp[vt],&c);
//					cout<<temp[vt];
//				}else 
//					BaoLoi("Nhap loi!");	
//	}
//	return temp;
//}

int count_item(char td [][50])
{
	int i;
	for(i = 0; td[i][0] != NULL; ++i);
	return i;
}
//menu dong
const int dong =2;
const int cot = 2 ;
const int Up = 72;
const int Down = 80;

void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
int MenuDong(char td [][50]){
  Normal();
  system("cls");   
  cout<<"----------------------------------------------------QUAN  LY CHUYEN BAY-------------------------------------------------\n";
  int chon =0;
  int i; 
  int so_item=count_item(td);
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		              	Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  } 
  } while (1);
}

char thucdon [5][50] = {"1. Quan ly danh sach may bay       ",
			                  "2. Quan ly danh sach chuyen bay    ",
			                  "3. Quan ly danh sach ve            ",
			                  "4. Quan ly danh sach hanh khach    ",
			                  "5. Thoat chuong trinh              ",
							 };
			                  
char thucdon1 [6][50] = {"1. Them may bay  ",
			                   "2. Sua may bay   ",
			                   "3. Xoa may bay   ",
			                   "4. In danh sach  ",
			                   "5. Quay lai      ",
			                   "6. Thoat         ",
			                  };

char thucdon2 [5][50] = {"1. Create file moi       ",
			                   "2. Load file tu o dia    ",
			                   "3. Quay lai              ",
			                   "4. Thoat                 ",
								};

char thucdon4 [4][50] = {"1. Create file moi       ",
			                   "2. Load file tu o dia    ",
			                   "3. Quay lai              ",
			                   "4. Thoat                 ",
								};

char thucdon5 [6][50] = {"1. Lap chuyen bay moi    ",
			                   "2. Hieu chinh ngay gio   ",
			                   "3. Huy chuyen            ",
			                   "4. In danh sach          ",
			                   "5. Quay lai              ",
			                   "6. Thoat                 ",
								};
