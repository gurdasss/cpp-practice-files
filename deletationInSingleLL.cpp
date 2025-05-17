#include <iostream>
#include <forward_list>

int main()
{
    std::forward_list<int> nums{4, 3, 2, 1, 0};

    // initialise iterators
    auto prevItr{nums.before_begin()}; // [] 4 3 2 1 0
    auto itr{nums.begin()};            //   [4] 3 2 1 0

#if 0
	// after this function call
	// the iterator(s) referring
	// to the deleted iterator will be
	// left dangling
	nums.erase_after(prevItr); // 3 2 1 0

	// dereferencing a dangling iterator
	// will produce undefined behaviour
	// std::cout << *itr << '\n';
#endif

    // to avoid dereferencing a dangling
    // iterator. We need to update those iterator(s)
    // who are still referring to that deleted iterator

    // NOTE: we have'nt updated 'itr' after deleting
    // the element which it was referring

    // we can do that by simply assign the
    // the following iterator of the erased
    // iterator.
    // erase_after() returns the following
    // iterator of the erased iterator OR
    // it will return .end()

    itr = nums.erase_after(prevItr); // [3] 2 1 0

    std::cout << *itr << '\n';

    return 0;
}