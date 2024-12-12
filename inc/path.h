#ifndef _PATH_H_
#define _PATH_H_


/**
  \file 
  \brief Functions that help with processing paths in the file system
  Here are the terms that will be used:
    - 'path': a whole given path;
    - 'file': the full name of the file to which the path points to;
    - 'base': the path up to the 'file' part;
    - 'name': the name of the file without the extension;
    - 'extn': the extension of the file;
  There are two functions that offer certain components from the 
  above list expecting the input to also be one of those components
  The third function returns an array of C style strings, each
  position points to, in the following order, the folders up to the 
  'file' part, the 'name' component and the 'extn' component.
  The functions will modify the original string, the user is expected to
  have that in mind.
*/

/**
  \brief Convert a full path into 'base' and 'file'
  More details down below: 
  @param path_to_base [inout] C style string to be processed
  @param file         [out]   Just the name of the file
*/
void path_to_base_and_file(char** path_to_base, char** file);

/**
  \brief Split the filename into the name itself and the extension
  More details down below: 
  @param file_to_name [inout] The full name of the file
  @param extn         [out]   The extension of the file
*/
void file_to_name_and_extn(char** file_to_name, char** extn);


/**
  \brief Convert a full 'path' into tokens 
  The first tokens are the folder making up the 'base' part 
  if they exist, the next one is 'name', the last one is 'extn'
  This parts are given only if they exist
  The number of found tokens is saved in the second argument
  The array of found tokens is returned by the function
  The user is expected to free its memory

  More details down below: 
  @param path [inout] C style string to be processed
  @param size [out]   The number of found tokens
  \return tokns An array of C style strings containing the tokens 
*/
char** path_to_toks(char* path, int *size);

#endif//_PATH_H_
