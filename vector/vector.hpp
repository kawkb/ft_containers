#pragma once
#include <iostream>
#include <cstddef>
#include "../utils/iterator.tpp"
#include "../utils/random_access_iterator.tpp"
#include "../utils/reverse_iterator.tpp"
namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector 
	{

		
	public:
		typedef size_t														size_type;
		typedef T 															value_type;
		typedef Allocator													allocator_type;
		typedef typename Allocator::reference								reference;
		typedef typename Allocator::const_reference 						const_reference;
		typedef typename Allocator::pointer 								pointer;
		typedef typename Allocator::const_pointer 							const_pointer;

		typedef	typename ft::random_access_iterator<value_type>  			iterator;
		typedef	typename ft::random_access_iterator<const value_type> 		const_iterator;
		typedef typename ft::reverse_iterator<iterator> 					reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> 				const_reverse_iterator;
		typedef ptrdiff_t 													difference_type;

	//default constructor:
		explicit vector (const allocator_type& alloc = allocator_type()) : m_size(0), m_capacity(0), m_array(nullptr), m_alloc(alloc) {}
	//fill constructor:
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_size(n), m_capacity(n), m_alloc(alloc)
		{
			m_array = m_alloc.allocate(n);
			for (int i = 0; i < n ; i++)
				m_alloc.construct(m_array + i, val);
		}
	//range constructor:
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& alloc)
    	: m_alloc(alloc)
    	{
    		m_size = 0;
    		m_capacity = 0;
    		for (InputIterator it = first; it != last; ++it) 
    	    	++m_capacity;
    		m_array = m_alloc.allocate(m_capacity);
    	    while (first != last)
    	    {
    	        m_alloc.construct(m_array + m_size, *first);
    	        m_size++;
    	        ++first;
    	    }
    	}
	//copy constructor:
		vector (const vector& x) : m_size(x.m_size), m_capacity(x.m_capacity)
		{
			m_array = m_alloc.allocate(m_capacity);
			for(int i = 0; i < x.m_size; i++)
				m_alloc.construct(m_array + i, *(x.m_array + i));
		}
	// destructor:
		~vector()
		{
			for(size_t i = 0; i < m_size; i++)
				m_alloc.destroy(m_array + i);
			m_alloc.deallocate(m_array, m_capacity);
		}
	// assignment operator overload:
		vector& operator= (const vector& x)
		{
			if (this != &x)
			{
				if (m_capacity < x.m_size)
				{
					for (size_t i = 0; i < m_size; i++)
						m_alloc.destroy(m_array + i);
					m_alloc.deallocate(m_array, m_capacity);
					m_array = m_alloc.allocate(x.m_size);
					for(int i = 0; i < x.m_size; i++)
						m_alloc.construct(m_array + i, *(x.m_array + i));
					m_size = x.m_size;
					m_capacity = x.m_size;
				}
				else
				{
					for (size_t i = 0; i < m_size; i++)
						m_alloc.destroy(m_array + i);
					for(int i = 0; i < x.m_size; i++)
						m_alloc.construct(m_array + i, *(x.m_array + i));
					m_size = x.m_size;
				}
			}
			return(*this);
		}

	// iterators:
		iterator				begin() { return (iterator(m_array));}
		const_iterator			begin() const { return (const_iterator(m_array));}
		iterator				end() {return (iterator(m_array + m_size));}
		const_iterator			end() const {return (const_iterator(m_array + m_size));}
		reverse_iterator		rbegin() {return (reverse_iterator(m_array + m_size));}
		const_reverse_iterator	rbegin() const {return const_reverse_iterator(m_array + m_size);}
		reverse_iterator		rend() {return (reverse_iterator(m_array));}
		const_reverse_iterator	rend() const {return (reverse_iterator(m_array));}

	// Capacity:
		size_type				size() const { return(m_size);}
		size_type				max_size() const { return(m_alloc.max_size());}
		void 					resize (size_type n, value_type val = value_type())
		{
			if (n < m_size)
			{
				for(size_type i = n; i < m_size; i++)
					m_alloc.destroy(m_array + i);
			}
			else
			{
				if (n > m_capacity)
				{
					pointer		new_array = m_alloc.allocate(n);
					for(size_type i = 0; i < m_size; i++)
					{
						m_alloc.construct(new_array + i, *(m_array + i));
						m_alloc.destroy(m_array + i);
					}
					m_alloc.deallocate(m_array, m_capacity);
					m_array = new_array;
					m_capacity = n;
				}
				for(size_type i = m_size; i < n; i++)
					m_alloc.construct(m_array + i, val);
			}
			m_size = n;
		}
		size_type				capacity() const { return(m_capacity);}
		bool					empty() const { return(m_size == 0);}
		void					reserve(size_type n)
		{
			if (m_capacity < n)
			{
            	value_type* new_array = m_alloc.allocate(m_capacity);
            	for (size_type i = 0; i < m_size; i++)
            	{
            	    m_alloc.construct(new_array + i, *(m_array + i));
            	    m_alloc.destroy(m_array + i);
            	}
            	m_alloc.deallocate(m_array, m_size);
            	m_array = new_array;
				m_capacity = n;
			}
		}
		void 					shrink_to_fit()
		{
			if (m_capacity > size())
			{
        		value_type* new_array = m_alloc.allocate(m_size);
				for(size_type i = 0; i < m_size; i++)
				{
					m_alloc.construct(new_array + i, *(m_array + i));
					m_alloc.destroy(m_array + i);
				}
				m_alloc.deallocate(m_array, m_capacity);
				m_array = new_array;
				m_capacity = m_size;
			}
		}
	
	// element access:
		reference				operator[](size_type n) { return (*(m_array + n));}
		const_reference			operator[](size_type n) const { return (*(m_array + n));}
		const_reference			at(size_type n) const
		{
			if (n > m_size)
				throw std::out_of_range("Index out of bounds");;
			return (*(m_array + n));
		}
		reference				at(size_type n)
		{
			if (n > m_size)
				throw std::out_of_range("Index out of bounds");;
			return (*(m_array + n));
		}
		reference				front() { return (*m_array);}
		const_reference			front() const { return (*m_array);}
		reference				back() { return (*m_array + m_size - 1);}
		const_reference			back() const { return (*m_array + m_size - 1);}

	//modifiers:
		// template <class InputIterator>
		// void 					assign(InputIterator first, InputIterator last)
		// {
			
		// }

		void 					assign(size_type n, const value_type& val)
		{
			if (n > m_capacity)
			{
				for(size_type i = 0; i < m_size; i++)
					m_alloc.destroy(m_array + i);
				m_alloc.deallocate(m_array, m_capacity);
				this = vector(n, val);
				m_capacity = n;
			}
			else
			{
				for (int i = 0; i < n ; i++)
				{
					m_alloc.destroy(m_array + i);
					m_alloc.construct(m_array + i, val);
				}
			}
			m_size = n;
		}

		void					push_back(const T& x)
		{
    		if (m_size == m_capacity) 
    		    reserve(m_capacity == 0 ? 1 : 2 * m_capacity);
    		m_alloc.construct(m_array + m_size, x);
    		++m_size;
		}

		void					pop_back()
		{
			if (m_size > 0)
			{
				m_alloc.destroy(m_array + m_size - 1);
				m_size--;
			}
		}
		iterator				insert(iterator position, const T& x);
		void					insert(iterator position, size_type n, const T& x);
		template <class InputIterator>
		void					insert(iterator position,
		InputIterator first, InputIterator last);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(vector<T,Allocator>&v)
		{
			vector<T, Allocator> tmp = vector(*this);
			*this = v;
			v = *tmp;
			// T* temp = m_array;
    		// m_array = v.m_array;
    		// v.m_array = temp;
    		// size_type temp_size = m_size;
    		// m_size = v.m_size;
    		// v.m_size = temp_size;
    		// size_type temp_capacity = m_capacity;
    		// m_capacity = v.m_capacity;
    		// v.m_capacity = temp_capacity;
		}
		void					clear()
		{
			for(size_type i = 0; i < m_size; i++)
				m_alloc.destroy(m_array + i);
			m_size = 0;
		}

		allocator_type get_allocator() const {return(m_alloc);}
	private:
		value_type				*m_array;
		size_type				m_capacity;
		size_type				m_size;
		Allocator				m_alloc;
	// };
	// template <class T, class Allocator>
	// bool operator==(const vector<T,Allocator>& x,
	// const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// bool operator< (const vector<T,Allocator>& x,
	// const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// bool operator!=(const vector<T,Allocator>& x,
	// const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// bool operator> (const vector<T,Allocator>& x,
	// const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// bool operator>=(const vector<T,Allocator>& x,
	// const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// bool operator<=(const vector<T,Allocator>& x,
	// const vector<T,Allocator>& y);
	// // specialized algorithms:
	// template <class T, class Allocator>
	// void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
	// 	template <class InputIterator>

};
}