/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Daniel
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"

typedef struct _Graphic_engine Graphic_engine;

/**
  * @brief Creates the graphic engine
  * @author Daniel
  * 
  * @return A graphic engine
  */
Graphic_engine *graphic_engine_create();

/**
  * @brief Destroys the graphic engine
  * @author Daniel
  * 
  * @param ge A pointer to the graphic engine
  */
void graphic_engine_destroy(Graphic_engine *ge);

/**
  * @brief Paints game
  * @author Daniel
  * 
  * @param ge A pointer to the graphic engine
  * @param game A pointer to a game
  */
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);

/**
  * @brief writes command
  * @author Daniel
  * 
  * @param ge A pointer to a graphic engine
  * @param str A pointer to a string
  */
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
