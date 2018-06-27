#pragma once
#include "config.h"
#include <string>
#include<cstdio>
#include <iomanip>
#define TRUE 1
#define FALSE 0 
using namespace std;

void SaveListTicket (ListVe &ds, char *tenfile)
{
  FILE *f;
  f= fopen (tenfile, "wb"); 
  if (f==NULL) { cout<< "Loi mo file de ghi"; return ; }
  
  for (int i=0; i < ds.n ; i++)
  {
    fwrite (&ds.dsve, sizeof(ds.dsve),1,f);
  }
  fclose(f);
}
int OpenListTicket (ListVe &ds, char *tenfile)
{
  FILE *f; 
  f= fopen (tenfile, "rb");
  if (f==NULL) { cout<< "Loi mo file de doc"; return -1 ; }
  else cout<<"Load file thanh cong!\n";
  int i=0;
   while ( fread (&ds.dsve, sizeof(ds.dsve),1,f)!=0 ) i++;
  fclose(f);
  ds.n=i;
}
//HAM NHAP THONG TIN VE 
void nhap_ve(Ve &ve)
{
	cout<<"Nhap so thu tu: ";
	cin>>ve.stt;
	fflush(stdin);
	cout<<"Nhap ma chuyen bay: ";
	gets(ve.macb);
	fflush(stdin);
	cout<<"Nhap so cmnd: ";
	cin>>ve.cmnd;
};
//HAM NHAP DANH SACH VE
void  nhapds_ve(ListVe &ds)
{
	for(int i=0;i<ds.n;i++)
	{
		nhap_ve(ds.dsve[i]);
	}
};
//HAM XUAT THONG TIN VE
void xuat_ve(Ve ve)
{
	cout<<ve.stt<<setw(10);
	cout<<ve.macb<<setw(20);
	cout<<ve.cmnd<<endl;
};
//HAM XUAT DANH SACH VE
void xuat_dsve (ListVe ds)
{
	cout<<"STT"<<setw(10)<<"MaCB"<<setw(20)<<"CMND\n";
	for(int i=0;i<ds.n;i++)
	{
		xuat_ve(ds.dsve[i]);
	}
}
