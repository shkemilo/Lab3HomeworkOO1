#pragma once
#include "Exceptions.h"

template<typename T>
class Lista
{
public:
	Lista() = default;
	Lista(const Lista<T>&) = delete;
	Lista(Lista<T>&&) = delete;

	Lista<T>& operator=(const Lista<T>&) = delete;
	Lista<T>& operator=(Lista<T>&&) = delete;

	int Count() const;

	Lista<T>& AddElement(const T& data);

	void Begin() const;

	void Advance() const;

	bool CurrentExsist() const;

	T& Current();

	const T& Current() const;

	void RemoveCurr();

	~Lista();

private:
	struct Elem
	{
		Elem(const T& data) : data(data) { }

		T data;
		Elem* next = nullptr;
	};

	mutable Elem* curr = nullptr;
	mutable Elem* prev = nullptr;
	Elem* head = nullptr;
	Elem* tail = nullptr;
	int n = 0;
};

template<typename T>
inline int Lista<T>::Count() const
{
	return n;
}

template<typename T>
inline Lista<T>& Lista<T>::AddElement(const T& data)
{
	tail = ((head == nullptr) ? head : tail->next) = new Elem(data);
	n++;
	return *this;
}

template<typename T>
inline void Lista<T>::Begin() const
{
	curr = head;
	prev = nullptr;
}

template<typename T>
inline void Lista<T>::Advance() const
{
	if (!CurrentExsist())
		return;

	prev = curr;
	curr = curr->next;
}

template<typename T>
inline bool Lista<T>::CurrentExsist() const
{
	return curr != nullptr;
}

template<typename T>
inline T& Lista<T>::Current()
{
	if (!CurrentExsist())
		throw IteratorException();

	return curr->data;
}

template<typename T>
inline const T& Lista<T>::Current() const
{
	if (!CurrentExsist())
		throw IteratorException();

	return curr->data;
}

template<typename T>
inline void Lista<T>::RemoveCurr()
{
	{
		if (!CurrentExsist())
			throw IteratorException();

		if (prev == nullptr)
			head = head->next;
		else
			prev->next = curr->next;

		curr->next = nullptr;
		delete curr;
		n--;

		if (prev == nullptr)
			curr = head;
		else
			curr = prev->next;
	}
}

template<typename T>
inline Lista<T>::~Lista()
{
	for (Begin(); CurrentExsist();)
		RemoveCurr();

	head = tail = prev = curr = nullptr;
}
