#include <iostream>
#include <string>
using namespace std;

int main(){

string in;
int number = 0;
int input[10000];
int output = 0;
int temp;
int a; int s=0; int ans= 0;

while(cin >> in){
        if(in == "x"){break;}
        temp = 0;
        if(in[0] != '-'){
            for(int i = 0; i < in.length(); i++){
                temp = temp*10 + (in[i] - '0');
            }
            input[number] = temp;
        }
        if(in[0] == '-'){
            for(int i = 1; i < in.length(); i++){
                temp = temp*10 + (in[i] - '0');
            }
            input[number] = temp * -1;
        }
        //cout << "number" << number << ": " << input[number] << endl;
        number++;
}

    for(int n=  0; n < number; n++){
        a = input[n];
        for(int m =  n + 1; m < number; m++){
            a = a + input[m];
            temp = a;
            if(temp > output){output = temp;}
        }
    }

   cout << output << endl;

return 0;
}
