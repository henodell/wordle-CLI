#include <stdio.h>
#include <string.h>

// Colored Text
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define GRAY "\x1b[90m"

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

    while (guessCount < MAX_GUESSES) {
        guessCount++;

        // handle input, flush rest of stdin if long input
        // if short input remove \n to get only char
        // then check if string is equal to word length (short input check)
        do {
            if (fgets(plrGuess, sizeof(plrGuess), stdin) == NULL) {
                printf("\nInput error or EOF.");
                break;
            }
            flushStdin();
            plrGuess[strcspn(plrGuess, "\n")] = 0;
        } while (strlen(plrGuess) != WORD_LENGTH);

        
    }
}
