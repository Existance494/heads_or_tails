#include "heads_or_tails.h"

#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h> // Sleep(n) will make program sleep for n milliseconds

#ifndef STDIO_H
#include <stdio.h>
#endif

enum coins {
    heads = 1,
    tails
};

void normal_mode(FILE *fp) {
    printf("___________________________________________________________________________________________\n");
    printf(" _   _                            _   __  __           _      \n");
    printf("| \\ | | ___  _ __ _ __ ___   __ _| | |  \\/  | ___   __| | ___ \n");
    printf("|  \\| |/ _ \\| '__| '_ ` _ \\ / _` | | | |\\/| |/ _ \\ / _` |/ _ \\ \n");
    printf("| |\\  | (_) | |  | | | | | | (_| | | | |  | | (_) | (_| |  __/\n");
    printf("|_| \\_|\\___/|_|  |_| |_| |_|\\__,_|_| |_|  |_|\\___/ \\__,_|\\___|\n");
    printf("___________________________________________________________________________________________\n");
    int score = 0;
    int highscore = 0;
    if (fp == NULL) {
        highscore = 0;
    }
    if (fp != NULL) {
        fscanf(fp, "Highscore: %d", &highscore);
        printf("\nGood luck!\n");
    }
    srand(time(NULL));
    while(1) {
        int value = rand() % (2 - 1 + 1) + 1;
        printf("What side will the coin land on? (Heads or Tails)\n");
        char guess[6];
        scanf("%s", guess);
        for (int i = 0; guess[i] != '\0'; i++) {
            guess[i] = tolower(guess[i]);
        }
        if (value == heads) {
            if ((strcmp(guess, "heads") == 0) || (strcmp(guess, "head") == 0) || (strcmp(guess, "h") == 0)) {
                score++;
                printf("Correct! You have now guessed ");
                printf("%d", score);
                printf(" coin flips in a row correctly!\n");
            }
            else {
                printf("Incorrect! You got ");
                printf("%d", score);
                printf(" guesses correct in a row, try again next time\n");
                break;
            }
        }
        else {
            if ((strcmp(guess, "tails") == 0) || (strcmp(guess, "tail") == 0) || (strcmp(guess, "t") == 0)) {
                score++;
                printf("Correct! You have now guessed ");
                printf("%d", score);
                printf(" coin flips in a row correctly!\n");
            }
            else {
                printf("Incorrect! You got ");
                printf("%d", score);
                printf(" guesses correct in a row, try again next time\n");
                break;
            }
        }
    }
    if (score > highscore) {
        highscore = score;
        printf("You achieved a new highscore of ");
        printf("%d", score);
        printf(" consecutive correct guesses!\n");
        FILE *fp2 = fopen("highscore.txt", "w");
        fprintf(fp2, "Highscore: ");
        fprintf(fp2, "%d\n", highscore);
        fprintf(fp2, "\n");
        if (fp2 != NULL) {
            fclose(fp2);
        }
        fp2 = NULL;
    }
    else if (score == highscore) {
        printf("You tied your highscore of ");
        printf("%d", score);
        printf(" consecutive correct guesses!\n");
    }
    else if (score < highscore) {
        printf("You couldn't beat your highscore of ");
        printf("%d", highscore);
        printf(" consecutive correct guesses...\n");
        printf("You were ");
        printf("%d", (highscore - score));
        printf(" guesses off\n");
        printf("Better luck next time!\n");
    }
    printf("Press any key to move on\n");
    _getch();
}

void ten_guess(FILE *fp) {
    printf("___________________________________________________________________________________________\n");
    printf(" _  ___     ____                       __  __           _      \n");
    printf("/ |/ _ \\   / ___|_   _  ___  ___ ___  |  \\/  | ___   __| | ___ \n");
    printf("| | | | | | |  _| | | |/ _ \\/ __/ __| | |\\/| |/ _ \\ / _` |/ _ \\ \n");
    printf("| | |_| | | |_| | |_| |  __/\\__ \\__ \\ | |  | | (_) | (_| |  __/\n");
    printf("|_|\\___/   \\____|\\__,_|\\___||___/___/ |_|  |_|\\___/ \\__,_|\\___|\n");
    printf("___________________________________________________________________________________________\n");
    printf("10 guess mode\n");
    int num_correct;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int value = rand() % (2 - 1 + 1) + 1;
        printf("%d. What side will the coin land on? (Heads or Tails)\n", i+1);
        char guess[6];
        scanf("%s", guess);
        for (int i = 0; guess[i] != '\0'; i++) {
            guess[i] = tolower(guess[i]);
        }
        if (value == heads) {
            if ((strcmp(guess, "heads") == 0) || (strcmp(guess, "head") == 0) || (strcmp(guess, "h") == 0)) {
                num_correct++;
                printf("Correct! You have now guessed ");
                printf("%d", num_correct);
                printf(" coin flips correctly!\n");
            }
            else {
                printf("Incorrect!\n");
            }
        }
        else {
            if ((strcmp(guess, "tails") == 0) || (strcmp(guess, "tail") == 0) || (strcmp(guess, "t") == 0)) {
                num_correct++;
                printf("Correct! You have now guessed ");
                printf("%d", num_correct);
                printf(" coin flips correctly!\n");
            }
            else {
                printf("Incorrect!\n");
            }
        }
    }
    printf("You have guessed ");
    printf("%d", num_correct);
    printf(" coin flips correctly!\n");
    printf("That is a ");
    float rate = (num_correct / 10.0) * 100;
    printf("%d%% success rate!\n", (int)rate );
    printf("Press any key to move on\n");
    _getch();
}

void custom_guess(FILE *fp) {
    printf("___________________________________________________________________________________________\n");
    printf("  ____          _                    __  __           _      \n");
    printf(" / ___|   _ ___| |_ ___  _ __ ___   |  \\/  | ___   __| | ___ \n");
    printf("| |  | | | / __| __/ _ \\| '_ ` _ \\  | |\\/| |/ _ \\ / _` |/ _ \\ \n");
    printf("| |__| |_| \\__ \\ || (_) | | | | | | | |  | | (_) | (_| |  __/\n");
    printf(" \\____\\__,_|___/\\__\\___/|_| |_| |_| |_|  |_|\\___/ \\__,_|\\___|\n");
    printf("___________________________________________________________________________________________\n");
    printf("Welcome to Custom Length Guess Mode\n");
    printf("How many rounds would you like to guess?\n");
    int num_correct;
    int length = 0;
    scanf("%d", &length);
    while (length <= 0) {
        if (scanf("%d", &length) == 1 && length > 0) {
            int i;
            break;
        }
        int i;
        while ((i = getchar()) != '\n' && i != EOF); // clears buffer
        length = 0;
        printf("Please choose a positive integer\n");
    }
    int i;
    while ((i = getchar()) != '\n' && i != EOF); // clears buffer
    srand(time(NULL));
    for (int i = 0; i < (int)length; i++) {
        int value = rand() % (2 - 1 + 1) + 1;
        printf("%d. What side will the coin land on? (Heads or Tails)\n", i+1);
        char guess[6];
        scanf("%s", guess);
        for (int i = 0; guess[i] != '\0'; i++) {
            guess[i] = tolower(guess[i]);
        }
        if (value == heads) {
            if ((strcmp(guess, "heads") == 0) || (strcmp(guess, "head") == 0) || (strcmp(guess, "h") == 0)) {
                num_correct++;
                printf("Correct! You have now guessed ");
                printf("%d", num_correct);
                printf(" coin flips correctly!\n");
            }
            else {
                printf("Incorrect!\n");
            }
        }
        else {
            if ((strcmp(guess, "tails") == 0) || (strcmp(guess, "tail") == 0) || (strcmp(guess, "t") == 0)) {
                num_correct++;
                printf("Correct! You have now guessed ");
                printf("%d", num_correct);
                printf(" coin flips correctly!\n");
            }
            else {
                printf("Incorrect!\n");
            }
        }
    }
    printf("You have guessed ");
    printf("%d", num_correct);
    printf(" coin flips correctly!\n");
    printf("That is a ");
    float rate = (num_correct / (float)length) * 100;
    printf("%.2f%% success rate!\n", rate );
    printf("Press any key to move on\n");
    _getch();
}

void check_highscores(FILE *fp) {
    printf("___________________________________________________________________________________________\n");
    printf(" _   _ _       _                            \n");
    printf("| | | (_) __ _| |__  ___  ___ ___  _ __ ___ \n");
    printf("| |_| | |/ _` | '_ \\/ __|/ __/ _ \\| '__/ _ \\ \n");
    printf("|  _  | | (_| | | | \\__ \\ (_| (_) | | |  __/\n");
    printf("|_| |_|_|\\__, |_| |_|___/\\___\\___/|_|  \\___|\n");
    printf("         |___/                              \n");
    printf("___________________________________________________________________________________________\n");
    int highscore = 0;
    if (fp == NULL) {
        highscore = 0;
    }
    if (fp != NULL) {
        fscanf(fp, "Highscore: %d", &highscore);
        printf("Your current normal mode highscore is ");
        printf("%d", highscore);
        printf("\nGood luck!\n");
    }
    printf("Press any key to move on\n");
    _getch();
}

void instructions(FILE *fp) {
    printf("___________________________________________________________________________________________\n");
    printf(" _   _                 _                _             \n");
    printf("| | | | _____      __ | |_ ___    _ __ | | __ _ _   _ \n");
    printf("| |_| |/ _ \\ \\ /\\ / / | __/ _ \\  | '_ \\| |/ _` | | | |\n");
    printf("|  _  | (_) \\ V  V /  | || (_) | | |_) | | (_| | |_| |\n");
    printf("|_| |_|\\___/ \\_/\\_/    \\__\\___/  | .__/|_|\\__,_|\\__, |\n");
    printf("                                 |_|            |___/ \n");
    printf("___________________________________________________________________________________________\n");
    printf("Welcome to the heads/tails game!\n");
    printf("The game is pretty simple, you have to predict which side a coin is going to land on\n");
    printf("Press any key to move on\n");
    _getch();
}

void main_menu(FILE *fp) {
    while(1) {
        printf("___________________________________________________________________________________________\n");
        printf(" __  __       _         __  __                  \n");
        printf("|  \\/  | __ _(_)_ __   |  \\/  | ___ _ __  _   _ \n");
        printf("| |\\/| |/ _` | | '_ \\  | |\\/| |/ _ \\ '_ \\| | | |\n");
        printf("| |  | | (_| | | | | | | |  | |  __/ | | | |_| |\n");
        printf("|_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|\n");
        printf("___________________________________________________________________________________________\n");
        printf("\n");
        printf("1. Normal Mode\n");
        printf("2. 10 Guess Challenge\n");
        printf("3. Custom Length Guess challenge\n");
        printf("4. Check Highscore\n");
        printf("5. How to play\n");
        printf("6. Exit Game\n");
        printf("\n");
        printf("Choose a game mode (Type a number 1-6 to choose):\n");
        char selection[2];
        scanf("%s", selection);
        if ((strcmp(selection, "1") == 0)) {
            normal_mode(fp);
        }
        else if ((strcmp(selection, "2") == 0)) {
            ten_guess(fp);
        }
        else if ((strcmp(selection, "3") == 0)) {
            custom_guess(fp);
        }
        else if ((strcmp(selection, "4") == 0)) {
            check_highscores(fp);
        }
        else if ((strcmp(selection, "5") == 0)) {
            instructions(fp);
        }
        else if ((strcmp(selection, "6") == 0)) {
            printf("Thanks for playing!\n");
            if (fp != NULL) {
                fclose(fp);
            }
            fp = NULL;
            exit(0);
        }
        else {
            printf("That is not a valid number from 1-6, please try again\n");
            continue;
        }
    }
    if (fp != NULL) {
        fclose(fp);
    }
    fp = NULL;
}

int main() {
    int score = 0;
    int highscore = 0;
    FILE *fp = fopen("highscore.txt", "r");
    instructions(fp);
    while(1) {
        main_menu(fp);
    }
    return 0;
}