#include <stdio.h>

// Colored Text
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define GRAY "\x1b[90m"

typedef enum {
    SUCCESS,
    MISPLACED,
    INCORRECT
} letterState;

void printLetter(char letter, letterState state) {
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

void setup() {
    printf("You will have 6 letters to guess the correct word.\n");
    printf("After every guess, each letter will be either green, yellow, gray.\n");
    printf("Green means correct letter and correct place.\n");
    printf("Yellow means correct letter and wrong place.\n");
    printf("Grey means wrong letter.\n");
}

int main(void) {
    setup();

    // printf("%i", WORD_LENGTH);
    const int WORD_LENGTH = 6;
    const char *WORD_ANSWER = "crane";

    char *plrGuess = "";
    int guessCount = 0;
}
