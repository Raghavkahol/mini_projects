#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct data{
int pos;	
int val;
char *cmnd;
};
struct stack{
	struct data *d;
	int top;
};

void dlt(struct stack *s,int k,int m,char sr[]){
	s->top=s->top+1;
	s->d[s->top].val=k;
	s->d[s->top].pos=m;
	int l=strlen(sr);
	int cnt=1;
	int i=0;
	while(cnt!=m&&sr[i]!='\0'){
		if(sr[i]==' '&&i!=l){
			cnt++;
		}
		i++;
	}
	int f=i;
	int gk=0;
	int se=0;
	char pr[10];
	while(sr[f]!=' '&&sr[f]!='\0'){
		pr[se]=sr[f];
		se++;
		gk++;
		f++;
	}		int ct=0;
	pr[se]='\0';
	while(ct<=gk){
		for(int j=i;j<=l-1;j++){
			sr[j]=sr[j+1];
		}
		l=l-1;
			sr[l]='\0';
				s->d[s->top].cmnd=(char *)malloc(10*sizeof(struct stack));
	strcpy(s->d[s->top].cmnd,pr);
		ct++;
	}
}

void insert(struct stack*s,int k,int m,char r[],char sr[]){
	s->top=s->top+1;
	s->d[s->top].val=k;
	s->d[s->top].pos=m;
		s->d[s->top].cmnd=(char *)malloc(10*sizeof(struct stack));
	strcpy(s->d[s->top].cmnd,r);
	int l=strlen(sr);
	int cnt=1,i=0,j,x,y,z;
	while(cnt!=m){
		if(sr[i]==' '||sr[i]=='\0'){
			cnt++;
		}
		i++;	
	}
		int gk=strlen(r);
	if(sr[i-1]=='\0'){
	sr[i-1]=' ';
	int sty=0;
	for(j=i;j<gk+i;j++){
		sr[j]=r[sty];
		sty++;
	}
	sr[j]='\0';
	}else{
	

	for(j=l+gk+1;j>=i+gk+1;j--){
		sr[j]=sr[j-gk-1];
	}
	int p=0;
	for(j=i;j<i+gk;j++){
		sr[j]=r[p];
		p++;
	}
	sr[j]=' ';
}
}


int main(){
	char sr[100],r[10];
	int rd=0;
	struct stack* s=(struct stack*)calloc(1,sizeof(struct stack));
		struct stack* s1=(struct stack*)calloc(1,sizeof(struct stack));
	s->d=(struct data*)malloc(10*sizeof(struct data));
	s->d[s->top].cmnd=(char *)malloc(10*sizeof(struct stack));
		s1->d=(struct data*)malloc(10*sizeof(struct data));
	s1->d[s->top].cmnd=(char *)malloc(10*sizeof(struct stack));
	s->top=-1;
	s1->top=-1;
	int cnt=0;
	printf("Enter a string\n");
	scanf("%[^\n]s",sr);
	int i,j,k,l,m;
	l=strlen(sr);
	printf("Press 1 for insert , 2 for delete ,0 for undo ,-1 for redo and 3 for exit\n");
	scanf("%d",&k);
	int f=0,zz=0;
	while(k!=3){
		if(k==1){
			printf("Enter Position\n");
			scanf("%d",&m);
			printf("Enter String\n");
			scanf("%s",r);
			insert(s,1,m,r,sr);
			printf("%s",sr);
			cnt++;
		}else if(k==2){
			printf("Enter Position\n");
			scanf("%d",&m);
			dlt(s,2,m,sr);
			printf("%s",sr);
			cnt++;
		}else if(k==0){
			if(cnt>0){
			if(f==1&&s1->top==-1){
				printf("Can't Undo\n");
				
			}else{
			f=1;
			if(s->d[s->top].val==1){
			dlt(s1,2,s->d[s->top].pos,sr);
			printf("%s",sr);
			}else if(s->d[s->top].val==2){
			insert(s1,1,s->d[s->top].pos,s->d[s->top].cmnd,sr);
			printf("%s",sr);
			}}
			zz++;}else{
				printf("Cant't Undo\n");
			}
			cnt--;
			}else if(k==-1){
			if(rd<zz){
			if(s1->d[s1->top].val==1){
			dlt(s1,2,s1->d[s1->top].pos,sr);
			printf("%s",sr);
			}else if(s1->d[s1->top].val==2){
			insert(s1,1,s1->d[s1->top].pos,s1->d[s1->top].cmnd,sr);
			printf("%s",sr);
			}
			s1->top=s1->top-1;
			}else{
				printf("Can't redo\n");
			}
			rd++;
			}
	printf("\nPress 1 for insert , 2 for delete , 0 for undo , -1 for redo and 3 for exit\n");
	scanf("%d",&k);
	}}
