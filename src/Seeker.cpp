#include "Seeker.hpp"
#include "Tokenizer.h"
#include "Global.h"
namespace Structure {
	
// SEEK ELEMENT
	
Element* SeekElement(std::string path)
{
        return SeekElement(path.c_str());
}
Element* SeekElement(const char* path)
{
        TokenizedCString* tokens = CopyTokenizeString(path,'\\');
        Element* elem = SeekElement(tokens);
        DestroyTokens(tokens);
        return elem;
}

Element* SeekElement(TokenizedCString* path)
{
        return SeekElement(path->tokenized_string,path->tokens);
}

Element* SeekElement(std::string* path,int tokens)
{
	Element* tmp_element = ROOT_DIRECTORY;
        IF_DEBUG(
		std::cout << "Beginning search for: ";
                for(int i = 0;i < tokens;++i)
		{
			std::cout << "\\" << path[i];
		}
		std::cout << std::endl;
        )
	for(int i = 0;i < tokens;++i)
	{
		IF_DEBUG(
			std::cout << "Current at: " << tmp_element->GetPath() << std::endl;
			std::cout << "Looking for: " << tmp_element->GetPath() << "\\" << path[i] << std::endl;
			)
		if(tmp_element->IsDirectory())
		{
			std::cout << tmp_element->GetPath() << " is a directory - the search continues." << std::endl;
			tmp_element = ((Directory*)tmp_element)->GetPElementByName(path[i]);
			if(!tmp_element) break;
		}
		else break;
	}
	if(!tmp_element)
	{
		IF_DEBUG(
			std::cout << "Did not find the element. Returning a nullpointer." << std::endl;
		)
		return 0;
	}
	if(tmp_element->GetName() == path[tokens-1])
	{
		IF_DEBUG(
			std::cout << "Found the element!" << std::endl;
		)
		return tmp_element;
	}
	else
	{
		IF_DEBUG(
			std::cout << "Did not find the element. Returning a nullpointer." << std::endl;
		)
		return 0;
	}
}

Element* SeekElement(char** path,int tokens)
{
	Element* tmp_element = ROOT_DIRECTORY;
        IF_DEBUG(
		std::cout << "Beginning search for: ";
                for(int i = 0;i < tokens;++i)
		{
			std::cout << "\\" << path[i];
		}
		std::cout << std::endl;
        )
	for(int i = 0;i < tokens;++i)
	{
		IF_DEBUG(
			std::cout << "Current at: " << tmp_element->GetPath() << std::endl;
			std::cout << "Looking for " << tmp_element->GetPath() << "\\" << path[i] << std::endl;
			)
		if(tmp_element->IsDirectory())
		{
			std::cout << tmp_element->GetPath() << " is a directory - the search continues." << std::endl;
			tmp_element = ((Directory*)tmp_element)->GetPElementByName((std::string)path[i]);
			if(!tmp_element) break;
		}
		else break;
	}
	if(!tmp_element)
	{
		IF_DEBUG(
			std::cout << "Did not find the element. Returning a nullpointer." << std::endl;
		)
		return 0;
	}
	if(tmp_element->GetName() == path[tokens-1])
	{
		IF_DEBUG(
			std::cout << "Found the element!" << std::endl;
		)
		return tmp_element;
	}
	else
	{
		IF_DEBUG(
			std::cout << "Did not find the element. Returning a nullpointer." << std::endl;
		)
		return 0;
	}
}
	
/*Element* SeekElement(std::string path)
{
	TokenizedCString tokens = TokenizeString(path.c_str(),'/');
	Element* tmp_element = ROOT_DIRECTORY;
	
	for(int i = 0;i < tokens.tokens;++i)
	{
		if(tmp_element->IsDirectory())
		{
			tmp_element = *(((Directory*)tmp_element)->GetElementByName(tokens.tokenized_string[i]));
		}
		else break;
	}
	if(tmp_element->GetName() == (std::string)tokens.tokenized_string[tokens.tokens-1]) return tmp_element;
	else return 0;
	DestroyTokens(&tokens);
}*/

// MKDIR

Directory* Mkdir(std::string* path,int tokens)
{
	Element* tmp_element = ROOT_DIRECTORY;
	Element* tmp_element2;
	for(int i = 0;i < tokens;++i)
	{
		if(tmp_element->IsDirectory())
		{
			tmp_element2 = ((Directory*)tmp_element)->GetPElementByName((std::string)path[i]);
			if(!tmp_element2)
			{
				tmp_element2 = new Directory(path[i],(Directory*)tmp_element);
			}
			tmp_element = tmp_element2;
		}
		else return 0;
	}
	if(tmp_element->GetName() == path[tokens-1]) return (Directory*)tmp_element;
	else return 0;
}
Directory* Mkdir(char** path,int tokens)
{
	Element* tmp_element = ROOT_DIRECTORY;
	Element* tmp_element2;
	for(int i = 0;i < tokens;++i)
	{
		if(tmp_element->IsDirectory())
		{
			tmp_element2 = ((Directory*)tmp_element)->GetPElementByName((std::string)path[i]);
			if(!tmp_element2)
			{
				tmp_element2 = new Directory((std::string)path[i],(Directory*)tmp_element);
			}
			tmp_element = tmp_element2;
		}
		else return 0;
	}
	if(tmp_element->GetName() == path[tokens-1]) return (Directory*)tmp_element;
	else return 0;
}
Directory* Mkdir(TokenizedCString* path)
{
        return Mkdir(path->tokenized_string,path->tokens);
}
Directory* Mkdir(const char* path)
{
        TokenizedCString* tokens = CopyTokenizeString(path,'\\');
        Directory* elem = Mkdir(tokens);
        DestroyTokens(tokens);
        return elem;
}
Directory* Mkdir(std::string path)
{
        return Mkdir(path.c_str());
}

}