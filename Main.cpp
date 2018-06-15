#include<iostream>
#include "config.h"
#include "function.h"
#include"maybay.h"

using namespace std;

int main()
{
	switch (MenuDong(thucdon))
	{
		case 1://quan ly danh sach may bay
		{
//			switch(MenuDong(thucdon2))	
//			{
//				case 1:
//					cout<<"Nhap ten file muon tao: ";
//					gets(tenfile);
//					
//			}
//		}
			switch (MenuDong(thucdon1))
			{
				char *tenfile;
				case 1://them may bay 
					char key;
					insert_item(dsmb);
					xuatds_mb(dsmb);
					cout<<endl;
					SaveList(dsmb,tenfile);
					cout<<"Ban co muon luu danh sach khong ? Nhap(Y/N): ";
					key=getch();
					if(key=='y')
					{
						cout<<endl;
						cout<<"Nhap ten file muon tao: ";
						cin>>tenfile;
					}else break;
					break;
				case 2://sua may bay
						
						
					break;
				case 3://xoa may bay
						
							
					break;
			}
		}
		break;
		case 2://quan ly danh sach chuyen bay
			
			
		break;
		case 3://quan ly danh sach ve
			
			
		break;
		case 4://quan ly danh sach hanh khach
			
			
		break;	
	}
}
