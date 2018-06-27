#pragma once
#include "config.h"
#include <string>
#include<cstdio>
#include <iomanip>
#define TRUE 1
#define FALSE 0 
using namespace std;

int empty(listmb &dsmb);
int full(listmb &dsmb);
void nhap_mb(MayBay &mb);
void nhapds_mb(listmb &dsmb);
void xuat_mb(MayBay mb);
void xuatds_mb(listmb dsmb);
void SaveList (listmb &dsmb, char *tenfile);
int OpenList ( listmb &dsmb, char *tenfile);
int insert_item(listmb &dsmb,int n);
int BSearch(listmb &ds,MayBay info);
int delete_item(listmb &ds,int i);
int delete_info(listmb &ds, MayBay info);
void edit_list(listmb &ds, MayBay info, MayBay result);
void Quicksort(listmb &dsmb, int left, int right);


int empty(listmb &dsmb)
{
	return(dsmb.n==0 ? TRUE : FALSE);
}
int full(listmb &dsmb)
{
	return(dsmb.n==MAXMB ? TRUE : FALSE);
}
void nhap_mb(MayBay &mb)
{
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
	cout<<endl;
	}while(mb.cho<20);
}
void nhapds_mb(listmb &dsmb)
{
	dsmb.n;
	for(int i=0; i<dsmb.n; i++)
	{
		nhap_mb(dsmb.mb[i]);
	}
	cout<<"Da nhap xong "<<dsmb.n<<" may bay!\n";
};
void xuat_mb(MayBay mb)
{
	cout<< mb.sohieu<<"\t\t"<<mb.loai<<"\t\t\t"<<mb.cho<<endl;
};
void xuatds_mb(listmb dsmb)
{
	cout<<"\t\t\t======DANH SACH CAC MAY BAY======\n\n";
	cout<<"SoHieu\t\t"<<"Loai\t\t\t"<<"Cho"<<endl;
	for(int i=0; i<dsmb.n; i++)
	{
		xuat_mb(dsmb.mb[i]);
	}
};
void SaveList (listmb &dsmb, char *tenfile)
{
  FILE *f;
  f= fopen (tenfile, "wb"); 
  if (f==NULL) { cout<< "Loi mo file de ghi"; return ; }
  
  for (int i=0; i < dsmb.n ; i++)
  {
    fwrite (&dsmb.mb, sizeof(dsmb.mb),1,f);
  }
  fclose(f);
}
int OpenList (listmb &dsmb, char *tenfile)
{
  FILE *f; 
  f= fopen (tenfile, "rb");
  if (f==NULL) { cout<< "\nLoi mo file de doc\n"; return -1 ; }
  else cout<<"\nLoad file thanh cong!\n";
  int i=0;
   while ( fread (&dsmb.mb, sizeof(dsmb.mb),1,f)!=0 ) i++;
  fclose(f);
  dsmb.n=i;
}
int insert_item(listmb &dsmb,int n)
{
	if (full(dsmb)==TRUE)
	
		cout <<"Danh sach day!";
	else if(dsmb.n<MAXMB)
		{
			for(int i=1; i<=n; i++)
				nhap_mb(dsmb.mb[dsmb.n++]);
		}
		cout<<"\nDa them "<<n<<" may bay!\n";
}
int BSearch(listmb &ds, MayBay info)
{
	int left=0;
	int right=ds.n-1;
	do
	{
		for(int i=0 ; i<ds.n ;i++)
		{
			int mid=(left+right)/2;
			if(strcmp(ds.mb[mid].sohieu, info.sohieu)==0)
				return mid;
			else if(strcmp(ds.mb[mid].sohieu, info.sohieu)==1)
				right=mid-1;
			else 
				left=mid+1;	
		}
	}while(left<=right);
	return -1;
}
void edit_list(listmb &ds, MayBay info, MayBay result)
{
	int dem=0;
	char *tenfile;
	nhap_mb(result);
	for(int i=0;i<ds.n;i++ )
	{
		if(strcmp(ds.mb[i].sohieu, info.sohieu)==0)
		{
			ds.mb[i]=result; 
			dem++;
		}
	}
	cout<<"\nDa chinh sua "<<dem<<" may bay!\n";
}
void Quicksort(listmb &dsmb, int left, int right)
{
	if(left >= right) return;
	MayBay pivot = dsmb.mb[(left + right) / 2];
	int i= left; int j= right;
	do
	{
		while (strcmp(dsmb.mb[i].sohieu, pivot.sohieu) < 0) i++;
		while (strcmp(dsmb.mb[j].sohieu, pivot.sohieu) > 0) j--;
		if(i<=j)
		{
			char sohieu[15];
			char loai[40];
			strcpy(sohieu, dsmb.mb[i].sohieu);
			strcpy(loai, dsmb.mb[i].loai);
			int cho=dsmb.mb[i].cho;		
				
			strcpy(dsmb.mb[i].sohieu, dsmb.mb[j].sohieu);
			strcpy(dsmb.mb[i].loai, dsmb.mb[j].loai);
			dsmb.mb[i].cho=dsmb.mb[j].cho;
			
			strcpy(dsmb.mb[j].sohieu, sohieu);
			strcpy(dsmb.mb[j].loai, loai);
			dsmb.mb[j].cho=cho;
			i++;
			j--;
		}
	}while(i<j);
	Quicksort(dsmb, left, j);
	Quicksort(dsmb, i, right);
}
int delete_item(listmb &ds,int i)
{
	int j;
	for(j=i+1;j<ds.n;++j)
	{
		ds.mb[j-1]=ds.mb[j];
	}
	ds.n--;
	return 1;
}
int delete_info(listmb &ds, MayBay info)
{
	int dem=0;
	for(int i=0;i<ds.n; )
	{
		if(strcmp(ds.mb[i].sohieu, info.sohieu)==0)
		{
			delete_item(ds,i);
			dem++;	
		}
		else i++;
	}
	return dem;
}
