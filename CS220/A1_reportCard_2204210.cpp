#include <stdio.h>
int main()
{
    /*
    Name: Atharva Keny
    Roll No: 2204210
    Date: 29th July, 2023.
    Purpose: To print a report card of a student based on input of name, roll number, and subject marks.
    */

    // defining a character variable name[] to store name
    char name[] = "Atharva Keny";
    // defining an integer variable roll_number to store roll number
    int roll_number = 2204210;
    // defining an integer variable maths_marks to store marks in maths
    int maths_marks = 90;
    //  defining an integer variable science_marks to store marks in science
    int science_marks = 85;
    //  defining an integer variable history_marks to store marks in history
    int history_marks = 80;
    // defining an integer variable geography_marks to store marks in geography
    int geography_marks = 75;
    // defining an integer variable avefage_marks to store average marks of the four subjects
    // formula for average = sum of all elements / number of elements
    float average_marks = (float)(maths_marks + science_marks + history_marks + geography_marks) / 4.0;

    // print all the given data in the format: Name, Roll Number, All marks, Average marks
    printf("Name: %s\n", name);
    printf("Roll Number: %d\n", roll_number);
    printf("Marks in Maths: %d\n", maths_marks);
    printf("Marks in Science: %d\n", science_marks);
    printf("Marks in History: %d\n", history_marks);
    printf("Marks in Geography: %d\n", geography_marks);
    printf("Average Marks: %f\n", average_marks);
}