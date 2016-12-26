/* 
 * File:	 Directory.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 11., 17:25
 */

#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP
#include "Element.hpp"
namespace Structure {
	
class Directory : public Element
{
	friend class Element;
private:
	ElementContainer children;
	Element* __RemoveChild(ElementIterator elem);
	Element* __RemoveChild(std::string name);
	Element* __RemoveChild(Element* elem);
	Element* __AddChild(Element* elem);
public:
	bool IsData() const { return false; }
	bool IsDirectory() const { return true; }
	ElementIterator GetIElementByName(std::string name);
	ElementIterator GetIElementByAddr(Element* elem);
	Element* GetPElementByName(std::string name);
	Element* GetPElementByAddr(Element* elem);
	void RemoveChild(std::string name);
	void RemoveChild(Element* elem);
	void AddChild(Element* elem);
	
	Directory(std::string name,Directory* parent);
	~Directory();
	Directory(std::string* path,int tokens);
	Directory(char** path,int tokens);
	Directory(TokenizedCString* path);
	Directory(const char* path);
	Directory(std::string path);
	void Serialize(FILE* handle);
};
extern Directory* ROOT_DIRECTORY;

//Directory* ROOT_DIRECTORY;

}

#endif /* DIRECTORY_HPP */

