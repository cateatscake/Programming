
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
main ()
{
    char word1[5] = {'m','u','s','i','c'};
    char word2[5] = {'k', 'i', 't', 't', 'y'};
    char word3[5] = {'p', 'h', 'o', 'n', 'e'};  //declare arrays
    char word4[5] = {'m', 'o', 'u', 's', 'e'};
    char word5[5] = {'b', 'o', 'x', 'e', 'r'};
    
    //gaming components
    int lives = 6;
    char letters_guessed[26];
    char guess;
    int i;
    int counter = 0;
    int word_length = 5;
    int spaces = 5;
    char word[5];
    char correct = 'n';
    char guessed_before = 'n';
    char playagain = 'y';
    int isdigit (int ch); //I found this function when I googled how to check if input is a number, I used it instead of an array consisting of every letter of the alphabet as was
                          //my original idea from the program design.
    
    printf("Hangman Game\n"); //Start up text
    printf("Begin game? (Y/N)\n");
    scanf(" %c", &playagain);
    
    do //program will run at least once and will determine whether they want to play again when it has finished running
    {
        lives = 6;                                          // These are all set back to original settings so that if user
        char word_displayed[5] = {'_', '_', '_', '_', '_'}; // chooses to play again the program will continue to print
        counter = 0;                                        // out _ for letters to be guessed. Lives are also reset to 6               
        spaces = 5;                                         // and spaces to 5 so that program will know there are letters to be guessed
        
        switch (playagain)
        {
            case 'Y': //if user chooses to play
            case 'y':
            {
                int rand_num = 1;
                srand (time(0));      //picks number at random
                rand_num = rand()%5+1;
            
                switch(rand_num)
                {
                    case 1: //if random number = 1 ie: first array (word1) is chosen as word to be guessed
                    {
                        for(i = 0; i < word_length; i++)
                        {
                            word[i]=word1[i]; //cycles through index of the array word[5] and copies index from word1[5] to it
                        }
                        break;
                    }
                
                    case 2:
                    {
                        for(i=0; i<word_length; i++)
                        {
                            word[i]=word2[i];
                        }
                        break;
                    }
                
                    case 3:
                    {
                        for(i=0; i<word_length; i++)
                        {
                            word[i]=word3[i];
                        }
                        break;
                    }
                
                    case 4:
                    {
                        for(i=0; i<word_length; i++)
                        {
                            word[i]=word4[i];
                        }
                        break;
                    }
                
                    case 5:
                    {
                        for(i=0; i<word_length; i++)
                        {
                            word[i]=word5[i];
                        }
                        break;
                    }
                }
            
                while(lives != 0 && spaces != 0) //while the user has more than 0 lives and there are letters still left to be guessed
                {
                    printf("_____\n");
                    printf("Lives: %d\n", lives);
                    printf("Word: %c %c %c %c %c\n", word_displayed[0], word_displayed[1], word_displayed[2], word_displayed[3], word_displayed[4]); //displays _  so the user knows how many letters in word/are left to guess 
                    printf("Letters guessed:");
                
                    for(i=0; i<counter; i++)
                    {
                        printf(" %c", letters_guessed[i]); //cycles through indexes of letters_guessed and displays on screen
                    }
                
                    do
                    {
                        guessed_before = 'n'; // allows loop to be continued each time
                        printf("\nPlease guess a letter\n");
                        scanf(" %c", &guess); //user enters letter
                        
                        for(i=0; i<counter; i++)
                        {
                            if(guess == letters_guessed[i]) //checks each index of letters_guessed for the guessed letter to determine whether it has already been guessed or not
                            {
                                guessed_before = 'y'; //ie: if letters_guessed contains the guess, it has already been guessed before
                                printf("Letter already guessed\n");
                                break;
                            }
                        }
                        
                    }
                    while(guessed_before == 'y'); //repeats while letter input has already been guessed, ie: will keep asking for another letter until user enters one that has not already been guessed
                    
                    if (isdigit (guess) ) //checks if guess is a number again
                    {
                        letters_guessed[counter] != guess; //does not put the number into the letters_guessed array to be displayed on screen
                    }
                    
                    else //if it is a letter it puts it into the letters_guessed array
                    {
                        letters_guessed[counter] = guess; //guess is put into the index of counter ie: the guess will be put into a different index every time instead of being overwritten
                        counter++; //counter is increased every time a different letter is guessed
                    }
                    
                    correct = 'n';
                    for(i=0; i<word_length; i++)
                    {
                        if(word[i] == guess) //checks if letter guessed is in the word to be guessed
                        {
                            word_displayed[i] = guess;// if it is, it will copy guess into the corresponding index of the word to be displayed
                            correct = 'Y'; //determines if a life will be taken or not
                            spaces--; //spaces is decreased so the program knows if there are still letters to be guessed
                        }
                    }
                
                    
                    if(correct == 'n')
                    {
                        if (isdigit (guess) ) //checks if input is a number
                        {
                            printf("Invalid input. Please enter a letter\n");
                        }
                        
                        else
                        {
                            lives--; //life is taken for an incorrect guess
                            printf("Incorrect guess\n");
                        }
                    }
                }//end while
                
                if (lives == 0) //when user has no lives left
                {
                    printf("You lose :( \n");
                    printf("Word was: %c%c%c%c%c\n", word[0], word[1], word[2], word[3], word[4]); //prints out what the word actually was
                    playagain = 'n'; //allows loop to continue as playagain was 'y' before
                    printf("\nPlay again? (Y/N)\n");
                    scanf(" %c", &playagain);
                }
                
                else //user guesses word correctly while lives > 0
                {
                    printf("You win :) \n");
                    printf("Word was: %c%c%c%c%c\n", word[0], word[1], word[2], word[3], word[4]);
                    playagain = 'n';
                    printf("\nPlay again? (Y/N)\n");
                    scanf(" %c", &playagain);
                }
                
                if (playagain != 'y' && playagain !='Y' && playagain != 'n' && playagain != 'N') //error checking: in case user enters something other that y or n such as a number
                {
                    printf("Please enter either Y or N\n");
                    scanf(" %c", &playagain);
                }
    
                if (playagain == 'n' || playagain == 'N') //user chooses not to continue playing
                {
                    printf("Thanks for playing!\n");
                    return 0; //closes program
                }
            
            break;
            }
            
            case 'N': //user chooses not to play game at beginning
            case 'n':
            {
                printf("Thanks for playing!\n\n");
                break;
            }
            
            default: //error checking: user enters something other than y or n
            {
                printf("Please enter either Y or N\n");
                scanf(" %c", &playagain);
            }
        }//end switch
    }
    while (playagain == 'y' || playagain == 'Y'); //will check what playagain is and will continue as long as it is 'y'

}//End main ()