#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
const int ENTER =13;
const int SPACE=32;
const int ESC=27;
const int BACK=8;
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
char *InputWord()
{
	char c=0;
	char *temp=new char[strlen(temp)];
	for(int vt=0;vt<strlen(temp);vt++)
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
		}else if((c>=65 && c<=90)||(c>=90 && c<=122)||(c>=48 && c<=57)||c==SPACE)
				{ 
					strcpy(&temp[vt],&c);
					cout<<temp[vt];
				}else 
					BaoLoi("Nhap loi!");
	}
	return temp;
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
  }  // end switch
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

char thucdon2 [4][50] = {"1. Create file moi       ",
			                   "2. Load file tu o dia    ",
			                   "3. Quay lai              ",
			                   "4. Thoat                 ",};









