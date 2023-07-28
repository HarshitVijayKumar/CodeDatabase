#include <iostream>
#include <string>
using namespace std;

int variable_check(int i,string equation[]){
    if (((equation[i][0]>64)&&(equation[i][0]<91))||((equation[i][0]>96)&&(equation[i][0]<123))){
        return 1;
    }
    else{
        return 0;
    }
}

int operator_check(int i,string equation[]){
    if((equation[i][0]=='+')||(equation[i][0]=='-')||(equation[i][0]=='*')||(equation[i][0]=='/')||(equation[i][0]=='^')||(equation[i][0]=='=')){
        return 1;
    }
    else{
        return 0;
    }
}

int uppercase_check(char s){
    if(((int)s>64)&&((int)s<91)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    string equation;
    //Please enter a string in lowercase only
    //The variables will be generate in uppercase
    cout<<"Enter the string : ";
    getline(cin,equation);

    //Variables
    int i,j,size,eq_pointer=0,variable_pointer=0,k=65;
    string eq_array[equation.length()],variables[equation.length()];

    for(i=0;i<equation.length();i++){
        if(equation[i]!=' '){
            eq_array[eq_pointer] = equation[i];
            eq_pointer++;
        }
    }
    size = eq_pointer-1;
    while(size>1){
        if(variable_check(size,eq_array)==1){
            if(operator_check(size-1,eq_array)==1){
                if(variable_check(size-2,eq_array)==1){
                    variables[variable_pointer] = eq_array[size-2]+eq_array[size-1]+eq_array[size];
                    eq_array[size-2] = (char)k;
                    k++;
                    variable_pointer++;
                    size = size-2;
                }
                else{
                    variables[variable_pointer] = eq_array[size-1]+eq_array[size];
                    eq_array[size-1] = (char)k;
                    k++;
                    variable_pointer++;
                    size = size-1;
                }
            }
        }
    }
    
    for(j=0;j<variable_pointer;j++){
        cout<<(char)(65+j)<<" = "<<variables[j]<<endl;
    }
    //Quadruples
    cout<<"Quadruple Generation\n"<<endl;
    cout<<"Op\tS1\tS2\tResult"<<endl;
    for(i=0;i<variable_pointer;i++){
        if(variables[i][0]=='+'){
            cout<<"uplus\t"<<variables[i][1]<<"\t-\t"<<(char)(65+i)<<endl;
        }
        else if(variables[i][0]=='-'){
            cout<<"uminus\t"<<variables[i][1]<<"\t-\t"<<(char)(65+i)<<endl;
        }
        else if((variables[i][1]=='+')||(variables[i][1]=='-')||(variables[i][1]=='*')||(variables[i][1]=='/')||(variables[i][1]=='^')||(variables[i][1]=='^')){
            cout<<variables[i][1]<<"\t"<<variables[i][0]<<"\t"<<variables[i][2]<<"\t"<<(char)(65+i)<<endl;
        }
    }
    cout<<endl;
    //Triples
    cout<<"Triple Generation\n"<<endl;
    cout<<"Op\tArg1\tArg2"<<endl;
    for(i=0;i<variable_pointer;i++){
        if(variables[i][0]=='+'){
            cout<<"uplus\t"<<variables[i][1]<<endl;
        }
        else if(variables[i][0]=='-'){
            cout<<"uminus\t"<<variables[i][1]<<endl;
        }
        else if((variables[i][1]=='+')||(variables[i][1]=='-')||(variables[i][1]=='*')||(variables[i][1]=='/')||(variables[i][1]=='^')||(variables[i][1]=='=')){
            if(uppercase_check(variables[i][2])==1)
                cout<<variables[i][1]<<"\t"<<variables[i][0]<<"\t("<<(int)variables[i][2]-65<<")\t"<<endl;
            else
                cout<<variables[i][1]<<"\t"<<variables[i][0]<<"\t"<<variables[i][2]<<"\t"<<endl;
        }
    }
    cout<<endl;
    //Indirect Triples
    cout<<"Indirect Triple Generation\n"<<endl;
    cout<<"sno\tOp\tArg1\tArg2"<<endl;
    for(i=0;i<variable_pointer;i++){
        if(variables[i][0]=='+'){
            cout<<"("<<65+i<<")\tuplus\t"<<variables[i][1]<<endl;
        }
        else if(variables[i][0]=='-'){
            cout<<"("<<65+i<<")\tuminus\t"<<variables[i][1]<<endl;
        }
        else if((variables[i][1]=='+')||(variables[i][1]=='-')||(variables[i][1]=='*')||(variables[i][1]=='/')||(variables[i][1]=='^')||(variables[i][1]=='=')){
            if(uppercase_check(variables[i][2])==1)
                cout<<"("<<65+i<<")\t"<<variables[i][1]<<"\t"<<variables[i][0]<<"\t("<<(int)variables[i][2]<<")\t"<<endl;
            else
                cout<<"("<<65+i<<")\t"<<variables[i][1]<<"\t"<<variables[i][0]<<"\t"<<variables[i][2]<<"\t"<<endl;
        }
    }
    cout<<endl;
    return 0;
}