#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 100

int board[BOARD_SIZE];
int playerPos[2] = {0, 0};
char playerNames[2][20];

void initializeBoard()
{
    // Initialize board with ladders (you can change value to anything)
    board[1] = 37;
    board[4] = 10;
    board[9] = 22;
    board[21] = 21;
    board[28] = 56;
    board[51] = 16;
    board[71] = 20;
    board[80] = 20;

    // Initialize board with snakes (you can change value to anything)
    board[17] = -10;
    board[54] = -20;
    board[62] = -43;
    board[64] = -4;
    board[87] = -51;
    board[93] = -20;
    board[95] = -20;
    board[98] = -19;
}

void drawBoard()
{
    system("cls");
    printf("Snakes and Ladders Game\n\n");
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        if (i == playerPos[0]) {
            printf(" P1 ");
        } else if (i == playerPos[1]) {
            printf(" P2 ");
        } else if (board[i] != 0) {
            if (board[i] > 0) {
                printf(" L  ");
            } else {
                printf(" S  ");
            }
        } else {
            printf("  %i  ");
        }
        if (i % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int rollDice()
{
    return rand() % 6 + 1;
}

int main(void)
{
    srand(time(0));
    initializeBoard();

    for (int i = 0; i < 2; i++)
    {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", playerNames[i]);
    }

    int currentPlayer = 0;
    while (1)
    {
        drawBoard();
        printf("%s is currently at position %d\n", playerNames[currentPlayer], playerPos[currentPlayer]);
        printf("\nPress enter to roll the dice...");
        printf("\n\nLadders: 1 - 38, 4 - 14, 9 - 31, 21 - 42, 28 - 84, 51 - 67, 71 - 91, 80 - 100  ");
        printf("\n\nSnakes: 17 - 10, 54 - 34, 62 - 19, 64 - 60, 87 - 36, 93 - 73, 95 - 75, 98 - 79 ");
        int diceRoll = rollDice();
        printf("\n\n%s rolled a %d", playerNames[currentPlayer], diceRoll);
        playerPos[currentPlayer] += diceRoll;
        if (playerPos[currentPlayer] >= BOARD_SIZE)
        {
            printf("Congratulations %s, you won!\n", playerNames[currentPlayer]);
            break;
        } else if (board[playerPos[currentPlayer]] != 0)
        {
            int newPos = playerPos[currentPlayer] + board[playerPos[currentPlayer]];
            printf("\n%s landed on a %c, moving from %d to %d", playerNames[currentPlayer], (board[playerPos[currentPlayer]] > 0 ? 'L' : 'S'), playerPos[currentPlayer], newPos);
            playerPos[currentPlayer] = newPos;
            if (playerPos[currentPlayer] < 0)
            {
            playerPos[currentPlayer] = 0;
            }

        }
           currentPlayer = (currentPlayer + 1) % 2;
           getchar();
        }
        return 0;
        }

