#include "display.h"
#include <stdio.h>
#include <ncurses.h>
void initDisplay()
{
  //ncurses initialization
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
}
void setDelay(int delay)
{
  cbreak();
	halfdelay(delay);
}
WINDOW *initWindow(int winSizeY, int winSizeX, int y, int x)
{
  return newwin(winSizeY, winSizeX, y, x);
}
void delWindow(WINDOW *win)
{
  delwin(win);
}
void endDisplay()
{
  endwin();
}
void printMap(map *gameMap, robot *list[ROBOTSLIMIT], WINDOW *mainWin, int px, int py, int sizeX, int sizeY, WINDOW *statsWin)
{
    wclear(mainWin);
    wclear(statsWin);
    for(int y = 0; y<sizeY; y++)
    {
        for(int x = 0; x<sizeX; x++)
        {
            int id = gameMap->whole[x+px][y+py];
            if(id>=0)
            {
                if(list[id]->isRed)
                {
                    if(list[id]->isBase)
                    {
                        wattron(mainWin, COLOR_PAIR(2));
                        wprintw(mainWin, "Q");
                        wattroff(mainWin, COLOR_PAIR(2));
                    }
                    else
                    {
                        wattron(mainWin, COLOR_PAIR(6));
                        wattron(mainWin, A_BOLD);
                        wprintw(mainWin, "O");
                        wattroff(mainWin, COLOR_PAIR(6));
                        wattroff(mainWin, A_BOLD);
                    }
                }
                else
                {
                    if(list[id]->isBase)
                    {
                        wattron(mainWin, COLOR_PAIR(1));
                        wprintw(mainWin, "Q");
                        wattroff(mainWin, COLOR_PAIR(1));
                    }
                    else
                    {
                        wattron(mainWin, COLOR_PAIR(5));
                        wattron(mainWin, A_BOLD);
                        wprintw(mainWin, "O");
                        wattroff(mainWin, COLOR_PAIR(5));
                        wattroff(mainWin, A_BOLD);
                    }
                }
            }
            else if(id==-3)
            {
                wattron(mainWin, COLOR_PAIR(4));
                wprintw(mainWin, "#");
                wattroff(mainWin, COLOR_PAIR(4));
            }
            else if(id==-2)
            {
                wattron(mainWin, COLOR_PAIR(3));
                wprintw(mainWin, "#");
                wattroff(mainWin, COLOR_PAIR(3));
            }
            else if(id==-1)
            {
                wprintw(mainWin, " ");
            }
        }
    }
    wborder(statsWin, '|', '|', '-', '-', '+', '+', '+', '+');
    wattron(statsWin, COLOR_PAIR(6));
    mvwprintw(statsWin, 1, 1, "gold %d", gameMap->resources[1]);
    mvwprintw(statsWin, 2, 1, "hp %d", list[0]->hp);
    wattroff(statsWin, COLOR_PAIR(6));
    wattron(statsWin, COLOR_PAIR(5));
    mvwprintw(statsWin, 4, 1, "gold %d", gameMap->resources[0]);
    mvwprintw(statsWin, 5, 1, "hp %d", list[1]->hp);
    wattroff(statsWin, COLOR_PAIR(5));
    mvwprintw(statsWin, 7, 1, "move cam");
    mvwprintw(statsWin, 8, 1, "with arrows");
    mvwprintw(statsWin, 10, 1, "speed up-K");
    mvwprintw(statsWin, 11, 1, "slow down-L");
    mvwprintw(statsWin, 12, 1, "quit-Q");
    mvwprintw(statsWin, 13, 1, "skip-S");

    wrefresh(statsWin);
    wrefresh(mainWin);
}
