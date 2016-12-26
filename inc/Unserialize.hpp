/* 
 * File:   Unserialize.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 25., 19:06
 */

#ifndef UNSERIALIZE_HPP
#define UNSERIALIZE_HPP
#include <cstdio>
#include "Filetypes/CustomFile.hpp"
#include "Filetypes/RawFile.hpp"
#include "Filetypes/StringFile.hpp"
#include "Filetypes/String16File.hpp"
#include "Filetypes/String32File.hpp"
namespace Structure {
namespace Io {

void Unserialize(FILE* handle);
	
}
}
#endif /* UNSERIALIZE_HPP */

