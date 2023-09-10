#include <bits/stdc++.h>

using namespace std;

char s[100005];

char temp;
int index_num;

void read_char();
void print_out(int mode);


int main(int argc, char const *argv[])
{ 
    index_num = 0;
    read_char();
    print_out(11);
    printf("\n");
    print_out(21);

    return 0;
}


void read_char(){
    while(true){
        temp = getchar();
        if(temp == 'E'){
            s[index_num] = '\0';
            index_num++;
            break;
        }else{
            if(temp == 'W' || temp == 'L'){
                s[index_num] = temp;
                index_num++;
            }
        }
    }
}

void print_out(int mode){
    int num1=0,num2=0;
    for(int i = 0; i < index_num; i++){
        if(s[i] == 'W'){
            num1++;
        }else if(s[i] == 'L'){
            num2++;
        }
        if(((num1>=mode || num2>=mode) && abs(num1-num2) >= 2) || (i == index_num-1)){
            printf("%d:%d\n",num1,num2);
            num1=0,num2=0;
        }
    }
}