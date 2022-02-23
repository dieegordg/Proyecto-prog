/** 
 * @brief It defines the game interface
 * 
 * @file game.h
 * @author Diego
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"

typedef struct _Game Game;

/**
  * @brief It loads the game spaces
  * @author Diego 
  *
  * 
  * @param Game receives a pointer
  * @param filename receives a pointer
  * @return ERROR or OK
  */
STATUS game_load_spaces(Game *game, char *filename);

#endif
