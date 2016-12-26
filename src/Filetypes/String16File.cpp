/* 
 * File:   String16File.cpp
 * Author: metalhead33
 * 
 * Created on 2016. december 26., 17:16
 */

#include "String16File.hpp"
namespace Structure {


String16File::String16File(std::u16string content,std::string name,Directory* parent)
	: File(name,parent)
{
	m_content = content;
}
String16File::String16File(std::u16string content,std::string* path,int tokens)
	: File(path,tokens)
{
	m_content = content;
}
String16File::String16File(std::u16string content,char** path,int tokens)
	: File(path,tokens)
{
	m_content = content;
}
String16File::String16File(std::u16string content,TokenizedCString* path)
	: File(path)
{
	m_content = content;
}
String16File::String16File(std::u16string content,const char* path)
	: File(path)
{
	m_content = content;
}
String16File::String16File(std::u16string content,std::string path)
	: File(path)
{
	m_content = content;
}

String16File::~String16File() {
}

std::wstring String16File::GetWstring()
{
	return std::wstring((wchar_t*)m_content.c_str(),m_content.length());
}

void String16File::Serialize(FILE* handle) //This one won't end with '\0'
{
	const char16_t* path = m_content.c_str();
	const uint64_t pathsize = (uint64_t)m_content.length();
	File::Serialize(handle);
	fwrite(&pathsize,sizeof(uint64_t),1,handle);
	fwrite(path,sizeof(char16_t),pathsize,handle);
}

}