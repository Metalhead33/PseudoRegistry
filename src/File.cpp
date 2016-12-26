/* 
 * File:   File.cpp
 * Author: metalhead33
 * 
 * Created on 2016. december 23., 18:12
 */

#include "File.hpp"

namespace Structure {
File::File(std::string name,Directory* parent)
	: Element(name,parent)
{
	
}
File::File(std::string* path,int tokens)
	: Element(path,tokens)
{
	
}
File::File(char** path,int tokens)
	: Element(path,tokens)
{
	
}
File::File(TokenizedCString* path)
	: Element(path)
{
	
}
File::File(const char* path)
	: Element(path)
{
	
}
File::File(std::string path)
	: Element(path)
{
	
}

File::~File() {
}

void File::Serialize(FILE* handle)
{
	const int16_t type = (int16_t)GetFiletype();
	Element::Serialize(handle);
	fwrite(&type,sizeof(int16_t),1,handle);
}

}

