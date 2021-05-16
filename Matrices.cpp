#include <iostream>
#include <math.h>
using namespace std;
#define N 4
void AddMatrices(int A[][N], int B[][N], int C[][N]){
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void SubstractMatrices(int A[][N], int B[][N], int C[][N]){
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}
void MultiplyMatrices(int A[][N], int B[][N], int C[][N]){
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            C[i][j] = 0;
            for(int k=0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}
void ScalarMultiplication(int A[][N], int k){
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            A[i][j] = A[i][j] * k;
        }
    }
}
bool EqualMatrices(int A[][N], int B[][N]){
    bool flag = false;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            if( A[i][j] != B[i][j]){
                cout << "The matrices are not equal" << endl;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(!flag)
        cout << "The matrices are equal" << endl;
    return flag;
}
int DeterminationOfMatrix( int n, int A[][N]){

    int det =0, subi, subj;
    int subMatrix[N][N];
    if( n == 2){
        return  ( (A[0][0] * A[1][1]) - (A[1][0] * A[0][1]) );
    }
    else{
        for (int m = 0; m < n; m++) {
            subi = 0;
            for (int i = 1; i < n; i++) {
                subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == m) {
                        continue;
                    }
                    subMatrix[subi][subj] = A[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, m) * A[0][m] * DeterminationOfMatrix(n - 1, subMatrix));
        }
    }
    return  det;
}
void TranspositionOfMatrix(int A[][N], int C[][N]){
    for(int i=0; i < N; i++){
        for(int j=0; j<N; j++){
            C[j][i] = A[i][j];
        }
    }
}
void DigonalSum(int A[][N] ){
    int sum=0;
    for(int i=0; i< N; i++){
        sum += A[i][i];
    }
    cout <<"Diagonal Sum = " << sum << endl;
}
bool LowerTringularMatrix(int A[][N]){
    bool lowZero= false;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            if( i < j && A[i][j] != 0){
                lowZero = true;
            }
        }
    }
    if(lowZero) {
        cout << "This matrix is not lower tringular" << endl;
        return false;
    }
    else {
        cout << "This matrix is lower tringular" << endl;
        return true;
    }
}
bool UpperTringularMatrix(int A[][N]){
    bool lowZero= false;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++){
            if( i < j && A[i][j] != 0){
                lowZero = true;
            }
        }
    }
    if(lowZero) {
        cout << "This matrix is not upper tringular" << endl;
        return false;
    }
    else {
        cout << "This matrix is upper tringular" << endl;
        return true;
    }
    return false;
}
void IdentityMatrix(int D[][N]){
    if(!LowerTringularMatrix(D) || !UpperTringularMatrix(D)){
        cout << "This matris is no identity" << endl;
    }
    else{
        int i;
        for(i=0; i <N; i++){
            if(D[i][i] != 1){
                break;
            }
        }
        if( i == N)
            cout << "This matris is identity" << endl;
        else
            cout << "This matris is no identity" << endl;
    }

}
void SparseMatrix(int D[][N]){
    int countZero=0;
    int countNonZero=0;
    for(int i=0; i<N; i++){
        for(int j=0; j < N; j++){
            if(D[i][j] == 0){
                countZero++;
            }
            else{
                countNonZero++;
            }
        }
    }
    if(countZero > countNonZero)
        cout << "This matrix is sparse" << endl;
    else
        cout << "This matrix is not sparse" << endl;

}
void SymmetricMatrix(int D[][N]){
    int E[N][N];
    TranspositionOfMatrix(D, E);
   if(! EqualMatrices(E, D))
       cout << "This matrix is symmetric" << endl;
   else
       cout << "This matrix is not symmetric" << endl;

}
int main() {
    int A[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};
    int B[N][N] = { {1, 1, 1, 1},
                    {2, 2, 2, 2},
                    {3, 3, 3, 3},
                    {4, 4, 4, 4}};

    int C[N][N];
    AddMatrices(A, B, C);
    cout << "Added matrices" << endl;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    SubstractMatrices(A, B, C);
    cout << "Substracted matrices" << endl;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    MultiplyMatrices(A, B, C);
    cout << "Multiplied matrices" << endl;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
  /*  ScalarMultiplication(A, 5);
    cout << "Scalar multiplication of a matrix" << endl;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    } */
    EqualMatrices(A, B);

     cout << "Determination of matrix = " << DeterminationOfMatrix(N, A) << endl;

    TranspositionOfMatrix(A, C);
    cout << "Transposition of matrix" << endl;
    for(int i=0; i < N; i++){
        for(int j=0; j < N; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }
    DigonalSum(A);
    int D[N][N] = { {1, 0, 1, 4},
                {0, 2, 0, 0},
                {0, 0, 3, 0},
                {0, 0, 0, 4}};
    LowerTringularMatrix(D);
    UpperTringularMatrix(D);
    IdentityMatrix(D);
    SparseMatrix(D);
    SymmetricMatrix(D);
    return 0;
}
