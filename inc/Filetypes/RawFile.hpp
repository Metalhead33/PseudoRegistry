/* 
 * File:   RawFile.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 24., 21:03
 */

#ifndef RAWFILE_HPP
#define RAWFILE_HPP
#include "../File.hpp"
namespace Structure {
class RawFile : public File {
private:
	void* m_content;
	size_t m_size;
public:
	RawFile(size_t filesize,void* ptr,std::string name,Directory* parent);
	RawFile(size_t filesize,void* ptr,std::string* path,int tokens);
	RawFile(size_t filesize,void* ptr,char** path,int tokens);
	RawFile(size_t filesize,void* ptr,TokenizedCString* path);
	RawFile(size_t filesize,void* ptr,const char* path);
	RawFile(size_t filesize,void* ptr,std::string path);
	virtual ~RawFile();
	File::FileType GetFiletype() const { return File::RAW_DATA; }
	size_t GetSize() const { return m_size; }
	void* GetPointer() const { return m_content; }
	void* Allocate(size_t size);
	void* Callocate(size_t num,size_t size);
	void* Reallocate(size_t size);
	void Free();
	void* operator*() const { return m_content; }
	char operator[](int b) const { return ((char*)m_content)[b]; }
	virtual void Serialize(FILE* handle); // every variant must end with fputc('\0',handle); except the RawFile

};
}

#endif /* RAWFILE_HPP */

