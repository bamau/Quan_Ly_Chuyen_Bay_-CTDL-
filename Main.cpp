#include<iostream>
#include "config.h"
#include "function.h"
#include"maybay.h"

using namespace std;

int main()
{
	listmb dsmb;
	char *tenfile=new char[50];

	int choice=MenuDong(thucdon);
	switch(choice)
	{
		case 1://quan ly dsmb
			{
				Normal();
				int choice2=MenuDong(thucdon2);
				switch(choice2)
				{
					case 1:
						{	
							Normal();
							system("cls");
							cout<<"Nhap ten file can tao: ";
							gets(tenfile);
							SaveList(dsmb,tenfile);
							cout<<"Da tao thanh cong!\n";
							break;
						}
					case 2:
						{
							Normal();
							system("cls");
							cout<<"Nhap ten file trong o cung: ";
							gets(tenfile);
							OpenList(dsmb, tenfile);
							Sleep(1000);
							int choice1=MenuDong(thucdon1);
							switch(choice1)
							{
								case 1:
									{
										Normal();
										system("cls");
										int n;
										cout<<"Nhap so may bay muon them: ";
										cin>>n;
										insert_item(dsmb, n);
										Quicksort(dsmb, 0, dsmb.n-1);
										SaveList(dsmb,tenfile);
										break;
									}
								case 2:
									{
										Normal();
										system("cls");
										MayBay info, result;
										cout<<"Nhap vao so hieu may bay can sua: ";
										gets(info.sohieu);
										int kq=BSearch(dsmb, info);
										if (kq==-1)
										{
											cout<<"Khong tim thay!\n";
										}
										else
										{
											cout<<"Da tim thay. Nhap so lieu may bay moi: \n";
											edit_list(dsmb,info, result);
											Quicksort(dsmb, 0, dsmb.n-1);
											SaveList(dsmb, tenfile);
										}
										break;
									}
								case 3:
									{
										Normal();
										system("cls");
										MayBay info;
										cout<<"Nhap vao so hieu may bay can xoa: ";
										gets(info.sohieu);
										int kq=delete_info(dsmb, info);
										cout<<"Da xoa "<<kq<<" may bay!\n";
										SaveList(dsmb,tenfile);
										break;
									}
								case 4:
									{
										Normal();
										system("cls");
										xuatds_mb(dsmb);
										break;
									}
							}
							break;
						}
				}
				
			}
	}
	return 0;
}
