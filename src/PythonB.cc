#include "PythonB.h"

PythonB::PythonB(){

}
char const* hello() {
   return "hello world";
}

BOOST_PYTHON_MODULE(liblink){


        boost::python::def("hello", hello);
}
