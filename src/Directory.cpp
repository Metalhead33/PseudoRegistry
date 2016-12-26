/* 
 * File:   Directory.cpp
 * Author: metalhead33
 * 
 * Created on 2016. december 11., 17:25
 */

#include "Directory.hpp"
#include "Global.h"
#include <exception>
namespace Structure {
Directory::Directory(std::string name, Directory* parent)
	: Element(name,parent)
{
	
}
Directory::Directory(std::string* path,int tokens)
	: Element(path,tokens)
{
	
}
Directory::Directory(char** path,int tokens)
	: Element(path,tokens)
{
	
}
Directory::Directory(TokenizedCString* path)
	: Element(path)
{
	
}
Directory::Directory(const char* path)
	: Element(path)
{
	
}
Directory::Directory(std::string path)
	: Element(path)
{
	
}

Directory::~Directory()
{
        IF_DEBUG(
                std::cout << this->GetName() << "[" << this << "] : " << "Removing all children of the directory before deinitalizing." << std::endl;
        )
	ElementIterator it;
	for(it=children.begin();it != children.end();++it)
	{
		(*it)->__SetParent(0);
	}
}

ElementIterator Directory::GetIElementByName(std::string name)
{
	ElementIterator it;
	for(it=children.begin();it != children.end();++it)
	{
		if( (*it)->GetName() == name)
		{
			return it;
		}
	}
	throw -1;
}
ElementIterator Directory::GetIElementByAddr(Element* elem)
{
	ElementIterator it;
	for(it=children.begin();it != children.end();++it)
	{
		if( (*it) == elem)
		{
			return it;
		}
	}
	throw -1;
}

Element* Directory::GetPElementByName(std::string name)
{
	try {
		return *(GetIElementByName(name));
	} catch(int i)
	{
		return 0;
	}
}
Element* Directory::GetPElementByAddr(Element* elem)
{
	try {
	return *(GetIElementByAddr(elem));
	} catch(int i)
	{
		return 0;
	}
}

// HIDDEN FUNCTIONS NEVER TO BE USED

Element* Directory::__RemoveChild(ElementIterator elem)
{
        IF_DEBUG(
                std::cout << this->GetName() << "[" << this << "] : " << "Removing the child at" << *elem << " named " << (*elem)->GetName() << std::endl;
        )
	Element* tmp = (*elem);
	children.erase(elem);
	return tmp;
}
Element* Directory::__RemoveChild(std::string name)
{
	return __RemoveChild(GetIElementByName(name));
}

Element* Directory::__RemoveChild(Element* elem)
{
	return __RemoveChild(GetIElementByAddr(elem));
}
Element* Directory::__AddChild(Element* elem)
{
        IF_DEBUG(
                std::cout << this->GetName() << "[" << this << "] : " << "Adding child with the name " << elem->GetName() << " and address " << elem << " to the directory." << std::endl;
        )
	children.push_back(elem);
	return elem;
}

// USABLE VERSIONS

void Directory::RemoveChild(std::string name)
{
	__RemoveChild(name)->__SetParent(0);
}
void Directory::RemoveChild(Element* elem)
{
	__RemoveChild(elem)->__SetParent(0);
}
void Directory::AddChild(Element* elem)
{
	elem->SetParent(0);
	__AddChild(elem)->__SetParent(this);
}
void Directory::Serialize(FILE* handle)
{
	if(this != ROOT_DIRECTORY) {
	const int16_t type = -1;
	Element::Serialize(handle);
	fwrite(&type,sizeof(int16_t),1,handle);
	fputc('\0',handle); }
	ElementIterator it;
	for(it=children.begin();it != children.end();++it) (*it)->Serialize(handle);
}

}