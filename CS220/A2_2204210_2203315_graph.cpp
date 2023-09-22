/* Nayan Garg - 2203315, Atharva Keny - 2204210    
Date: 08/08/2023 
Purpose: To create a graph which plots the points given as input by the user */
#include <stdio.h>
void plot(int, int, int); // Function to take in input x and y and by using recursion to keep taking subsequent inputs if the user wishes to continue
void input();
int main()
{
    int x, y, i;
    while (true)
    {
        printf("Enter the values of x, y:\t");
        scanf("%d %d", &x, &y); // To take in plot points as input from user
        printf("                    Y\n                   /|\\\n");
        for (i = 9; i >= -9; i--)
            plot(x, y, i);
        printf("                   \\|/\nDo you want to continue?");
        char decision;
        scanf(" %c", &decision); // Taking user decision to continue plotting or not
        if (decision != 'Y')
            break;
    }
}
void plot(int x, int y, int j) // To plot each line of the graph one by one
{
    int i;
    if (j == 0) // To plot the x-axis
    {
        printf("<");
        for (i = -19; i <= 19; i++)
        {
            if (i == x && x >= 0 && y == 0)
                printf(".(%d,%d)", x, y); // Plotting points on the non negative x-axis
            else if (x - 6 == i && x < 0 && y == 0)
                printf("(%d,%d).", x, y); // Plotting points on the negative x-axis
            else
                printf("-");
        }
        printf(">X\n");
    }
    else if (x > 0 && j == y) // To plot points in the first or fourth quadrant
    {
        printf("                    |");
        for (i = 1; i < x; i++)
            printf(" ");
        printf(".(%d,%d)\n", x, y);
    }
    else if (x < 0 && j == y) // To plot points in the second or third quadrant
    {
        if (y > 0)
            for (i = -20; i < x - 6; i++)
                printf(" "); // To plot point in the second quadrant
        else if (y < 0)
            for (i = -20; i < x - 7; i++)
                printf(" "); // To plot point in the third quadrant
        printf("(%d,%d).", x, y);
        for (i = x + 1; i < 0; i++)
            printf(" ");
        printf("|\n");
    }
    else // To plot a single line on y axis if points do not lie in any quadrant
    {
        if (j != y)
            printf("                    |\n");
        else if (j == y)
            printf("                    .(%d,%d)\n", x, y);
    }
}