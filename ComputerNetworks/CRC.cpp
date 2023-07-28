#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int i,temp,code_sent,code_sent_length,n;
    cout<<"Enter the code : ";
    cin>>code_sent;
    code_sent_length = ceil(log2(code_sent));
    if(code_sent%2==0)
        code_sent_length++;
    cout<<"Enter the greatest exponent power in the polynomial : ";
    cin>>n;
    int divisor[n];
    for(i=0;i<n;i++){
        cout<<"Enter the coefficient of "<<i;
        cin>>divisor[n];
    }

    //Code to convert the code word to binary
    int bin_code_sent[code_sent_length];
    temp = code_sent;
    i=0;
    while(temp>0){
        bin_code_sent[i] = temp%2;
        i++;
        temp = temp/2;
    }
    for(i=code_sent_length-1;i>-1;i--){
        cout<<bin_code_sent[i];
    }
    cout<<endl;
    

    return 0;
}