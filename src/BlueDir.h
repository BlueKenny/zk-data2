// This is start of the header guard.  ADD_H can be any unique name.  By convention, we use the name of the header file.
#ifndef BLUEDIR_H
#define BLUEDIR_H

// This is the content of the .h file, which is where the declarations go
extern bool PathExists(std::string directory);
extern void MkDir(std::string directory);
extern string ListDir(std::string directory);
 
// This is the end of the header guard
#endif
