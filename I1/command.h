/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Diego 
 * @version 2.0
 * @date 8-2-2022
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2
#define N_CMD 7

typedef enum enum_CmdType {
  CMDS,
  CMDL} T_CmdType;

typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  NEXT,
  BACK,
  TAKE,
  DROP
  } T_Command;

/**
  * @brief It gets the user input
  * @author Diego 
  * @param there are no params
  * @return returns cmd which is the user input
  */
T_Command command_get_user_input();

#endif
