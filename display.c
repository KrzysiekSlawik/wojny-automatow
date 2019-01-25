#include "display.h"
#include <stdio.h>
void red()
{
  printf("\033[1;31m");
}
void gold()
{
  printf("\033[1;33m");
}
void green()
{
  printf("\033[0;32m");
}
void white()
{
  printf("\033[0m");
}

void printMap(map *gameMap, robot *list[1000])
{
    for(int y = 0; y<gameMap->sizeY; y++)
    {
        for(int x = 0; x<gameMap->sizeX; x++)
        {
            if(gameMap->whole[x][y]>=0)
            {
                if(list[gameMap->whole[x][y]]->isRed)
                {
                    red();
                    if(list[gameMap->whole[x][y]]->isBase)
                    {
                        printf(" Q");
                    }
                    else
                    {
                        printf(" #");
                    }
                }
                else
                {
                    green();
                    if(list[gameMap->whole[x][y]]->isBase)
                    {
                        printf(" Q");
                    }
                    else
                    {
                        printf(" #");
                    }
                }
            }
            else if(gameMap->whole[x][y]==-3)
            {
                white();
                printf("##");
            }
            else if(gameMap->whole[x][y]==-2)
            {
                gold();
                printf("##");
            }
            else if(gameMap->whole[x][y]==-1)printf("  ");
        }
        putchar('\n');
    }
}
