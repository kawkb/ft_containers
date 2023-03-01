#pragma once
#include <cstddef>

namespace ft 
{
	template<typename T>
	class RandomAccessIterator
	{
	private:
		T* m_ptr;
	public:
		// Required iterator typedefs
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;
	
		// Default constructor
		RandomAccessIterator(pointer ptr = nullptr) : m_ptr(ptr) {}

		// Copy constructor
		RandomAccessIterator(const RandomAccessIterator& other) : m_ptr(other.m_ptr) {}
	
		// Destructor
		~RandomAccessIterator() {}
	
		// Assignment operator
		RandomAccessIterator& operator=(const RandomAccessIterator& other)
		{
			if (this != &other) {
				m_ptr = other.m_ptr;
			}
			return (*this);
		}
	
		// Equality operator
		bool operator==(const RandomAccessIterator& other) const 
		{
			return (m_ptr == other.m_ptr);
		}

		// Inequality operator
		bool operator!=(const RandomAccessIterator& other) const 
		{
			return (m_ptr != other.m_ptr);
		}

		// Dereference operator
		reference operator*() const 
		{
			return (*m_ptr);
		}

		// Member access operator
		pointer operator->() const 
		{
			return (m_ptr);
		}
	
		// Increment operator
		RandomAccessIterator& operator++()
		{
			++m_ptr;
			return (*this);
		}
	
		// Increment operator (post)
		RandomAccessIterator operator++(int)
		{
			RandomAccessIterator temp(*this);
			++m_ptr;
			return (temp);
		}
	
		// Decrement operator
		RandomAccessIterator& operator--()
		{
			--m_ptr;
			return (*this);
		}
	
		// Decrement operator (post)
		RandomAccessIterator operator--(int)
		{
			RandomAccessIterator temp(*this);
			--m_ptr;
			return (temp);
		}
		
		// Addition operator
		RandomAccessIterator operator+(difference_type n) const
		{
			return (RandomAccessIterator(m_ptr + n););
		}

		// Subtraction operator
		RandomAccessIterator operator-(difference_type n) const
		{
			return (RandomAccessIterator(m_ptr - n));
		}
	
		// Difference operator
		difference_type operator-(const RandomAccessIterator& other) const
		{
			return m_ptr - other.m_ptr;
		}

		// Addition assignment operator
		RandomAccessIterator& operator+=(difference_type n)
		{
			m_ptr += n;
			return (*this);
		}
	
		// Subtraction assignment operator
		RandomAccessIterator& operator-=(difference_type n) {
			m_ptr -= n;
			return *this;
		}

	
		// Less than operator
		bool operator<(const RandomAccessIterator& other) const {
			return m_ptr < other.m_ptr;
		}
	
		// Less than or equal to operator
		bool operator<=(const RandomAccessIterator& other) const {
			return m_ptr <= other.m_ptr;
		}
	
		// Greater than operator
		bool operator>(const RandomAccessIterator& other) const {
			return m_ptr > other.m_ptr;
		}
	
		// Greater than or equal to operator
		bool operator>=(const RandomAccessIterator& other) const {
			return m_ptr >= other.m_ptr;
		}

		reference operator[](difference_type n) const
		{
		    return *(m_ptr + n);
		}
	};
}