 * string_view

std::string_view is a string-like object which point to a const char* sequence, and contains the its length. Using string_view in should be very fast in various situations, and very dangerous too, if we aren’t using it carefully.
In this example, there is a string_view points to the string s. The string_view is only knew the original length of the string, and when we concatenate a string literal to the string_view, that length won't be valid anymore.

The only valid use of string_view is, where it points to an existing string. In this example, the string exists only inside the function, and the function's return value will contain a reference which no longer points to the string.

What if, we set this string static? Every string_view will point to the same string every time. 

* copy a vector
