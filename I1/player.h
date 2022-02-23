/**
 * @brief Defines player interface
 *
 * @file player.h
 * @author Daniel
 * @version 2.0
 * @date 14-02-2022
 * @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

#define MAX_PLAYERS 100

typedef struct _Player Player;

/*Private functions*/
STATUS player_set_location(Player *player, Id id);

/**
  * @brief It creates a new player
  * @author Daniel
  *
  * player_create allocates memory for a new player
  *  and initializes its members
  * @param id the identification number for the new player
  * @return a new player, initialized
  */
Player* player_create(Id id);

/**
  * @brief It destroys a player
  * @author Daniel
  *
  * player_destroy frees the previous memory allocation 
  *  for a player
  * @param space a pointer to the player that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_destroy(Player* player);

/**
  * @brief It gets the id of a player
  * @author Daniel
  * 
  * @param player a pointer to the player  
  * @return the id of player
  */
Id player_get_id(Player* player);

/**
  * @brief It sets the name of a player
  * @author Daniel
  * 
  * @param player a pointer to the player
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_name(Player* player, char* name);

/**
  * @brief It gets the name of a player
  * @author Daniel
  * 
  * @param player a pointer to the player
  * @return  a string with the name of the player
  */
const char* player_get_name(Player* player);

/**
  * @brief It gets the player location
  * @author Daniel
  *
  * @param player a pointer to the player
  * @return a boolean, specifying if in the player there is an object (TRUE) or not (FALSE)
  */
Id player_get_location(Player *player);
/**
  * @brief It sets whether the space has an object or not
  * @author Daniel
  *
  * @param player a pointer to the player
  * @param value a boolean, specifying if in the player there is an object (TRUE) or not (FALSE)
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_object(Player* player, BOOL value);

/**
  * @brief It gets whether the player has an object or not
  * @author Daniel
  *
  * @param player a pointer to the player
  * @return a boolean, specifying if in the player there is an object (TRUE) or not (FALSE)
  */
BOOL player_get_object(Player* player);

/**
  * @brief It prints the player information
  * @author Daniel
  *
  * This function shows the id and name of the player, the location and wheter it has an object or not.
  * @param player a pointer to the player
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_print(Player* player);

#endif
