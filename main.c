#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#define max_length 100

char pc_turn()
{
    char pc_choice[] = {'r', 'p', 's'};
    srand(time(NULL));
    int index = rand() % 3;
    char choice = pc_choice[index];
    return choice;
}

int main()
{

    char user_name[max_length];

    static int score_user = 0;
    static int score_pc = 0;
    char user_choice[max_length];
    printf("<<<<<<<<<< WELCOME TO ROCK PAPER SCISSOR >>>>>>>>>>>>>\n");
    printf("Enter Your Name ");
    fgets(user_name, max_length, stdin);

    while (score_pc < 5 && score_user < 5)
    {
        char pc_choice = pc_turn();
        int len = strlen(user_name);
        if (user_name[len - 1] == '\n')
        {
            user_name[len - 1] = '\0';
        }
        system("cls");
        printf("\n ROck - R\n Paper - P\n Scissor - s\n\n");
        printf("User Scores- %d || Computer Scores- %d\n\n", score_user, score_pc);
        printf("%s's turn: ", user_name);
        fgets(user_choice, max_length, stdin);
        printf("\n");

        if (pc_choice == user_choice[0])
        {
            printf("-----BOTH HAVE SELECTED SAME WEAPONS----- <;");
            Sleep(2000);
        }

        else if ((pc_choice == 'r' && user_choice[0] == 'p') || (pc_choice == 'p' && user_choice[0] == 's') || (pc_choice == 's' && user_choice[0] == 'r'))
        {
            printf("User Scores");
            score_user++;
            Sleep(1000);
        }

        else if ((pc_choice == 'r' && user_choice[0] == 's') || (pc_choice == 'p' && user_choice[0] == 'r') || (pc_choice == 's' && user_choice[0] == 'p'))
        {
            printf("Computer Scores");
            score_pc++;
            Sleep(1000);
        }

        else if (score_pc == 5 || score_user == 5)
        {
            break;
        }

        else
        {
            printf("Some Problem");
        }
    }

    if (score_pc == 5)
    {
        system("cls");
        printf("\nUser Score- %d || Computer Scores- %d\n\n", score_user, score_pc);
        printf("............. Computer!  Wins......");
    }
    else if (score_user == 5)
    {
        system("cls");
        printf("\nUser Scores- %d || Computer Scores- %d\n\n", score_user, score_pc);
        printf("...............Hurray! %s Wins..........", user_name);
    }

    printf("\n\n...............GAME ENDS\nTHANKYOU FOR PLAYING- By Ayush");
    getchar();

    return 0;
}
