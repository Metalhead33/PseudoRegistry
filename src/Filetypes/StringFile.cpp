/* 
 * File:   StringFile.cpp
 * Author: metalhead33
 * 
 * Created on 2016. december 23., 19:22
 */

#include "StringFile.hpp"
namespace Structure {

StringFile::StringFile(std::string content,std::string name,Directory* parent)
	: File(name,parent)
{
	m_content = content;
}
StringFile::StringFile(std::string content,std::string* path,int tokens)
	: File(path,tokens)
{
	m_content = content;
}
StringFile::StringFile(std::string content,char** path,int tokens)
	: File(path,tokens)
{
	m_content = content;
}
StringFile::StringFile(std::string content,TokenizedCString* path)
	: File(path)
{
	m_content = content;
}
StringFile::StringFile(std::string content,const char* path)
	: File(path)
{
	m_content = content;
}
StringFile::StringFile(std::string content,std::string path)
	: File(path)
{
	m_content = content;
}

StringFile::~StringFile() {
}


std::string StringFile::operator+(StringFile* b)
{
	return (m_content + b->GetContent());
}
std::string StringFile::operator+=(StringFile* b)
{
	return (m_content += b->GetContent());
}
std::string StringFile::operator+(std::string b)
{
	return (m_content + b);
}
std::string StringFile::operator+=(std::string b)
{
	return (m_content += b);
}
std::string StringFile::operator+(const char* b)
{
	return (m_content += b);
}
std::string StringFile::operator+=(const char* b)
{
	return (m_content += b);
}
std::string StringFile::operator=(std::string b)
{
	return (m_content = b);
}
std::string* StringFile::operator*()
{
	return &m_content;
}

void StringFile::Serialize(FILE* handle) // every variant must end with fputc('\0',handle);
{
	const char* path = m_content.c_str();
	const size_t pathsize = m_content.length();
	File::Serialize(handle);
	fwrite(path,1,pathsize,handle);
	fputc('\0',handle);
}

}