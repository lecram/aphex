
#include "types.h"

int main(int argc, char **argv)
{
	/*
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &aphexTerm);
	aphexWin testBase;
	aphexWin testChild;
	aphexWinInit(&testBase, 0, 0, aphexTerm.ws_col, aphexTerm.ws_row);
	aphexWinInit(&testChild, 5, 10, 3, 6);
	aphexWinToWin(&testBase, &testChild);
	for (int i=0; i<testBase.height; i++) {
		for (int j=0; j<testBase.width; j++) {
			printf("%c",testBase.c[j + (testBase.width)*i]);
		}
	}
	while (!(getch()=='Q')) {}
	free(testBase.c);
	free(testChild.c);
	return 0;
	*/
	if (argc < 2 || (strcmp(argv[1], "-h") == 0)) {
		printf("usage: %s <file>\n", argv[0]);
		printf("maximum filesize on system: %lu MB",ULONG_MAX/1024/1024);
		exit(EXIT_SUCCESS);
	}
	if (strcmp(argv[1], "-r") == 0) {
		aphexMode = APHEX_READONLY_MODE;
		buf_open((unsigned char*)argv[2]);
	} else {
		aphexMode = APHEX_COMMAND_MODE;
		buf_open((unsigned char*)argv[1]);
	}

	quit = false;
	comNum = 1;
	resetComBuf();
	system("clear");
	if (!aphexContentInit()) {
		printf("terminal too small\n");
		exit(EXIT_SUCCESS);
	}
	cursorX = APHEX_WIN_HEX_X;
	cursorY = APHEX_WIN_HEX_Y;
	while (!quit) {
		aphexWinDraw(&winBase);
		aphexInputProcess();
	}

	buf_close();
	aphexContentFree();
	system("clear");
	exit(EXIT_SUCCESS);
}
