#include <stdio.h>

struct PHAN_SO{
	int tu, mau;
}PS;

void nhap (PHAN_SO *a);
void xuat (PHAN_SO a);
void rutgon (PHAN_SO *a);
void congps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c);
void trups (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c);
void nhanps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c);
void chiaps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c);
int main()
{
	PHAN_SO a, b, c;
	printf("\nNhap phan so thu nhat: ");
	nhap(&a);
	printf("\nNhap phan so thu hai: ");
	nhap(&b);
	
	printf("\nPhan so da nhap la: ");
	xuat(a);
	printf("\t");
	xuat(b);
	
	printf("\nPhan so dang RUT GON: ");
	rutgon(&a);
	rutgon(&b);
	xuat(a);
	printf("\t");
	xuat(b);
	
	printf("\nPhep cong hai phan so %d/%d va %d/%d: ", a.tu, a.mau, b.tu, b.mau);
	congps(&a,&b,&c);
	rutgon(&c);
	xuat(c);
	
	printf("\nPhep tru hai phan so %d/%d va %d/%d: ", a.tu, a.mau, b.tu, b.mau);
	trups(&a,&b,&c);
	rutgon(&c);
	xuat(c);
	
	printf("\nPhep nhan hai phan so %d/%d va %d/%d: ", a.tu, a.mau, b.tu, b.mau);
	nhanps(&a,&b,&c);
	rutgon(&c);
	xuat(c);
	
	printf("\nPhep chia hai phan so %d/%d va %d/%d: ", a.tu, a.mau, b.tu, b.mau);
	chiaps(&a,&b,&c);
	rutgon(&c);
	xuat(c);
	return 0;
}

void chiaps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c)
{
	c->tu=a->tu*b->mau;
	c->mau=a->mau*b->tu;
}
void nhanps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c)
{
	c->tu=a->tu*b->tu;
	c->mau=a->mau*b->mau;
}
void trups (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c)
{
	if(a->mau==b->mau)
	{
		c->mau=a->mau;
		c->tu=a->tu-b->tu;
	}
	else if(a->mau!=b->mau)
	{
		c->mau=a->mau*b->mau;
		c->tu=(a->tu*b->mau)-(b->tu*a->mau);
	}
}
void congps (PHAN_SO *a, PHAN_SO *b, PHAN_SO *c)
{
	if(a->mau==b->mau)
	{
		c->mau=a->mau;
		c->tu=a->tu+b->tu;
	}
	else if(a->mau!=b->mau)
	{
		c->mau=a->mau*b->mau;
		c->tu=(a->tu*b->mau)+(b->tu*a->mau);
	}
}
void rutgon (PHAN_SO *a)
{
	for (int i=2; i<=a->tu ; i++)
	{
		if((a->tu%i==0)&&(a->mau%i==0))
		{
			a->tu/=i;
			a->mau/=i;
		}
	}
	for (int i=2; i<=a->mau ; i++)
	{
		if((a->tu%i==0)&&(a->mau%i==0))
		{
			a->tu/=i;
			a->mau/=i;
		}
	}
}
void xuat (PHAN_SO a)
{
	printf("%d/%d", a.tu, a.mau);
}
void nhap (PHAN_SO *a)
{
	printf("\nNhap vao tu so: ");
	scanf("%d", &a->tu);
	printf("\nNhap vao mau so: ");
	scanf("%d", &a->mau);
}
