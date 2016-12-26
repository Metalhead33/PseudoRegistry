/* 
 * File:	 Element.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 11., 17:22
 */

#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include <vector>
#include <string>
#include <cstdio>
#include "Tokenizer.h"

namespace Structure {
class Directory;
class Element
{
	friend class Directory;
private:
	Directory* m_parent;
	std::string m_name;
	void __SetParent(Directory* setto);
public:
	virtual bool IsData() const = 0;
	virtual bool IsDirectory() const = 0;
	Directory* GetParent() const;
	std::string GetName() const;
	void SetName(std::string setto);
	void SetParent(Directory* setto);
	
	virtual ~Element();
	Element();
	Element(std::string name,Directory* parent);
	Element(std::string* path,int tokens);
	Element(char** path,int tokens);
	Element(TokenizedCString* path);
	Element(const char* path);
	Element(std::string path);
	
	std::string GetPath();
	virtual void Serialize(FILE* handle);
};

typedef std::vector<Element*> ElementContainer;
typedef ElementContainer::iterator ElementIterator;
}

#endif /* ELEMENT_HPP */

