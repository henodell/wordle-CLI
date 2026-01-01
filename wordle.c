#include <stdio.h>
#include <string.h>

// Colored Text
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define GRAY "\x1b[90m"
#define RED "\x1b[31m"

typedef enum {
    SUCCESS,
    MISPLACED,
    INCORRECT
} LetterState;

// Helper Functions //

void flushStdin(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printLetter(char letter, LetterState state) {
    switch (state) {
        case SUCCESS:
            printf("%s%c%s", GREEN, letter, RESET);
            break;
        case MISPLACED:
            printf("%s%c%s", YELLOW, letter, RESET);
            break;
        case INCORRECT:
            printf("%s%c%s", GRAY, letter, RESET);
            break;
    }
}

// Logic Functions //

void evaluateGuess(const char answer[], const char guess[]) {
    LetterState states[5]; // state for each letter
    int used[5] = {0}; // false if not checked, true if checked

    // mark greens
    for (int i = 0; i < 5; i++) {
        if (guess[i] == answer[i]) {
            states[i] = SUCCESS;
            used[i] = 1;

        } else {
            states[i] = INCORRECT;
        }
    }

    // mark yellows
    for (int i = 0; i < 5; i++) {
        if (states[i] == SUCCESS) {
            continue;
        }

        for (int j = 0; j < 5; j++) {
            if (!used[j] && guess[i] == answer[j]) {
                states[i] = MISPLACED;
                used[j] = 1;
                break;
            }
        }
    }

    // print each letter
    for (int i = 0; i < 5; i++) {
        printLetter(guess[i], states[i]);
    }
}

void setup(void) {
    printf("You will have 6 letters to guess the correct word.\n");
    printf("After every guess, each letter will be either green, yellow, gray.\n");
    printf("Green means correct letter and correct place.\n");
    printf("Yellow means correct letter and wrong place.\n");
    printf("Grey means wrong letter.\n");
}

int main(void) {
    setup();

    const int WORD_LENGTH = 5;
    const char WORD_ANSWER[] = "crane";

    // buffer to hold player input
    char plrGuess[WORD_LENGTH + 1];

    const int MAX_GUESSES = 6;
    int guessCount = 0;

    while (guessCount < MAX_GUESSES && strcmp(plrGuess, WORD_ANSWER) != 0) {
        guessCount++;

        // input loop until its atleast 5 chars
        do {
            if (fgets(plrGuess, sizeof(plrGuess), stdin) == NULL) {
                printf("\nInput error or EOF.");
                break;
            }
            
            // if \n is not the buff that means stdin could have remaining chars
            if (strchr(plrGuess, '\n') == NULL) {
                flushStdin();
            }

            // make newline into null to so strlen returns correct size
            plrGuess[strcspn(plrGuess, "\n")] = 0;

            if (strlen(plrGuess) < WORD_LENGTH) {
            printf("Input must be atleast 5 letters.\n");
            }

        } while (strlen(plrGuess) != WORD_LENGTH);

        evaluateGuess(WORD_ANSWER, plrGuess);        
        printf(" Guess %i\n", guessCount);
    }

    // ending text depends on if the player got the word
    if (strcmp(plrGuess, WORD_ANSWER) == 0) {
        printf("%sCongrats! You have won in %i guesses.%s\n", GREEN, guessCount, RESET);
    }
    else {
        printf("%sYou have lost! The word was %s.%s\n", RED, WORD_ANSWER, RESET);
    }
}