#include <iostream>
#include <list>

//IMPORTANT NOTE: DLL file 'libstdc++-6.dll' MUST be included within the same directory as the executable
//Thomas Linssen

template<typename T>
struct DynamicList
{
private:
	std::list<T> lijst;
public:

	DynamicList(){}
	
	DynamicList(size_t size, const T& value)
	: lijst(std::list<T>(size, value)){}
	
	void Add(const T& value)
	{
		lijst.push_back(value);
	}
	
	void Insert(size_t index, const T& value)
	{
		typename std::list<T>::iterator it = lijst.begin();
		std::advance(it, index);
		*it = value;
	}
	
	void Remove(size_t index)
	{
		typename std::list<T>::iterator it = lijst.begin();
		std::advance(it, index);
		lijst.erase(it);
	}
	
	T Get(size_t index) const
	{
		typename std::list<T>::const_iterator it = lijst.begin();
		std::advance(it, index);
		return *it;
	}
	
	int Length() const
	{
		return lijst.size();
	}
	
	//Hier nog een 'Sort' functie toevoegen

	void Print() const
	{
		typename std::list<T>::const_iterator it;
		for (it = lijst.begin(); it != lijst.end(); it++)
		{
			std::cout << *it << " ";
		}
	}
};