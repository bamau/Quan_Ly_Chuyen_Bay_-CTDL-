#pragma once
#include "config.h"
#include <string>
#include<cstdio>
#include <iomanip>
#define TRUE 1
#define FALSE 0 

int empty(listmb dsmb)
{
	return(dsmb.n==0 ? TRUE : FALSE);
}

int full(listmb dsmb)
{
	return(dsmb.n==MAXMB ? TRUE : FALSE);
}


//HAM NHAP THONG TIN MAY BAY
void nhap_mb(MayBay &mb)
{
	system("cls");
	fflush(stdin);
	cout<<"Nhap so hieu may bay: ";
	gets(mb.sohieu);
	fflush(stdin);
	cout<<"Nhap loai may bay: ";
	gets(mb.loai);
	do
	{
	fflush(stdin);
	cout<<"Nhap so ghe ngoi: ";
	cin>>mb.cho;
	}while(mb.cho<20);
}

void nhapds_mb(listmb &dsmb)//HAM NHAP DANH SACH MAY BAY
{
	dsmb.n;
	for(int i=0; i<dsmb.n; i++)
	{
		nhap_mb(dsmb.mb[i]);
	}
};
//HAM XUAT THONG TIN MOT MAY BAY
void xuat_mb(MayBay mb)
{
	cout<< mb.sohieu<<setw(15)<<mb.loai<<setw(15)<<mb.cho<<setw(5);
};
//HAM XUAT DANH SACH MAY BAY
void xuatds_mb(listmb dsmb)
{
	cout<<"So Hieu"<<setw(15)<<"Loai"<<setw(15)<<"Cho"<<setw(5)<<endl;
	for(int i=0; i<dsmb.n; i++)
	{
		xuat_mb(dsmb.mb[i]);
	}
};
// HAM KIEM TRA DS DA DAY CHUA
int kt_full(listmb dsmb)
{
	return (dsmb.n==	MAXMB ? TRUE : FALSE);
}
// HAM THEM MAY BAY VAO DS MAY BAY
//void insert_mb(listmb &dsmb, int i, int info)
//{
//	int j;
//	if(i<0||i>dsmb.n)
//	cout<<"Vi tri them khong phu hop!\n";
//	else if(kt_full(dsmb)==1)
//		cout<<"Danh sach da day!";
//		else
//		{
//		cout<<"Nhap vao info may bay: ";
//		info==nhap_mb(mb);
//			if(i==0)i=1;
//			for(j=dsmb.n-1;j>=i-1;j--)
//				dsmb.mb[j+1]=dsmb.mb[j];
//			dsmb.mb[i-1]=info;
//			dsmb.n++;
//		}
//		
//}

void SaveList (listmb &dsmb, char *tenfile){
  FILE *f;// khai bao bien file
  f= fopen (tenfile, "w"); 
  if (f==NULL) { printf ("Loi mo file de ghi"); return ; }
  
  for (int i=0; i < dsmb.n ; i++)
  {
    fwrite (&dsmb.mb[i].sohieu, sizeof(dsmb.mb[i].sohieu),1,f);
  	fwrite (&dsmb.mb[i].loai, sizeof(dsmb.mb[i].loai),1,f);
  	fwrite (&dsmb.mb[i].cho, sizeof(dsmb.mb[i].cho),4,f);
  }
  fclose(f);
}

//

int insert_item(listmb &dsmb)
{
	MayBay mb;
	if (full(dsmb)==TRUE)
	
		cout <<"Danh sach day!";
	else if(dsmb.n<MAXMB)
		{
			nhap_mb(dsmb.mb[dsmb.n++]);
		}
		system("cls");
		cout<<"Da them thanh cong!\n";
}

