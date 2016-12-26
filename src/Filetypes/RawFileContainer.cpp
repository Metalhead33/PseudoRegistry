/* 
 * File:   RawFileContainer.cpp
 * Author: metalhead33
 * 
 * Created on 2016. december 24., 22:22
 */

#include "RawFileContainer.hpp"

namespace Structure {
template <typename T> RawFileContainer<T>::RawFileContainer(RawFile* file)
{
	m_container = file;
	object_number = file->GetSize() / sizeof(T);
	object_pointer = (T*)(file->GetPointer());
}

template <typename T> RawFileContainer<T>::RawFileContainer(size_t num,T* ptr,std::string name,Directory* parent)
	: m_container(new RawFile(num*sizeof(T),ptr,name,parent))
{
	object_number = num;
	object_pointer = (T*)(m_container->GetPointer());
}

template <typename T> RawFileContainer<T>::RawFileContainer(size_t num,T* ptr,std::string* path,int tokens)
	: m_container(new RawFile(num*sizeof(T),ptr,path,tokens))
{
	object_number = num;
	object_pointer = (T*)(m_container->GetPointer());
}
template <typename T> RawFileContainer<T>::RawFileContainer(size_t num,T* ptr,char** path,int tokens)
	: m_container(new RawFile(num*sizeof(T),ptr,path,tokens))
{
	object_number = num;
	object_pointer = (T*)(m_container->GetPointer());
}
template <typename T> RawFileContainer<T>::RawFileContainer(size_t num,T* ptr,TokenizedCString* path)
	: m_container(new RawFile(num*sizeof(T),ptr,path))
{
	object_number = num;
	object_pointer = (T*)(m_container->GetPointer());
}
template <typename T> RawFileContainer<T>::RawFileContainer(size_t num,T* ptr,const char* path)
	: m_container(new RawFile(num*sizeof(T),ptr,path))
{
	object_number = num;
	object_pointer = (T*)(m_container->GetPointer());
}
template <typename T> RawFileContainer<T>::RawFileContainer(size_t num,T* ptr,std::string path)
	: m_container(new RawFile(num*sizeof(T),ptr,path))
{
	object_number = num;
	object_pointer = (T*)(m_container->GetPointer());
}

template <typename T> RawFileContainer<T>::RawFileContainer(const RawFileContainer<T>& orig) {
	m_container = orig.GetContainer();
	object_pointer = orig.GetObjectPointer();
	object_number = orig.GetObjectNumber();
}
template <typename T> RawFileContainer<T>::RawFileContainer(const RawFileContainer<T>* orig) {
	m_container = orig->GetContainer();
	object_pointer = orig->GetObjectPointer();
	object_number = orig->GetObjectNumber();
}

template <typename T> RawFileContainer<T>::~RawFileContainer() {
}

template <typename T> T* RawFileContainer<T>::Allocate(size_t new_number)
{
	if((object_pointer = (T*)(m_container->Callocate(new_number,sizeof(T))))) object_number = new_number;
	else object_number = 0;
	return object_pointer;
}
template <typename T> T* RawFileContainer<T>::Reallocate(size_t new_number)
{
	if((object_pointer = (T*)(m_container->Reallocate(new_number*sizeof(T))))) object_number = new_number;
	else object_number = 0;
	return object_pointer;
}
template <typename T> void RawFileContainer<T>::Free()
{
	m_container->Free();
	object_number = 0;
	object_pointer = 0;
}

}