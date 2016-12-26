/* 
 * File:   CustomFile.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 24., 18:43
 */

#ifndef CUSTOMFILE_HPP
#define CUSTOMFILE_HPP
#include "../File.hpp"
#include <cstdint>
#include <cstdio>
namespace Structure {
template <typename T,File::FileType type> class CustomFile : public File {
private:
	T m_content;
public:
	CustomFile(T content,std::string name,Directory* parent)
	: File(name,parent)
	{
		m_content = content;
	}
	CustomFile(T content,std::string* path,int tokens)
	: File(path,tokens)
	{
		m_content = content;
	}
	CustomFile(T content,char** path,int tokens)
	: File(path,tokens)
	{
		m_content = content;
	}
	CustomFile(T content,TokenizedCString* path)
	: File(path)
	{
		m_content = content;
	}
	CustomFile(T content,const char* path)
	: File(path)
	{
		m_content = content;
	}
	CustomFile(T content,std::string path)
	: File(path)
	{
		m_content = content;
	}
	virtual ~CustomFile()
	{
		
	}
	File::FileType GetFiletype() const { return type; }
	T GetContent() const { return m_content; }
	T* GetPointer() const { return &m_content; }
	void SetContent(T setto) { m_content = setto; }
	static size_t GetSize() { return sizeof(T); }
	T* operator*() const { return &m_content; }
	void Serialize(FILE* handle) // every variant must end with fputc('\0',handle); except the RawFile
	{
	File::Serialize(handle);
	fwrite(&m_content,sizeof(T),1,handle);
	fputc('\0',handle);
	}
};

#define CustomTemplateFile(F) template <class T> F CustomFile<T>
typedef CustomFile<bool,File::BOOL> BooleanFile;
typedef CustomFile<int8_t,File::SINT8> Int8File;
typedef CustomFile<uint8_t,File::UINT8> Uint8File;
typedef CustomFile<int64_t,File::SINT64> Int64File;
typedef CustomFile<uint64_t,File::UINT64> Uint64File;
typedef CustomFile<double,File::FLOAT> FloatFile;

}
#endif /* CUSTOMFILE_HPP */

