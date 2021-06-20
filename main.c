#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
/* 0. print the input stream in reverse order
  1. each letter in the input string found at position n in string1 assigns the corresponding
  letter from string2 to position in, and any characters not found writes unchanged
  2. reads one positive integer and prints its digits with words
  3. function int countzeros (long number), which will determine how many zeros
  have a number written in binary (counting from the first one).
  5. The content of the settlement.txt file always consists of an unknown number of lines.
  Each line contains the name of the item (one word, no whitespace) and the price, e.g .:
 sandwich 2.50
 cake 1.50
 mineral_water 1.75
The program calculates the total amount due and adds this amount to the file bills.txt
  6. same as 5. only the name of the item contains whitespace
  7. reads words from a file with the name saved in the input.txt file, calculates the average,
  minimum and maximum length of words and the number of words, and puts the results in the statistics.dat file.
 11. dynamically creates an array of the given size, fills it with random numbers, and then lists all elements, ignoring duplicates.
 12.
the program, which dynamically creates a 2D array with given dimensions, completes it with random numbers;
 sorts the value on each line; Sorts rows according to increasing standard deviation.*/
//0
void ReverseString(){
    char text[20] = "Hello World";
    int size = strlen(text);
    for (int i = size-1; i >= 0; i--)
    {
        printf("%c", toupper(text[i]));
    }
    printf("\n");
}
//1
void FindLetter(){
    char S1[100]= "abcdefghijklmnopqrstuvwxyz";
    char S2[100]= "yxwvutsrqponmlkjihgfedcba";
    int sizeS1 = strlen(S1);
    int sizeS2 = strlen(S2);
    int i;
    for( i=0; i < sizeS1; i++){
        if(i < sizeS2){
            S1[i] = S2[i];
        }
    }
    for (i = 0; i < sizeS1; i++)printf("%c", S1[i]);
    printf("\n");
}
//2
void WriteDownTheNumbers() {
    int number =123;
  //  scanf("%i", number);
    char *digit[10]= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while( number != 0){
        int dig = number%10;
        printf("%s ", digit[dig]);
        number = number/10;
    }
}
//3
int CountZero(long number){
  int count0=0;
  while(number > 0){

      if(!(number & 1)){
          count0 = count0 +1;
      }

      number = number >> 1;
  }
  return count0;
}
//5 and 6
void Bill(){
    float sum=0;
    char c;
    FILE *file;
    file = fopen("../settlement.txt", "r");
    if(file == NULL){
        printf("Error");
        exit(EXIT_FAILURE);
    }

   else{
       float price;
       do {
           fscanf(file, "%c", &c);
           if (c == ' ') {
               fscanf(file, "%f", &price);
               sum += price;
           }
       }while(!feof(file));

        fclose(file);
        file = fopen("bills.txt", "w");
        fprintf(file, "%f", sum);
        fclose(file);
   }

}
//7
void Statistics(){
    FILE *file;
    int min= INT_MAX, max= INT_MIN, ave=0;
    int length=0, total=0, word=0;
    char c;
    file = fopen("../input.txt", "r");
    if(file == NULL){
        printf("Error");
        exit(EXIT_FAILURE);
    }
    else{
        do{
            fscanf(file, "%c", &c);
            if( c == ' ' || feof(file)){
                if(length < min){
                    min = length;
                }
                else if(length > max){
                    max = length;
                }
                word++;
                length=0;
            }
            length++;
            total++;
        }while(!feof(file));
        fclose(file);
        file = fopen("statistics.dat", "w");
        fprintf(file, "Words %d\n", word);
        fprintf(file, "Medium len: %d\n", total/word);
        fprintf(file, "Min len: %d\n",min);
        fprintf(file, "Max len: %d\n",max);
        fclose(file);
    }
}
//11
void RandomNumber(){
    int size = 3;

    int* p= calloc(10, sizeof (int));
    int i,j,k;
    for(i = 0; i < 10; i ++){
        *(p+i) = rand() % 10;
    }
    size = 10;
    for(i=0; i < size; i ++){
        printf("%i", *(p+i));

    }
    printf("\n");
    for(i=0; i < size; i++){
        for(j=i+1; j < size; j++){
            if(*(p+i) == *(p+j)){
                for(k=j; k < size-1; k++){
                    *(p+k) = *(p+k+1);
                }
                size --;
                j--;
            }
        }
    }

    for(i=0; i < size; i ++){
        printf("%i", *(p+i));

    }
    free(p);
}
//12
void StandardDeviation(){
    int r = 10, c = 4, i ,j, k;

    int** arr = (int**)malloc(r*sizeof(int*));
    for(i=0; i < r;i++)
        *(arr+i)= (int*)malloc(c*sizeof(int));

    for(i=0; i < r; i++) {
        for (j = 0; j < c; j++)
            *(*(arr + i) + j) = rand() % 10;
    }
   for(i=0; i < r; i++) {
        for (j = 0; j < c; j++)
            for(k=(j+1); k < c; k++) {
                if (*(*(arr + i) + j) > *(*(arr + i) + k)) {
                    int swap = *(*(arr + i) + j);
                    *(*(arr + i) + j) = *(*(arr + i) + k);
                    *(*(arr + i) + k) = swap;
                }
            }
    }
   //standard deviation for each row
   double* SD = (double*) malloc(r*sizeof(double));
   for(i =0; i < r; i++){

       //average
       double sum=0;
       for(j=0; j < c; j++){
           sum += *(*(arr+i)+j);
       }
       double ave = sum /  r;

       for(j=0; j < c; j++)
           sum += pow(*(*(arr+i)+j) - ave, 2);

       *(SD+i) = sqrt(sum/c);
   }
   //sorting first elements
   for(i=0; i < r; i++){
       for(j=i+1; j < r; j++){
           if(*(SD+i) < *(SD+j)){
               double tD = *(SD+i);
               *(SD+i) = *(SD+j);
               *(SD+j) = tD;
               int* swap = *(arr + i);
               *(arr + i) = *(arr + j);
               *(arr + j) = swap;
           }
       }
   }
    for(i=0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%i", *(*(arr + i) + j));
        }
        printf("\n");
    }

    free(SD);
    for(i=0; i < r; i ++){
        free(*(arr+i));
    }
    free(arr);
}
int main(int argc, char *argv[]) {
   /* ReverseString();
    FindLetter();
    WriteDownTheNumbers(); */
 //   printf("%i", CountZero(2345643432));
  //  Bill();
 //   Statistics();
 //   printf("here1");
  //  RandomNumber();
  StandardDeviation();
    return 0;
}
