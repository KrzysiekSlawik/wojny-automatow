#include "display.h"
#include <stdio.h>
#include <ncurses.h>
void printMap(map *gameMap, robot *list[ROBOTSLIMIT], WINDOW *mainWin, int px, int py, int sizeX, int sizeY)
{
    wclear(mainWin);
    for(int y = 0; y<sizeY; y++)
    {
        for(int x = 0; x<sizeX; x++)
        {
            if(gameMap->whole[x+px][y+py]>=0)
            {
                if(list[gameMap->whole[x+px][y+py]]->isRed)
                {
                    if(list[gameMap->whole[x+px][y+py]]->isBase)
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
                    if(list[gameMap->whole[x+px][y+py]]->isBase)
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
            else if(gameMap->whole[x+px][y+py]==-3)
            {
                wattron(mainWin, COLOR_PAIR(4));
                wprintw(mainWin, "#");
                wattroff(mainWin, COLOR_PAIR(4));
            }
            else if(gameMap->whole[x+px][y+py]==-2)
            {
                wattron(mainWin, COLOR_PAIR(3));
                wprintw(mainWin, "#");
                wattroff(mainWin, COLOR_PAIR(3));
            }
            else if(gameMap->whole[x+px][y+py]==-1)
            {
                wprintw(mainWin, " ");
            }
        }
    }
    wborder(mainWin, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(mainWin);
}
