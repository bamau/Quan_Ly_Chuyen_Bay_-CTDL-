#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "config.h"
#include <string>
#include<cstdio>
#include <iomanip>
#define TRUE 1
#define FALSE 0 
using namespace std;

void DeleteInfo(LISTCB &list, ChuyenBay cb);
void ClearList(LISTCB &ds);
void DeleteAfter(LISTCB &list, PTRCB p);
void DeleteLast(LISTCB &list);
void DeleteFrist(LISTCB &list);
void XuatDSCB(LISTCB ds);
void readfile(char * filename, LISTCB &ds);
void DocCB(ifstream &filein, ChuyenBay &cb);
void writefile(char * filename, LISTCB &ds);
void InsertLast(LISTCB &list, ChuyenBay cb);
void InsertFirst(LISTCB &list, ChuyenBay cb);
int SizeOfList (LISTCB list);
void XuatCB (ChuyenBay cb);
PTRCB CreateNode (ChuyenBay cb);
ChuyenBay NhapCB();
void CreateList (LISTCB &list); 
void SortList(LISTCB &list);
void NhapNgay(ChuyenBay &cb);
void NhapGio(ChuyenBay &cb);
PTRCB SearchInfo(LISTCB ds, ChuyenBay cb);


void CreateList (LISTCB &list)
{
	list=new ListCB;
	list->pHead=NULL;
	list->pTail=NULL;
}
int EmptyList(LISTCB ds)
{
	return(ds->pHead == NULL ? TRUE : FALSE);
}
void NhapCB(ChuyenBay &cb)
{
	char key;
	fflush(stdin);
	cout<<"Ma chuyen bay: ";
	gets(cb.macb);
	fflush(stdin);
	cout<<"So hieu may bay: ";
	gets(cb.sohieu_mb);
	fflush(stdin);
	cout<<"San bay den: ";
	gets(cb.sanbay_den);
	NhapNgay(cb);
	NhapGio(cb);
	cout<<"Trang thai: ";
	cin>>cb.trangthai;
}

void NhapNgay(ChuyenBay &cb)
{
	char key;
	fflush(stdin);
	cout<<"Ngay bay: ";
	do
	{
		cin>>cb.ngay_cb.ngay;
	}while(cb.ngay_cb.ngay>=31&&cb.ngay_cb.ngay<0);
	cin>>key;
	do
	{
		cin>>cb.ngay_cb.thang;
	}while((cb.ngay_cb.thang<0)&&((cb.ngay_cb.ngay==30&&cb.ngay_cb.thang==2)||(cb.ngay_cb.ngay==31&&cb.ngay_cb.thang==(2||4||6||9||11))));
	cin>>key;
	do
	{
		cin>>cb.ngay_cb.nam;
	}while(cb.ngay_cb.nam<0);
}

void NhapGio(ChuyenBay &cb)
{
	char key;
	fflush(stdin);
	cout<<"Gio bay: ";
	do
	{
		cin>>cb.gio_cb.gio;
	}while(cb.gio_cb.gio<0&&cb.gio_cb.gio>24);
	cin>>key;
	do
	{
		cin>>cb.gio_cb.phut;
	}while(cb.gio_cb.phut<0&&cb.gio_cb.phut>60);
	cin>>key;
}
PTRCB CreateNode (ChuyenBay cb)
{
	PTRCB pNode = new Node;
	if(pNode == NULL)
	{
		cout<<"Cap phat bo nho that bai!\n";
		return NULL;
	}
	pNode->data=cb;
	pNode->pnext=NULL;
	return pNode;
}

void XuatCB (ChuyenBay cb)
{
	cout<<setw(5)<<cb.macb<<setw(10);
	cout<<cb.sohieu_mb<<setw(20);
	cout<<cb.sanbay_den<<setw(12);
	cout<<cb.ngay_cb.ngay<<setw(1)<<"/"<<setw(2)<<cb.ngay_cb.thang<<setw(1)<<"/"<<setw(4)<<cb.ngay_cb.nam<<setw(6);
	cout<<cb.gio_cb.gio<<setw(1)<<"."<<setw(2)<<cb.gio_cb.phut<<setw(1)<<"'"<<setw(10);
	cout<<cb.trangthai;
}

int SizeOfList (LISTCB list)
{
	PTRCB pTemp=list->pHead;
	int nSize=0;
	while(pTemp!=NULL)
	{
		pTemp=pTemp->pnext;
		nSize++;
	}
	return nSize;
}
void InsertFirst(LISTCB &list, PTRCB p)
{
	if(list->pHead==NULL)
	{
		list->pHead=list->pTail=p;
	}
	else
	{
		p->pnext=list->pHead;
		list->pHead=p;
	}
}

void InsertLast(LISTCB &list, PTRCB p)
{
	if(list->pHead==NULL)
	{
		list->pHead=list->pTail=p;
	}
	else
	{
		list->pTail->pnext=p;
		list->pTail=p;
	}
}

void XuatDSCB(LISTCB ds)
{
	if(EmptyList(ds)==TRUE)
		cout<<"\nDanh sach rong!\n";
	else
		cout<<setw(5)<<"MaCb"<<setw(10)<<"SoHieuMB"<<setw(20)<<"SanBayDen"<<setw(20)<<"NgayBay"<<setw(10)<<"GioBay"<<setw(15)<<"TrangThai\n";
	for(PTRCB p=ds->pHead; p!=NULL; p=p->pnext)
	{
		XuatCB(p->data);
		cout<<endl;
	}
}
void DeleteFrist(LISTCB &list)
{
	
	if (list->pHead == NULL)
	{
		return;
	}
	PTRCB p = list->pHead; 
	list->pHead = list->pHead->pnext;
	delete p;
}
void DeleteLast(LISTCB &list)
{
	if(list->pHead==NULL)
		return;
	if(list->pHead->pnext=NULL)
	{
		DeleteFrist(list);
		return;
	}
	for(PTRCB p=list->pHead; p!=NULL; p=p->pnext)
	{
		if(p->pnext==list->pTail)
		{
			delete list->pTail;
			p->pnext=NULL;
			list->pTail=p;
			return;
		}
	}
}
void DeleteAfter(LISTCB &list, PTRCB p)
{
	for(PTRCB k=list->pHead; k!=NULL; k=k->pnext)
	{
		if(stricmp(k->data.macb, p->data.macb)==0)
		{
			PTRCB g=k->pnext;
			k->pnext=g->pnext;
			delete g;
		}
	}
}
void DeleteInfo(LISTCB &list, ChuyenBay cb)
{
	if(list->pHead=NULL)
		return;
	if(stricmp(list->pHead->data.macb, cb.macb)==0)
	{
		DeleteFrist(list);
		return;
	}
	if(stricmp(list->pTail->data.macb, cb.macb)==0)
	{
		DeleteLast(list);
		return;
	}
	PTRCB g=new Node;
	for(PTRCB k=list->pHead; k != NULL; k=k->pnext)
	{
		if(stricmp(k->data.macb, cb.macb)==0)
		{
			g->pnext=k->pnext;
			delete k;
			return;
		}
		g=k;
	}
}
void ClearList(LISTCB &ds)
{
	PTRCB p=NULL;
	while(ds->pHead!=NULL)
	{
		p=ds->pHead;
		ds->pHead=ds->pHead->pnext;
		delete p; 
	}
}
void SortList(LISTCB &list)
{
	for(PTRCB p=list->pHead; p!=NULL; p=p->pnext)
	{
		
		for(PTRCB q=p->pnext; q!=NULL; q=q->pnext)
		{
			if(strcmp(p->data.macb, q->data.macb)>0)
			{
				ChuyenBay temp;
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}
PTRCB SearchInfo(LISTCB ds, ChuyenBay cb)
{
	for(PTRCB p=ds->pHead; p!=NULL; p=p->pnext)
	{
		if(stricmp(p->data.macb, cb.macb)==0)
			return p;
		return NULL;
	}
}

void GhiDuLieu(LISTCB list, char*filename)
{
    FILE *f ;
    f=fopen(filename,"wb");
    for (PTRCB p=list->pHead; p!=NULL ;p=p->pnext)
        fwrite(&p->data,sizeof(p->data),1,f);
    fclose(f) ;
    cout<<"\nGHI DU LIEU VAO FILE THANH CONG \n"    ;
}
void DocDuLieu(LISTCB &list, char*filename)
{
    FILE *f ;
    ChuyenBay cb;
    f=fopen(filename,"rb");
    if (f==NULL )
        cout<<"\nFILE DU LIEU KHONG TON TAI VUI LONG TAO MOI DANH SACH \n \n \n";
    else
    {
    	cout<<"\nLoad file thanh cong!\n";
    	Sleep(1500);
        while(fread(&cb,sizeof(ChuyenBay),1,f)==1)
        {
        	PTRCB p=CreateNode(cb);
            InsertLast(list,p);
        }
        fclose(f);
        cout<<"\n DA NAP DU LIEU VAO BO NHO \n"    ;
    }
}
