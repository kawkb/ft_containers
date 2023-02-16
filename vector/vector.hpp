#pragma once
#include <iostream>
#include <vector>
namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		typedef size_t												size_type; // See 23.1
		typedef T 													value_type;
		typedef Allocator											allocator_type;
		typedef typename Allocator::reference						reference;
		typedef typename Allocator::const_reference 				const_reference;
		typedef typename Allocator::pointer 						pointer;
		typedef typename Allocator::const_pointer 					const_pointer;

		// typedef	ft::random_access_iterator<value_type>  		iterator; // See 23.1
		// typedef	ft::random_access_iterator<const value_type> 	const_iterator; // See 23.1
		// typedef ft::reverse_iterator<iterator> 					reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
		// typedef implementation defined 							difference_type;// See 23.1

	private:
		value_type				*m_array;
		size_type				m_capacity;
		size_type				m_size;
		Allocator				m_alloc;
		

	public:
		// types:


	//default constructor:
		explicit vector (const allocator_type& alloc = allocator_type()) : m_size(0), m_capacity(0), m_array(nullptr)  {}
	//fill constructor:
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : m_size(n), m_capacity(n), m_alloc(alloc)
		{
			m_array = m_alloc.allocate(n);
			for (int i = 0; i < n ; i++)
				m_alloc.construct(m_array + i, val);
		}
	//range constructor:
		// template <class InputIterator>         
		// vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){}
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


	// 	// iterators:
	// 	iterator				begin();
	// 	const_iterator			begin() const;
	// 	iterator				end();
	// 	const_iterator			end() const;
	// 	reverse_iterator		rbegin();
	// 	const_reverse_iterator	rbegin() const;
	// 	reverse_iterator		rend();
	// 	const_reverse_iterator	rend() const;

	// Capacity:
		size_type				size() const { return(m_size); }
		size_type				max_size() const { return(m_alloc.max_size()); }
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
				m_alloc.allocate(n - m_capacity, m_array + m_capacity);
				m_capacity = n;
			}
		}
		void 					shrink_to_fit();
	// 	// element access:
	// 	reference				operator[](size_type n)
	// 	{
	// 		return (m_array[n]);
	// 	}
	// 	const_reference			operator[](size_type n) const
	// 	{
	// 		return (m_array[n]);
	// 	}
	// 	const_reference			at(size_type n) const;
	// 	reference				at(size_type n);
	// 	reference				front();
	// 	const_reference			front() const;
	// 	reference				back();
	// 	const_reference			back() const;

	// 	//modifiers:
	// 	void					push_back(const T& x)
	// 	{
	// 		allocator_type myAlloc;
	// 		if(m_size < m_capacity)
	// 			m_array[m_size++] = x;
	// 		else if(m_size == m_capacity)
	// 		{
	// 			value_type *tmp = myAlloc.allocate(m_capacity * 2);
	// 		}
	// 	}
	// 	void					pop_back();
	// 	iterator				insert(iterator position, const T& x);
	// 	void					insert(iterator position, size_type n, const T& x);
	// 	template <class InputIterator>
	// 	void					insert(iterator position,
	// 	InputIterator first, InputIterator last);
	// 	iterator				erase(iterator position);
	// 	iterator				erase(iterator first, iterator last);
	// 	void					swap(vector<T,Allocator>&);
	// 	void					clear();

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
	// 	void assign(InputIterator first, InputIterator last)
	// 	{

	// 	}

	// 	void assign(size_type n, const T& u)
	// 	{

	// 	}

	// 	allocator_type get_allocator() const
	// 	{

	// 	}
};
}