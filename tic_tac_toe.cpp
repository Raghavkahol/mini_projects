#include<iostream>
#include<stdlib.h>
using namespace std;
void tic(int);
int main(){
	int z;
	int i,j,k,l,m,a;
	z=rand();
	if(z%2==0){
	cout<<"2's turn"<<endl;
	a=2;
	tic(a);
}else{
	cout<<"1's turn"<<endl;
	a=1;
	tic(a);
}
}
void tic(int a){
	int b[3][3]={0};
	int i,j,k,l,m,n,f=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
		cout<<b[i][j]<<" ";
		cout<<"\n";
	}
	for(i=0;i<9;i++){
		cout<<"Enter two coordinates"<<endl;
	cin>>m>>n;
	if(b[m][n]==0)
	b[m][n]=a;


    
    k=0;
    l=0;
    		if((b[m][k]==b[m][k+1])&&(b[m][k]==b[m][k+2])){
    		f=1;
    		cout<<endl<<a<<" wins"<<endl<<endl;
    	}
    		else if((b[l][n]==b[l+1][n])&&(b[l][n]==b[l+2][n])){
    		f=1;
    		cout<<endl<<a<<" wins"<<endl<<endl;
    	}
    		else if(m==n){
    			if((b[0][0]==b[1][1])&&(b[0][0]==b[2][2])){
    			f=1;
    			cout<<endl<<a<<" wins"<<endl<<endl;
    		}}
    		else if(m+n==2){
    		
    			 if((b[0][2]==b[1][1])&&(b[0][2]==b[2][0])){
    			
    			f=1;
			cout<<endl<<a<<" wins"<<endl<<endl;
			}
}

    
	for(j=0;j<3;j++){
		for(k=0;k<3;k++)
		cout<<b[j][k]<<" ";
		cout<<"\n";
	}
	if(a==1)
	a=2;
	else if(a==2)
	a=1;
if(f==1)
break;

}
if(i==9)
cout<<"Match Draw";
}
