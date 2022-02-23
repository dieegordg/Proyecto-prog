/**
 * @brief It defines the space interface
 *
 * @file object.h
 * @author Diego
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

#define MAX_OBJECTS 100

typedef struct _Object Object;

/*Private functions*/
STATUS object_set_location(Object *object, Id id);

/**
  * @brief It creates a new object
  * @author Diego
  *
  * object_create allocates memory for a new space
  *  and initializes its members
  * @param id the identification number for the new object
  * @return a new object, initialized
  */
Object* object_create(Id id);

/**
  * @brief It destroys a object
  * @author Diego
  *
  * object_destroy frees the previous memory allocation 
  *  for a object
  * @param object a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object* object);

/**
  * @brief It gets the id of a object
  * @author Diego
  * 
  * @param object a pointer to the object  
  * @return the id of object
  */
Id object_get_id(Object* object);

/**
  * @brief It sets the name of a object
  * @author Diego
  * 
  * @param object a pointer to the object
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_name(Object* object, char* name);

/**
  * @brief It gets the name of a object
  * @author Diego
  * 
  * @param object a pointer to the object
  * @return  a string with the name of the object
  */
const char* object_get_name(Object* object);

/**
  * @brief It gets the object location
  * @author Diego
  *
  * @param object a pointer to the object
  * @return the object location
  */
Id object_get_location(Object *object);
/**
  * @brief It prints the object information
  * @author Diego
  *
  * This fucntion shows the id and name of the object
  * @param object a pointer to the object
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(Object* object);

#endif
