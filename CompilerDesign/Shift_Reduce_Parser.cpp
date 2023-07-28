#include <iostream>
using namespace std;

class productions{
    public:
    char right;
    string left;
};

int push(char stack[],char symbol,int k){
    stack[k] = symbol;
    return 0;
}

int display(char stack[],string word,int k,int pointer){
    int i;
    for(i=0;i<k;i++){
        cout<<stack[i];
    }
    cout<<"\t";
    for(i=pointer;i<word.length();i++){
        cout<<word[i];
    }
    cout<<"\t\t";
    return 0;
}

int main(){
    string word,temp;
    int n,i,j,l;
    cout<<"Enter the RE : ";
    cin>>word;
    cout<<"Enter the number of productions : ";
    cin>>n;

    productions rules[n];
    cout<<"While entering a production rule instead of '->' please use '>'"<<endl;
    for(i=0;i<n;i++){
        cout<<"Enter production "<<i<<" : ";
        cin>>temp;
        j=0;
        rules[i].right = temp[j];
        j++;
        if(temp[j]=='>')
            j++;
        while(j<temp.length()){
            rules[i].left = rules[i].left + temp[j];
            j++;
        }
    }

    cout<<"Stack"<<"\t"<<"Input Buffer"<<"\t"<<"Action"<<endl;
    word = word+'$';
    char stack[word.length()];
    int k=0,pointer=0; //Tells where the pointer of the stack is
    //Pushing the $ symbol
    push(stack,'$',k);
    k++;
    display(stack,word,k,pointer);
    cout<<"Initialization"<<endl;
    while((word[pointer]!='$')){
        push(stack,word[pointer],k);
        pointer++;
        k++;
        display(stack,word,k,pointer);
        cout<<"Shift"<<endl;
        temp = "";
        i=k;
        while(stack[i-1]!='$'){
            temp = temp+stack[i-1];
            i--;
            for(l=0;l<n;l++){
                if (temp==rules[l].left){
                    temp = "";
                    for(j=i;j<k;j++){
                        stack[j] = ' ';
                    }
                    push(stack,rules[l].right,i);
                    i++;
                    k=i;
                    display(stack,word,k,pointer);
                    cout<<"Reduced using rules : "<<rules[l].right<<"->"<<rules[l].left<<endl;
                }
            }
        }
    }
    temp = "";
    for(i=0;i<k;i++){
        temp = temp+stack[i];
    }
    cout<<endl;
    if(temp=="$E")
        cout<<"The string is a valid string!"<<endl;
    else
        cout<<"The string is an invalid string!"<<endl;
    return 0;
}