#pragma once
#include <cstddef>

namespace ft 
{
	template<typename T>
	class RandomAccessIterator {
	private:
		T* m_ptr;
	public:
		typedef T 									value_type;
		typedef T& 									reference;
		typedef T* 									pointer;
		typedef ptrdiff_t 							difference_type;
		typedef ft::random_access_iterator_tag		iterator_category;

		RandomAccessIterator(pointer ptr = nullptr) : m_ptr(ptr) {}

		reference operator*() const { return *m_ptr; }
		pointer operator->() const { return m_ptr; }

		RandomAccessIterator& operator++() { ++m_ptr; return *this; }
		RandomAccessIterator operator++(int) { RandomAccessIterator tmp(*this); ++m_ptr; return tmp; }
		RandomAccessIterator& operator--() { --m_ptr; return *this; }
		RandomAccessIterator operator--(int) { RandomAccessIterator tmp(*this); --m_ptr; return tmp; }

		RandomAccessIterator operator+(difference_type n) const { return RandomAccessIterator(m_ptr + n); }
		friend RandomAccessIterator operator+(difference_type n, const RandomAccessIterator& it) { return it + n; }
		RandomAccessIterator operator-(difference_type n) const { return RandomAccessIterator(m_ptr - n); }
		difference_type operator-(const RandomAccessIterator& rhs) const { return m_ptr - rhs.m_ptr; }

		reference operator[](difference_type n) const { return *(m_ptr + n); }

		bool operator==(const RandomAccessIterator& rhs) const { return m_ptr == rhs.m_ptr; }
		bool operator!=(const RandomAccessIterator& rhs) const { return !(*this == rhs); }
		bool operator<(const RandomAccessIterator& rhs) const { return m_ptr < rhs.m_ptr; }
		bool operator>(const RandomAccessIterator& rhs) const { return rhs < *this; }
		bool operator<=(const RandomAccessIterator& rhs) const { return !(rhs < *this); }
		bool operator>=(const RandomAccessIterator& rhs) const { return !(*this < rhs); }
};
}