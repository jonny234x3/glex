#include "PythonB.h"

using namespace boost::python;

PythonB::PythonB(){

}
char const* hello() {
   return "Start";
}

BOOST_PYTHON_MODULE(liblink){

        boost::python::def("hello", hello);
        class_<Game>("Game")
    	        .def("Start", &Game::Start);
}
