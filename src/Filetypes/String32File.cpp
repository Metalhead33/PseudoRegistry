/* 
 * File:   String32File.cpp
 * Author: metalhead33
 * 
 * Created on 2032. december 26., 17:52
 */

#include "String32File.hpp"
namespace Structure {


String32File::String32File(std::u32string content,std::string name,Directory* parent)
	: File(name,parent)
{
	m_content = content;
}
String32File::String32File(std::u32string content,std::string* path,int tokens)
	: File(path,tokens)
{
	m_content = content;
}
String32File::String32File(std::u32string content,char** path,int tokens)
	: File(path,tokens)
{
	m_content = content;
}
String32File::String32File(std::u32string content,TokenizedCString* path)
	: File(path)
{
	m_content = content;
}
String32File::String32File(std::u32string content,const char* path)
	: File(path)
{
	m_content = content;
}
String32File::String32File(std::u32string content,std::string path)
	: File(path)
{
	m_content = content;
}

String32File::~String32File() {
}

std::wstring String32File::GetWstring()
{
	return std::wstring((wchar_t*)m_content.c_str(),m_content.length());
}

void String32File::Serialize(FILE* handle) //This one won't end with '\0'
{
	const char32_t* path = m_content.c_str();
	const uint64_t pathsize = (uint64_t)m_content.length();
	File::Serialize(handle);
	fwrite(&pathsize,sizeof(uint64_t),1,handle);
	fwrite(path,sizeof(char32_t),pathsize,handle);
}

}