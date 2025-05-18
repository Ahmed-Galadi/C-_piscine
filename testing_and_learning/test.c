
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

#define WIDTH 40
#define HEIGHT 20

const char *frames[] = {
    "        .-''''''-.\n"
    "     .'          '.\n"
    "    /   O      O   \\\n"
    "   :                :\n"
    "   |                |\n"
    "   : ',          ,' :\n"
    "    \\  '-......-'  /\n"
    "     '.          .'\n"
    "       '-......-'\n",

    "       .-''''''-.\n"
    "    .'          '.\n"
    "   /   O      O   \\\n"
    "  :                :\n"
    "  |                |\n"
    "  :  ',        ,'  :\n"
    "   \\   '-....-'   /\n"
    "    '.          .'\n"
    "      '-......-'\n",

    "      .-''''''-.\n"
    "   .'          '.\n"
    "  /   O      O   \\\n"
    " :                :\n"
    " |                |\n"
    " :   ',      ,'   :\n"
    "  \\    '-..-'    /\n"
    "   '.          .'\n"
    "     '-......-'\n",
};

int main() {
    int frame = 0;
    while (1) {
        printf("\033[H\033[J"); // Clear screen and move cursor to top
        for (int i = 0; i < HEIGHT / 2; i++)
            printf("\n");

        for (int i = 0; i < WIDTH / 2; i++)
            printf(" ");

        printf("%s", frames[frame]);
        frame = (frame + 1) % (sizeof(frames) / sizeof(frames[0]));
        usleep(200000); // Sleep 200ms
    }
    return 0;
}
