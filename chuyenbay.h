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

void Initialize (LISTCB &list)
{
	list=new ListCB;
	list->pHead=NULL;
	list->pTail=NULL;
}
ChuyenBay NhapCB()
{
	ChuyenBay cb;
	char key;
	cin.ignore();
	fflush(stdin);
	cout<<"Ma chuyen bay: ";
	gets(cb.macb);
	fflush(stdin);
	cout<<"So hieu may bay: ";
	gets(cb.sohieu_mb);
	fflush(stdin);
	cout<<"Ngay bay: ";
	cin>>cb.ngay_cb.ngay>>key>>cb.ngay_cb.thang>>key>>cb.ngay_cb.nam;
	fflush(stdin);
	cout<<"Gio bay: ";
	cin>>cb.gio_cb.gio>>key>>cb.gio_cb.phut>>key;
	fflush(stdin);
	cout<<"San bay den: ";
	gets(cb.sanbay_den);
	fflush(stdin);	
	cout<<"Trang thai: ";
	cin>>cb.trangthai;
	return cb;
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
	cout<<cb.macb<<"\t";
	cout<<cb.sohieu_mb<<"\t";
	cout<<cb.ngay_cb.ngay<<"/"<<cb.ngay_cb.thang<<"/"<<cb.ngay_cb.nam<<"\t";
	cout<<cb.gio_cb.gio<<"."<<cb.gio_cb.phut<<"'\t";
	cout<<cb.sanbay_den<<"\t";
	cout<<cb.trangthai<<endl;
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
 void InsertFirst(LISTCB &list, ChuyenBay cb)
 {
	PTRCB pNode=CreateNode(cb);
	if(list->pHead==NULL)
	{
		list->pHead=list->pTail=pNode;
	}
	else
	{
		pNode->pnext=list->pHead;
		list->pHead=pNode;
	}
 }

void InsertLast(LISTCB &list, ChuyenBay cb)
 {
	PTRCB pNode=CreateNode(cb);
	if(list->pHead==NULL)
	{
		list->pHead=list->pTail=pNode;
	}
	else
	{
		list->pTail->pnext=pNode;
		list->pTail=pNode;
	}
 }
//ham ghi du lieu xuong file
void writefile(char * filename, LISTCB &ds)
{
	ofstream fs(filename, ios::binary | ios::out );//| ios::app
	PTRCB t=ds->pHead;
	while(t!=NULL)
	{
	fs.write((char*)&t->data,sizeof(int));
	t=t->pnext;
	}
	fs.close();
}
void ReadDate(ifstream &filein, ngaybay &date)
{
	filein>>date.ngay;
	filein.seekg(1,filein.cur);
	filein>>date.thang;
	filein.seekg(1,filein.cur);
	filein>>date.nam;
}
void ReadHour(ifstream &filein, giobay &hour)
{
	filein>>hour.gio;
	filein.seekg(1,filein.cur);
	filein>>hour.phut;
	filein.seekg(1,filein.cur);
}
void DocCB(ifstream &filein, ChuyenBay &cb)
{
	filein.getline(cb.macb, 15, ',');
	filein.seekg(1,filein.cur);
	filein.getline(cb.sohieu_mb, 15, ',');
	filein.seekg(1,filein.cur);
	ReadDate(filein, cb.ngay_cb);
	filein.seekg(2,filein.cur);
	ReadHour(filein, cb.gio_cb);
	filein.seekg(2,filein.cur);
	filein.getline(cb.sanbay_den, 50, ',');
	filein.seekg(2,filein.cur);
	filein>>cb.trangthai;
}
///hàm doc du lieu tu file
void readfile(char * filename, LISTCB &ds)
{
	ifstream filein;
	filein.open(filename, ios::in);
	while(!filein.eof())
	{
		ChuyenBay cb;
		DocCB(filein, cb);
		PTRCB p =CreateNode(cb);
		InsertLast(ds, cb);
	}
	filein.close();
}
void XuatDSCB(LISTCB ds)
{
	for(PTRCB p=ds->pHead; p!=NULL; p=p->pnext)
	{
		XuatCB(p->data);
	}
}
