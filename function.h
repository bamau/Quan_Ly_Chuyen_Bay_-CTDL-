#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
const int ENTER =13;
const int SPACE=32;
const int ESC=27;
using namespace std;
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
char *InputWord(int n)
{
	char c=0;
	char *temp=new char[n];
	for(int vt=0;vt<n;vt++)
	{
		c=getch();
		if (c== ENTER) break;
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
		}else if((c>=65 && c<=90)||(c>=90 && c<=122)||c==SPACE)
				{ 
					strcpy(&temp[vt],&c);
					cout<<temp[vt];
				}else 
					BaoLoi("Nhap loi!");
	}
	return temp;
}
char *InputNumber(int n)
{
	char c=0;
	char *temp=new char[n];
	for(int vt=0;vt<n;++vt)
	{
		c=getch();
		if(c==ENTER) break;
		else if(vt==0 && c==SPACE)
			{
				BaoLoi("Dau day khong duoc khoang trang !");
				vt--;
				continue;
			}
			if(c==ESC)
			{
				ClearRow(0,0);
				delete temp;
				BaoLoi("Da xoa");
				break;
			}else if(c>=48 && c<=57)
				{ 
					strcpy(&temp[vt],&c);
					cout<<temp[vt];
				}else 
					BaoLoi("Nhap loi!");	
	}
	return temp;
}

//menu dong
const int so_item = 4;
const int dong =2;
const int cot = 2 ;
const int Up = 72;
const int Down = 80;
char thucdon [so_item][50] = {"1. Quan ly danh sach may bay       ",
			                  "2. Quan ly danh sach chuyen bay    ",
			                  "3. Quan ly danh sach ve            ",
			                  "4. Quan ly danh sach hanh khach    ",};
void Normal () {
	SetColor(15);
	SetBGColor(0);
}
void HighLight () {
	SetColor(15);
	SetBGColor(1);
}
int MenuDong(char td [so_item][50]){
  Normal();
  system("cls");   int chon =0;
  int i; 
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
  }  // end switch
  } while (1);
}

char thucdon1 [so_item][50] = {"1. Them may bay  ",
			                   "2. Sua may bay   ",
			                   "3. Xoa may bay   ",
			                  };

char thucdon2 [so_item][50] = {"1. Create file moi       ",
			                   "2. Load file tu o dia    ",
			                  };







////HAM NHAP THONG TIN CHUYEN BAY
//void nhapcb (ChuyenBay &cb)
//{
//	fflush(stdin);
//	cout<<"Nhap ma chuyen bay: ";
//	gets(cb.macb);
//	fflush(stdin);
//	cout<<"Nhap so hieu may bay: ";
//	gets(cb.sohieu_mb);
//	fflush(stdin);
//	cout<<"Nhap ngay bay: ";
//	cin>>cb.ngay_cb.ngay>>cb.ngay_cb.thang>>cb.ngay_cb.nam;
//	fflush(stdin);
//	cout<<"Nhap gio bay: ";
//	cin>>cb.gio_cb.gio>>cb.gio_cb.phut;
//	fflush(stdin);
//	cout<<"Nhap san bay den: ";
//	gets(cb.sanbay_den);
//	fflush(stdin);
//	cout<<"Nhap trang thai: ";
//	cin>>cb.trangthai;
//};
////HAM NHAP DANH SACH CHUYEN BAY
//

