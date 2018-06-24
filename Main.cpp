#include<iostream>
#include "config.h"
#include "function.h"
#include"maybay.h"
#include"chuyenbay.h"

using namespace std;

//int main()
//{
//	listmb dsmb;
//	char *tenfile=new char[50];
//	char key;
//	int choice;
//	do
//	{
//		choice=MenuDong(thucdon);
//		switch(choice)
//		{
//			case 1://quan ly dsmb
//				{
//					Normal();
//					int choice2;
//					do
//					{
//						choice2=MenuDong(thucdon2);
//						switch(choice2)
//						{
//							case 1:
//								{	
//									Normal();
//									system("cls");
//									cout<<"Nhap ten file can tao: ";
//									gets(tenfile);
//									SaveList(dsmb,tenfile);
//									cout<<"Da tao thanh cong file: '"<<tenfile<<"'\n";
//									Sleep(1500);
//									break;
//								}
//							case 2:
//								{
//									Normal();
//									system("cls");
//									cout<<"Nhap ten file trong o cung: ";
//									gets(tenfile);
//									int check=OpenList(dsmb, tenfile);									
//									Sleep(1000);
//									if (check==-1)
//										break;
//									int choice1;
//									do
//									{
//										choice1=MenuDong(thucdon1);
//										switch(choice1)
//										{
//											case 1:
//												{
//													Normal();
//													system("cls");
//													int n;
//													cout<<"Nhap so may bay muon them: ";
//													cin>>n;
//													cout<<endl;
//													insert_item(dsmb, n);
//													Quicksort(dsmb, 0, dsmb.n-1);
//													SaveList(dsmb,tenfile);
//													break;
//												}
//											case 2:
//												{
//													Normal();
//													system("cls");
//													MayBay info, result;
//													cout<<"Nhap vao so hieu may bay can sua: ";
////													char *temp=new char[15];
////													temp=InputWord();
////													strcpy(info.sohieu, temp);
//													gets(info.sohieu);
//													int kq=BSearch(dsmb, info);
//													if (kq==-1)
//													{
//														cout<<"\nKhong tim thay!\n";
//													}
//													else
//													{
//														cout<<"\nTim thay. Nhap so lieu may bay moi: \n";
//														edit_list(dsmb,info, result);
//														Quicksort(dsmb, 0, dsmb.n-1);
//														SaveList(dsmb, tenfile);
//													}
//													break;
//												}
//											case 3:
//												{
//													Normal();
//													system("cls");
//													MayBay info;
//													cout<<"Nhap vao so hieu may bay can xoa: ";
//													gets(info.sohieu);
//													int kq=delete_info(dsmb, info);
//													cout<<"Da xoa "<<kq<<" may bay!\n";
//													SaveList(dsmb,tenfile);
//													break;
//												}
//											case 4:
//												{
//													Normal();
//													system("cls");
//													xuatds_mb(dsmb);
//													break;
//												}
//											case 5:
//												break;
//											case 6:
//												{
//													Normal();
//													system("cls");
//													cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
//													key=getch();
//													if(key==ENTER)
//													{
//														system("cls");
//														cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
//														return 0;
//													}
//													break;
//												}
//										}
//										if(choice1==5)
//											break;
//										system("pause");
//									}while(choice1!=5);
//									break;
//								}
//							case 3:
//								break;
//							case 4:
//								{
//									Normal();
//									system("cls");
//									cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
//									key=getch();
//									if(key==ENTER)
//									{
//										system("cls");
//										cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
//										return 0;
//									}
//									break;
//								}
//						}
//					}while(choice2!=3);	
//				}
//			case 2:
//				{
//					Normal();
//					system("cls");
//					LISTCB list;
//					Initialize(list);
//					char*filename=new char[50];
//					cout<<"Nhap tenfile trong o cung: ";
//					gets(filename);
//					readfile(filename, list);
//					XuatDSCB(list);
////					for(int i=1; i<=n; i++)
////					{
////						ChuyenBay cb=NhapCB();
////						PTRCB p=CreateNode(cb);
////						InsertFirst(list,cb);
////					}
////					cout<<"------DSCB------\n";
//				
//					system("pause");
//					break;
//				}
//			case 3:
//				{
//					break;
//				}
//			case 4:
//				{
//					break;
//				}
//			case 5:
//				Normal();
//				system("cls");
//				break;
//		}
//		if(choice==5)
//			cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
//	}while(choice!=5);
//	return 0;
//}

int main()
{
	LISTCB list;
	Initialize(list);
	ChuyenBay cb;
	char*filename=new char[50];
	cout<<"Nhap tenfile trong o cung: ";
	gets(filename);
	readfile(filename, list);
	XuatDSCB(list);
	return 0;
}
