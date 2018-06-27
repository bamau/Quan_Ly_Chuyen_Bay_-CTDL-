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

void CreateTree (TREE &root)
{
	root=NULL;
}

void InsertNode(TREE &root, NODE *q)
{
	if(root==NULL)
	{
		NODE *p=new NODE;
		p->data=q->data;
		p->pLeft=NULL;
		p->pRight=NULL;
		root=p;
	}
	else
	{
		if(root->data.CMND > q->data.CMND)
		{
			InsertNode(root->pLeft, q);
		}else if(root->data.CMND < q->data.CMND)
		{
			InsertNode(root->pRight, q);
		}
	}
}
NODE* New_Node(HanhKhach &hk)
{
	NODE *p=new NODE;
	p->data=hk;
	p->pLeft=p->pRight=NULL;
	return p;
}

NODE* Search(TREE root, HanhKhach hk)
{
	if(root=NULL)
		return NULL;
	else
	{
		if(root->data.CMND > hk.CMND)
		{
			Search(root->pLeft, hk);
		}
		else if(root->data.CMND < hk.CMND)
		{
			Search(root->pRight, hk);
		}
		else
			return root;
	}
}

void GhiDuLieuHK(TREE root, char*filename)
{
    FILE *f ;
    f=fopen(filename,"wb");
    fwrite(&root->data,sizeof(root->data),1,f);    
    fclose(f) ;
    cout<<"\nGHI DU LIEU VAO FILE THANH CONG \n"    ;
}
void DocDuLieuHK(TREE &root, char*filename)
{
    FILE *f ;
	HanhKhach hk;
    f=fopen(filename,"rb");
    if (f==NULL )
        cout<<"\nFILE DU LIEU KHONG TON TAI VUI LONG TAO MOI DANH SACH \n \n \n";
    else
    {
    	cout<<"\nLoad file thanh cong!\n";
    	Sleep(1500);
        while(fread(&hk,sizeof(HanhKhach),1,f)==1)
        {
        	NODE *p=New_Node(hk);
            InsertNode(root, p);
        }
        fclose(f);
    }
}
void NhapHK(HanhKhach &hk)
{
	fflush(stdin);
	cout<<"CMND: ";
	cin>>hk.CMND;
	fflush(stdin);
	cout<<"Ho va ten: ";
	gets(hk.HoTen);
	fflush(stdin);
	cout<<"Phai: ";
	gets(hk.Phai);
}
void display()
{
cout<<"            DANH SACH HANH KHACH                  \n";
cout<<"|------------------------------------------------|\n";
cout<<"|        CMND       |          TEN        | PHAI |\n";
cout<<"|------------------------------------------------|\n";

}
void Print(TREE root)
{
	gotoxy(0, wherey());
	cout<<"|   "<<root->data.CMND;
	gotoxy(20,wherey());
	cout<<"|   "<<root->data.HoTen;
	gotoxy(42, wherey());
	cout<<"|  "<<root->data.Phai;
	gotoxy(49, wherey());
	cout<<"|\n";
}
void DuyetNLR(TREE root)
{
	if(root != NULL)
	{
		Print(root);
		DuyetNLR(root->pLeft);
		DuyetNLR(root->pRight);
	}
}
