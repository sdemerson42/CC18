#pragma once

#include <vector>
#include <algorithm>

template<typename T>
class AutoList
{
public:
	virtual ~AutoList()
	{
		auto p = static_cast<T*>(this);
		auto ref = std::find(begin(m_refVector), end(m_refVector), p);
		if (ref != end(m_refVector))
		{
			m_refVector.erase(ref);
		}
	}
	static auto size() 
	{
		return m_refVector.size();
	}
	static T *get(typename std::vector<T*>::size_type index)
	{
		return m_refVector[index];
	}
protected:
	AutoList()
	{
		m_refVector.push_back(static_cast<T*>(this));
	}
private:
	static std::vector<T*> m_refVector;
};

template<typename T>
std::vector<T*> AutoList<T>::m_refVector;