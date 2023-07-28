#include <iostream>
using namespace std;

int xor1(int code_sent,int divisor){
    if(code_sent==divisor){
        return 0;
    }
    else{
        return 1;
    }
}
int flip(int bit){
    if(bit==0){
        return 1;
    }
    else{
        return 0;
    }
}
int power(int a,int b){
    int i,mult=1;
    for(i=0;i<b;i++){
        mult = mult*a;
    }
    return mult;
}

int main(){
    int choice=0,divisor=1101;
    int code_sent,code_sent_length,temp,i,j,k,l,mult,flag,code_accepted=0,sender_side_processed=0;
    int sent[100],received[100];
    cout<<"---------ERROR HANDLING---------\n";
    cout<<"1. Enter a message\n";
    cout<<"2. CRC Sender Side\n";
    cout<<"3. CRC Reciever Side\n";
    cout<<"4. Hamming Code\n";
    cout<<"5. Exit\n";
    while(choice!=5){
        cout<<"Enter your command : ";
        cin>>choice;
        switch(choice){
            case 1: //Entering the message
            code_accepted = 0;
            flag=1;
            cout<<"Enter the code : ";
            cin>>code_sent;
            temp = code_sent;
            //Ensuring that the message has only 0s and 1s
            while(temp>0){
                if((temp%10!=0)&&(temp%10!=1)){
                    flag = 0;
                }
                temp = temp/10;
            }
            if(flag==0){
                cout<<"Please enter 0s and 1s only"<<endl;
            }
            //When confirmed the message is accepted
            else{
                code_accepted = 1;
            }
            break;
            case 2:
            //Message when a valid message has not been entered
            if(code_accepted==0){
                cout<<"Please enter a valid message first"<<endl;
            }
            //Continuing if the message is entered
            else{
                //Adding the n-1 0 bits
                code_sent_length = 0;
                code_sent = code_sent*1000;
                //Computing the total number of bits in the message
                temp = code_sent;
                while(temp>0){
                    code_sent_length++;
                    temp = temp/10;
                }
                
                //Making arrays and storing the messages in them
                int array_sent[code_sent_length],array_recieved[code_sent_length];
                int divisor[4];
                divisor[0] = 1;
                divisor[1] = 1;
                divisor[2] = 0;
                divisor[3] = 1;
                temp = code_sent;
                i=code_sent_length-1;
                while(temp>0){
                    array_sent[i] = temp%10;
                    temp = temp/10;
                    i--;
                }
                //Making an recieved array which initially is the same as array_sent
                for(i=0;i<code_sent_length;i++){
                    array_recieved[i] = array_sent[i];
                }
                //Loop to perform division
                flag=0;
                while(flag==0){
                    //Select the first bit where the message is not 0 in the MSB
                    i=0;
                    while(array_recieved[i]==0){
                        i++;
                        if(i>code_sent_length-4){
                            flag=1;
                            break;
                        }
                    }
                    //Perform division for the bits
                    for(j=0;j<3;j++){
                        array_recieved[i+j] = xor1(array_recieved[i+j],divisor[j]);
                    }
                }
                for(i=code_sent_length-1;i>code_sent_length-4;i--){
                    array_sent[i] = array_recieved[i];
                }
                cout<<"----SENDER SIDE----"<<endl;
                cout<<"Array sent : ";
                for(i=0;i<code_sent_length;i++){
                    sent[i] = array_sent[i];
                    cout<<array_sent[i];
                }
                cout<<endl;
                sender_side_processed = 1;
            }
            break;
            case 3:
            if(code_accepted==0){
                cout<<"Please enter a valid message first"<<endl;
            }
            else if(sender_side_processed==0){
                cout<<"Process the code via sender side first"<<endl;
            }
            else{
                cout<<"----RECIEVER SIDE----"<<endl;
                cout<<"Without Error ---"<<endl;
                int array_recieved[code_sent_length],code_check[code_sent_length];
                int divisor[4];
                divisor[0] = 1;
                divisor[1] = 1;
                divisor[2] = 0;
                divisor[3] = 1;
                for(i=0;i<code_sent_length;i++){
                    array_recieved[i] = sent[i];
                }
                cout<<"Receieved Code : ";
                for(i=0;i<code_sent_length;i++){
                    cout<<array_recieved[i];
                }
                cout<<endl;
                flag=0;
                while(flag==0){
                    i=0;
                    while(array_recieved[i]==0){
                        i++;
                        if(i>code_sent_length-4){
                            flag=1;
                            break;
                        }
                    }
                    for(j=0;j<3;j++){
                        array_recieved[i+j] = xor1(array_recieved[i+j],divisor[j]);
                    }
                }
                cout<<"Code After Processing : ";
                for(i=0;i<code_sent_length;i++){
                    cout<<array_recieved[i];
                }
                cout<<endl;
                if(array_recieved[i]==array_recieved[i+1]==array_recieved[i+2]==array_recieved[i+3]==0){
                    cout<<"Code Accepted!"<<endl;
                }
                cout<<"With Error ---"<<endl;
                cout<<"Flipping a Random Bit..."<<endl;
                for(i=0;i<code_sent_length;i++){
                    array_recieved[i] = sent[i];
                }
                array_recieved[5%code_sent_length] = flip(array_recieved[5%code_sent_length]);
                cout<<"Receieved Code : ";
                for(i=0;i<code_sent_length;i++){
                    cout<<array_recieved[i];
                }
                cout<<endl;
                flag=0;
                while(flag==0){
                    i=0;
                    while(array_recieved[i]==0){
                        i++;
                        if(i>code_sent_length-4){
                            flag=1;
                            break;
                        }
                    }
                    for(j=0;j<3;j++){
                        array_recieved[i+j] = xor1(array_recieved[i+j],divisor[j]);
                    }
                }
                cout<<"Code After Processing : ";
                for(i=0;i<code_sent_length;i++){
                    cout<<array_recieved[i];
                }
                cout<<endl;
                temp = 1;
                for(j=0;j<3;j++){
                    if(array_recieved[i+j]!=0){
                        temp = 0;
                    }
                }
                cout<<"Receieved Code : ";
                for(i=0;i<code_sent_length;i++){
                    cout<<array_recieved[i];
                }
                cout<<endl;
                if(temp==1){
                    cout<<"Code Accepted!"<<endl;
                }
                else{
                    cout<<"Error Detected, Resend Code"<<endl;
                }
            }
            break;
            case 4:
            if(code_accepted==0){
                cout<<"Please enter a valid message first"<<endl;
            }
            else if(sender_side_processed==0){
                cout<<"Process the code via sender side first"<<endl;
            }
            else{
                int r_bits=0;
                flag=0;
                code_sent_length = code_sent_length-3;
                while(flag==0){
                    if(code_sent_length+r_bits<=power(2,r_bits)-1){
                        flag=1;
                    }
                    else{
                        r_bits++;
                    }
                }
                int hamming_code_sent[code_sent_length+r_bits+1],hamming_code_recieved[code_sent_length+r_bits+1];
                hamming_code_sent[0] = 0;
                j=0;
                k=0;
                for(i=1;i<code_sent_length+r_bits+1;i++){
                    if(i==power(2,j)){
                        j++;
                    }
                    else{
                        hamming_code_sent[i] = sent[k];
                        k++;
                    }
                }
                cout<<"Finding the Redundancy Bits ---"<<endl;
                l=0;
                for(j=0;j<r_bits;j++){
                    k=0;
                    flag=0;
                    while(k<code_sent_length+r_bits+1){
                        temp = power(2,l);
                        while(temp>0){
                            k++;
                            temp--;
                        }
                        if(k>code_sent_length+r_bits){
                            break;
                        }
                        temp = power(2,l);
                        while(temp>0){
                            if(k!=power(2,l)){
                                if(flag==0){
                                    hamming_code_sent[power(2,l)] = hamming_code_sent[k];
                                    flag=1;
                                }
                                else{
                                    hamming_code_sent[power(2,l)] = xor1(hamming_code_sent[power(2,l)],hamming_code_sent[k]);
                                }
                                k++;
                                temp--;
                            }
                            else{
                                k++;
                                temp--;
                            }
                            if(k>code_sent_length+r_bits){
                                break;
                            }
                        }
                        if(k>code_sent_length+r_bits){
                            break;
                        }
                    }
                    l++;
                }
                cout<<"Hamming Code Sent : ";
                for(i=code_sent_length+r_bits;i>0;i--){
                    cout<<hamming_code_sent[i];
                }
                cout<<endl;

                int error_pos[r_bits];
                int error=0,error_correct=0;
                cout<<"Enter a position to input the error : ";
                cin>>error;
                error = error%(code_sent_length+r_bits);
                cout<<"Putting an error at the "<<error<<" bit ---"<<endl;
                for(i=0;i<code_sent_length+r_bits+1;i++){
                    hamming_code_recieved[i] = hamming_code_sent[i];
                }
                hamming_code_recieved[error] = flip(hamming_code_recieved[error]);
                for(i=code_sent_length+r_bits;i>0;i--){
                    cout<<hamming_code_recieved[i];
                }
                cout<<endl;
                cout<<"Finding the Error ---"<<endl;
                for(j=0;j<r_bits;j++){
                    k=0;
                    flag=0;
                    while(k<code_sent_length+r_bits+1){
                        temp = power(2,j);
                        while(temp>0){
                            k++;
                            temp--;
                        }
                        if(k>code_sent_length+r_bits){
                            break;
                        }
                        temp = power(2,j);
                        while(temp>0){
                            if(flag==0){
                                error_pos[j] = hamming_code_recieved[k];
                                flag=1;
                            }
                            else{
                                error_pos[j] = xor1(error_pos[j],hamming_code_recieved[k]);
                            }
                            k++;
                            temp--;
                            if(k>code_sent_length+r_bits){
                                break;
                            }
                        }
                        if(k>code_sent_length+r_bits){
                            break;
                        }
                    }
                }
                cout<<"Error Position : ";
                for(i=r_bits-1;i>-1;i--){
                    cout<<error_pos[i];
                }
                cout<<endl;
                cout<<"Correcting the error : ";
                for(i=0;i<r_bits;i++){
                    error_correct = error_pos[i]*power(2,i)+error_correct;
                }
                hamming_code_recieved[error_correct] = flip(hamming_code_recieved[error_correct]);
                for(i=code_sent_length+r_bits;i>0;i--){
                    cout<<hamming_code_recieved[i];
                }
                cout<<endl;
            }
            break;
            case 5:
            cout<<"------Exiting------"<<endl;
            break;
            default:
            cout<<"Enter a valid input"<<endl;
        }
    }
}