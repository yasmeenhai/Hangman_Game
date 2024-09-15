#ifndef PROJ_H
#define PROJ_H

typedef int bool;

#define True 1
#define False 0

#define NumWords 9

 bool gameover;

// Structure definition for WordWithHint
struct WordWithHint {
    char Word[15];
    char Hint[100];
};

// Function prototypes (declarations)
void drawHangman(int trials);
void DisplayWord(const char wordChar[], const bool guessedChar[]);

#endif
