#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Game{
	string s;
	char r[100];
	char d[10];
	
	public:
		
		//it will take input
		void input(){
			cout<<"Enter a movie's name:"<<endl;
			getline(cin,s);
				cout<<"Type Bollywood if its Hindi movie and Hollywood if its a english movie :"<<endl;
			cin>>d;
		system("CLS");
	}
	
	//game will be played in this
		void play(){
			int i,j,k,l,c=0,x=0,f=0,z=0;
			char q;
			l=s.length();
			
			
			//this loop will check for vowels
			for(i=0;i<l;i++){
				if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
				x++;
				r[i]=s[i];
			}
				else if(s[i]==32){
					r[i]=32;
					x++;
				}
				else{
				
				r[i]='_';
				//x++;
			}}
	
		r[l]='\0';
		//it will check the condition
			for(;;){
					cout<<d<<endl;
					cout<<r<<endl;
					cout<<endl<<"Enter ur choice"<<endl;
				
				cin>>q;
				for(i=0;i<l;i++){
					if(q==s[i]){
						r[i]=q;		
						x++;
						f=1;
				}
					}
					if(f==0){
					
			d[c]='*';
					c++;
					cout<<endl<<"wrong guess,Be carefull"<<endl;
					}
					f=0;
				
				if(x==l){
					cout<<s<<endl;
					cout<<"u win,congo";
					break;
				}else if(c==9){
					cout<<d<<endl;
					cout<<"Game Over";
					break;
				}
			}
		
}
};
int main(){
	Game p;
	p.input();
	p.play();
}
