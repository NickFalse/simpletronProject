#include <stdio.h>
#include <stdlib.h>
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43
int arr[100];
int accumulator = 0;
int instructionCounter = 0;
int instructionRegister = 0;
int operationCode = 0;
int operand = 0;

//intro() method prints out the introductory statements
void intro(){
printf("\n*** Welcome to Simpletron! ***\n*** Please enter your program one instruction ***\n*** (or data word) at a time. I will display ***\n*** the location number and a question mark (?) ***\n*** You then type the word for that location. ***\n*** Type -99999 to stop entering your program. ***\n\n");
}


//input() method reads in data from the user, and stores it in the arr array
void input(){
for(instructionCounter = 0; instructionCounter < 100; instructionCounter++){
printf("%02d ? ",instructionCounter);
scanf("%d", &arr[instructionCounter]);

if(arr[instructionCounter] == -99999){
break;
}

//checks for invalid numbers
if(arr[instructionCounter] < -9999 || arr[instructionCounter] > 9999){
printf("Invalid input, please input a number between -9999 and 9999\n");
instructionCounter -= 1;
}

}
printf("\n*** Program loading completed ***\n*** Program execution begins ***\n");
}


//Dump Method displays all of the data from the simpletron
void dump(){

//prints variables
printf("\n\n");
printf("REGISTERS:\n");
printf("accumulator:         %04d\n", accumulator);
printf("instructionCounter     %02d\n", instructionCounter);
printf("instructionRegister  %04d\n", instructionRegister);
printf("operationCode          %02d\n", operationCode);
printf("operand                %02d\n", operand);
printf("\n\n");


//Prints column numbers
printf("        0        1        2        3        4        5        6        7        8        9\n");

//This loops through the array, printing the 4-digit int at the index. This loop also does some formatting so that it looks nice.
for(int x = 0; x < 100; x++){

if(x == 0){
printf("\n %d", x);//making first row align properly
}

if(x % 10 == 0 && x != 0){//prints row numbers
printf("\n%d", x);
}

printf("   %04d  ",arr[x]);

}//end of for loop
printf("\n");
}//End of dump() method




//Main Method
int main(int argc, char *argv[]) {
intro();
input();
dump();
 }
