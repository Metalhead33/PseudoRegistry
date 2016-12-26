/* 
 * File:   File.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 23., 18:12
 */

#ifndef FILE_HPP
#define FILE_HPP
#include "Element.hpp"
namespace Structure {

	
class File : public Element {
public:
	File(std::string name,Directory* parent);
	File(std::string* path,int tokens);
	File(char** path,int tokens);
	File(TokenizedCString* path);
	File(const char* path);
	File(std::string path);
	virtual ~File();
	
	enum FileType {
		DUMMY,
		BOOL,
		UINT8,
		SINT8,
		UINT64,
		SINT64,
		FLOAT,
		STRING,
		STRING16,
		STRING32,
		RAW_DATA,
		FUNCTION,
		CUSTOM
	};
	
	bool IsData() const { return true; }
	bool IsDirectory() const { return false; }
	virtual File::FileType GetFiletype() const { return File::DUMMY; }
	virtual void Serialize(FILE* handle); // every variant must end with fputc('\0',handle); except the RawFile
private:

};

}
#endif /* FILE_HPP */

