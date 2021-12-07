#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *n1, int *n2);
struct user{
    int id;
    char *userName[];
};

void testFun1(int n1);
void testFun2(int n1);
void testFun3(int n1);

int main(){

//pointer to variable
int var = 5;
int *ptrVar;
ptrVar = &var;

printf("We access the address of the variable var through the pointer");
printf("%p\n", ptrVar);
printf("We access the value of the variable var through the pointer");
printf("%d\n\n\n\n", *ptrVar);

//pointer and arrays
int arr[5]= {1, 2, 3, 4, 5};
int *ptrArr;
ptrArr = arr;
printf("We access the addresses and tha values of the array through the pointer");
for(int i=0; i<5; i++){
    printf("%p\n", ptrArr+i);
    printf("%d\n", *(ptrArr+i));
}
printf("\n\n\n\n");

//pointers and Fucntions

//example1
int num1 = 1, num2 = 2;
printf("num1 = %d\n", num1);
printf("num2 = %d\n", num2);
swap(&num1, &num2);
printf("num1 = %d\n", num1);
printf("num2 = %d\n", num2);

//example2

void (*funPointer[])(int) = {testFun1, testFun2, testFun3};
//we call the testFun1,2 ,3....
funPointer[0](num1);
funPointer[1](num1);
funPointer[2](num1);


// pointers and Structs
struct user *userPtr, user1;
userPtr = &user1;

printf("Enter user's id: ");
scanf(" %d", &userPtr->id);


printf("Enter user's name: ");
scanf(" %[^\n]%*c", &userPtr->userName);

printf("id: %d\n", userPtr->id);
printf("UserName: %s\n", userPtr->userName);

//Dynamic memory allocation of structs
// void *malloc(size_t size), Parameters: size of memory block in bites, Returns: Pointer to the allocated memory or NULL if the request fails

int *ptrNums;
ptrNums = malloc(10 * sizeof(*ptrNums));

for(int i=0; i<10; i++){
    *(ptrNums + i) = i;
    printf("Value of ptrNums[%d] using malloc is: %d\n", i, *(ptrNums+i));
}
printf("\n\n\n\n");
//Then we free the allocated memory
free(ptrNums);

//void *calloc(size_t nitems, size_t size), Parameters: nitems = Number of elements to be alocated, size = size of elements
// All bites are initialized to zero









}




void swap(int *n1, int *n2){

    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;

}

void testFun1(int n1){
    printf("You chose testFun1 with input %d\n", n1);
}
void testFun2(int n1){
    printf("You chose testFun2 with input %d\n", n1);
}
void testFun3(int n1){
    printf("You chose testFun3 with input %d\n", n1);
}