 * string_view

std::string_view is a string-like object which point to a const char* sequence, and contains the its length. Using string_view in should be very fast in various situations, and very dangerous too, if we aren’t using it carefully.
In this example, there is a string_view points to the string s. The string_view is only knew the original length of the string, and when we concatenate a string literal to the string_view, that length won't be valid anymore.

The only valid use of string_view is, where it points to an existing string. In this example, the string exists only inside the function, and the function's return value will contain a reference which no longer points to the string.

What if, we set this string static? Every string_view will point to the same string every time. 

* copy a vector

std::copy has a few different methods to use. The three arguments are: the first and the last element of the data from the source vector, and the destination vector's first iterator. In this example, we didn't reserve memory to destination vector to hold data, and this will lead to segmentation fault.

There is two simple solutions:
    * dest.reserve(countOfData) - right before start to copy the data, we can allocate memory to hold data in the destination vector.
    * std::back_inserter() - a function template that constructs a back_inserter_iterator which call a push_back for the vector( and that will allocate memory for each copied data) 


Mixing C and C++ features are frequently lead to serious issues. Like the example, there is an array what we want to copy to a vector. The issue is the same, like the previous example, there is no allocated memory for data. The back_inserter will solve the problem.

* Not a Number (NaN) value flaws

Not a Number is a floating point value, which represents non-representable values for floating point elements, like missing data.
In this example, a vector contains float point random numbers, and there is one which is missing, the value is NAN. This missing data will confuse the sorting algorithm, and the result will be an undefined behavior.

* Noexcept

The noexcept(true) specifier disables exception throwing for a function. If we throw an exception inside a noecept specified function, the std::terminate() will be called, which terminates the application.

Possible solution is to specify noexcept(false), which means the function might throw an exception.

* Ranged For Loop iterators failure - iteration invalidation

Ranged for loop has to work with the iterators of the same container. In the example, there is a function, that construct and fill up a vector with constant data and returns it. The problem is, there is two different containers will create, so their iterators will be different too, however those containers have the same data. This leads to an undefined behavior problem.

Solution:
for (auto &i : getVect()) {
    /*  ... */
}

