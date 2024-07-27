//
//  game.c
//

#include "game.h"

#include <stdio.h>
#include <string.h>

static PlaydateAPI *pd = NULL;

// Main functions

void setup(PlaydateAPI *p) {
	pd = p;

	pd->display->setRefreshRate(50);
}

int update(void *ud) {
	pd->graphics->clear(1);

	char text[] = "Hello world!";
	pd->graphics->drawText(text, strlen(text), kASCIIEncoding, LCD_COLUMNS / 2, LCD_ROWS / 2);

	return 1;
}