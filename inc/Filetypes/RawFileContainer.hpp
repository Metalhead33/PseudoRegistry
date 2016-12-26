/* 
 * File:   RawFileContainer.hpp
 * Author: metalhead33
 *
 * Created on 2016. december 24., 22:22
 */

#ifndef RAWFILECONTAINER_HPP
#define RAWFILECONTAINER_HPP
#include "RawFile.hpp"
namespace Structure {
template <typename T> class RawFileContainer {
private:
	RawFile* m_container;
	T* object_pointer;
	size_t object_number;
public:
	RawFile* GetContainer() const { return m_container; }
	T* GetObjectPointer() const { return object_pointer; }
	size_t GetObjectNumber() const { return object_number; }
	size_t GetTypeSize() const { return sizeof(T); }
	RawFileContainer(RawFile* file);
	RawFileContainer(size_t num=0,T* ptr=0,std::string name="NO_NAME",Directory* parent=0);
	RawFileContainer(size_t num,T* ptr,std::string* path,int tokens);
	RawFileContainer(size_t num,T* ptr,char** path,int tokens);
	RawFileContainer(size_t num,T* ptr,TokenizedCString* path);
	RawFileContainer(size_t num,T* ptr,const char* path);
	RawFileContainer(size_t num,T* ptr,std::string path);
	RawFileContainer(const RawFileContainer& orig);
	RawFileContainer(const RawFileContainer* orig);
	virtual ~RawFileContainer();
	
	T* Allocate(size_t new_number);
	T* Reallocate(size_t new_number);
	void Free();
};
}
#endif /* RAWFILECONTAINER_HPP */

