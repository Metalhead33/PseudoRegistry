/* 
 * File:   Unserialize.cpp
 * Author: metalhead33
 * 
 * Created on 2016. december 25., 19:06
 */

#include "Unserialize.hpp"
#include "Seeker.hpp"
#include "Global.h"
namespace Structure {
namespace Io {

void Unserialize(FILE* handle)
{
	while(true)
	{
		char buf[1024];
		char tmp;
		int i = 0;
		int16_t type;
		Element* temp_elem;
		for(;(buf[i] = fgetc(handle)) != EOF && buf[i] != '\n' && buf[i] != '\0';++i );
		buf[i] = '\0';
		fread(&type,sizeof(int16_t),1,handle);
		if(type < 0)
		{
			IF_DEBUG(
				std::cout << "Creating the directory: " << buf << std::endl;
				)
			Mkdir((std::string)buf);
			fseek(handle,1,SEEK_CUR); // Skip the following zero.
		}
		else
		{
			temp_elem = SeekElement(buf);
			if(temp_elem) delete temp_elem; // If the file already exists, we overwrite it.
			switch((File::FileType)type) {
				case File::BOOL :
				{
					bool temp_buffer;
					fread(&temp_buffer,sizeof(bool),1,handle);
					temp_elem = new BooleanFile(temp_buffer,(std::string)buf);
					IF_DEBUG(
						std::cout << "Creating a boolean with the value \"" << temp_buffer << "\" at the path " << temp_elem->GetPath()  << std::endl;
						)
					fseek(handle,1,SEEK_CUR); // Skip the following zero.
					break;
				}
				case File::FLOAT :
				{
					double temp_buffer;
					fread(&temp_buffer,sizeof(double),1,handle);
					temp_elem = new FloatFile(temp_buffer,(std::string)buf);
					IF_DEBUG(
						std::cout << "Creating a double with the value \"" << temp_buffer << "\" at the path " << temp_elem->GetPath()  << std::endl;
						)
					fseek(handle,1,SEEK_CUR); // Skip the following zero.
					break;
				}
				case File::UINT8 :
				{
					uint8_t temp_buffer;
					fread(&temp_buffer,sizeof(uint8_t),1,handle);
					temp_elem = new Uint8File(temp_buffer,(std::string)buf);
					IF_DEBUG(
						std::cout << "Creating an unsigned char with the value \"" << temp_buffer << "\" at the path " << temp_elem->GetPath()  << std::endl;
						)
					fseek(handle,1,SEEK_CUR); // Skip the following zero.
					break;
				}
				case File::SINT8 :
				{
					int8_t temp_buffer;
					fread(&temp_buffer,sizeof(int8_t),1,handle);
					temp_elem = new Int8File(temp_buffer,(std::string)buf);
					IF_DEBUG(
						std::cout << "Creating a signed char with the value \"" << temp_buffer << "\" at the path " << temp_elem->GetPath()  << std::endl;
						)
					fseek(handle,1,SEEK_CUR); // Skip the following zero.
					break;
				}
				case File::UINT64 :
				{
					uint64_t temp_buffer;
					fread(&temp_buffer,sizeof(uint64_t),1,handle);
					temp_elem = new Uint64File(temp_buffer,(std::string)buf);
					IF_DEBUG(
						std::cout << "Creating an unsigned long long with the value \"" << temp_buffer << "\" at the path " << temp_elem->GetPath()  << std::endl;
						)
					fseek(handle,1,SEEK_CUR); // Skip the following zero.
					break;
				}
				case File::SINT64 :
				{
					int64_t temp_buffer;
					fread(&temp_buffer,sizeof(int64_t),1,handle);
					temp_elem = new Int64File(temp_buffer,(std::string)buf);
					IF_DEBUG(
						std::cout << "Creating a signed long long with the value \"" << temp_buffer << "\" at the path " << temp_elem->GetPath()  << std::endl;
						)
					fseek(handle,1,SEEK_CUR); // Skip the following zero.
					break;
				}
				case File::RAW_DATA :
				{
					uint64_t temp_buffer;
					fread(&temp_buffer,sizeof(uint64_t),1,handle);
					char* buf2 = (char*)malloc(temp_buffer);
					fread(buf2,sizeof(char),temp_buffer,handle);
					temp_elem = new RawFile(temp_buffer,buf2,(std::string)buf);
					IF_DEBUG(
						std::cout << "Creating a byte array with the size " << temp_buffer << " at the path " << temp_elem->GetPath()  << std::endl;
						)
					break;
				}
				case File::STRING :
				{
					int j;char* buf2;
					for(j = 0;fgetc(handle) != 0;++j);
					buf2 = (char*)malloc(j+1);
					fseek(handle,-1 * (j+1),SEEK_CUR); // Skip the following zero.
					for(j = 0;(buf2[j] = fgetc(handle)) != 0;++j);
					buf2[j] = 0;
					temp_elem = new StringFile((std::string)buf2,(std::string)buf);
					free(buf2);
					IF_DEBUG(
						std::cout << "Creating a string with the length " << j << " at the path " << temp_elem->GetPath()  << std::endl;
						)
					fseek(handle,1,SEEK_CUR); // Skip the following zero.
					break;
				}
				case File::STRING16 :
				{
					uint64_t temp_buffer;
					fread(&temp_buffer,sizeof(uint64_t),1,handle);
					char16_t* buf2 = (char16_t*)malloc(temp_buffer * sizeof(char16_t));
					fread(buf2,sizeof(char16_t),temp_buffer,handle);
					std::u16string temp_str(buf2,temp_buffer);
					temp_elem = new String16File(temp_str,(std::string)buf);
					free(buf2);
					// Do NOT the following (non-existent) zero.
					break;
				}
				case File::STRING32 :
				{
					uint64_t temp_buffer;
					fread(&temp_buffer,sizeof(uint64_t),1,handle);
					char32_t* buf2 = (char32_t*)malloc(temp_buffer * sizeof(char32_t));
					fread(buf2,sizeof(char32_t),temp_buffer,handle);
					std::u32string temp_str(buf2,temp_buffer);
					temp_elem = new String32File(temp_str,(std::string)buf);
					free(buf2);
					// Do NOT the following (non-existent) zero.
					break;
				}
			}
		}
		if(fgetc(handle) == EOF ) break; // Make sure it ain't the end of file
		else fseek(handle,-1,SEEK_CUR);
	}
}

}
}