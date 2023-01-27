// Determinant Calculator

/* This program will calculate the determinant 
of a given matrix of order n using Gaussian Elimination */

#include<stdio.h>
#include<math.h>

int gaussMethod(int n, double arr[n][n]){
    int i;
    int x;
    int y;
    double ratio;
    int rowSwaps = 0;

    for(i=0;i<n-1;i++){
        for(y=i+1;y<n;y++){
            if(fabs(arr[i][i]) < fabs(arr[y][i])){
                rowSwaps++;
                for(x=0;x<n;x++){                
                    double temp;
                    temp = arr[i][x];
                    arr[i][x] = arr[y][x];
                    arr[y][x] = temp;
                }
            }
        }
        
        for(y=i+1;y<n;y++){
            if(arr[i][i] != 0){
                ratio = arr[y][i]/arr[i][i];
            } else{
                ratio = arr[y][i]*arr[i][i];
            }
            for(x=0;x<n;x++){
                arr[y][x] = arr[y][x] - ratio*arr[i][x];
            }
        }
    }
    return rowSwaps;       
}

double calcDet(int n, double arr[n][n]){
    int rowSwaps = gaussMethod(n, arr);
    double sign = pow(-1,rowSwaps);
    double det = 1;

    for(int i=0;i<n;i++){
        det = det*arr[i][i];
    }
    return det*sign;
}

void getMatrix(int n, double arr[n][n]){
    int i;
    int x;
    int rowSwaps = gaussMethod(n, arr);
    double sign = pow(-1,rowSwaps);
    double det = 1;

    for(i=0;i<n;i++){
        for(x=0;x<n;x++){
            scanf("%lf",&arr[i][x]);
        }
    } 
}

int main(){
    int x;
    scanf("%d",&x);
    double arr[x][x];
    getMatrix(x,arr); 
    printf("%0.02lf\n",calcDet(x,arr));
}