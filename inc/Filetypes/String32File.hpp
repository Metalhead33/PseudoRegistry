/* 
 * File:   String32File.hpp
 * Author: metalhead33
 *
 * Created on 2032. december 26., 17:52
 */

#ifndef STRING32FILE_HPP
#define STRING32FILE_HPP
#include "../File.hpp"
#include <string>
namespace Structure {
class String32File : public File {
private:
	std::u32string m_content;
public:
	String32File(std::u32string content,std::string name,Directory* parent);
	String32File(std::u32string content,std::string* path,int tokens);
	String32File(std::u32string content,char** path,int tokens);
	String32File(std::u32string content,TokenizedCString* path);
	String32File(std::u32string content,const char* path);
	String32File(std::u32string content,std::string path);
	virtual ~String32File();
	File::FileType GetFiletype() const { return File::STRING32; }
	
	std::u32string GetContent() const { return m_content; }
	std::wstring GetWstring();
	void SetContent(std::u32string setto) { m_content = setto; }
	size_t GetSize() const { return m_content.size(); }
	size_t GetByteSize() const { return m_content.size() * sizeof(char32_t); }
	const char32_t* c_str() const { return m_content.c_str(); }
	const std::u32string* GetPointer() const { return &m_content; }
	void Serialize(FILE* handle); // This one won't end with '\0'
};
}
#endif /* STRING32FILE_HPP */

