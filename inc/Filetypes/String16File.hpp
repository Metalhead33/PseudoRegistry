/* 
 * File:   String16File.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 26., 17:16
 */

#ifndef STRING16FILE_HPP
#define STRING16FILE_HPP
#include "../File.hpp"
#include <string>
namespace Structure {
class String16File : public File {
private:
	std::u16string m_content;
public:
	String16File(std::u16string content,std::string name,Directory* parent);
	String16File(std::u16string content,std::string* path,int tokens);
	String16File(std::u16string content,char** path,int tokens);
	String16File(std::u16string content,TokenizedCString* path);
	String16File(std::u16string content,const char* path);
	String16File(std::u16string content,std::string path);
	virtual ~String16File();
	File::FileType GetFiletype() const { return File::STRING16; }
	
	std::u16string GetContent() const { return m_content; }
	std::wstring GetWstring();
	void SetContent(std::u16string setto) { m_content = setto; }
	size_t GetSize() const { return m_content.size(); }
	size_t GetByteSize() const { return m_content.size() * sizeof(char16_t); }
	const char16_t* c_str() const { return m_content.c_str(); }
	const std::u16string* GetPointer() const { return &m_content; }
	void Serialize(FILE* handle); // This one won't end with '\0'
};
}
#endif /* STRING16FILE_HPP */

