/* 
 * File:   RawFile.cpp
 * Author: metalhead33
 * 
 * Created on 2016. december 24., 21:03
 */

#include "RawFile.hpp"
#include <cstdlib>
#include <cstdint>
namespace Structure {

RawFile::RawFile(size_t filesize,void* ptr,std::string name,Directory* parent)
	: File(name,parent)
{
	m_size = filesize;
	if(ptr) m_content = ptr;
	else {
	if(filesize) m_content = malloc(filesize);
	else m_content = 0;
	}
}
RawFile::RawFile(size_t filesize,void* ptr,std::string* path,int tokens)
	: File(path,tokens)
{
	m_size = filesize;
	if(ptr) m_content = ptr;
	else {
	if(filesize) m_content = malloc(filesize);
	else m_content = 0;
	}
}
RawFile::RawFile(size_t filesize,void* ptr,char** path,int tokens)
	: File(path,tokens)
{
	m_size = filesize;
	if(ptr) m_content = ptr;
	else {
	if(filesize) m_content = malloc(filesize);
	else m_content = 0;
	}
}
RawFile::RawFile(size_t filesize,void* ptr,TokenizedCString* path)
	: File(path)
{
	m_size = filesize;
	if(ptr) m_content = ptr;
	else {
	if(filesize) m_content = malloc(filesize);
	else m_content = 0;
	}
}
RawFile::RawFile(size_t filesize,void* ptr,const char* path)
	: File(path)
{
	m_size = filesize;
	if(ptr) m_content = ptr;
	else {
	if(filesize) m_content = malloc(filesize);
	else m_content = 0;
	}
}
RawFile::RawFile(size_t filesize,void* ptr,std::string path)
	: File(path)
{
	m_size = filesize;
	if(ptr) m_content = ptr;
	else {
	if(filesize) m_content = malloc(filesize);
	else m_content = 0;
	}
}

RawFile::~RawFile() {
	if(m_content) free(m_content);
}

void* RawFile::Allocate(size_t size)
{
	if((m_content = malloc(size))) m_size = size;
	else m_size = 0;
	return m_content;
}
void* RawFile::Callocate(size_t num,size_t size)
{
	if((m_content = calloc(num,size))) m_size = num*size;
	else m_size = 0;
	return m_content;
}
void* RawFile::Reallocate(size_t size)
{
	if((m_content = realloc(m_content,size))) m_size = size;
	else m_size = 0;
	return m_content;
}
void RawFile::Free()
{
	if(m_content) free(m_content);
	m_content = 0;
	m_size = 0;
}
void RawFile::Serialize(FILE* handle) // every variant must end with fputc('\0',handle); except the RawFile
{
	const uint64_t size = (uint64_t)m_size;
	File::Serialize(handle);
	fwrite(&size,sizeof(uint64_t),1,handle);
	fwrite(m_content,1,m_size,handle);
}

}
