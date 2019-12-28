#pragma once
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

	Lista<T>& operator+=(const T& data);

	T& operator[](int index);
	const T& operator[](int index) const;

	Lista<T>& operator()(int index);

	~Lista();
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
	void remove(Elem*& prev, Elem*& curr);

	Elem* head = nullptr;
	Elem* tail = nullptr;
	int n = 0;
};

template<typename T>
inline Lista<T>::Lista(const Lista& list)
{
	copy(list);
}

template<typename T>
inline Lista<T>::Lista(Lista&& list)
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
inline Lista<T>& Lista<T>::operator+=(const T& data)
{
	tail = ((head == nullptr) ? head : tail->next) = new Elem(data);
	n++;

	return *this;
}

template<typename T>
inline T& Lista<T>::operator[](int index)
{
	if (index < 0 || index >= n)
		throw OutOfRangeException(index, n);

	Elem* curr = head;
	for (int i = 0; i != index; i++, curr = curr->next);

	return curr->data;
}

template<typename T>
inline const T& Lista<T>::operator[](int index) const
{
	if (index < 0 || index >= n)
		throw OutOfRangeException(index, n);

	Elem* curr = head;
	for (int i = 0; i != index; i++, curr = curr->next);

	return curr->data;
}

template<typename T>
inline Lista<T>& Lista<T>::operator()(int index)
{
	if (index < 0 || index >= n)
		throw OutOfRangeException(index, n);

	Elem* curr = head;
	Elem* prev = nullptr;
	for (int i = 0; i != index; i++)
	{
		prev = curr;
		curr = curr->next;
	}

	remove(prev, curr);

	return *this;
}

template<typename T>
inline Lista<T>::~Lista()
{
	destroy();
}

template<typename T>
inline void Lista<T>::destroy()
{
	Elem* curr = head;
	while (curr != nullptr)
	{
		head = head->next;
		delete curr;
		curr = head;
	}

	head = nullptr;
	tail = nullptr;
	n = 0;
}

template<typename T>
inline void Lista<T>::copy(const Lista<T>& list)
{
	n = list.n;
	for (Elem* curr = list.head; curr != nullptr; curr = curr->next)
		tail = ((head == nullptr) ? head : tail->next) = new Elem(*curr);
}

template<typename T>
inline void Lista<T>::move(Lista<T>& list)
{
	n = list.n;
	head = list.head;
	tail = list.tail;

	list.head = list.tail = nullptr;
}

template<typename T>
inline void Lista<T>::remove(Elem*& prev, Elem*& curr)
{
	if (curr == head)
		head = head->next;
	if (curr == tail)
		tail = prev;

	if (prev != nullptr)
		prev->next = curr->next;
	curr->next = nullptr;
	delete curr;
	n--;
}
