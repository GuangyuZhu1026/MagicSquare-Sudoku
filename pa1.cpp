//
//  main.cpp
//  MagicSquare
//
//  Created by Guangyu Zhu on 9/16/16.
//  Copyright © 2016 Guangyu Zhu. All rights reserved.
//

#include <iostream>
#include "pa1.h"
int main ()
{
    int n(0),i,j;
    int array[100][100]={0};
    int array2[100][100]={0};
    int array3[100][100]={0};
    
    //check if the number n that entered is an odd number between 3-15
    std::cout<<"Enter the size of magic square: ";
    std::cin>>n;
    std::cout<<std::endl;
    // call checkInput() to get the valid number n
    n=checkInput(n);
    
    //creating magic square
    int row=0,col=(n-1)/2;
    array[row][col]=1; //putting 1 in the middle of the first row
    for(i=2;i<=n*n;i++)//i is the actual number that is put in to the spot
    {
        //vertically fold it to find the upper right spot
        if((row-1)<0 && (col+1)<n)
        {
            if(array[n-1][col+1]==0)//check if the upper right is empty 0
            {
                //go to the uppper rigth spot
                row=n-1;
                col=col+1;
            }
            else
            {
                row=row+1;//if the upper rigth spot is taken, go down 1 row, and col does not change
            }
        }
        //once the upper rigth is out of n*n
        //horizontally fold it to find out the upper rigth spot
        else if((row-1)>=0 && (col+1)>=n)
        {
            if(array[row-1][0]==0)//make sure the upper right is empty
            {
                row=row-1;
                col=0;
            }
            else
            {
                row=row+1;//if the upper rigth spot is taken, go down 1 row, and col does not change
            }
        }
        //find the upper right spot when it is in n*n matrix region
        else if((row-1)>=0 && (col+1)<n)
        {
            if(array[row-1][col+1]==0)
            {
                row=row-1;
                col=col+1;
            }
            else
            {
                row=row+1;
            }
        }
        else
        {
            row=row+1;
        }
        array[row][col]=i;
    }
//print out the first magic square
    std::cout<<"Magic Square #1 is: \n\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            std::cout<<array[i][j]<< "\t";
        }
    std::cout<<"\n";
    }
    std::cout<<"\n";

    //call checkSums()
    checkSums(array, n);
    
//hprizontally flip magic square#1,and storing it in array array2[][].
    for(j=0; j<n; j++)
        for(i=0; i<n; i++)
        {
            array2[n-1-i][j]=array[i][j];
        }
    
    //Displaying array2[][]
    std::cout << "Magic Square #2 is: \n\n";
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
        {
            std::cout<< array2[i][j]<<"\t";
            if(j==n-1)
                std::cout << "\n";
        }
    std::cout<<"\n";
    
    //call checkSums()
    checkSums(array2, n);
    
//vertically flip magic square#2, and store it into new array3[][]
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            array3[i][n-1-j]=array2[i][j];
        }
    
    // Displaying new array3[][]
    std::cout << "Magic Square #3 is: \n\n";
    for(i=0; i<n; ++i)
        for(j=0; j<n; ++j)
        {
            std::cout<< array3[i][j]<<"\t";
            if(j==n-1)
                std::cout << "\n";
        }
    std::cout<<"\n";
    
    //call checkSums()
    checkSums(array3, n);
    
}

int checkInput(int n){
    while (n%2==0 || n<3 || n>15){
        std::cout<<"Error, please enter an odd number between 3 to 15: ";
        std::cin>>n;
        std::cout<<"\n";
    }
    return n;
}

void checkSums(int array[100][100], int n){
    int i, j;
    //check the sum of the rows
    std::cout<<"Checking the sum of every row: \t\t";
    for(i=0;i<n;i++)
    {
        int sumRow=0;
        for(int j=0;j<n;j++)
        {
            sumRow += array[i][j];
        }
        std::cout<<sumRow<<"\t";
    }
    std::cout<<"\n";
    
    //check the sum of columns
    std::cout<<"Checking the sum of every column: \t";
    for(j=0;j<n;j++)
    {
        int sumCol=0;
        for(i=0;i<n;i++)
        {
            sumCol += array[i][j];
        }
        std::cout<<sumCol<<"\t";
    }
    std::cout<<"\n";
    
    //check the sum of the two diagonals
    std::cout<<"Checking the sum of every diagonal:\t";
    int sumDiaLeftToRight=0;
    int sumDiaRightToLeft=0;
    for(i=0;i<n;i++)
    {
        sumDiaLeftToRight += array[i][i];
    }
    for(i=n;i>=0;i--){
        sumDiaRightToLeft += array[i][i];
    }
    std::cout<<sumDiaLeftToRight<<"\t"<<sumDiaRightToLeft;
    std::cout<<"\n\n";
    
}
