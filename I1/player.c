/**
 * @brief It defines a textual graphic engine
 *
 * @file player.c
 * @author Daniel
 * @version 2.0
 * @date 14/02/2022
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

struct _Player{
    Id id;                    /*!< Id number of the player, it must be unique */
    char name[WORD_SIZE + 1]; /*!< Name of the player */
    Id location;              /*!< Location of the player*/
    BOOL object;              /*!< Whether the player has an object or not */
};

/*creates a player*/
Player* player_create(Id id){
    Player *newPlayer = NULL;

    /* Error control */
    if (id == NO_ID)
    return NULL;

    newPlayer = (Player*)malloc(sizeof(Player));
    if (newPlayer == NULL) {
    return NULL;
    }

    /* Initialization of an empty player*/
    newPlayer->id = id;
    newPlayer->name[0] = '\0';
    newPlayer->location = NO_ID;
    newPlayer->object = FALSE;

  return newPlayer;
}

/** player_destroy frees the previous memory allocation 
  *  for a player
  */
STATUS player_destroy(Player* player) {
  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;
  return OK;
}

/** It gets the id of a player
  */
Id player_get_id(Player* player) {
  if (!player) {
    return NO_ID;
  }
  return player->id;
}

/** It sets the name of a player
  */
STATUS player_set_name(Player* player, char* name) {
  if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}
/** It gets the name of a player
  */
const char * player_get_name(Player* player) {
  if (!player) {
    return NULL;
  }
  return player->name;
}

/*sets the ID location of a player*/
STATUS player_set_location(Player *player, Id id)
{

  if ( id == NO_ID )
  {
    return ERROR;
  }

  player->location = id;

  return OK;

}

/*gets the ID location of a player¨*/
Id player_get_location(Player *player)
{
  return player->location;
}

/** It sets whether the player has an object or not
  */
STATUS player_set_object(Player* player, BOOL value) {
  if (!player) {
    return ERROR;
  }
  player->object = value;
  return OK;
}
/** It gets whether the player has an object or not
  */
BOOL player_get_object(Player* player) {
  if (!player) {
    return FALSE;
  }
  return player->object;
}

/** It prints the player information
  */
STATUS player_print(Player* player) {
  /* Error Control */
  if (!player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
 
  /* 2. Print the id of the player location */ 
  fprintf(stdout, "--> Player location(Id: %ld)\n", player->location);
  
  /* 3. Print if there is an object in the space or not */
  if (player_get_object(player)) {
    fprintf(stdout, "---> Object with the player.\n");
  } else {
    fprintf(stdout, "---> No object with the player.\n");
  }

  return OK;
}

