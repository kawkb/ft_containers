#pragma once
#include <cstddef>

namespace ft 
{
	template<typename T>
	class random_access_iterator
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
		random_access_iterator(pointer ptr = nullptr) : m_ptr(ptr) {}

		// Copy constructor
		random_access_iterator(const random_access_iterator& other) : m_ptr(other.m_ptr) {}
	
		// Destructor
		~random_access_iterator() {}
	
		// Assignment operator
		random_access_iterator& operator=(const random_access_iterator& other)
		{
			if (this != &other) {
				m_ptr = other.m_ptr;
			}
			return (*this);
		}
	
		// Equality operator
		bool operator==(const random_access_iterator& other) const 
		{
			return (m_ptr == other.m_ptr);
		}

		// Inequality operator
		bool operator!=(const random_access_iterator& other) const 
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
		random_access_iterator& operator++()
		{
			++m_ptr;
			return (*this);
		}
	
		// Increment operator (post)
		random_access_iterator operator++(int)
		{
			random_access_iterator temp(*this);
			++m_ptr;
			return (temp);
		}
	
		// Decrement operator
		random_access_iterator& operator--()
		{
			--m_ptr;
			return (*this);
		}
	
		// Decrement operator (post)
		random_access_iterator operator--(int)
		{
			random_access_iterator temp(*this);
			--m_ptr;
			return (temp);
		}
		
		// Addition operator
		random_access_iterator operator+(difference_type n) const
		{
			return (random_access_iterator(m_ptr + n););
		}

		// Subtraction operator
		random_access_iterator operator-(difference_type n) const
		{
			return (random_access_iterator(m_ptr - n));
		}
	
		// Difference operator
		difference_type operator-(const random_access_iterator& other) const
		{
			return m_ptr - other.m_ptr;
		}

		// Addition assignment operator
		random_access_iterator& operator+=(difference_type n)
		{
			m_ptr += n;
			return (*this);
		}
	
		// Subtraction assignment operator
		random_access_iterator& operator-=(difference_type n) {
			m_ptr -= n;
			return *this;
		}

	
		// Less than operator
		bool operator<(const random_access_iterator& other) const {
			return m_ptr < other.m_ptr;
		}
	
		// Less than or equal to operator
		bool operator<=(const random_access_iterator& other) const {
			return m_ptr <= other.m_ptr;
		}
	
		// Greater than operator
		bool operator>(const random_access_iterator& other) const {
			return m_ptr > other.m_ptr;
		}
	
		// Greater than or equal to operator
		bool operator>=(const random_access_iterator& other) const {
			return m_ptr >= other.m_ptr;
		}

		reference operator[](difference_type n) const
		{
		    return *(m_ptr + n);
		}
	};
}