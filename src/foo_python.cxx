#define PY_ARRAY_UNIQUE_SYMBOL foo_API

#include <boost/python.hpp>
#include <vigra/numpy_array.hxx>
#include <vigra/numpy_array_converters.hxx>


#include <foo/foo.hxx>

using namespace boost::python;

template <unsigned int N, class T>
vigra::NumpyAnyArray _foo(
    vigra::NumpyArray<N, T> src
){
    foo::foo(src);
    return src;
}

void export_stuff()
{
    def("foo", vigra::registerConverters(&_foo<2, unsigned char>),
        (
            arg("src")
        )
    );
}

BOOST_PYTHON_MODULE(_foo)
{
    import_array();
    vigra::import_vigranumpy();
    numeric::array::set_module_and_type("numpy", "ndarray");
    docstring_options docstring_options(true, true, false);

    export_stuff();
}
