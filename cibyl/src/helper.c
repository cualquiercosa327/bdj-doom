#include <org/homebrew.h>

void Helper_blitScreen(char* screen, char* palette)
{
    static int screen2[320*200];
    for(int i = 0; i < 320*200; i++)
    {
        int r = 0xff&*palette++;
        int g = 0xff&*palette++;
        int b = 0xff&*palette++;
        screen2[i] = 0xff00000|(r<<16)|(g<<8)|b;
    }
    NOPH_MyXlet_blitFramebuffer(0, 0, 320, 200, screen2, 320);
    NOPH_MyXlet_repaint();
}