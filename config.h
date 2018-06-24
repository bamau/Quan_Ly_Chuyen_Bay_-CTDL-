#pragma once
#include <mylib.h>
//KHAI BAO DANH SACH MAY BAY TUYEN TINH
const int MAXMB=100; 
struct MayBay
{
	char sohieu[15];
	char loai[40];
	int cho;   // so luong >= 20 cho
};
struct listmb
{
	int n=0;//so luong may bay
	MayBay mb[MAXMB];//DS mang cac may bay
};
listmb dsmb;

//KHAI BAO THONG TIN VE;
struct Ve
{
	int stt;
	char cmnd[15];
};
struct danhsachve
{
	int n;
	Ve *dsve;
};
 
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
	danhsachve ds;
};
struct Node
{
	ChuyenBay data;
	Node *pnext; //tro den phan tu ke tiep
};
typedef struct Node *PTRCB;
struct ListCB 
{
	PTRCB pHead;
	PTRCB pTail;
};
typedef struct ListCB *LISTCB;




