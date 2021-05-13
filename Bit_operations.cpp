#include <iostream>
#include <bitset>
#define SHOW(x); std::cout << " " << #x <<std::endl;

//recursive method to print binary representation of set
void display(unsigned short int s){
    if(s >1)
        display(s/2);
   std:: cout << s %2;
}
unsigned short int complement(unsigned short int set){
    return (~set);
}
unsigned short int Intersection(unsigned short  int setOne, unsigned short int setTwo){
    return (setOne & setTwo);
}
unsigned short int Sum(unsigned short int setOne, unsigned short int setTwo){
    return setOne | setTwo;
}
unsigned short int difference(unsigned short int setOne, unsigned short int setTwo){
    return Intersection(setOne, complement(setTwo));
}
unsigned short int SymmetricDifference(unsigned short int setOne, unsigned short int setTwo){
    return Sum(difference(setOne, setTwo), difference(setOne, setTwo));
}
bool containNthBitSet(int n, unsigned short int set){
    if(set & (1 << (n-1)))
        return true;
    else
        return false;
}

unsigned short int add(int n, unsigned short int set){

        if(!containNthBitSet(n, set))
               set |= (1 << (n-1));

        return set;
            
}
unsigned short int remove(unsigned short int n, unsigned short int set){
    if(containNthBitSet(n, set)){
        set &= ~(1 << (n-1));
    }
    return set;
}
unsigned short int cardinality(unsigned short int set){
    unsigned short int count  =0;
    while(set){
        count += set &1;
        set>>=1;
    }
    return count;
}
int main() {
    unsigned short int setOne = 45;
    unsigned short int setTwo = 44;
    display(setOne); SHOW(setOne);
    display(setTwo); SHOW(setTwo);
    unsigned short int compelementOfSetOne = complement(setOne);
    std:: cout <<  std::bitset<6> (compelementOfSetOne); SHOW(compelementOfSetOne);
    unsigned short int IntersectionOfSetOneAndTwo = Intersection(setOne, setTwo);
    std:: cout <<  std::bitset<6> (IntersectionOfSetOneAndTwo); SHOW(IntersectionOfSetOneAndTwo);
    unsigned short int sumOfTwoSets = Sum(setOne, setTwo);
    std:: cout <<  std::bitset<6> (sumOfTwoSets); SHOW(sumOfTwoSets);
    unsigned short int DifferenceOfTwoSets = difference(setOne, setTwo);
    std:: cout <<  std::bitset<6> (DifferenceOfTwoSets); SHOW(DifferenceOfTwoSets);
    unsigned short int SymmetricDifferenceOfTwoSets = SymmetricDifference(setOne, setTwo);
    std:: cout <<  std::bitset<6> (SymmetricDifferenceOfTwoSets); SHOW(SymmetricDifferenceOfTwoSets);
    containNthBitSet(5, setOne); //NO - correct answer
    containNthBitSet(3, setOne); // YES - correct answer
    unsigned short int AddBitToSet = add(2, setOne);
    display(AddBitToSet); SHOW(AddBitToSet);
    unsigned short int RemoveBit = remove( 1, setOne);
    display(RemoveBit); SHOW(RemoveBit);
    unsigned short int cardinalityOfset = cardinality(setOne);
    std::cout << cardinalityOfset << std::endl;
    return 0;
}
