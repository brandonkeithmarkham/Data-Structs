//  Brandon Markham uzy7@txstate.edu
//  Serial # : 24
//  Due Date : Monday 9/5/22
//  Programming Assignment Number 1
//  Fall 2022 - CS 3358 - 001
//  Instructor: Husain Gholoom
//  This Program Demonstrates Proficiency in Passing Arrays to Functions
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include <iostream>
#include <iomanip>
#include<cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void displayArrayFunctions();
//Populates Array
void populateArrays(int array1[][3],int array2[][3]);
//Displays Array
void display (int array[][3]);
//Adds Arrays
void addArrays(int array_1[][3],int array_2[][3],int array_3[][3]);
//Multiplys Arrays
void multiplyArrays(int array_1[][3],int array_2[][3],int array_3[][3]);
//Transoposes Arrays
void transposeArray(int array[][3], int transposeArray[][3]);
//Calculates determinant of 2d array.
int determinant(int array[][3]);
//Totals sum of rows
void sumOfRows(int array1[][3]);
//Totals sum of columns
void sumOfColumns(int array1[][3]);
//Totals sum of diagonals
void sumOfDiagonals(int array1[][3]);
//Computes special number
int specialNumber(int row, int col);
//Determines if array is special
int isSpecialArray(int array1[][3],int snum);



int main() {
    char choice = 'Y';
    
    //Displays program introduction
    cout << "Welcome to my Array program. The function of the"
         << " program is to :"<<endl<<endl<<endl
         << "1. Create an 2 Arrays (Array_1,Array_2). Each "
         << "Array is of size 3x3."<<endl
         << "2. Populate both Arrays with distinct random numbers "
         << "that are betweein 1 and 12.\n   Display both Arrays."
         << "\n3. Adding and multiplying Array_1 and Array_2.\n"
         << "4. Displaying the transposed and the determinate of"
         << " Array_1.\n5. Displaying the sum of elements of each"
         << " row of Array_1, displaying the sum of \n   elements "
         << " of each column of Array_1, displaying the sum of "
         << "both diagonal elemnents of \n   Array_1.\n"
         << "6. Finally, determining whether or not Array_1"
         << " is special array.\n\n"
         << "7. Repeating the above steps until the user terminates"
         << " the program.\n\n\n";
    
    //Conditional statements that validate user input.
    while(choice == 'Y'||choice == 'y'){ displayArrayFunctions();
   
    cout << "\n";
    cout<<"Would like to check another Array - Enter Y/y for yes or N/n for no\n\n";
    
    //user input
    cin>> choice;
        while(choice != 'Y' && choice!='y' && choice!='N' && choice!='n'){
            
            cin.clear();
            cout << "Error enter valid input. Enter Y/y or N/n \n";
           
            cin>>choice;
        }
        if(choice == 'n' ||choice == 'N')
            break;
    }
    cout << "\n\nThis program was implemented by Brandon Markham on September, 2nd 2022\n";
    //Terminates program
    return 0;
}

//*****************************************************************
// This function takes 2d array of elements, initialies a 1d array
// and populates it with numbers from 1-12 then shuffles the array
// using a Fisher - Yates shuffle algorithm, then populates the
// 2d array with the shuffled 1d array containing numbers 1-12.
//
// param-1-array[][3] the array to be populated with the shuffled
// array.
//
// Function is of type void and has no returns.
//*******************************************************************
void Shuffle (int array[][3])
{
    int setOfElements[12];
    int index = 0;
    
    //Populates array with digits 1-12
    for(int i =1; i<=12; i++)
    {
        setOfElements[i-1] = i;
    }
    //Swap For Random Values.
    for(int i = 11; i>0; i--)
    {
        int j = rand() % (i+1);
        swap(setOfElements[i],setOfElements[j]);
    }
    //Populate 2d array with 1d array.
    for(int i = 0; i<3; i++)
    
        for(int j = 0; j<3; j++)
        {
            array[i][j] = setOfElements[index++];
        }
        
}
//*****************************************************************
// This function that shuffles both arrays to make numbers.
// random.
//
// param-1-array1[][3] (array to be shuffled)
// param-2-array2[][3] (array to be shuffled)
//
// Function is of type void therfore there is no return.
//*******************************************************************
void populateArrays(int array1[][3], int array2[][3])
{
    Shuffle(array1);
    Shuffle(array2);
}
//*****************************************************************
// This function adds the elements of array 1 to array 2 and puts
// the values into 3rd array.
// param-1-array1
// param-2-array2
// param-3-array3 (array to contain the sums of  array1 and array 2)
//
// returns description of what function returns (if anything)
//*******************************************************************
void addArrays(int array1[][3], int array2[][3], int array3[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            array3[i][j] = array1[i][j]+array2[i][j];
        }
    }
}
//*****************************************************************
// This function uses matrix multiplication to multiply 2 2d arrays
//
// param-1-array1[][]
// param-2-array2[][]
// param-3-array3[][] (array to store product of array1 & array2)
//
// Function is of type void therefore there is no return type.
//*******************************************************************
void multiplyArrays(int array1[][3],int array2[][3], int array3[][3])
{
    for(int i=0; i<3; ++i)
        
        for(int j=0; j<3; ++j)
        {
            array3[i][j] = 0;
        }
    
        for(int i=0; i<3; ++i)
            for(int j=0; j<3; ++j)
                for(int k=0; k<3; ++k)
                {
                    array3[i][j]+=array1[i][k]*array2[k][j];
                }
   
}
//*****************************************************************
// This function displays the contents of an array
//
// param-1-array[][] Array to be displayed
//
// This function is of type void therfore there is no return type.
//*******************************************************************
void display(int array[][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << array[i][j]<<" ";
        }
        cout <<endl<<endl;
        
    }
    cout << endl;
}
//*****************************************************************
// This function takes the rows and columns of array 1 and transposes
// them and outputs the transposed values into another.
//
// param-1-array[][3] (array to be transposed)
// param-2-transposition[][] (array to hold transpostion)
//
// Function is of type void therefore there is no return type.
//*******************************************************************
void transposeArray(int array[][3], int transposition[][3])
{
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
      {
        transposition[j][i] = array[i][j];
      }
    
    cout << "Transpose of Array 1 \n\n\n";
    
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
      {
        cout <<transposition[i][j]<<" ";
          if (j == 3 - 1)
            cout<<"\n\n";
      }
}
//*******************************************************************
// This function takes array and runs computaion to find determinant.
//
// param-1-a[][] array to be computed.
//
// Returns integer that holds value of dertiminant.
//*******************************************************************
int determinant(int a[][3])
{
    int d1;
    int d2;
    int d3;
    int dfinal;
    
    d1 = (a[0][0]*((a[1][1]*a[2][2])-(a[1][2]*a[2][1])));
    d2 = (a[0][1]*((a[1][0]*a[2][2])-(a[1][2]*a[2][0])));
    d3 = (a[0][2]*((a[1][0]*a[1][2])-(a[1][1]*a[2][0])));
    dfinal = d1-d2+d3;
    
    return dfinal;
}
//*****************************************************************
// This funciton calculates the total sum of the rows in a 2d array
//
// param-1-array1
//
// Function is of type void therefore there is no return type.
//*******************************************************************
void sumOfRows (int array1[][3])
{
     
        int total = 0;
     
        cout << "\nFinding Sum of each row:\n\n";
     
        // finding the row sum
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                // Add the element
                total = total + array1[i][j];
            }
     
            // Displays the row total
            cout
                << "Sum of the row "
                << i << " = " << total
                << endl;
     
            
            total = 0;
        }
     
}
//*****************************************************************
// This function sums the columns of a 2d array.
//
// param-1-array1[][]
//
// Function is of type void therefore there is no return type.
//*******************************************************************
void sumOfColumns(int array1[][3])
{
    int total = 0;
     
        cout << "\nFinding Sum of each column:\n\n";
     
        // finding the column sum
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
     
                // Add the index
                total = total + array1[j][i];
            }
     
            // Displays the column sum
            cout
                << "Sum of the column "
                << i << " = " << total
                << endl;
     
            // Reset the total
            total = 0;
        }
    
}
//*****************************************************************
// This function computes & displays the sum of the diagonals of a
// 2d array.
//
// param-1-array1[][3] array to be summed.
//
//Function is of type void therefore there is no return type.
//*******************************************************************
void sumOfDiagonals(int array1[][3])
{
    {
        int diagonal_1 = 0, diagonal_2 = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
     
                // Calculates diagonal 1.
                if (i == j)
                    diagonal_1 += array1[i][j];
     
                // Calculates diagonal 2.
                if ((i + j) == (3 - 1))
                    diagonal_2 += array1[i][j];
            }
        }
     
        cout << "The sum of the fist diagonal of Array_1"
             <<setw(6)
             <<" = "
             << setw(4)
             << diagonal_1
             << endl;
        cout << "The sum of the second diagonal of Array_1"
             <<setw(4)
             <<" = "
             << setw(4)
             << diagonal_2
             << endl;
    }
}
//*****************************************************************
// This function takes the numbers of rows and columns and computes
// special number.
//
// param-1-row (holds value for number of rows)
// param-2-col (holds value for number of columns)
//
// Returns integer that holds value of the special number.
//*******************************************************************
int specialNumber(int row,int col)
{
    int snum;
    
    snum =  row *(pow(col,2) + 1 )  / 2;
    return snum;
}
//*****************************************************************
// This function takes the array and the special number and checks
// the special number against the sum of each row, column, and
// diagonal to see if the array is a special array.
//
// param-1-a[][3] (the array to be evaluated.)
// param-2-snum (holds value of special number)
//
// if the array is a special array the return is 0. If the array is
// not a special array the return is 1.
//*******************************************************************
int isSpecialArray(int a[][3],int snum) {


int total = 0;

// total row elements to determine if == to snum or not
    for (int i = 0; i < 3; ++i)
    {
        total =0;
        
        for (int j = 0; j < 3; ++j)
        {
            total = total + a[i][j];
        }

        if(total != snum)

        return 1;
    }

// total column elements to determine if == to snum or not
    for(int i=0; i<3; i++)
    {
        total = 0;
        
        for(int j=0; j<3; j++)
        {
            total = total + a[j][i];
        }
        
        if(total != snum)
            
        return 1;
    }
    total = 0;
// total for diagonal 1 for array
    for(int i=0; i<3; i++)
    {
        total = total + a[i][i];
    }

    if(total != snum)

    return 1;
// reset the total
    total = 0;
// total for diagonal 2 for array
    for(int i=2; i>=0; i--)
    {
        total = total+  a[i][i];
    }

    if(total != snum)

        return 1;
    
return 0;

}
//*****************************************************************
// This function is the function that displays and calls all the
// the other functions for array manipulations.
//
// Because this function only prints there are no parameters or
// returns.
//*******************************************************************
void displayArrayFunctions()
{
int row = 3;
int col = 3;

//Array Initialization

int array_1 [3][3];
int array_2 [3][3];
int array_3 [3][3];
int transposition[3][3];

//Seed Random from time.
srand(time(NULL));

// Call function to populate arrays with randomized digits.
populateArrays (array_1,array_2);
// Call function to add array1 to array2 and store
// respective sum in array3
addArrays(array_1,array_2,array_3);
cout << "Array 1  :\n\n\n";
display(array_1);
cout << "Array 2  : \n\n\n";
display(array_2);
cout << "Sum of Array 1 and Array 2  : \n\n\n";
display(array_3);
// Call function to multiply arrays
multiplyArrays(array_1, array_2, array_3);
cout<< "Product of Array 1 and Array 2 \n\n\n";
display(array_3);
// Call function to transpose array1
transposeArray(array_1,transposition);
// Calculate and display function
cout <<  "Determinate of Array 1 = "
     << determinant(array_1)
     << "\n\n";
// Sum rows of array1
sumOfRows(array_1);
cout << "\n\n";
// Sum Columns of array1
sumOfColumns(array_1);
cout << "\n\n";
// Sum and display diagonals of array1
sumOfDiagonals(array_1);
cout << "\n\n\n";
// Compute special number
cout << "The special number for Array 1 is: "
     << specialNumber(row, col);
cout << "\n\n\n";

// Declare variable for Boolean like conditional.
int specArray = isSpecialArray(array_1,specialNumber(row,col));
// Display result
if(specArray!=0){
    cout << "Array 1 is not a special array \n\n"<<endl;}
else
    cout<< "Array 1 is a special array \n\n";
    
}
