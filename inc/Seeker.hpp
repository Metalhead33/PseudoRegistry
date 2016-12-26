/* 
 * File:   Seeker.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 11., 19:05
 */
#ifndef SEEKER_HPP
#define SEEKER_HPP
#include "Directory.hpp"
#include "Tokenizer.h"
namespace Structure {

//Element* SeekElement(std::string path);
Element* SeekElement(std::string* path,int tokens);
Element* SeekElement(char** path,int tokens);
Element* SeekElement(TokenizedCString* path);
Element* SeekElement(const char* path);
Element* SeekElement(std::string path);

Directory* Mkdir(std::string* path,int tokens);
Directory* Mkdir(char** path,int tokens);
Directory* Mkdir(TokenizedCString* path);
Directory* Mkdir(const char* path);
Directory* Mkdir(std::string path);

}
#endif /* SEEKER_HPP */

