#include<bits/stdc++.h>
using namespace std;

struct DMY
{
	int ngay;
	int thang;
	int nam;
};
struct utilities
{
	long long id;
	string name;
	string status;
	DMY date;	
};
void themThietBi(utilities* database, map<int,bool>& mp,int& soThuTu,map<long long,long long>& mpCheck)
{
	mp[soThuTu] = 1;
	utilities newDevice;
	cout<<"Tao thiet bi...."<<endl;
	cout<<"Nhap ma so san pham :"<<endl;
	cin>>newDevice.id;
	mpCheck[newDevice.id] = soThuTu;
	cin.ignore();
	cout<<"Nhap ten san pham :"<<endl;
	getline(cin, newDevice.name);
	cout<<"Nhap trang thai san pham :"<<endl;
	getline(cin, newDevice.status);
	cout<<"Nhap ngay bao tri :"<<endl;
	cin>>newDevice.date.ngay;
	cout<<"Nhap thang bao tri :"<<endl;
	cin>>newDevice.date.thang;
	cout<<"Nhap nam bao tri :"<<endl;
	cin>>newDevice.date.nam;
	database[soThuTu] = newDevice;
	soThuTu++;
	cout<<"Thiet bi da duoc them thanh cong !"<<endl;
}
void xoaThietBi(utilities* database, map<int,bool>& mp, map<long long,long long>& mpCheck)
{
	cout<<"Xoa san pham..."<<endl;
	long long index=-1;
	utilities newDevice;
	cout<<"Hay nhap ma so san pham can xoa :"<<endl;
	cin>>index;
	while(mp[mpCheck[index]]==0)
	{
		cin>>index;
		cout<<"Khong ton tai san pham co ma so "<<index<<"!, Hay thu lai..."<<endl;
	}
	mp[mpCheck[index]] = 0;
	cout<<"San pham da duoc xoa thanh cong !"<<endl;
}
void xuatDanhSach(utilities* database, map<int,bool>& mp)
{
	for(int i=0;i<1000;i++)
	{
		if(mp[i] == 1)
		{
			cout<<"Thong tin san pham :"<<endl;
			cout<<"Ma so san pham :"<<database[i].id<<endl;
			cout<<"Ten san pham :"<<database[i].name<<endl;
			cout<<"Trang thai san pham :"<<database[i].status<<endl;
			cout<<"Ngay bao tri tiep theo :"<<database[i].date.ngay<<"/"<<database[i].date.thang<<"/"<<database[i].date.nam<<endl;
			cout<<endl;
		}
	}
}
void reportProblems(utilities* database, map<int,bool>& mp, map<long long,long long>& mpCheck)
{
	cout<<"Hay nhap ma so san pham can bao cao loi : "<<endl;
	long long idCheck;
	cin>>idCheck;
	while(mp[mpCheck[idCheck]] == 0)
	{
		cout<<"Ma so san pham khong ton tai ! Hay thu lai..."<<endl;
		cin>>idCheck;
	}
	cout<<"Da tim thay san pham, hay nhap loi:"<<endl;
	string s;
	cin.ignore();
	getline(cin, s);
	database[mpCheck[idCheck]].status = s;
	cout<<"Bao cao loi thanh cong!"<<endl;
}
void baoTri(utilities* database, map<int,bool>& mp, map<long long,long long>& mpCheck)
{
	cout<<"Hay nhap ma so san pham can bao tri :"<<endl;
	long long idCheck;
	cin>>idCheck;
	while(mp[mpCheck[idCheck]] == 0)
	{
		cout<<"Ma so san pham khong ton tai ! Hay thu lai..."<<endl;
		cin>>idCheck;
	}
	cout<<"Da tim thay san pham !"<<endl;
	cout<<"Sau khi bao tri san pham co loi gi khong? Neu khong hay go ok ..."<<endl;
	string s;
	cin.ignore();
	getline(cin, s);
	database[mpCheck[idCheck]].status = s;
	cout<<"Hay nhap thoi gian bao tri tiep theo:"<<endl;
	cout<<"Ngay : "<<endl;
	cin>>database[mpCheck[idCheck]].date.ngay;
	cout<<"Thang : "<<endl;
	cin>>database[mpCheck[idCheck]].date.thang;
	cout<<"Nam : "<<endl;
	cin>>database[mpCheck[idCheck]].date.nam;

	cout<<"Bao tri thanh cong!"<<endl;
	
}
void traCuu(utilities* database,map<int,bool>& mp, map<long long,long long>& mpCheck)
{
	cout<<"Hay nhap ma so san pham can tra cuu :"<<endl;
	long long idCheck;
	cin>>idCheck;
	while(mp[mpCheck[idCheck]] == 0)
	{
		cout<<"Ma so san pham khong ton tai ! Hay thu lai..."<<endl;
		cin>>idCheck;
	}
	cout<<"Da tim thay thong tin san pham :"<<endl;
	cout<<"Ma so san pham :"<<database[mpCheck[idCheck]].id<<endl;
	cout<<"Ten san pham :"<<database[mpCheck[idCheck]].name<<endl;
	cout<<"Trang thai san pham :"<<database[mpCheck[idCheck]].status<<endl;
	cout<<"Ngay bao hanh tiep theo :"<<database[mpCheck[idCheck]].date.ngay<<"/"<<database[mpCheck[idCheck]].date.thang<<"/"<<database[mpCheck[idCheck]].date.nam<<endl;
	cout<<endl;
}
int main()
{
    char choices='a';
    cout<<"Chao mung den voi chuong trinh quan ly thiet bi !"<<endl;
    cout<<"Hay nhap phim chuc nang tuong ung voi so thu tu :"<<endl;
    cout<<"1.Them thiet bi"<<endl;
    cout<<"2.Xoa thiet bi"<<endl;
    cout<<"3.Xuat danh sach cac thiet bi"<<endl;
    cout<<"4.Bao cao loi cua thiet bi"<<endl;
    cout<<"5.Bao tri"<<endl;
    cout<<"6.Tra cuu thiet bi qua id"<<endl;
    cout<<"7.Ket thuc chuong trinh"<<endl;
    cout<<endl;
    utilities* database = (utilities*)malloc(500*sizeof(utilities));
    map<long long,long long> mpCheck;
    map<int,bool> mp;
    int currentIndex = 3;
    mp[1] = 1,mp[2] = 1,mp[3] = 1;
    mpCheck[999] = 1,mpCheck[998] = 2,mpCheck[997] = 3;
    //Khoi tao mot so thiet bi co san 
    database[1].id = 999;
	database[1].name = "May giat";
	database[1].status = "On dinh";
	database[1].date = {20, 12, 2025};

	database[2].id = 998;
	database[2].name = "Tu lanh";
	database[2].status = "Het ga";
	database[2].date = {15, 4, 2025};

	database[3].id = 997;
	database[3].name = "Dieu hoa";
	database[3].status = "Loi nguon";
	database[3].date = {22, 11, 2025};

    while(choices != '7')
    {
    	cin>>choices;
    	switch(choices)
    	{
    		case '1':
    			themThietBi(database,mp,currentIndex,mpCheck);
    			break;
    		case '2' :
    			xoaThietBi(database,mp,mpCheck);
    			break;
    		case '3' :
    			xuatDanhSach(database,mp);
    			break;
    		case '4' :
    			reportProblems(database,mp,mpCheck);
    			break;
    		case '5' :
    			baoTri(database,mp,mpCheck);
    			break;
    		case '6' :
    			traCuu(database,mp,mpCheck);
    			break;
    		case '7' :
    			break;
    		default : 
    			cout<<"Gia tri khong hop le! Hay thu lai"<<endl;
    	}

    }
    delete[] database;
    cout<<"Dong chuong trinh, xoa du lieu...."<<endl;
}

