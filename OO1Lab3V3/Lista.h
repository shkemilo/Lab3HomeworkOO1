#pragma once
#include <iostream>
#include "Exceptions.h"

template<typename T>
class Lista
{
public:
	Lista() = default;
	Lista(const Lista<T>& list);
	Lista(Lista<T>&& list);

	Lista<T>& operator=(const Lista<T>& list);
	Lista<T>& operator=(Lista<T>&& list);

	int Count() const;

	Lista<T>& AddElement(const T& data);

	void Begin() const;

	void Advance() const;

	bool CurrentExsist() const;

	T& Current();

	const T& Current() const;

	void RemoveCurr();

	~Lista();

	friend std::ostream& operator<<(std::ostream& os, const Lista<T>& list)
	{
		for (list.Begin(); list.CurrentExsist(); list.Advance())
			os << list.Current() << std::endl;

		return os;
	}

private:
	struct Elem
	{
		Elem(const T& data) : data(data) { }

		T data;
		Elem* next = nullptr;
	};

	void destroy();
	void copy(const Lista<T>& list);
	void move(Lista<T>& list);

	mutable Elem* curr = nullptr;
	mutable Elem* prev = nullptr;
	Elem* head = nullptr;
	Elem* tail = nullptr;
	int n = 0;
};

template<typename T>
inline Lista<T>::Lista(const Lista<T>& list)
{
	copy(list);
}

template<typename T>
inline Lista<T>::Lista(Lista<T>&& list)
{
	move(list);
}

template<typename T>
inline Lista<T>& Lista<T>::operator=(const Lista<T>& list)
{
	if (this != &list)
	{
		destroy();
		copy(list);
	}

	return *this;
}

template<typename T>
inline Lista<T>& Lista<T>::operator=(Lista<T>&& list)
{
	if (this != &list)
	{
		destroy();
		move(list);
	}

	return *this;
}

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

template<typename T>
inline Lista<T>::~Lista()
{
	destroy();
}

template<typename T>
inline void Lista<T>::destroy()
{
	for (Begin(); CurrentExsist(); RemoveCurr());

	head = tail = prev = curr = nullptr;
}

template<typename T>
inline void Lista<T>::copy(const Lista<T>& list)
{
	for (list.Begin(); list.CurrentExsist(); list.Advance())
		AddElement(list.Current());

	curr = prev = nullptr;
}

template<typename T>
inline void Lista<T>::move(Lista<T>& list)
{
	n = list.n;
	head = list.head;
	tail = list.tail;

	curr = prev = list.head = list.tail = nullptr;
}
