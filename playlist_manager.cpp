#include<iostream>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct song{
	int sId;
	struct song *next;
};
struct hash{
	struct song*hs[20];
	int full[20];
};
struct playlist{
	int pId;
	struct playlist *next;
	struct song *head;
	int playmode;
	int count;
	int active;
};
struct playlist* createPly(struct playlist* nw){
	cout<<"Enter playlist id"<<endl;
	int n;
	cin>>nw->pId;
	nw->next=NULL;
	nw->head=NULL;
	nw->playmode=1;
	nw->active=1;
	nw->count=0;
	return nw;
	
}
struct playlist *createPlaylist(struct playlist* p){
	if(p==NULL){
			struct playlist *nw=new playlist();
		nw->pId=1;
		nw->next=NULL;
			nw->head=NULL;
		nw->playmode=1;
		nw->count=0;
		nw->active=1;
		p=nw;
		
	}else{
		  
	  struct playlist *temp=p;
	  while(temp->next!=NULL){
	  	temp=temp->next;
	  }
	  struct playlist *nw=new playlist();
	
	  temp->next=createPly(nw);
	}

	return p;
}

void addSong(struct playlist *p,struct hash *h){
	 struct song*s=new song;
	 struct song *tmp;
	 p->count=p->count+1;
	 cout<<"Enter song id"<<endl;
	 cin>>s->sId;
	  s->next=NULL;
	 if(p->head==NULL){
	 	p->head=s;
	 }else{
	 	tmp=p->head;
	 	while(tmp->next!=NULL)
	 	  tmp=tmp->next;
	 	  tmp->next=s;
	 }
	 h->hs[s->sId]=s;
	 h->full[s->sId]=1;	 
}


int select(){
	cout<<"Select option :"<<endl;
	cout<<"1 for Add song      ";
	cout<<"2 for deleting song      ";
	cout<<"3 for Shuffling"<<endl;
	cout<<"4 for exit     ";
	cout<<"5 for viewPlaylist     ";
	cout<<"6 for creating new playlist    ";
	cout<<"7 for changing active playlist"<<endl;
	int n;
	cin>>n;
	return n;
}


void deleteSong(struct playlist *p,struct hash *h){
	cout<<"Enter songID of song to delete"<<endl;
	int nn;
	cin>>nn;
	struct song *s=p->head;
	if(s->sId==nn){
		p->head=s->next;
		return;
	}else{
		while(s->next->sId!=nn){
			s=s->next;
		}
				s->next=s->next->next;
			}
			p->count=p->count-1;
		
	 h->full[s->sId]=0;
}


void shuffleSong(struct hash *h){
	int count=0;
for(int i=0;i<20;i++){
	if(h->full[i]==1)
	  count++;
}
	int pp;
		srand(time(NULL));
		cout<<"Shuffled list is:"<<endl;
	while(count>0){
		pp=rand()%20;
		if(h->full[pp]==1){
			cout<<h->hs[pp]->sId<<endl;
			h->full[pp]=2;
			count--;
		}
	
	}
	
	for(int i=0;i<20;i++){
		if(h->full[i]==2)
		  h->full[i]=1;
	}	
	
}


void viewPlaylist(struct playlist *p1){
	cout<<"Enter 1 for infinite play 2 for all songs and 3 for one song on repeat"<<endl;
	int z;
	cin>>z;
	if(z==1){
		while(!kbhit()){
		
		cout<<endl<<"Playlist is"<<endl;
	struct song *temp=p1->head;
	while(temp!=NULL){
		cout<<temp->sId<<endl;
		temp=temp->next;
	}}	
	}else if(z==2){
	
	cout<<endl<<"Playlist is"<<endl;
	struct song *temp=p1->head;
	while(temp!=NULL){
		cout<<temp->sId<<endl;
		temp=temp->next;
	}}else if(z==3){
		cout<<"Enter iD u want to play"<<endl;
		int r;
		cin>>r;
		cout<<endl<<"Playlist is"<<endl;
	struct song *temp=p1->head;
	
	while(!kbhit()){
		cout<<r<<endl;
	}	
	}	
}


int changePlaylist(){
	int n;
	cout<<"Enter playlist u want to open"<<endl;
	cin>>n;
	return n;
}


int main(){
	
	int act=1;
    struct hash*h=new hash;
    int i;
    for(i=0;i<20;i++){
    	h->hs[i]=NULL;
    	h->full[i]=0;
	}
	struct playlist* p=NULL;
    p=createPlaylist(p);
   struct playlist *temp=p;
	int n=select();
		while(1){
			cout<<"Active playlist is: "<<temp->pId<<endl;
		switch(n){
		case 1:
			addSong(temp,h);
			
			break;
		case 2:
			deleteSong(temp,h);
			
			break;
		case 3:
			shuffleSong(h);
			break;
		case 4:
			break;	
			case 5:
				viewPlaylist(temp);
				break;
				case 6:
					createPlaylist(temp);
					break;
				case 7:
					act=changePlaylist();
					temp=p;
					while(temp->pId!=act)
					temp=temp->next;
					break;
	}
	cout<<endl;
		 n=select();
			cout<<endl;
if(n==4)
break;
	}
}
