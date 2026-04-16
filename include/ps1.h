#ifndef PS1_H
#define PS1_H

enum Buttons
{
    X_BUTTON = 0x0001,
    SQUARE_BUTTON = 0x0080,
    CIRCLE_BUTTON = 0x0020,
    TRIANGLE_BUTTON = 0x0010,

    UP_BUTTON = 0x1000,
    RIGHT_BUTTON = 0x2000,
    DOWN_BUTTON = 0x4000,
    LEFT_BUTTON = 0x8000,

    SELECT_BUTTON = 0x0100,
    START_BUTTON = 0x0800,

    R1_BUTTON = 0x0008,
    L1_BUTTON = 0x0004,
    R2_BUTTON = 0x0002,
    L2_BUTTON = 0x0001,

    L3_BUTTON = 0x0200,
    R3_BUTTON = 0x0400
};

struct RECT
{
    short x;
    short y;
    short w;
    short h;
};

/* Example purple error screen
struct RECT dummy;

dummy.w = 0x3ff;
dummy.x = 0;
dummy.y = 0;
dummy.h = 0x1ff;

do
{
    _ClearImage(&dummy, 37, 23, 71);
} while (true);*/

#endif // PS1_H
