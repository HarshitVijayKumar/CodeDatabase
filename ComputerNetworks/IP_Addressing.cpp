#include <iostream>
#include <string>
using namespace std;

int dectobin(int n){
    string temp="";
    int i;
    while(n>0){
        if(n%2==0){
            temp = '0'+temp;
        }
        else{
            temp = '1'+temp;
        }
        n = n/2;
    }
    cout<<temp<<"  ";
    return 0;
}

int main(){
    string ip,temp;
    cout<<"-----IP Manipulation-----"<<endl;
    cout<<"1. Enter the IP Address"<<endl;
    cout<<"2. Find Class of IP Address"<<endl;
    cout<<"3. Decimal to Binary"<<endl;
    cout<<"4. Find Netid and Hostid"<<endl;
    cout<<"5. Find network address"<<endl;
    cout<<"6. Find last address"<<endl;
    cout<<"7. Exit"<<endl;
    int choice=0,ip_entered=0;
    int i,k;
    int note[4];
    while(choice!=7){
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice){
            case 1:
            temp="";
            cout<<"Enter the IP : "<<endl;
            cin>>ip;
            k=0;
            for(i=0;i<ip.length();i++){
                if(ip[i]=='.'){
                    note[k] = stoi(temp);
                    k++;
                    temp = "";
                }
                else{
                    temp = temp+ip[i];
                }
            }
            note[3] = stoi(temp);
            ip_entered = 1;
            for(k=0;k<4;k++){
                if((note[k]>255)||(note[k]<0)){
                    ip_entered = 0;
                }
            }
            if(ip_entered==0){
                cout<<"Invalid IP"<<endl;
            }
            else{
                cout<<"IP Successfully entered"<<endl;
            }
            break;
            case 2:
            if(ip_entered == 0){
                cout<<"Please enter an IP !"<<endl;
            }
            else{
                if(note[0]<128){
                    cout<<"Class A IP"<<endl;
                }
                else if(note[0]<192){
                    cout<<"Class B IP"<<endl;
                }
                else if(note[0]<224){
                    cout<<"Class C IP"<<endl;
                }
                else if(note[0]<240){
                    cout<<"Class D IP"<<endl;
                }
                else if(note[0]<256){
                    cout<<"Class E IP"<<endl;
                }
            }
            break;
            case 3:
            if(ip_entered == 0){
                cout<<"Please enter an IP !"<<endl;
            }
            else{
                cout<<"The binary IP is : "<<endl;
                for(i=0;i<4;i++){
                    cout<<note[i]<<".";
                }
                cout<<endl;
                for(i=0;i<4;i++){
                    dectobin(note[i]);
                }
                cout<<endl;
            }
            break;
            case 4:
            if(ip_entered == 0){
                cout<<"Please enter an IP !"<<endl;
            }
            else{
                if(note[0]<224){
                    if(note[0]<127){
                        cout<<"Net ID is : "<<note[0]<<".0.0.0"<<endl;
                        cout<<"Host ID is : "<<note[1]<<'.'<<note[2]<<'.'<<note[3]<<endl;
                    }
                    else if(note[0]<192){
                        cout<<"Net ID is : "<<note[0]<<'.'<<note[1]<<endl;
                        cout<<"Host ID is : "<<note[2]<<'.'<<note[3]<<endl;
                    }
                    else if(note[0]<224){
                        cout<<"Net ID is : "<<note[0]<<'.'<<note[1]<<'.'<<note[2]<<endl;
                        cout<<"Host ID is : "<<note[3]<<endl;
                    }
                }
                else{
                    cout<<"Net ID is : "<<note[0]<<'.'<<note[1]<<'.'<<note[2]<<'.'<<note[3]<<endl;
                    cout<<"Host ID is : This class does not have host id"<<endl;
                }
            }
            break;
            case 5:
            if(ip_entered == 0){
                cout<<"Please enter an IP !"<<endl;
            }
            else{
                if(note[0]<127){
                    cout<<note[0]<<".0.0.0"<<endl;
                }
                else if(note[0]<192){
                    cout<<note[0]<<"."<<note[1]<<".0.0"<<endl;
                }
                else if(note[0]<224){
                    cout<<note[0]<<"."<<note[1]<<"."<<note[2]<<".0"<<endl;
                }
                else{
                    cout<<ip<<endl;
                }
            }
            break;
            case 6:
            if(ip_entered == 0){
                cout<<"Please enter an IP !"<<endl;
            }
            else{
                if(note[0]<127){
                    cout<<note[0]<<".255.255.255"<<endl;
                }
                else if(note[0]<192){
                    cout<<note[0]<<"."<<note[1]<<".255.255"<<endl;
                }
                else if(note[0]<224){
                    cout<<note[0]<<"."<<note[1]<<"."<<note[2]<<".255"<<endl;
                }
                else{
                    cout<<ip<<endl;
                }
            }
            break;
            case 7:
            cout<<"----Exiting----"<<endl;
            break;
            default:
            cout<<"Please enter a valid choice !"<<endl;
        }
    }
    return 0;
}