#include <iostream>
using namespace std;

char xor1(int a,int b){
    if(a==b){
        return '0';
    }
    else{
        return '1';
    }
}

int main(){
    string net1,net2;
    cin>>net1>>net2;
    
    int temp1 = stoi(net1);
    int temp2 = stoi(net2);
    cout<<temp1<<" "<<temp2<<endl;
    return 0;
}