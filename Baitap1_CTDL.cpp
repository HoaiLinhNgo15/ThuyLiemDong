#include <stdio.h>
#include <math.h>

#define EPSILON 0.05

typedef struct TAM_GIAC {
	int maso;
	float a,b,c;
}TG;

typedef struct Node
{
	TG Info; 
	Node * pNext; 
}Node;

typedef struct List {
	Node *pHead;
	Node *pTail;
}List;

Node *GetNode(TG x);
void Init(List &l);
void AddTail(List &l, Node *new_ele);
void InputTail(List &l);
void Output(List l);
Node* Search1(List l , int x);
void RemoveFirst(List &l);
void RemoveAfter(List &l, Node *q );
int checkTGV (float a, float b, float c);
void CountTGV (List l);
void OutPutTGVC (List l);
void increase1 (List &l);
void RemoveEqual (List &l);

int main() {
	List list;
	Init(list);
	InputTail(list);
	Output(list);
	
	CountTGV(list);
	OutPutTGVC(list);
	
	printf("\nDS sau khi xoa: \n");
	RemoveEqual(list);
	Output(list);
	
	printf("\nDS sau khi tang them 1 DV: \n");
	increase1(list);
	Output(list);
	return 0;
}

Node *GetNode(TG x) {
	Node *p;
	p = new Node;
	if (p==NULL)
	{
		printf("Khong du bo nho!");
		return NULL;
	}
	p->Info = x; 
	p->pNext = NULL;
	return p;
}

void Init(List &l) {
	l.pHead = l.pTail = NULL;
}

void AddTail(List &l, Node *new_ele){
	if (l.pHead==NULL) {	
		l.pHead = new_ele;		
		l.pTail = l.pHead;		
	}	
	else {
		l.pTail->pNext = new_ele;		
		l.pTail = new_ele ;	
	}
}

void InputTail(List &l) {
	int n;
	TG x;	
	printf("Nhap so pt: ");scanf("%d",&n);	
	for(int i=1;i<=n;i++)	
	{	
		do {
			printf("Nhap phan tu thu %d :",i);
			printf("Nhap ma so: ");
			scanf("%d",&x.maso);
			printf("Nhap do dai canh thu nhat: ");
			scanf("%f", &x.a);
			printf("Nhap do dai canh thu hai: ");
			scanf("%f", &x.b);
			printf("Nhap do dai canh thu ba: ");
			scanf("%f", &x.c);
				
			if(((x.a+x.b) >=x.c) && ((x.a+x.c)>= x.b) && ((x.b + x.c) >= x.a)) {
				Node* p=GetNode(x);	
				AddTail(l, p);	
			}
		}while((x.a+x.b<x.c) && (x.a+x.c < x.b) && (x.b + x.c < x.a));
	}
}

void Output(List l) {
	Node* p=l.pHead;
	printf("Ma So\tCanh 1\tCanh 2\tCanh 3\tChu Vi\tDien Tich\n");
	while(p!=NULL) {
		float S,P;
		P = p->Info.a + p->Info.b + p->Info.c;
		S = sqrt((P/2)*((P/2) - p->Info.a)*((P/2) - p->Info.b)*((P/2) - p->Info.c));
		printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", p->Info.maso, p->Info.a, p->Info.b, p->Info.c, P, S);
		p=p->pNext;
	}
		
}

Node* Search1(List l , int x) {
	Node* p=l.pHead;	
	while( p!=NULL && p->Info.maso!=x)	
		p=p->pNext;	
	return p;
}

void RemoveFirst(List &l) {
	if(l.pHead != NULL) {	
		Node* p=l.pHead;	
		l.pHead=p->pNext;	
		if(l.pHead == NULL) l.pTail=NULL;	
		delete p;	
	}
}

void RemoveAfter(List &l, Node *q ) {
	if((q !=NULL) && (q->pNext !=NULL)) {	
		Node* p = q->pNext;	
		q->pNext = p->pNext;	
		if(p==l.pTail)
		l.pTail=q;	
		delete p;	
	}
}

int checkTGV (float a, float b, float c) {
    float a2 = a * a, b2 = b * b, c2 = c * c;
    return (
        fabs((a2 + b2) - c2) < EPSILON || 
        fabs((a2 + c2) - b2) < EPSILON || 
        fabs((b2 + c2) - a2) < EPSILON
    ); 
}


void CountTGV (List l) {
	Node* p=l.pHead;
	int count = 0;
	while(p!=NULL) {
		if(checkTGV(p->Info.a, p->Info.b, p->Info.c))
			count ++;
		p=p->pNext;
	}
	printf("\nTong so Tam Giac Vuong la: %d", count);
}

void OutPutTGVC (List l) {
	Node* p=l.pHead;
	printf("\nMa so Tam Giac Vuong Can: ");
	while(p!=NULL) {
		if(checkTGV(p->Info.a, p->Info.b, p->Info.c))
			if((p->Info.a == p->Info.b) || (p->Info.b == p->Info.c) || (p->Info.a == p->Info.c))
				printf("%d\t", p->Info.maso);

		p=p->pNext;
	}
}

void increase1 (List &l) {
	Node *p=l.pHead;
	while(p!=NULL) {
		p->Info.a +=1;
		p->Info.b +=1;
		p->Info.c +=1;
		p=p->pNext;
	}
}

void RemoveEqual(List &l) {
    // X? lý các node d?u có a == 1
    while (l.pHead != NULL && l.pHead->Info.a == 1) {
        Node* temp = l.pHead;
        l.pHead = l.pHead->pNext;
        delete temp;
    }

    // N?u danh sách r?ng
    if (l.pHead == NULL) {
        l.pTail = NULL;
        return;
    }

    // Duy?t các ph?n t? còn l?i
    Node* prev = l.pHead;
    Node* curr = l.pHead->pNext;

    while (curr != NULL) {
        if (fabs(curr->Info.a - 1.0) < 1e-6) {
            Node* temp = curr;
            curr = curr->pNext;
            prev->pNext = curr;
            if (temp == l.pTail)
                l.pTail = prev;
            delete temp;
        } else {
            prev = curr;
            curr = curr->pNext;
        }
    }
}

