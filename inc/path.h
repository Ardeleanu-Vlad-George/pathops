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
  There are two functions, their purpose well stated by the their name 
  The functions will modify the original string, the user is expected to
  in mind.
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

#endif//_PATH_H_
