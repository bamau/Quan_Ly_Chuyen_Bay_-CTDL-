#include<iostream>
#include "config.h"
#include"maybay.h"
#include"chuyenbay.h"
#include"ve.h"
#include"hanhkhach.h"
using namespace std;

int main()
{
	char key;
	int choice;
	do
	{
		choice=MenuDong(thucdon);
		switch(choice)
		{
			case 1://quan ly dsmb
				{
					Normal();
					char *tenfile=new char[50];
					listmb dsmb;
					int choice2;
					char key2;
					do
					{
						choice2=MenuDong(thucdon2);
						switch(choice2)
						{
							case 1:
								{	
									Normal();
									system("cls");
									cout<<"Nhap ten file can tao: ";
									tenfile=InputWord();
									SaveList(dsmb,tenfile);
									cout<<"Da tao thanh cong file: '"<<tenfile<<"'\n";
									Sleep(1500);
									break;
								}
							case 2:
								{
									Normal();
									system("cls");
									cout<<"Nhap ten file trong o cung: ";
									tenfile=InputWord();
									int check=OpenList(dsmb, tenfile);									
									Sleep(1500);
									if (check==-1)
										break;
									int choice1;
									char key1;
									do
									{
										choice1=MenuDong(thucdon1);
										switch(choice1)
										{
											case 1:
												{
													Normal();
													system("cls");
													int n;
													cout<<"Nhap so may bay muon them: ";
													cin>>n;
													cout<<endl;
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
													char *temp=new char[15];
													temp=InputWord();
													strncpy(info.sohieu, temp, strlen(temp));
												//	gets(info.sohieu);
													int kq=BSearch(dsmb, info);
													if (kq==-1)
													{
														cout<<"\nKhong tim thay!\n";
													}
													else
													{
														cout<<"\nTim thay. Nhap so lieu may bay moi: \n";
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
											case 5:
												{
													Normal();
													break;
												}
											case 6:
												{
													Normal();
													system("cls");
													cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
													key1=getch();
													if(key1==ENTER)
													{
														system("cls");
														cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
														return 0;
													}
													break;
												}
										}
										if(choice1==1 || choice1 == 2 || choice1 == 3 || choice1 == 4)
											system("pause");
										else if(choice1==5)
												break;	
									}while(choice1!=5);
									break;
								}
							case 3:
								{
									Normal();
									break;	
								}
							case 4:
								{
									Normal();
									system("cls");
									cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
									key2=getch();
									if(key2==ENTER)
									{
										system("cls");
										cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
										return 0;
									}
									break;
								}
						}
					}while(choice2!=3);	
					break;
				}
			case 2:
				{
					Normal();
					system("cls");
					ChuyenBay cb;
					LISTCB list;
					CreateList(list);
					int choice4;
					int check;
					char key4;
					char*filename=new char[50];
					do
					{
						choice4=MenuDong(thucdon4);
						switch(choice4)
						{
							case 1:
							{
								Normal();
								system("cls");
								cout<<"Nhap ten file can tao: ";
								gets(filename);
								GhiDuLieu(list, filename);
								cout<<"Da tao thanh cong file '"<<filename<<"'\n";
								Sleep(1500);
								break;
							}
							case 2:
							{
								Normal();
								system("cls");
								cout<<"Nhap filename tu o cung: ";
								gets(filename);
								DocDuLieu(list, filename);
//								if(check==-1)
//										break;
								int choice5;
								char key5;
								do
								{
									choice5=MenuDong(thucdon5);
									switch(choice5)
									{
										case 1:
											{
												Normal();
												system("cls");
												ChuyenBay cb;
												NhapCB(cb);
												PTRCB p=CreateNode(cb);
												InsertLast(list, p);
											//	XuatDSCB(list);
											//	SortList(list);
												GhiDuLieu(list, filename);
												Sleep(1500);
												break;
											}
										case 2:
											{
												Normal();
												system("cls");
												ChuyenBay info, cb;
												cout<<"Nhap MaCB muon sua: ";
												gets(info.macb);
												PTRCB p=SearchInfo(list, info);
												system("cls");
												XuatCB(p->data);
												cout<<"\nMoi nhap thong tin muon sua: ";
												NhapCB(cb);
												DeleteInfo(list, p->data);
												PTRCB q=CreateNode(cb);
												InsertLast(list, q);
												GhiDuLieu(list, filename);
												cout<<"\nDa chinh sua thanh cong!\n";
												break;
											}
										case 3:
											{
												Normal();
												system("cls");
												ChuyenBay info, cb;
												cout<<"Nhap MaCB muon huy chuyen: ";
												gets(info.macb);
												DeleteInfo(list,info);
												cout<<"\nDa huy thanh cong chuyen bay!\n";
												break;
											}
										case 4:
											{
												Normal();
												system("cls");
												XuatDSCB(list);
												system("pause");
												break;
											}
										case 5:
											{
												Normal();
												break;
											}
										case 6:
											{
												Normal();
												system("cls");
												cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
												key5=getch();
												if(key5==ENTER)
												{
													system("cls");
													cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
													return 0;
												}
												break;
											}
									}
								}while(choice5!=5);
								break;	
							}
						case 3:
							{
								Normal();
								break;
							}
						case 4:
							{
								Normal();
								system("cls");
								cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
								key4=getch();
								if(key4==ENTER)
								{
									system("cls");
									cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
									return 0;
								}
								break;
							}	
						}
					}while(choice4 != 3);					
					ClearList(list);
					break;
				}
			case 3:
				{
					Normal();
					system("cls");
					ListVe ds;
					ds.n=1;
					char*filename=new char[50];
					cout<<"Nhap tenfile trong o cung: ";
					gets(filename);
//					nhapds_ve(ds);
//					SaveListTicket(ds, filename);
					OpenListTicket(ds, filename);
					xuat_dsve(ds);
					system("pause");
					break;
				}
			case 4:
				{
					Normal();
					system("cls");
					TREE root;
					CreateTree(root);
					HanhKhach hk;
					int check;
					char *name=new char[50];
					cout<<"Nhap tenfile tu o cung: ";
					gets(name);
//					NhapHK(hk);
//					NODE*p=New_Node(hk);
//					InsertNode(root, p);
//					GhiDuLieuHK(root, name);
					DocDuLieuHK(root, name);
//					cout<<setw(4)<<"CMND"<<setw(30)<<"Ho va ten"<<setw(10)<<"Phai\n";
					display();
					DuyetNLR(root);
					system("pause");
					break;
				}
			case 5:
				{
					Normal();
					system("cls");
					int check;
					cout<<"Ban muon thoat?. Nhan 'ENTER' de xac nhan hoac 'BACK' de quay lai: ";
					key=getch();
					if(key==ENTER)
					{
						system("cls");
						cout<<"\n\t\t\t\tCam on ban!. Hen gap lai!\n";
						return 0;
					}
					break;
				}
		}
	}while(choice==5||choice!=1||choice!=2||choice!=3||choice!=4);
	return 0;
}
