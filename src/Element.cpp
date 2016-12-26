/* 
 * File:   Element.cpp
 * Author: metalhead33
 * 
 * Created on 2016. december 11., 17:22
 */

#include "Element.hpp"
#include "Directory.hpp"
#include "Global.h"
#include "Seeker.hpp"

namespace Structure {

Element::Element()
{
        IF_DEBUG(
                std::cout << m_name << "[" << this << "] : " << "Initiating element with NO_NAME and 0 parent." << std::endl;
        )
	m_name = "NO_NAME";
	SetParent(0);
        IF_DEBUG(
                std::cout << m_name << "[" << this << "] : " << "Succesful initialization! Address is at: " << this << "." << std::endl;
        )
}

Element::Element(std::string name, Directory* parent) {
        IF_DEBUG(
                std::cout << m_name << "[" << this << "] : " << "Initiating the name " << name << " and the parent at " << parent << "." << std::endl;
        )
	m_name = name;
        m_parent = 0;
	SetParent(parent);
        IF_DEBUG(
                std::cout << m_name << "[" << this << "] : " << "Succesful initialization! Address is at: " << this << "." << std::endl;
        )
}

Element::~Element() {
        IF_DEBUG(
                std::cout << m_name << "[" << this << "] : " << "De-initializing element with the name \"" << m_name << " and address " << this << "." << std::endl;
        )
	if(m_parent) m_parent->__RemoveChild(this);
}

Element::Element(std::string* path,int tokens)
{
	m_name = path[tokens-1];
        m_parent = 0;
	if(tokens>1) SetParent(Mkdir(path,tokens-1));
	else SetParent(ROOT_DIRECTORY);
	
}
Element::Element(char** path,int tokens)
{
	m_name = (std::string)path[tokens-1];
        m_parent = 0;
	if(tokens>1) SetParent(Mkdir(path,tokens-1));
	else SetParent(ROOT_DIRECTORY);
}

Element::Element(TokenizedCString* path)
{
	m_name = (std::string)path->tokenized_string[path->tokens - 1];
        m_parent = 0;
	if(path->tokens >1) SetParent(Mkdir(path->tokenized_string,path->tokens -1));
	else SetParent(ROOT_DIRECTORY);
}
Element::Element(const char* path)
{
        TokenizedCString* tokens = CopyTokenizeString(path,'\\');
	m_name = (std::string)tokens->tokenized_string[tokens->tokens - 1];
        m_parent = 0;
	if(tokens->tokens >1) SetParent(Mkdir(tokens->tokenized_string,tokens->tokens -1));
	else SetParent(ROOT_DIRECTORY);
        DestroyTokens(tokens);
}

Element::Element(std::string path)
{
        TokenizedCString* tokens = CopyTokenizeString(path.c_str(),'\\');
	m_name = (std::string)tokens->tokenized_string[tokens->tokens - 1];
        m_parent = 0;
	if(tokens->tokens >1) SetParent(Mkdir(tokens->tokenized_string,tokens->tokens -1));
	else SetParent(ROOT_DIRECTORY);
        DestroyTokens(tokens);
}

Directory* Element::GetParent() const
{
	return m_parent;
}

void Element::__SetParent(Directory* setto)
{
        IF_DEBUG(
                std::cout << m_name << "[" << this << "] : " << "Setting the parent of Elemet at " << this << " from " << m_parent << " to " << setto << std::endl;
        )
	m_parent = setto;
}

std::string Element::GetName() const
{
	return m_name;
}

void Element::SetName(std::string setto)
{
        IF_DEBUG(
                std::cout << m_name << "[" << this << "] : " << "Setting the name of Elemet at " << this << " from " << m_name << " to " << setto << std::endl;
        )
	m_name = setto;
}

void Element::SetParent(Directory* setto)
{
	if(m_parent) m_parent->__RemoveChild(this);
	if(setto) setto->__AddChild(this);
	this->__SetParent(setto);
}
std::string Element::GetPath()
{
	/*if(m_parent) return m_parent->GetPath() + "\\" + m_name;
	else return m_name;*/
	if(!m_parent || m_parent == ROOT_DIRECTORY) return m_name;
	else return m_parent->GetPath() + "\\" + m_name;
}
void Element::Serialize(FILE* handle)
{
	const std::string tmp_path = GetPath();
	const char* path = tmp_path.c_str();
	const size_t pathsize = tmp_path.length();
	fwrite(path,1,pathsize,handle);
	fputc('\n',handle);
}

}