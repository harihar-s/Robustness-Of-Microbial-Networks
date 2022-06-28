#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main(){
    int n = 20, i, j;
    double w;
    freopen("test1.txt", "w", stdout);
    cout << n << "\n";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j){
                cout << 0 << " ";
            }
            else{
                w = rand()%1000;
                w /= 1000;
                cout << w << " ";
            }
        }
        cout << "\n";
    }
    fclose(stdout);
    freopen("test2.txt", "w", stdout);
    cout << n << "\n";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==j){
                cout << 0 << " ";
                continue;
            }
            if((i<10 && j<10) || (i>=10 && j>=10)){
                w = rand()%1000;
                w /= 1000;
                cout << w << " ";
            }
            else{
                if((rand()%10)==0){
                    w = rand()%1000;
                    w /= 1000;
                    cout << w << " ";
                }
                else{
                    cout << 0 << " ";
                }
            }
        }
        cout << "\n";
    }
    fclose(stdout);
    freopen("test3.txt", "w", stdout);
    cout << n << "\n";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            w = rand()%1000;
            w /= 1000;
            if(i==j){
                cout << 0 << " ";
            }
            else if(i<5 && j<5){
                cout << w << " ";
            }
            else if(i>=5 && i<10 && j>=5 && j<10){
                cout << w << " ";
            }
            else if(i>=10 && i<15 && j>=10 && j<15){
                cout << w << " ";
            }
            else if(i>=15 && i<20 && j>=15 && j<20){
                cout << w << " ";
            }
            else{
                if(rand()%15==0){
                    cout << w << " ";
                }
                else{
                    cout << 0 << " ";
                }
            }
        }
        cout << "\n";
    }
    fclose(stdout);
    freopen("test4.txt", "w", stdout);
    cout << n << "\n";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            w = rand()%1000;
            w /= 1000;
            if(i!=j && abs(i-j)<=4){
                cout << w << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    fclose(stdout);
    freopen("test5.txt", "w", stdout);
    cout << n << "\n";
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            w = rand()%1000;
            w /= 1000;
            if(abs(i-j)==1){
                cout << w << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    fclose(stdout);
    return 0;
}