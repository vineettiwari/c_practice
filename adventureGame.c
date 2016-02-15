/**
    adventureGame.c
    Purpose:

    @author   Vineet Tiwari
    @version  1.0
    @date     May 05th, 2015
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INPUT_BUFF 10
#define MAX_HEALTH 5

typedef struct room Room;
struct room 
{
  Room  *toRight,
        *toLeft,
        *toTop,
        *toBottom;

  int content,
      xCordinate,
      yCordinate;
};

typedef struct player Player;
struct player
{
  int health;
  Room *inRoom;
};

void status(Player *);
void movePlayer(Player *, Room *);
void readInput(Player *);

int isGameOver;

int main() 
{
  int empty = 0;
  int tresure = 1;
  int monster = 2;

  Room *initialRoom = NULL;

  isGameOver = 0;

  Room room1;
  room1.xCordinate = 0;
  room1.yCordinate = 0;

  Room room2;
  room2.xCordinate = 0;
  room2.yCordinate = 1;

  Room room3;
  room3.xCordinate = 0;
  room3.yCordinate = 2;

  Room room4;
  room4.xCordinate = 0;
  room4.yCordinate = 3;

  Room room5;
  room5.xCordinate = 1;
  room5.yCordinate = 0;

  Room room6;
  room6.xCordinate = 1;
  room6.yCordinate = 1;

  Room room7;
  room7.xCordinate = 1;
  room7.yCordinate = 2;

  Room room8;
  room8.xCordinate = 1;
  room8.yCordinate = 3;

  Room room9;
  room9.xCordinate = 2;
  room9.yCordinate = 0;

  Room room10;
  room10.xCordinate = 2;
  room10.yCordinate = 1;

  Room room11;
  room11.xCordinate = 2;
  room11.yCordinate = 2;

  Room room12;
  room12.xCordinate = 2;
  room12.yCordinate = 3;

  Room room13;
  room13.xCordinate = 3;
  room13.yCordinate = 0;

  Room room14;
  room14.xCordinate = 3;
  room14.yCordinate = 1;

  Room room15;
  room15.xCordinate = 3;
  room15.yCordinate = 2;

  Room room16;
  room16.xCordinate = 3;
  room16.yCordinate = 3;

  room1.toRight = &room2;
  room1.toLeft = NULL;
  room1.toTop = NULL;
  room1.toBottom = &room5;
  room1.content = empty;

  room2.toRight = &room3;
  room2.toLeft = &room1;
  room2.toTop = NULL;
  room2.toBottom = &room6;
  room2.content = empty;

  room3.toRight = &room4;
  room3.toLeft = &room2;
  room3.toTop = NULL;
  room3.toBottom = &room7;
  room3.content = empty;

  room4.toRight = NULL;
  room4.toLeft = &room3;
  room4.toTop = NULL;
  room4.toBottom = &room8;
  room4.content = empty;

  room5.toRight = &room6;
  room5.toLeft = NULL;
  room5.toTop = &room1;
  room5.toBottom = &room9;
  room5.content = empty;

  room6.toRight = &room7;
  room6.toLeft = &room5;
  room6.toTop = &room2;
  room6.toBottom = &room10;
  room6.content = empty;

  room7.toRight = &room8;
  room7.toLeft = &room6;
  room7.toTop = &room3;
  room7.toBottom = &room11;
  room7.content = empty;

  room8.toRight = NULL;
  room8.toLeft = &room7;
  room8.toTop = &room4;
  room8.toBottom = &room12;
  room8.content = empty;

  room9.toRight = NULL;
  room9.toLeft = &room10;
  room9.toTop = &room5;
  room9.toBottom = &room13;
  room9.content = empty;

  room10.toRight = &room11;
  room10.toLeft = &room9;
  room10.toTop = &room6;
  room10.toBottom = &room14;
  room10.content = empty;

  room11.toRight = &room12;
  room11.toLeft = &room10;
  room11.toTop = &room7;
  room11.toBottom = &room15;
  room11.content = tresure;

  room12.toRight = NULL;
  room12.toLeft = &room11;
  room12.toTop = &room8;
  room12.toBottom = &room16;
  room12.content = empty;

  room13.toRight = &room14;
  room13.toLeft = NULL;
  room13.toTop = &room9;
  room13.toBottom = NULL;
  room13.content = empty;

  room14.toRight = &room15;
  room14.toLeft = &room13;
  room14.toTop = &room10;
  room14.toBottom = &room5;
  room14.content = monster;

  room15.toRight = &room16;
  room15.toLeft = &room14;
  room15.toTop = &room11;
  room15.toBottom = NULL;
  room15.content = empty;

  room16.toRight = NULL;
  room16.toLeft = &room15;
  room16.toTop = &room12;
  room16.toBottom = NULL;
  room16.content = empty;

  Player player1;
  player1.inRoom = &room1;
  player1.health = MAX_HEALTH;

  while(!isGameOver) 
  {
    status(&player1);
    readInput(&player1);
  }
    return 0;
}

void status(Player *player1)
{
  printf( "\nYou are in room: %d,%d\n"
            "Your health:     %d\n"
          "Your exits are:\n",
          player1->inRoom->xCordinate, 
          player1->inRoom->yCordinate, 
          player1->health);

  Room *room = player1->inRoom;

  if(room->toRight)
  {
    printf("\t\t right\n");
  }
  if(room->toLeft)
  {
    printf("\t\t left\n");
  }
  if(room->toTop)
  {
    printf("\t\t top\n");
  }
  if(room->toBottom)
  {
    printf("\t\t bottom\n");
  }

  printf("\n%s", "Enter direction to move\n"
                "or 'quit' to end game: ");
}


void movePlayer(Player *player1, Room *room)
{
  if(!room)
    printf("%s\n", "Room does not exist.");

  player1->inRoom = room;

  switch(room->content)
  {
    case 0 :
      break;

    case 1 :
      printf("\nYou found the treasure!\n"
              "Game Over, You Won!\n\n");
      isGameOver = 1;
      break;

    case 2 :
      printf("\nYou ran into the monster!\n");
      player1->health -= 1;
      if(player1->health == 0)
      {
        printf("Game Over, You Lost!\n\n");
        isGameOver = 1;
      }
      break;

    default :
      printf("%s\n", "Invalid content");
  }
}

void readInput(Player *player1)
{
  char input[INPUT_BUFF];
  int index;
  unsigned length;

  fgets(input, INPUT_BUFF, stdin);
  length = strlen(input);
  input[length - 1] = '\0';

  for(index = 0; index < length; index++)
  {
    input[index] = tolower(input[index]);
  }

  switch(input[0])
  {
    case 'r' :
      movePlayer(player1, player1->inRoom->toRight);
      break;

    case 'l' :
      movePlayer(player1, player1->inRoom->toLeft);
      break;

    case 't' :
      movePlayer(player1, player1->inRoom->toTop);
      break;

    case 'b' :
      movePlayer(player1, player1->inRoom->toBottom);
      break;

    case 'q' :
      printf("%s\n", "Good Bye!");
      isGameOver = 1;
      break;

    default :
      printf("%s\n", "Invalid input.");
  }
}

