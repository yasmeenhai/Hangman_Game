#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "proj.h"  





int main() {

        struct WordWithHint arr[] = {
            {"Madrid", "Capital of a country in Europe"},
            {"Spoon", "Something we use while eating"},
            {"University", "A place where we hate to go :((("},
            {"Youtube", "A website we use to watch videos"},
        {"Library", "A place where you can borrow books"},
        {"Oxygen", "A gas essential for breathing"},
        {"Giraffe", "An animal known for its long neck"},
        {"Pizza", "A popular Italian dish with cheese and toppings"},
        {"Elephant", "The largest land animal with big ears and a trunk"}
        };

        // Select some random word
        srand(time(NULL));
        // Generate a random index between 0 and (Numwords-1)
        int wordIndex = rand() % NumWords; //word index for this round
        struct WordWithHint word = arr[wordIndex];
        int lettersNum=strlen(word.Word);
        // Dynamically allocate memory for guessedChar
        bool* guessedchar = (bool*)malloc(lettersNum * sizeof(bool));
        // Initialize guessedchar to False (0)
        for (int i = 0; i < lettersNum; i++) {
            guessedchar[i] = False;
        }

        puts("HANGMAN GAME ^_^");
        printf("Hint : %s\n", word.Hint);
        //intialize variables to start the game
        int trials = 0;
        char wrong_entered_chars [5]={0};
        char entered_char;
        bool completed=False;
        gameover=False;

        bool not_out_of_guesses = True ;
        /* ============= Pseudo code ============= */

        while (not_out_of_guesses )
        {
            bool iscorrect = False;  //use to increment trials if the letter is not found in this trial
            bool repeated = False; //to handle not printing wrong guess for a repeated input

                //display current word statue
                DisplayWord(word.Word,guessedchar);

                // End the game if the word is guessed or game is over
               if (completed || trials >2 || gameover)  break;

                //draw current statue
                drawHangman(trials);


                //ask the user to guess a letter from the word
                puts("Guess a letter :");
                scanf(" %c", &entered_char);
                // Convert entered_char to lowercase for case-insensitive comparison
                 entered_char = tolower(entered_char);
            //Check for repeatition [If (S)he entered that letter before]
            for (int i = 0 ; i < trials ; i++)
            {
                if(entered_char==wrong_entered_chars[i])
                {
                puts("Repeated , Try again ") ;
                  repeated=True;
                    break;
                }

            }

        // check if the word contains the guessed character
            for (int i = 0 ; i < lettersNum ; i++)
            {
                if(tolower(word.Word[i])==entered_char) {
                    iscorrect=True ;
                    guessedchar[i]=True;
                    }
            }
               if(iscorrect)  puts("nice guess ");
               else if(! repeated){

                puts("Oops, wrong guess ");
                wrong_entered_chars[trials]=entered_char;
                trials++;

               }


                if (trials>3) not_out_of_guesses =False;

                //check if the word is completed
                if(!completed)
                {
                    int i ;
                    for(i = 0 ; i < lettersNum ; i++ ){
                        if(guessedchar[i]==False) break;
                    }
                    if (i == lettersNum){ //exit the for loop after looping on all the characters are found
                        completed=True;
                        puts("Yaaaaaaaayy , you guessed it right ");
                                    }
                }

        }
        free(guessedchar);
        return 0;

}
