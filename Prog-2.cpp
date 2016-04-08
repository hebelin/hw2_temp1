#include <iostream>
#include <string>
using namespace std;

int maxsubfind(int A[], int left, int right) {
    if(right == left){
        return A[left];
    }
    int middle = (left + right) / 2;
    int leftans = maxsubfind(A, left, middle);
    int rightans = maxsubfind(A, middle+1, right);
    int leftmax = A[middle];
    int rightmax = A[middle+1];
    int temp = 0;
    for(int i = middle; i >= left; i--) {
        temp = temp + A[i];
        if(temp > leftmax){
            leftmax = temp;
        }
    }
    temp = 0;
    for(int i = middle + 1; i <= right; i++) {
        temp = temp + A[i];
        if(temp > rightmax){
            rightmax = temp;
        }
    }
    return max(max(leftans, rightans),leftmax+rightmax);
}

int maxsub(int A[], int n) {
    if(n==0) return 0;
    else if(n > 0){
        int ans = maxsubfind(A,0,n-1);
        return ans;
    }
}

int main(){

string in;
int number = 0;
int input[10000];
int output = 0;
int temp;

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

    cout << maxsub(input, number) <<endl;

return 0;
}
