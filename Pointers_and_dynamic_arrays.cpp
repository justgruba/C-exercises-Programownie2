/*
0. Utworzyć tablicę A o rozmiarze n i wypełnić ja losowymi wartościami od 0 do 10
1. Wyszukuje największą wartość w tablicy A
2. Odwraca kolejność elementów w tablicy A
3. Cylkiczne przesuwanie elementów tablicy w lewo o m pól
4. Uworzyć dwie posortowane tablice, a następnie scalić je w jedną posortowaną
5. Przemoży ze sobą współczynniki wielomianu stopnia m i n. Tablicę liczb można traktować jako współczynniki wielomianu
6. Utworzyć tablicę S taką, że S[n][k] = symbol Newtona "n po k". Dla N >= 0 */
#include <iostream>
#include <cstdlib>

void display(int* A, int length){
    for(int i=0; i < length; i++){
        std::cout << *(A+i) << "  ";
    }
    std:: cout << std::endl;
}
//6
void triangle(int n){

    //dynamiczna tablica wskaźników na wskaźniki
    int** S = new int* [n + 1];
    for(int i =0; i < n; i++){
        *(S+i) = new int[i];
    }

    for(int row=0; row<n; row++){
        **(S+row) = *(*(S+row)+row) =1;
    }

      for(int row=2; row < n; row++){
          for(int col =1; col < row; col++)
            *(*(S+row)+col) = *(*(S+row-1)+col-1) + *(*(S+row-1)+ col);
      }
    int i=0, j=0;
    for(i =0; i < n; i++){
        for( j=0; j<i; j++) {
            std::cout << *(*(S+i)+j) << "  ";
        }
        std::cout<<*(*(S+i)+j)<<std::endl;
    }
    for(int i=0; i < n; i++) {
        delete S[i];
    }
    delete[] S;
}
//5
void multiply(int* A, int* B,int n, int m){
    int* C = new int[m+n];
    for(int i=0; i < (m+n); i ++)
        *(C+i) = 0;

    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++)
            *(C+j+i) += *(A+i) * (*(B+j));
    }
    display(C, (n+m));

      delete[] C;
}
//4
void sort(int* arr, int length) {
    for (int i = 1; i < length; ++i) {
        for (int j = 0; j < (length - i); ++j)
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;

            }
    }
}
void join(int* A, int* B, int n, int m){
    int* C = new int[n+m];
    int i=0, j=0;
    sort(A,n);
    sort(B,m);

    while(i < n && j<m){
        if(*(A+i) < *(B+j)){
            *(C+i+j) = *(A+i);
            i++;
        }
        else{
            *(C+i+j) = *(B+j);
            j++;
        }
    }
    while(i<n){
        *(C+i+j) = *(A+i);
        i++;
    }
    while(j<m){
        *(C+i+j) = *(B+j);
        j++;
    }
    display(C, (n+m));
    delete[] C;
}
//3
void move(int* A, int n, int m){

    for( int j =0; j <m; j++) {
        int temp = *A;
        for (int i = 0; i < n; i++) {
            *(A + i) = *(A + i + 1);
        }
        *(A + n - 1) = temp;
    }
    display(A, n);
}
//2
void reverse(int* A, int n){
    int j = n-1;
    for(int i =0; i <j; i++, j--){
      int  tmp = *(A+i);
        *(A+i) = *(A+j);
        *(A+j) = tmp;
    }
    display(A,n);
}
//1
int findMaxminum(int* A, int n){
    int max= *A;

    for(int i=0; i<n; i++)
        if(*(A+i) > max) {
            max = *(A + i);
        }
    return max;
}

//0
int* createArray(int n){
    int* A = new int[n];

    for(int i=0; i < n; i++)
        *(A + i) = rand() % 11;

    return A;
}

int main() {
    int n = 10;
    int m = 15;
    int* A = createArray(n);
    int* B = createArray(m);
 //   display(A, n);
 //   display(B, m);
 //   std:: cout << findMaxminum( A, n);
 //   reverse(A, n);
  //  move(A, n, 5);
 // join(A, B, n, m);
   // multiply(A ,B, n, m);
   triangle(6);
    delete[] A;
    delete[] B;
}
