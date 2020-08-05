#include <stdio.h>
#include <pybind11/pybind11.h>

// Spew for debugging:
#define _SPEW(file, line, func, fmt, ...)\
         fprintf(stderr, "%s:%d:%s: " fmt "\n", file, line, func, ##__VA_ARGS__)
#define SPEW(...) _SPEW(__BASE_FILE__, __LINE__,__func__,  __VA_ARGS__)



namespace py = pybind11;


// I know this is not the form that I want.
//
// It needs to have generic arguments.  I need to parse the arguments that
// are passed in.   It can easily, but tediously, do that with the python
// C API.
//
// I also need to copy some of the arguments and pass them back to the
// python script as arguments to functions in the python script at a
// later time.  So, this is just the start of what I have not figured out
// how-to ...   It's all very straight forward with the python C API.
//
// Also need one of the passed in arguments to be a python function that
// takes arbitrary arguments. That part I figured out.  The python
// function will be saved and called later; again, very straight forward
// with the python C API.
//
// There are popular python modules that do these kinds of things.  They
// provide very slick interfaces for their users.  Example
// https://flask-socketio.readthedocs.io/en/latest/
//
int magic(int x1, int x2) {
    SPEW("got %d %d", x1, x2);
    return x1 * x2;
}



PYBIND11_MODULE(mod,m) {

    m.doc() = "pybind11 example plugin";

    m.def("magic", &magic, "Magic function");
}
