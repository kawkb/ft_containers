#include <cstddef>

namespace ft
{
	template<class Iterator>
	class ReverseIterator
	{
	private:
		Iterator m_iterator;
	public:
		typedef typename	Iterator                                                    iterator_type;
		typedef typename	ft::iterator_traits<typename Iterator>::iterator_category   category;
		typedef typename	ft::iterator_traits<typename Iterator>::value_type          value_type;
		typedef typename	ft::iterator_traits<typename Iterator>::difference_type		difference_type;
		typedef typename	ft::iterator_traits<typename Iterator>::pointer				pointer;
		typedef typename	ft::iterator_traits<typename Iterator>::reference			reference;
	
	// Default constructor
		ReverseIterator(): m_iterator(){}

	// Initalization constructor
		explicit ReverseIterator(iterator_type it): m_iterator(it){}
	
	// Copy constructor
		template <class Iter>
		ReverseIterator(const reverse_iterator<Iter>& rev_it): m_iterator(rev_it.base()){}
	
	// Deconstructor
		~ReverseIterator(){}
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
	// 
	}; 
}