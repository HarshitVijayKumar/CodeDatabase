#include <iostream>
using namespace std;

int variable_check(char s){
    if (((s>64)&&(s<91))||((s>96)&&(s<123))){
        return 1;
    }
    else{
        return 0;
    }
}

int operator_check(char s){
    if((s=='+')||(s=='-')||(s=='*')||(s=='/')||(s=='^')||(s=='=')){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    cout<<"Enter the number of codes : ";
    cin>>n;

    string code[n];
    int i,j,k;

    cout<<"Enter the codes : "<<endl;
    for(i=0;i<n;i++){
        cin>>code[i];
    }

    k=1;
    for(i=0;i<n;i++){
        j=code[i].length()-1;
        while(j>-1){
            if (code[i][j]==' '){
                j--;
            }
            else{
                if(variable_check(code[i][j])==1){
                    cout<<"MOVE R"<<k<<", "<<code[i][j]<<endl;
                    k++;
                    j--;
                }
                else if(code[i][j]=='='){
                    cout<<"ASSIGN "<<code[i][j-1]<<",R"<<k-1<<endl;
                    j=j-2;
                }
                else if(operator_check(code[i][j])==1){
                    if(variable_check(code[i][j-1])==1){
                        if(code[i][j]=='+'){
                            cout<<"ADD R"<<k-1<<", "<<code[i][j-1]<<endl;
                        }
                        else if(code[i][j]=='-'){
                            cout<<"SUB R"<<k-1<<", "<<code[i][j-1]<<endl;
                        }
                        if(code[i][j]=='*'){
                            cout<<"MUL R"<<k-1<<", "<<code[i][j-1]<<endl;
                        }
                        if(code[i][j]=='/'){
                            cout<<"DIV R"<<k-1<<", "<<code[i][j-1]<<endl;
                        }
                        j=j-2;
                    }
                    else{
                        if(code[i][j]=='-'){
                            cout<<"SUB R"<<k-1<<", 2*"<<code[i][j+1]<<endl;
                        }
                        j=j-2;
                    }
                }
                else{
                    j--;
                }
            }
        }
    }
}