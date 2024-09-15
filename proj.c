#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "proj.h"





void drawHangman(int trials){
          switch(trials) {
        case 0:
            printf(" ______\n");
            printf(" |    |\n");
            printf(" |     \n");
            printf(" |     \n");
            printf(" |     \n");
            printf("_|_    \n\n");
            break;
        case 1:
            printf(" ______\n");
            printf(" |    |\n");
            printf(" |    O\n");
            printf(" |     \n");
            printf(" |     \n");
            printf("_|_    \n\n");
            break;
        case 2:
            printf(" ______\n");
            printf(" |    |\n");
            printf(" |    O\n");
            printf(" |   /|\\\n");
            printf(" |     \n");
            printf("_|_    \n\n");
            break;
        case 3:
            printf(" ______\n");
            printf(" |    |\n");
            printf(" |    O\n");
            printf(" |   /|\\\n");
            printf(" |   / \\\n");
            printf("_|_      \n\n");
            gameover=True;
            printf("Game Over! You are hanged!\n\n");
            break;
        default:
            printf("Invalid number of trials!\n");
    }
}


void DisplayWord(const char wordChar [], const bool gussedChar []){
    int charNum=strlen(wordChar);
    printf("Word : ");
    for(int i = 0 ; i < charNum ;i++){
        if(gussedChar[i]) {
            printf("%c",wordChar[i]);
        }
        else {
            printf("%c",'X');
        }
    }
    printf("\n\n");

}



