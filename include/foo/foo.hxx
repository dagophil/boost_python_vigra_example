#ifndef FOO_HXX
#define FOO_HXX

#include <iostream>
#include <vigra/multi_array.hxx>


namespace foo {


using namespace vigra;

template<unsigned int N, class T>
void foo(
        const MultiArrayView<N, T> & src
){
    std::cout << "src.shape(): " << src.shape() << std::endl;
    std::cout << "end of foo" << std::endl;
}


} // namespace foo

#endif // FOO_HXX
