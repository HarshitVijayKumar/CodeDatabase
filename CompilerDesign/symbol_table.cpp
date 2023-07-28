#include <iostream>
using namespace std;

int main(){
  string code,temp;
  int i,j,t,temp_num,mult,no_of_line=0,n=0;
  cout<<"Enter the code : ";
  getline(cin,code);

  for(i=0;i<code.length();i++){
    if(code[i]==';'){
      no_of_line++;
      n++;
    }
    if(code[i]==',')
      n++;
    if(code[i]=='['){
      i=i+1;
      temp_num = 0;
      mult=1;
      while(code[i]!=']'){
        temp_num = temp_num*mult+(int)code[i]-48;
        mult = mult*10;
        i++;
      }
      n = n+temp_num-1;
    }
  }
  
  string line[no_of_line];
  int k=0;
  for(i=0;i<code.length();i++){
    if(code[i]!=';')
      temp = temp+code[i];
    else{
      line[k] = temp;
      temp = "";
      k++;
    }
  }
  
  string type[n],name[n];
  int mem=1000,memory[n];
  temp = "";
  k=0;
  for(i=0;i<no_of_line;i++){
    temp = "";
    j = 0;
    while(line[i][j]==' '){
      j++;
    }
    while(line[i][j]!=' '){
      temp = temp+line[i][j];
      j++;
    }
    type[k] = temp;
    while(line[i][j]==' '){
      j++;
    }
    while(j<line[i].length()){
      if(line[i][j]!=','){
        name[k] = name[k]+line[i][j];
        j++;
      }
      if(line[i][j]==','){
        type[k+1] = type[k];
        j++;
        k++;
      }
      if(line[i][j]=='['){
        j++;
        temp_num = 0;
        mult = 1;
        while(line[i][j]!=']'){
          temp_num = temp_num*mult + (int)line[i][j]-48;
          mult = mult*10;
          j++;
        }
        j++;
        for(t=0;t<temp_num;t++){
          type[k+t] = type[k];
          name[k+t] = name[k];
        }
        for(t=0;t<temp_num;t++){
          name[k+t] = name[k+t]+'['+(char)(t+48)+']';
        }
        k = k+t-1;
      }
    }
    k++;
  }
  for(i=0;i<k;i++){
    if(type[i].compare("int")==0){
      memory[i] = mem;
      mem = mem+2;
    }
    if(type[i].compare("float")==0){
      memory[i] = mem;
      mem = mem+4;
    }
    if(type[i].compare("char")==0){
      memory[i] = mem;
      mem = mem+1;
    }
    if(type[i].compare("double")==0){
      memory[i] = mem;
      mem = mem+8;
    }
  }

  cout<<"Symbol Table -- "<<endl;
  cout<<"Type"<<"\t"<<"Name"<<"\t"<<"Memory"<<endl;
  for(i=0;i<k;i++){
    cout<<type[i]<<"\t"<<name[i]<<"\t"<<memory[i]<<endl;
  }
  return(0);
}
