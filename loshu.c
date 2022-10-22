/*
*   Myo Aung- Loshu Magic Square - CS 2600-System Programming
*   Two function requred to solve this problem
*   displaySquare() function which will display the the quare
*   checkIsLoshu() function checks if the square generated randomly by random numbers is a truely Loshi Magic Square.
*   
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displaySquare(int square[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
}

int checkIsLoshu(int square[3][3])
{
    int val = 0, temp = 0;                                  // Storing sum of first row in val, and comparing it with all the other values

    for (int i = 0; i < 3; i++)                             // Check First Row
    {
        val = val + square[0][i];
    }

    for (int i = 1; i < 3; i++)                             // Checking 2nd and 3rd row
    {
        temp = 0;
        for (int j = 0; j < 3; j++)
        {
            temp = temp + square[i][j];
        }
        if (temp != val)
        {
            return 0;
        }
    }

    for (int i = 0; i < 3; i++)                             // Checking all columns
    {
        temp = 0;
        for (int j = 0; j < 3; j++)
        {
            temp = temp + square[j][i];
        }
        if (temp != val)
        {
            return 0;
        }
    }

    temp = 0;                                               // Cheking diagonals
    for (int i = 0; i < 3; i++)
    {
        temp = temp + square[i][i];
    }
    if (temp != val)
    {
        return 0;
    }

    temp = square[0][2] + square[1][1] + square[2][0];
    if (temp != val)
    {
        return 0;
    }

    return 1;
}

int main(void)
{
    int square[3][3];
    int count = 0;                                          // Count of squares that are generated
    while (1)
    {
        count++;
        int used[10] = {0};
        srand(time(0) + count);                             // Changing seed , so that we get new values each time
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int n = rand() % 9 + 1;
                while (used[n])
                {
                    n = rand() % 9 + 1;
                }
                square[i][j] = n;
                used[n] = 1;
            }
        }

        /*
        printf("No. of squares generated : %d \n", count);  // Commented Out the display of all squares generated
        displaySquare(square);
        */
            
        if (checkIsLoshu(square) == 1)                     // Loop stops when the magic square is found.
        {
            break;
        }
    }

    printf("Number of squares generated : %d Squares.\n", count);
    displaySquare(square);                                    // Just printing the last Loshi-Magic-Square
    return EXIT_SUCCESS;
}