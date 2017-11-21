#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
struct snake{
	int x,y;
	char val;
	struct snake * next;
};
struct food{
	int x;
	int y;
	char val;
};


struct snake * createSnake(struct snake * head){
	int i;
	head->x=rand()%10+5;
		head->y=rand()%10+5;
		head->next=NULL;
		head->val='A';
	for(i=0;i<2;i++){
	    	struct snake * nw=(struct snake *)malloc(sizeof(struct snake));
			struct snake * temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			nw->x=temp->x;
			nw->y=temp->y+1;
			nw->val='#';
			temp->next=nw;
		nw->next=NULL;
}

return head;
}


struct food* generateFood(struct food *f,struct snake * head ){
	int flag;
	do{
	 flag=1;
	f->x=rand()%20+1;
	f->y=rand()%20+1;
	struct snake * temp=head;
	while(temp!=NULL){
		if(temp->x==f->x&&temp->y==f->y){
			flag=0;
		}
		temp=temp->next;
	}
	f->val='F';
}while(flag==0);
return f;
}

void print(struct food *f,struct snake * head,char mat[22][22],int score){
	int i,j;
	
mat[f->x][f->y]=f->val;
struct snake * temp=head;
while(temp!=NULL){
	mat[temp->x][temp->y]=temp->val;
	temp=temp->next;
}
for(i=0;i<21;i++){
	mat[0][i]='*';
}
for(i=0;i<21;i++){
	mat[21][i]='*';
}
for(i=0;i<=21;i++){
	for(j=0;j<=21;j++){
		if(j==0||j==21)
		mat[i][j]='*';
	}
}
for(i=0;i<=21;i++){
	for(j=0;j<=21;j++)
	printf("%c",mat[i][j]);
	printf("\n");
}
printf("SCORE : %d\n",score);
}


void input(int *x,int *l){

do{
	
	if(_kbhit()){
		*l=*l+1;
		switch(_getch()){
			case 'w':
				*x=1;
				break;
				case 'a':
					*x=2;
					break;
					case 'd':
						*x=3;
						break;
				case 's':
					*x=4;
					break;
		}
	}
	
}while(*l==0);
}
struct snake * move(struct snake * head,struct food *f,int *score,char * quit,int X,int l){
	char c;
	struct snake * nw=(struct snake *)malloc(sizeof(struct snake));
int g=1;
while(g==1){
	switch(X){
		case 1:
			nw->x=head->x-1;
			nw->y=head->y;
			break;
			case 2:
			nw->x=head->x;
			nw->y=head->y-1;
			break;
			case 3:
				nw->x=head->x;
				nw->y=head->y+1;
				break;
				case 4:
					nw->x=head->x+1;
					nw->y=head->y;
					break;
		default:
			*quit='y';
				}
				if(nw->x==head->next->x&&nw->y==head->next->y){
					l=0;
			X=rand()%4+1;
				g=1;
	}		else
				g=0;
}
	nw->val=head->val;
if(nw->x==21)
nw->x=1;
else if(nw->x==0)
nw->x=20;
else if(nw->y==21)
nw->y=1;
else if(nw->y==0)
nw->y=20;
	struct snake * temp=head;
	while(temp->next->next!=NULL){
		temp->val=temp->next->val;
		temp=temp->next;
	}
	int w,z;
	w=temp->next->x;
	z=temp->next->y;
	temp->val=temp->next->val;
	temp->next=NULL;
		nw->next=head;
		head=nw;
			if(nw->x==f->x&&nw->y==f->y){
*score=*score+1;
		int flag;
	do{
	 flag=1;
	f->x=rand()%20+1;
	f->y=rand()%20+1;
	struct snake * temp=head;
	struct snake * nw=(struct snake *)malloc(sizeof(struct snake));
	nw->val='#';
	nw->x=w;
	nw->y=z;
	nw->next=NULL;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=nw;
		temp=head;
	while(temp!=NULL){
		if(temp->x==f->x&&temp->y==f->y){
			flag=0;
		}
		temp=temp->next;
	}
	f->val='F';
}while(flag==0);
	}
		return head;
}

int main(){
	char mat[22][22]={{}};
	int score =0;
		struct snake * head=(struct snake *)malloc(sizeof(struct snake));
			struct food *f=(struct food *)malloc(sizeof(struct food));
struct snake *temp;
	head=createSnake(head);
f=	generateFood(f,head);
char quit;
int l=0;
int x;
do{
   system("@cls||clear");
  	print(f,head,mat,score);
	input(&x,&l);
	head=move(head,f,&score,&quit,x,l);
	temp=head->next;
		int i,j;
		
for(i=0;i<22;i++){
	for(j=0;j<22;j++){
		mat[i][j]=' ';
	}
}

int r=0;
 while(temp!=NULL){
		if(head->x==temp->x&&head->y==temp->y){
			quit='y';
			r=1;
				}
		temp=temp->next;
	}
		Sleep(150);
	}while(quit!='y');
printf("\nGAME OVER and your SCORE is %d\n",score);
}
