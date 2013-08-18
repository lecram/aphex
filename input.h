#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

typedef enum { CURSOR_UP, CURSOR_DOWN, CURSOR_LEFT, CURSOR_RIGHT, CURSOR_BOTTOM, CURSOR_TOP, CURSOR_HOME, CURSOR_END,
	APHEX_REDRAW, APHEX_INSERT_MODE = 'I', APHEX_COMMAND_MODE = 'C', APHEX_READONLY_MODE = 'R', APHEX_DELETE_COMBUF,
	APHEX_EDIT_HEX, APHEX_EDIT_ASCII, APHEX_EDIT_BIN, QUIT, NONE } aphexCom;

char comBuf[128];
unsigned long comNum;
int comIndex;
void resetComBuf();

aphexCom parseComBuf(char c);
aphexCom aphexMode;
aphexCom aphexEditMode;

bool quit;

char getch();

int cursorX, cursorY;
void aphexCursorSet(int x, int y);
void aphexCursorDown(int y);
void aphexCursorRight(int x);
void aphexCursorTop();
void aphexCursorBottom();
void aphexCursorHome();
void aphexCursorEnd();
void aphexCursorSetByOffset(long o);

void aphexCursorSetXRight(long o);
void aphexCursorSetXLeft(long o);
void aphexCursorSetYUp(long o);
void aphexCursorSetYDown(long o);

/* catch user input, redraw window, set cursor */
void aphexInputProcess();

bool aphexCursorHexBorderYTop(int y);
bool aphexCursorHexBorderYBottom(int y);
bool aphexCursorHexBorderXLeft(int x);
bool aphexCursorHexBorderXRight(int x);

#endif // INPUT_H_INCLUDED
