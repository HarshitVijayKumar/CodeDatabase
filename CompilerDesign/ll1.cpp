#include <iostream>
using namespace std;

class non_terminal{
  public:
  string name="";
  string right="";
  string first="";
  string follow="";
};
int main(){
  string grammar,temp;
  cout<<"Note: Enter Epsilon as #"<<endl;
  cout<<"Enter the grammars : ";
  getline(cin,grammar);
  int i,j,k,l,flag,n=0;
  i=0;
  while(i<grammar.length()){
    if(grammar[i]==';'){
      n++;
    }
    i++;
  }
  non_terminal nt[n];
  i=0,j=0;
  //Dividing the grammar into Non-Terminal and the Grammar it follows
  while(i<grammar.length()){
    while(grammar[i]!='>'){
      temp = temp+grammar[i];
      i++;
    }
    nt[j].name = nt[j].name+temp;
    i++;
    temp="";
    while(grammar[i]!=';'){
      temp = temp+grammar[i];
      i++;
    }
    nt[j].right = nt[j].right+temp;
    i++;
    j++;
    temp="";
  }
  k=0;
  //Calculation of First where First element Terminal
  while(k<n){
    temp = "";
    i=0;
    if(((nt[k].right[i]>96)&&(nt[k].right[i]<123))||(nt[k].right[i]=='#')){
      temp = temp+nt[k].right[i];
      i++;
    }
    while(i<(nt[k].right).length()){
      if(nt[k].right[i]=='|'){
        i++;
        if(((nt[k].right[i]>96)&&(nt[k].right[i]<123))||(nt[k].right[i]=='#')){
          temp = temp+nt[k].right[i];
        }
      }
      i++;
    }
    nt[k].first = nt[k].first+temp;
    k++;
  }
  //Calculation of First where First element is Non-Terminal
  k=0;
  while(k<n){
    temp = "";
    i=0;
    if((nt[k].right[i]>64)&&(nt[k].right[i]<91)){
      flag=1;
      j=0;
      while(j<n){
        if(nt[j].name[0]==nt[k].right[i]){
          nt[k].first = nt[k].first+nt[j].first;
          break;
        }
        else{
          j++;
        }
      }
      i++;
    }
    while(i<(nt[k].right).length()){
      if(nt[k].right[i]=='|'){
        i++;
        if((nt[k].right[i]>64)&&(nt[k].right[i]<91)){
          flag=1;
          j=0;
          while(j<n){
            if(nt[j].name[0]==nt[k].right[i]){
              nt[k].first = nt[k].first+nt[j].first;
              break;
            }
            else{
              j++;
            }
          }
        }
      }
      i++;
    }
    k++;
  }
  //Follow Condition for the Start Symbol
  nt[0].follow = "$";
  //Follow Condition
  k=0;
  while(k<n){
    i=0;
    while(i<grammar.length()){
      if(nt[k].name[0]==grammar[i]){
        if(i<(grammar).length()){
          i++;
          //Follow Condition for Teminals
          if((grammar[i]>96)&&(grammar[i]<123)){
            nt[k].follow = nt[k].follow+grammar[i];
          }
          //Follow Condition for Non-Terminals
          if((grammar[i]>64)&&(grammar[i]<91)){
            j=0;
            while(j<n){
              if(nt[j].name[0]==grammar[i]){
                for(l=0;l<(nt[j].first).length();l++){
                  if(nt[j].first[l]!='#'){
                    nt[k].follow = nt[k].follow+nt[j].first[l];
                  }
                }
                break;
              }
              else{
                j++;
              }
            }
          }
        }
      }
      i++;
    }
    k++;
  }
  //Folow Condtion for when the last terminal is a Non-Terminal
  k=0;
  while(k<n){
    i=0;
    temp="";
    while(i<(nt[k].right).length()){
      if(nt[k].right[i]=='|'){
        i--;
        if((nt[k].right[i]>64)&&(nt[k].right[i]<91)){
          j=0;
          while(j<n){
            if(nt[j].name[0]==nt[k].right[i]){
              nt[k].follow = nt[k].follow+nt[j].follow;
              break;
            }
            else{
              j++;
            }
          }
        }
        break;
      }
      i++;
    }
    i = (nt[k].right).length()-1;
    if((nt[k].right[i]>64)&&(nt[k].right[i]<91)){
      j=0;
      while(j<n){
        if(nt[j].name[0]==nt[k].right[i]){
          nt[k].follow = nt[k].follow+nt[j].follow;
          break;
        }
        else{
          j++;
        }
      }
    }
    k++;
  }
  //Follow Condition for when the Non-Terminal has epsilon
  
  for(i=0;i<n;i++){
    cout<<"Non-Terminal"<<"\t"<<"FIRST()"<<"\t\t"<<"FOLLOW()"<<endl;
    cout<<nt[i].name<<"\t\t"<<nt[i].first<<"\t\t"<<nt[i].follow<<endl;
  }
  //Parsing Table
  string terminals="";
  for(i=0;i<grammar.length();i++){
    if((grammar[i]>96)&&(grammar[i]<123)){
      flag=0;
      j=0;
      while(j<terminals.length()){
        if(grammar[i]==terminals[j]){
          flag=1;
          break;
        }
        j++;
      }
      if(flag==0){
        terminals=terminals+grammar[i];
      }
    }
  }
  terminals = terminals+"$";
  cout<<"Terminals : "<<terminals<<endl;
  string parsing_table[n][terminals.length()];
  for(i=0;i<n;i++){
    for(j=0;j<terminals.length();j++){
      parsing_table[i][j] = "error";
    }
  }
  //Parsing Table for First without Epsilon
  k=0;
  while(k<n){
    i=0;
    j=0;
    while(i<(nt[k].first).length()){
      for(j=0;j<terminals.length();j++){
        if(nt[k].first[i]==terminals[j]){
          parsing_table[k][j] = nt[k].right;
        }
      }
      i++;
    }
    k++;
  }
  //Parsing Table for First with Epsilon
  k=0;
  while(k<n){
    i=0;
    j=0;
    while(i<(nt[k].first).length()){
      if(nt[k].first[i]=='#'){
        j=0;
        for(l=0;l<(nt[k].follow).length();l++){
          while(j<terminals.length()){
            if(nt[k].follow[l]==terminals[j]){
              parsing_table[k][j] = "#";
            }
            j++;
          }
        }
      }
      i++;
    }
    k++;
  }
  cout<<"Parsing Table : "<<endl;
  cout<<"NT"<<"\t";
  for(i=0;i<terminals.length();i++){
    cout<<terminals[i]<<"\t";
  }
  cout<<endl;
  for(i=0;i<n;i++){
    cout<<nt[i].name[0]<<"\t";
    for(j=0;j<terminals.length();j++){
      cout<<parsing_table[i][j]<<"\t";
    }
    cout<<endl;
  }
  //Parsing the string
  string entered_string;
  cout<<"Enter the string : ";
  cin>>entered_string;
  string temp_parser,parser="";
  cout<<"Parsing : "<<endl;
  while(entered_string!=""){
    temp = "";
    temp = entered_string[0];
    for(i=0;i<n;i++){
      for(j=0;j<terminals.length();j++){
        if(parsing_table[i][j]==temp){
          parser = parser+nt[i].name[0];
        }
      }
    }
    cout<<parser<<endl;
    if(entered_string.length()==1){
      entered_string = "";
    }
    else{
      temp = "";
      i=1;
      while(i<entered_string.length()){
        temp = temp+entered_string[i];
        i++;
      }
      entered_string = temp;
    }
  }
  temp_parser = parser;
  parser = "";
  while(temp_parser!=""){
    parser = parser+temp_parser[0];
    for(i=0;i<n;i++){
      for(j=0;j<terminals.length();j++){
        if(parsing_table[i][j]==parser){
          parser = nt[i].name[0];
        }
      }
    }
    if(temp_parser.length()==1){
      temp_parser = "";
    }
    else{
      temp = "";
      i=1;
      while(i<temp_parser.length()){
        temp = temp+temp_parser[i];
        i++;
      }
      temp_parser = temp;
    }
  }
  cout<<parser<<endl;
  if(parser==nt[0].name){
    cout<<"The string belongs to the grammar"<<endl;
  }
  else{
    cout<<"The string does not belong to the grammar"<<endl;
  }
  return 0;
}
