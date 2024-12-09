#include <stdio.h>
#include <stdlib.h>

struct SACH 
{
	char masach[15], tensach[50], tgia[30], nxb[50];
	int namxb, soluong;
	float dongia, thanhtien, thue, thuctien;
};

void nhapTT (SACH *a);
void xuatTT (SACH a);
void nhap_TTSach (SACH a[], int n);
void xuat_TTSach (SACH a[], int n);
float thanh_tien (SACH *a);
float Thanhtien (SACH a[], int n);
float thuc_tien (SACH *a, int m);
float Thuctien (SACH a[], int n, int m);
void sapGiam (SACH a[], int n);
float timMax (SACH a[], int n, int m);
void inMax (SACH a[], int n, int m);
int  tongSach (SACH a[], int n);

int main ()
{
	SACH *sach, a;
	int n,m;
	sach=(SACH*)malloc(n*sizeof(SACH));
	
	do
	{
		printf("\nNhap vao so quyen sach can luu thong tin: ");
		scanf("%d", &n);
	}while(n<=0);
	
	nhap_TTSach(sach, n);
//	xuat_TTSach(sach, n);
	
/*	printf("\nThanh Tien %d quyen sach: %.2f", n, Thanhtien(sach, n));
	
	do
	{
		printf("\nNhap vao thue Gia Tri Gia Tang(VAT): ");
		scanf("%d", &m);
	}while(m<0||m>100);
	printf("\nThuc Tien %d quyen sach: %.2f", n, Thuctien(sach,n, m));	
	
	printf("\nSap xep theo chieu Giam cua Nam Xuat Ban: ");
	sapGiam(sach,n);
	xuat_TTSach(sach,n);		
	
	printf("\nNhung quyen sach co Thuc Tien Lon Nhat: %.2f", timMax(sach, n, m));
	inMax(sach, n, m);	*/
	
	printf("\nTong So Luong moi quyen sach: %d", tongSach(sach , n));
	
	return 0;
}

int  tongSach (SACH a[], int n)
{
	int s=0;
	for (int i=0 ; i<n ; i++)
	{
		s+=a[i].soluong;
	}
	return s;
}
void inMax (SACH a[], int n, int m)
{
	for (int i=0 ; i<n ; i++)
	{
		if(thuc_tien(&a[i],m)==timMax(a,n, m))
			xuatTT(a[i]);
	}
}
float timMax (SACH a[], int n, int m)
{
	float max=thuc_tien(&a[0], m); 
	for (int i=0 ; i<n ; i++)
	{
		if(thuc_tien(&a[i],m)>max)
			max=thuc_tien(&a[i],m);
	}
	return max;
}
void sapGiam (SACH a[], int n)
{
	int t;
	for (int i=0 ; i<n-1 ; i++)
	{
		for (int j=i+1; j<n ; j++)
		{
			if(a[i].namxb < a[j].namxb)
			{
				t=a[i].namxb;
				a[i].namxb=a[j].namxb;
				a[j].namxb=t;
			}
		}
	}
}
float Thuctien (SACH a[], int n, int m)
{
	float s=0;
	for (int i=0; i<n ; i++)
	{
		s+=thuc_tien(&a[i], m);
	}
	return s;
}
float thuc_tien (SACH *a, int m)
{
	a->thuctien=thanh_tien(a)+thanh_tien(a)*m/100;
	return a->thuctien;
}
float Thanhtien (SACH a[], int n)
{
	float s=0;
	for (int i=0 ; i<n ; i++)
	{
		s+=thanh_tien(&a[i]);
	}
	return s;
}
float thanh_tien (SACH *a)
{
	a->thanhtien=(a->soluong) * (a->dongia);
	return a->thanhtien;
}
void xuat_TTSach (SACH a[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		printf("\nThong tin quyen sach thu %d: ",  i+1);
		xuatTT(a[i]);
		printf("\n");
	}
}
void nhap_TTSach (SACH a[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		printf("\nNhap thong tin quyen sach thu %d: ", i+1);
		nhapTT(&a[i]);
	}
}
void xuatTT (SACH a)
{
	printf("\nMa Sach: %s\nTen Sach: %s\nTac Gia: %s", a.masach, a.tensach, a.tgia);
	printf("\nNXB: %s\nNam XB: %d", a.nxb, a.namxb);
	printf("\nSo Luong Nhap: %d\nDon Gia: %.2f", a.soluong, a.dongia);
}
void nhapTT (SACH *a)
{
	printf("\nNhap vao Ma Sach: ");
	fflush(stdin);
	gets(a->masach);
	
	printf("\nNhap vao Ten Sach: ");
	fflush(stdin);
	gets(a->tensach);
	
	printf("\nNhap vao ten Tac Gia: ");
	fflush(stdin);
	gets(a->tgia);
	
	printf("\nNhap vao Nha Xuat Ban: ");
	fflush(stdin);
	gets(a->nxb);
	
	printf("\nNhap vao Nam Xuat Ban: ");
	scanf("%d", &a->namxb);
	
	printf("\nNhap vao Don Gia: ");
	scanf("%f", &a->dongia);
	
	printf("\nNhap vao So Luong Nhap: ");
	scanf("%d", &a->soluong);
}
