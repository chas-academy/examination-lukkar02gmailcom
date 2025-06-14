//Write your code in this file
#include <stdio.h>
#include <ctype.h>

int AreTestScoresValid(int studentTestScores[13])
{
    for (int i = 0; i < 13; i++)
    {
        if (studentTestScores[i] < 0 || studentTestScores[i] > 10)
        {
            return 0;
        }
    }
    return 1;
}

float GetAverage(int studentTestScores[13])
{
    int sum = 0;

    for (int i = 0; i < 13; i++)
    {
        sum += studentTestScores[i];
    }

    return sum / 13.0;
}

float GetAverageOfAverages(float studentAverages[5])
{
    float sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += studentAverages[i];
    }

    return sum / 5.0;
}

void ShowStudentNameWithHighestAverage(char studentNames[5][10], float studentAverages[5])
{
    char* name = studentNames[0];

    for (int i = 1; i < 5; i++)
    {
        if (studentAverages[i - 1] < studentAverages[i])
        {
            name = studentNames[i];
        }
    }

    printf("%s\n", name);
}

void ShowStudentNamesBelowAverage(char studentNames[5][10], float studentAverages[5], float averageOfAverages)
{
    for (int i = 0; i < 5; i++)
    {
        if (studentAverages[i] < averageOfAverages)
        {
            printf("%s\n", studentNames[i]);
        }
    }
}

int main()
{
    char studentNames[5][10];
    int studentTestScores[5][13];
    float studentAverages[5];

    for (int i = 0; i < 5; i++)
    {
        scanf("%s %d %d %d %d %d %d %d %d %d %d %d %d %d",
            &studentNames[i],
            &studentTestScores[i][0],
            &studentTestScores[i][1],
            &studentTestScores[i][2],
            &studentTestScores[i][3],
            &studentTestScores[i][4],
            &studentTestScores[i][5],
            &studentTestScores[i][6],
            &studentTestScores[i][7],
            &studentTestScores[i][8],
            &studentTestScores[i][9],
            &studentTestScores[i][10],
            &studentTestScores[i][11],
            &studentTestScores[i][12]);

        if (!AreTestScoresValid(studentTestScores[i]))
        {
            return 0;
        }

        studentNames[i][0] = toupper(studentNames[i][0]);
        studentAverages[i] = GetAverage(studentTestScores[i]);
    }

    ShowStudentNameWithHighestAverage(studentNames, studentAverages);

    float averageOfAverages = GetAverageOfAverages(studentAverages);
    ShowStudentNamesBelowAverage(studentNames, studentAverages, averageOfAverages);

    return 1;
}
