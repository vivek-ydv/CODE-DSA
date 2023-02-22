  // Create Rock, Paper & Scissors Game.
// Player 1: rock.
// Player 2 (computer): scissors -->player 1 gets 1 point.

// rock vs scissors - rock wins.
// paper vs scissors - scissors wins.
// paper vs rock - paper wins.

// Write a C program to allow user to play this game three times with computer. Log the scores of computer and the player.
// Display the name of the winner at the end.
// Notes: You have to display name of the player during the game, Take users name as an input from the user.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int randgenrate()
{
    srand((time(NULL))); // To Genrate Random Number

    int rnum = rand() % 2; // To Store the number between 0 and limit(2).
    return rnum;
}

int main(int argc, char const *argv[])
{
    char pname[25];
    char pchar, cchar;
    int pchoice, cchoice;
    int pscore = 0, cscore = 0;

    char str[10] = {'r', 'p', 's'};

    printf("****WELCOME TO GAME****\nInput your name : ");
    scanf("%s", &pname);
    getchar();
    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        printf("Round:%d\n", i + 1);
        printf("Choose:\n1 for rock\n2 for paper\n3 for scissor\n\n");
        printf("%s turn:\n", pname);

        // Getting user input

        printf("Input your choice:");
        scanf("%d", &pchoice);
        getchar();
        pchar = str[pchoice - 1];
        printf("Your choice: %c\n", pchar);
        printf("\n");

        // Genrates Computer input

        printf("Computer turn:\n");
        int cchoice = randgenrate() + 1;
        printf("Computer input:%d\n", cchoice);
        cchar = str[cchoice - 1];
        printf("Computer choice: %c\n\n", cchar);

        // Calculating Scores

        if (pchar == cchar)
        {
            continue;
        }
        else if ((pchar == 'r') && (cchar == 's'))
        {
            pscore++;
        }
        else if ((pchar == 'r') && (cchar == 'p'))
        {
            cscore++;
        }
        else if ((pchar == 'p') && (cchar == 'r'))
        {
            pscore++;
        }
        else if ((pchar == 'p') && (cchar == 's'))
        {
            cscore++;
        }
        else if ((pchar == 's') && (cchar == 'r'))
        {
            cscore++;
        }
        else if ((pchar == 's') && (cchar == 'p'))
        {
            pscore++;
        }

        printf("%s score:%d \nCpu score:%d \n\n", pname, pscore, cscore);
    }

    // Showing result

    printf("\nThe final result is : ");
    if (pscore > cscore)
    {
        printf("Congratulations!! %s has win the game", pname);
    }
    else if (pscore == cscore)
    {
        printf("Draw");
    }
    else
    {
        printf("Oops!! Computer have won the game beter luck next time");
    }

    return 0;
}