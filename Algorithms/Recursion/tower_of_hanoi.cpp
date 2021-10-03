#include<iostream>
using namespace std;

void TOH(int num,int a,int b,int c){
    if(num>0){
        TOH(num-1,a,c,b);
        printf("moved form %d %d\n",a,c);
        TOH(num-1,b,a,c);

    }
    
}

int main(){
    cout<<"This is a code for 3 pillar recurive tower of hanoi"<<endl;

    int num;
    
    cout<<"Enter the no. og rings in first tower : ";
    cin>>num;

    cout<<"This is the result of the tower of hanoi code :"<<endl;

    TOH(num,1,2,3);
    cout<<endl;
    cout<<"End of the code ---------"<<endl;
}