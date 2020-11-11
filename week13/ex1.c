#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, fine=0, exceeds=0;

    FILE* file = fopen("input_dl.txt", "r");
    FILE* file1 = fopen("output_dl.txt", "w");
    fscanf(file,"%d %d", &n, &m);
    int E[m], A[m], C[n][m], R[n][m];
    for (int i = 0; i<m; i++){fscanf(file, "%d", &E[i]);}
    for (int i = 0; i<m; i++){fscanf(file, "%d", &A[i]);}
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            fscanf(file, "%d", &C[i][j]);
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            fscanf(file, "%d", &R[i][j]);
        }
    }

    int status[n];
    for (int i = 0; i<n; i++){
        status[i] = 0;
    }

    for (int i = 0; i<n; i++){
        int index = -1;
        for (int j = 0; j<n; j++){
            if (status[j] == 0){
                int fits = 1;
                for (int k = 0; k<m; k++){
                    if (A[k]<R[j][k]){
                        fits = 0;
                        break;
                    }
                }
                if (fits == 0){
                    continue;
                }
                index = j;
                break;
            }
        }
        if(index == -1){
            break;
        }
        for (int k = 0; k<m; k++){
            A[k] = A[k] + C[index][k];
        }

        status[i]=1;
        fine++;
    }
    if (fine==n){
        fprintf(file1, "Deadlock is not detected");
    }
    else{
        fprintf(file1, "Process(-es) ");
        for (int i = 0; i<n; i++){
            if(status[i]==0)
                fprintf(file1,"%d ", i);
        }
        fprintf(file1, " is(are) in deadlock state");

    }
    fclose(file);
    fclose(file1);



    return 0;
}