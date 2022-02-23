/** 
 * @brief It defines the game interface
 * 
 * @file game.h
 * @author Diego
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"
#include "game_reader.h"
#include "player.h"
#include "object.h"

/**
 * @brief Game
 *
 * This struct stores all the information of the game
 */
typedef struct _Game
{
  Player *player;         
  Object *object;
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;
} Game;

/**
  * @brief It adds sapce to the game
  * @author Diego 
  *
  * @param Game receives a pointer
  * @param space receives a pointer
  * @return ERROR or OK
  */
STATUS game_add_space(Game *game, Space *space);

/**
  * @brief It creates a new game
  * @author Diego 
  *
  * restarts player location, game location, id location and last_cmd
  * @param Game receives a pointer
  * @return ERROR or OK
  */
STATUS game_create(Game *game);
/**
  * @brief this creates the game from a file
  * @author Diego 
  *
  * creates the game at the file
  * @param Game receives a pointer
  * @param filename receives a pointer
  * @return ERROR or OK
  */
STATUS game_create_from_file(Game *game, char *filename);
/**
  * @brief this updtaes the game
  * @author Diego 
  *
  * updates the game at the file
  * @param Game receives a pointer
  * @param cmd receives the command
  * @return ERROR or OK
  */
STATUS game_update(Game *game, T_Command cmd);
/**
  * @brief this destroys the game
  * @author Diego 
  * @param Game receives a pointer
  * @return ERROR or OK
  */
STATUS game_destroy(Game *game);
/**
  * @brief this finishes the game
  * @author Diego 
  * @param Game receives a pointer
  * @return ERROR or OK
  */
BOOL game_is_over(Game *game);
/**
  * @brief prints the game data
  * @author Diego 
  * @param Game receives a pointer
  */
void game_print_data(Game *game);
/**
  * @brief gets the space of the game
  * @author Diego 
  * @param Game receives a pointer
  * @param id rceives the id
  * @return pointer to space
  */
Space *game_get_space(Game *game, Id id);

/**
  * @brief gets the object location
  * @author Diego 
  * @param Game receives a pointer
  * @return the information in game->lastcmd
  */

T_Command game_get_last_command(Game *game);

#endif
