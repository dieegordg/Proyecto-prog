/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Diego 
 * @version 2.0 
 * @date 8-2-2022 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"


/**
   Private functions
*/
Id game_get_space_id_at(Game *game, int position);

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);
void game_command_drop(Game *game);
void game_command_take(Game *game);

/**
   Game interface implementation
*/

/** game_create this creates the game, starting from the beginning
  */
STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  game->player = player_create(31);
  game->object = object_create(23);
  game->last_cmd = NO_CMD;

  return OK;
}

/** game_create_from_file this creates the game from a file
  */
STATUS game_create_from_file(Game *game, char *filename)
{

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR)
    return ERROR;

  /* The player and the object are located in the first space */
  player_set_location(game->player, game_get_space_id_at(game, 0));
  object_set_location(game->object, game_get_space_id_at(game, 0));

  return OK;
}

/** game_destroy this destroys the game so it starts from the beginning
  */
STATUS game_destroy(Game *game)
{
  int i = 0;
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }
  return OK;
}

/** game_add_space this adds spaces
  */
STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}

/** game_get_space_id_at returns the position
  */
Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}

/** *game_get_space returns the space
  */
Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}


/** game_update updates the game
  */
STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  
  switch (cmd)
  {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game_command_next(game);
      break;

    case BACK:
      game_command_back(game);
      break;

    case TAKE:
      game_command_take(game);
      break;
    
    case DROP:
      game_command_drop(game);
      break;

    default:
      break;
  }

  return OK;
}

/** game_get_last_command gets the last command
  */
T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}
/** game_print_data prints the data in the game
  */
void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)object_get_location(game->object));
  printf("=> Player location: %d\n", (int)player_get_location(game->player));
}

/** game_is_over it finishes the game
  */
BOOL game_is_over(Game *game)
{
  return FALSE;
}

/**
   Calls implementation for each action 
*/
void game_command_unknown(Game *game)
{
}

void game_command_exit(Game *game)
{
  
}

void game_command_drop(Game *game)
{
  player_set_object(game->player,FALSE);
  return;
}

void game_command_take(Game *game)
{
  Id current_id = NO_ID;
  current_id=player_get_location(game->player);
  if(object_get_location(game->object)==current_id)
    player_set_object(game->player,TRUE);
  return;
}

void game_command_next(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_location(game->player);

  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        if(player_get_object(game->player)==TRUE){
          object_set_location(game->object,current_id);
          player_set_location(game->player,current_id);
        }
        else
        player_set_location(game->player, current_id);
      }
      return;
    }
  }
}

void game_command_back(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = player_get_location(game->player);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        if(player_get_object(game->player)==TRUE){
          object_set_location(game->object,current_id);
          player_set_location(game->player,current_id);
        }
        else
        player_set_location(game->player, current_id);
      }
      return;
    }
  }
}
