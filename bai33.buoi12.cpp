#include <stdlib.h>
#include <stdio.h>

struct PHAN_SO{
	int tu, mau;
};

void nhapPS (PHAN_SO *a);
void xuatPS (PHAN_SO a);
void nhapDS (PHAN_SO a[], int n);
void xuatDS (PHAN_SO a[], int n);
void rutgon (PHAN_SO *a);

int main()
{
	PHAN_SO *ps, *ps2;
	int n, m=1;
	char path[50], path2[50];
	FILE *fp, *fp2;
	
	do
	{
		printf("\nNhap vao so phan so: ");
		scanf("%d", &n);
	}while(n<=0);
	ps2=(PHAN_SO*)malloc(n*sizeof(PHAN_SO));
/*	ps=(PHAN_SO*)malloc(n*sizeof(PHAN_SO));
	
	//nhap danh sach voi n phan so
	printf("\nNhap danh sach cac phan so: ");
	nhapDS(ps, n);
	
	printf("\nNhap duong dan: ");
	fflush(stdin);
	gets(path);
	
	fp=fopen(path, "wb");
	if(fp==NULL)
		printf("\nLoi mo file");
	else
	{
		for(int i=0 ; i<n ; i++)
		{
			fwrite(&ps[i], sizeof(PHAN_SO), n, fp);
		}
		fclose(fp);
	}	*/
	
	printf("\nNhap duong dan can doc: ");
	fflush(stdin);
	gets(path2);
	
	fp2=fopen(path2,"rb");
	if(fp2==NULL)
		printf("\nLoi mo file");
	else 
	{
		int i=0;
		while(!feof(fp2))
		{
			fread(&ps2[i], sizeof(PHAN_SO), 1, fp2);
			m++;
			i++;
			ps2=(PHAN_SO*)realloc(ps2, sizeof(PHAN_SO)*m);
		}
		fclose(fp2);
	}
	printf("\nDanh sach cac phan so vua doc: ");
	xuatDS(ps2, n);
	free(ps2);
	return 0;
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
void xuatPS (PHAN_SO a)
{
	printf("%d/%d", a.tu, a.mau);
}
void nhapPS (PHAN_SO *a)
{
	printf("\nNhap vao tu so: ");
	scanf("%d", &a->tu);
	printf("\nNhap vao mau so: ");
	scanf("%d", &a->mau);
}
void nhapDS (PHAN_SO a[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		printf("\nNhap vao phan so thu %d: ", i+1);
		nhapPS(&a[i]);
	}
}
void xuatDS (PHAN_SO a[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		xuatPS(a[i]);
		printf("\t");
	}
}

