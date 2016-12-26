/* 
 * File:   StringFile.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 23., 19:22
 */

#ifndef STRINGFILE_HPP
#define STRINGFILE_HPP
#include "../File.hpp"
namespace Structure {
class StringFile : public File {
private:
	std::string m_content;
public:
	StringFile(std::string content,std::string name,Directory* parent);
	StringFile(std::string content,std::string* path,int tokens);
	StringFile(std::string content,char** path,int tokens);
	StringFile(std::string content,TokenizedCString* path);
	StringFile(std::string content,const char* path);
	StringFile(std::string content,std::string path);
	virtual ~StringFile();
	File::FileType GetFiletype() const { return File::STRING; }
	
	std::string GetContent() const { return m_content; }
	void SetContent(std::string setto) { m_content = setto; }
	size_t GetSize() const { return m_content.size(); }
	const char* c_str() const { return m_content.c_str(); }
	const std::string* GetPointer() const { return &m_content; }
	std::string operator+(StringFile* b);
	std::string operator+=(StringFile* b);
	std::string operator+(std::string b);
	std::string operator+=(std::string b);
	std::string operator+(const char* b);
	std::string operator+=(const char* b);
	std::string operator=(std::string b);
	std::string* operator*();
	void Serialize(FILE* handle); // every variant must end with fputc('\0',handle);
};
}
#endif /* STRINGFILE_HPP */

