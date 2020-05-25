#include <ncurses.h>
#include <stdlib.h>

typedef struct Player{
    int xPosition;
    int yPosition;
    int health;
} Player;

int screenSetup();
int mapSetup();
Player * playerSetUp();

int main(){
    Player * user;
    int ch;
    screenSetup();
    mapSetup();
    user = playerSetUp();

    while((ch = getch()) != 'q' ){

    }

    endwin();
    return 0;
}

int screenSetup(){
    initscr();
    printw("Hello world!");
    noecho();
    refresh();
    return 0;
}

int mapSetup(){
    mvprintw(2, 40, "--------");
    mvprintw(3, 40, "|......|");
    mvprintw(4, 40, "|......|");
    mvprintw(5, 40, "|......|");
    mvprintw(6, 40, "|......|");
    mvprintw(7, 40, "--------");

    mvprintw(10, 40, "------------");
    mvprintw(11, 40, "|..........|");
    mvprintw(12, 40, "|..........|");
    mvprintw(13, 40, "|..........|");
    mvprintw(14, 40, "|..........|");
    mvprintw(15, 40, "------------");

    mvprintw(13, 13, "--------");
    mvprintw(14, 13, "|......|");
    mvprintw(15, 13, "|......|");
    mvprintw(16, 13, "|......|");
    mvprintw(17, 13, "|......|");
    mvprintw(18, 13, "--------");
}

Player * playerSetUp(){
    Player * newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->xPosition = 14;
    newPlayer->yPosition = 14;
    newPlayer->health = 20;

    mvprintw(newPlayer->yPosition, newPlayer->xPosition, "@");
    move(newPlayer->yPosition, newPlayer->xPosition);
    return newPlayer;
}