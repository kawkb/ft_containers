#include <cstddef>

namespace ft
{
	template<class Iterator>
	class reverse_iterator
	{
	private:
		Iterator m_iterator;
	public:
		typedef Iterator                                                    	iterator_type;
		typedef typename	ft::iterator_traits<Iterator>::iterator_category   	category;
		typedef typename	ft::iterator_traits<Iterator>::value_type          	value_type;
		typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename	ft::iterator_traits<Iterator>::reference			reference;
	
	// Default constructor
		reverse_iterator(): m_iterator(){}

	// Initalization constructor
		explicit reverse_iterator(iterator_type it): m_iterator(it){}
	
	// Copy constructor
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it): m_iterator(rev_it.base()){}
	
	// Deconstructor
		~reverse_iterator(){}
	// Base
		iterator_type base() const
		{
			return (m_iterator);
		}
	// Dereference operator
		reference operator*() const
		{
			iterator_type temp = m_iterator;
			temp--;
			return (*temp);
		}
	// Addition operator
		reverse_iterator operator+ (difference_type n) const
		{
			return reverse_iterator(m_iterator - n);
		}
	// Increment operators
		reverse_iterator& operator++()
		{
        	--m_iterator;
        	return *this;
		}

		reverse_iterator operator++(int) 
		{
        	reverse_iterator tmp = *this;
        	--m_iterator;
        	return tmp;
    	}

		reverse_iterator& operator+= (difference_type n)
		{
			m_iterator -= n;
			return(*this);
		}

	// Substruction operator
		reverse_iterator operator- (difference_type n) const
		{
			return reverse_iterator(m_iterator + n);
		}

	// Decrement operators
		reverse_iterator& operator--()
		{
        	++m_iterator;
        	return *this;
    	}
	
    	reverse_iterator operator--(int)
		{
        	reverse_iterator tmp = *this;
        	++m_iterator;
        	return tmp;
    	}
	// Retrocede iterator
		reverse_iterator& operator-=(difference_type n)
		{
        	m_iterator += n;
        	return *this;
    	}
	// Derefrence iterator with offset []
		reference operator[](difference_type n) const { return *(*this + n);}
	};

	template<class Iterator>
	bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
	    return x.base() == y.base();
	}

	template<class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
	    return !(x == y);
	}

	template<class Iterator>
	bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
	    return y.base() < x.base();
	}

	template<class Iterator>
	bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
	    return y < x;
	}

	template<class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
	    return !(y < x);
	}

	template<class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
	    return !(x < y);
	}

	template<class Iterator>
	typename reverse_iterator<Iterator>::difference_type  operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
	{
	    return y.base() - x.base();
	}

	template<class Iterator>
	reverse_iterator<Iterator>  operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& x)
	{
	    return reverse_iterator<Iterator>(x.base() - n);
	}
}