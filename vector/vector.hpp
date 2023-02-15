#pragma once
#include <iostream>
#include <vector>
namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
	private:
		T						*m_array;
		size_t					m_capacity;
		size_t					m_size;
		Allocator				m_alloc;
		

	public:
		// types:
		typedef T 												value_type;
		typedef Allocator										allocator_type;
		typedef typename Allocator::reference					reference;
		typedef typename Allocator::const_reference 			const_reference;
		typedef typename Allocator::pointer 					pointer;
		typedef typename Allocator::const_pointer 				const_pointer;

		// typedef	ft::random_access_iterator<value_type>  		iterator; // See 23.1
		// typedef	ft::random_access_iterator<const value_type> 	const_iterator; // See 23.1
		// typedef ft::reverse_iterator<iterator> 					reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator> 			const_reverse_iterator;
		// typedef implementation defined 							difference_type;// See 23.1
		typedef size_t											size_type; // See 23.1


	//default constructor:
		explicit vector(const Allocator& = Allocator()): m_size(0), m_capacity(0), m_array(nullptr)  {}

	//fill constructor:
		explicit vector(size_type n, const T& value = T(), const Allocator& alloc = Allocator()) : m_size(n), m_capacity(n), m_alloc(alloc)
		{
			m_array = m_alloc.allocate(n);
			for (int i = 0; i < n ; i++)
				m_alloc.construct(m_array + i, value);
		}

	//range constructor:
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const Allocator& = Allocator())
		{
			
		}
	//copy constructor
		vector(const vector<T,Allocator>& x) : m_size(x.m_size), m_capacity(x.m_capacity)
		{
			m_array = m_alloc.allocate(m_capacity);
			for(int i = 0; i < x.m_size; i++)
				m_alloc.construct(m_array + i, *(x + 1));
		}
	// destructor
		~vector()
		{
			for(int i = 0; i < m_size; i++)
				m_alloc.destroy(m_array + i);
			m_alloc.deallocate(m_array, m_capacity);
		}
	// 
	// 	vector<T,Allocator>& operator=(const vector<T,Allocator>& x)
	// 	{


	// 	}

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

	// 	// iterators:
	// 	iterator				begin();
	// 	const_iterator			begin() const;
	// 	iterator				end();
	// 	const_iterator			end() const;
	// 	reverse_iterator		rbegin();
	// 	const_reverse_iterator	rbegin() const;
	// 	reverse_iterator		rend();
	// 	const_reverse_iterator	rend() const;

	// 	// capacity:
	// 	size_type				size() const
	// 	{
	// 		return(m_size);
	// 	}
	// 	size_type				max_size() const{}
	// 	{
	// 		return(std::max_size(allocator_type))
	// 	}
	// 	void					resize(size_type sz, T c = T())
	// 	{

	// 	}

	// 	size_type				capacity() const
	// 	{
	// 		return(m_capacity);
	// 	}

	// 	bool					empty() const
	// 	{

	// 	}

	// 	void					reserve(size_type n);

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
	template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator>=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& x,
	const vector<T,Allocator>& y);
	// specialized algorithms:
	template <class T, class Allocator>
	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
};
}