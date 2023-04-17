#include<stdio.h>
#include<math.h>

// function to find the largest integer n such that 3^n is less than or equal to x
int findN(int x);

// function to get the sequence of signs
void getSig(int sig[]);

int main(){

    int x;
    printf("Please input an integer number: ");
    scanf("%d",&x);

    int n = findN(x);
    int exp[1000], sig[1000];
    int i = 0;

    for(;; i++){
        n = findN(x);
        exp[i] = n;

        if(x > (pow(3, n) / 2) && x < (pow(3, n))){
            sig[i] = -1;
            x = pow(3, n) - x;
        }
        else if(x == pow(3, n)){
            sig[i] = 0;
            break;
        }
        else{
            sig[i] = 1;
            x = x - pow(3, n);
        }
    }

    getSig(sig);
    // print the output
    for(int k = 0; k < i + 1; k++){
        if(k == 0){
            printf("L : %.0lf\n", pow(3, exp[0]));
        }
        else if(sig[k - 1] == 1){
            printf("L : %.0lf\n", pow(3, exp[k]));
        }
        else if(sig[k - 1] == -1){
            printf("R : %.0lf\n", pow(3, exp[k]));
        }
    }

    return 0;
}

// implementation of the findN function
int findN(int x){

    for(int i = 0;; i++){
        if(x > (pow(3, i) / 2) && x < (pow(3, i + 1) / 2)){
            return i;
        }
    }
}

// implementation of the getSig function
void getSig(int sig[]){

    int len = 0;
    for(; sig[len] != 0; len++);

    for(int k = len - 1; k > 0; k--){
        int temp = 1;
        for(int i = 0; i <= k; i++){
            temp *= sig[i];
        }
        sig[k] = temp;
    }
}
