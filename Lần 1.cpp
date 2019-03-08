#include <iostream>
#include <string.h>

using namespace std;
int menu()
{
	int chon;
	cout << endl;
	cout << "\n Bai tap LT1";
	cout << "\n Sinh vien thuc hien: " << "Nguyen Thi Hong Hanh" << "  MSSV:17520441";
	cout << "\n Cac bai tap: ";
	cout << "\n Bai tap: 1";
	cout << "\n \t 1.cau 1:Nhap thoi gian";
	cout << "\n \t 2.cau 2:Xuat thoi gian";
	cout << "\n \t 3.cau 3:Xuat thoi gian nam nhuan";
	cout << "\n \t 4.cau 4:Sap xep cac thoi gian theo thu tu tang dan";
	cout << "\n \t 5.cau 5:Xuat ra 2 thoi gian co khoang cach gan nhat";
	cout << "\n Bai tap 2";
	cout << "\n \t 6.cau 6:Nhap thong tin nhan vien";
	cout << "\n \t 7.cau 7:Xuat thong tin nhan vien";
	cout << "\n \t 8.cau 8:Xuat tong luong phai tra cho nhan vien";
	cout << "\n \t 9.cau 9:Xuat nhan vien tang dan theo ngay sinh";
	cout << "\n \t 10.cau 10:Xuat nhan vien co ngay sinh nhat sap toi, gan ngay 23/01";
	cout << "\n Ban chon cau so ";
	cout << "Ban chon so: "; cin >> chon;
	return chon;
}

struct thoigian
{
	int d, m, y;
};
// Nhập thời gian
void Nhaptg(thoigian a[], int &n)
{
	cout << "Nhap so thoi gian n: "; cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << "Nhap thoi gian " << i+1  << endl;
		cout << "Nhap ngay: "; cin >> a[i].d;
		cout << "Nhap thang: "; cin >> a[i].m;
		cout << "Nhap nam: "; cin >> a[i].y;
	}
}
//Xuất thời gian
void Xuattg(thoigian a[], int n)
{
	for (int i = 0; i<n; i++)
	{
		cout << "Thoi gian " << i+1  << ": " << a[i].d << "/" << a[i].m << "/" << a[i].y << endl;
	}
}
//Kiểm tra năm nhuận
int KTnamnhuan(thoigian a)
{

	if ((a.y % 4 == 0 && a.y % 100 != 0) || a.y % 400 == 0)
		return 1;
	else return 0;
}
//Kiểm tra thời gian hợp lệ
int KTthoigian(thoigian a)
{
	if (a.d<1 || a.d>31 || a.m<1 || a.m >12 || a.y <1) return 0;
	if (KTnamnhuan(a) == 1)
	{
		if (a.d>29 && a.m == 2) return 0;
	}
	else if (a.m == 2 && a.d>28) return 0;
    if (a.m == 4 || a.m == 6 || a.m == 9 || a.m == 11)
		if (a.d>30) return 0;
	return 1;
}
//So sánh 2 thời gian
int Sosanh(thoigian a, thoigian b)
{
	if (a.y<b.y) return 1;
	if (a.y>b.y) return -1;
	if (a.y == b.y)
	{
		if (a.m< b.m) return 1;
		if (a.m>b.m) return -1;
		if (a.m == b.m)
		{
			if (a.d< b.d) return 1;
			if (a.d> b.d) return -1;

		}
	}
	return 0;
}
//Sắp xếp 2 thời gian
void Sapxep(thoigian a[], int n)
{
	thoigian x;
	for (int i = 0; i<n - 1; i++)
		for (int j = i + 1; j<n; j++)
			if (Sosanh(a[i], a[j]) == 1)
			{
				x= a[i];
				a[i] = a[j];
				a[j] = x;
			}
}
//Tính số ngày
int Sothoigian(thoigian a)
{
	if (a.m<3)
	{
		a.y--;
		a.m = a.m + 12;
	}
	return 365 * a.y + a.y / 4 - a.y / 100 + a.y / 400 + (153 * a.m - 457) / 5 + a.d - 306;
}
//Tính khoảng cách giữa 2 thời gian
int Khoangcach(thoigian a, thoigian b)
{
	if (Sosanh(a, b) == 1)
		return Sothoigian(b) - Sothoigian(a);
	else return Sothoigian(a) - Sothoigian(b);
}
struct NVVP
{
	char hoten[100];
	thoigian ngaysinh;
	int songaylv;
};
struct NVSX
{
	char hoten[100];
	thoigian ngaysinh;
	int luongcb, sosp;
};
//Nhập số lượng, thông tin nhân viên văn phòng, sản xuất
void Nhapnv(NVVP vp[], int &n, NVSX sx[], int &m)
{
	cout << "Nhap so nvvp n= "; cin >> n;
	cout << "Nhap so nvsx m= "; cin >> m;
	for (int i = 0; i<n; i++)
	{
		cout << "Nhan vien van phong thu " << i + 1 << endl;
		cout << "Ho ten: ";
		cin.ignore(); 
		cin.getline(vp[i].hoten, 100);
		cout << "Ngay sinh: ";
		cin >> vp[i].ngaysinh.d;
		cout << "Thang sinh: ";
		cin >> vp[i].ngaysinh.m;
		cout << "Nam sinh: ";
		cin >> vp[i].ngaysinh.y;
		cout << "So ngay lam viec: ";
		cin >> vp[i].songaylv;
	}
	for (int j = 0; j<m; j++)
	{
		cout << "Nhan vien san xuat thu " << j + 1 << endl;
		cout << "Ho ten: "; 
		cin.ignore();
		cin.getline(sx[j].hoten, 100);
		cout << "Ngay sinh: ";
		cin >> sx[j].ngaysinh.d;
		cout << "Thang sinh: ";
		cin >> sx[j].ngaysinh.m;
		cout << "Nam sinh: "; 
		cin >> sx[j].ngaysinh.y;
		cout << "Luong can ban: "; 
		cin >> sx[j].luongcb;
		cout << "So san pham: ";
		cin >> sx[j].sosp;
	}
}
//Xuất nhân viên văn phòng, nhân viên sản xuất
void Xuatnv(NVVP vp[], int n, NVSX sx[], int m)
{
	for (int i = 0; i<n; i++)
	{
		cout << "Nhan vien van phong " << i + 1 << endl;
		cout << "Ho ten: " << vp[i].hoten << endl;
		cout << "Ngay sinh: " << vp[i].ngaysinh.d << "/" << vp[i].ngaysinh.m << "/" << vp[i].ngaysinh.y << endl;
		cout << "So ngay lam viec: " << vp[i].songaylv << endl;
	}
	for (int j = 0; j<m; j++)
	{
		cout << "Nhan vien san xuat thu " << j + 1 << endl;
		cout << "Ho ten: " << sx[j].hoten << endl;
		cout << "Ngay sinh: " << sx[j].ngaysinh.d << "/" << sx[j].ngaysinh.m << "/" << sx[j].ngaysinh.y << endl;
		cout << "Luong can ban: " << sx[j].luongcb << endl;
		cout << "So san pham: " << sx[j].sosp << endl;
	}
}
//Tính tổng lương phải trả 
float Tongluong(NVVP vp[], int n, NVSX sx[], int m)
{
	float S = 0;
	for (int i = 0; i<n; i++)
		S = S + vp[i].songaylv * 100000;
	for (int j = 0; j<m; j++)
		S = S + sx[j].luongcb + sx[j].sosp * 5000;
	return S;
}

int main()
{
	thoigian a[100], x, y;
	int n, m, chon, KC, k = 0;
	NVVP vp[100];
	NVSX sx[100];

	do
	{
		chon = menu();
		switch (chon)
		{
		case 0: return 0;
		case 1: Nhaptg(a, n);
			break;
		case 2: Xuattg(a, n);
			break;
		case 3: cout << "Thoi gian la nam nhuan: " << endl;
			for (int i = 0; i<n; i++)
			{
				if (KTnamnhuan(a[i]) == 1)
					cout << i << ": " << a[i].d << "/" << a[i].m << "/" << a[i].y << endl;
			}
			break;
		case 4: 
			Sapxep(a, n);
			cout << "Thoi gian tang dan: " << endl;
			for (int j = 0; j<n; j++)
				cout << a[j].d << "/" << a[j].m << "/" << a[j].y << "\t";
			cout << endl;
			break;
		case 5: cout << "Khoang cach gan nhat: " << endl;
			KC = Khoangcach(a[0], a[1]);
			for (int i = 0; i<n - 1; i++)
				for (int j = i + 1; j<n; j++)
					if (Khoangcach(a[i], a[j])<KC)
					{
						KC = Khoangcach(a[i], a[j]);
						x = a[i];
						y = a[j];
					}
			if (KC == Khoangcach(a[0], a[1]))
			{
				x = a[0];
				y = a[1];
			}
			cout << x.d << "/" << x.m << "/" << x.y << "\t" << y.d << "/" << y.m << "/" << y.y << endl;
			break;
		case 6: Nhapnv(vp, n, sx, m);
			break;
		case 7: Xuatnv(vp, n, sx, m);
			break;
		case 8: cout << "Tong luong phai tra cho nhan vien: " << Tongluong(vp, n, sx, m) << endl;
			break;
		case 9:
			for (int i = 0; i<n; i++)
			{
				a[k] = vp[i].ngaysinh;
				k++;
			}
			k = n;
			for (int j = 0; j<m; j++)
			{
				a[k] = sx[j].ngaysinh;
				k++;
			}
			n = k;
			Sapxep(a, n);

			for (int i = 0; i<k; i++)
			{
				for (int j = 0; j<k; j++)
				{
					if (Sosanh(a[i], vp[j].ngaysinh) == 0)
					{
						cout << "Nvvp " << j + 1 << endl;
						cout << "Ho ten: " << vp[j].hoten << endl;
						cout << "Ngay sinh: " << a[i].d << "/" << a[i].m << "/" << a[i].y << endl;
					}
					if (Sosanh(a[i], sx[j].ngaysinh) == 0)
					{
						cout << "Nvsx " << j + 1 << endl;
						cout << "Ho ten: " << sx[j].hoten << endl;
						cout << "Ngay sinh: " << a[i].d << "/" << a[i].m << "/" << a[i].y << endl;
					}

				}

			}
			break;
		case 10:
			cout << " Em khong biet lam, em xin loi thay :(((("; break;
		}
	} while (1);
	return 0;
}
