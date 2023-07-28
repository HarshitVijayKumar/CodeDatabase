#include <stdio.h>

int main(){
    char network_ip[16];
    printf("Enter the network IP : ");
    scanf("%s",network_ip);
    int network_class=0;
    for (int i=0;network_ip[i]!='.';i++){
        network_class = network_class*10 + ((int)network_ip[i]-48);
    }
    if((network_class<0)||(network_class>255)){
        printf("Invalid IP! \n");
    }
    else if((network_class>=0)&&(network_class<=127)){
        printf("%s is a Class A Network! \n",network_ip);
    }
    else if((network_class>=128)&&(network_class<=191)){
        printf("%s is a Class B Network! \n",network_ip);
    }
    else if((network_class>=192)&&(network_class<=223)){
        printf("%s is a Class C Network! \n",network_ip);
    }
    else if((network_class>=224)&&(network_class<=239)){
        printf("%s is a Class D Network! \n",network_ip);
    }
    else{
        printf("%s is a Class E Network! \n",network_ip);
    }
    return 0;
}

