#pragma once
#include <cstddef>

namespace ft 
{
	struct  input_iterator_tag{};
	struct  output_iterator_tag{};
	struct  forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type   difference_type;
		typedef typename Iterator::value_type        value_type;
		typedef typename Iterator::pointer           pointer;
		typedef typename Iterator::reference         reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <typename T>
	struct iterator_traits<T*>
	{
		typedef ptrdiff_t                       difference_type;
		typedef T                               value_type;
		typedef T*                              pointer;
		typedef T&                              reference;
		typedef ft::random_access_iterator_tag      iterator_category;
	};

	template <typename T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t                       difference_type;
		typedef T                               value_type;
		typedef const T*                        pointer;
		typedef const T&                        reference;
		typedef random_access_iterator_tag      iterator_category;
	};

	template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		typedef Category iterator_category;
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
	};
}
// best explanation: https://www.codeproject.com/Articles/36530/An-Introduction-to-Iterator-Traits