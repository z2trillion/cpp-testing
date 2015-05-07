//compile with: gcc -shared -I/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/include/python2.7/ /usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/lib/libpython2.7.dylib -o myModule.so myModule.cpp

#include <Python.h>

static PyObject* py_myFunction(PyObject* self, PyObject* args)
{
  return Py_BuildValue("s", "asdas");
}

static PyObject* py_myOtherFunction(PyObject* self, PyObject* args)
{
  double x, y;
  PyArg_ParseTuple(args, "dd", &x, &y);
  return Py_BuildValue("d", x*y);
}

static PyMethodDef myModule_methods[] = {
  {"myFunction", py_myFunction, METH_VARARGS},
  {"myOtherFunction", py_myOtherFunction, METH_VARARGS},
  {NULL, NULL}
};

extern "C" void initmyModule(void)
{
  (void) Py_InitModule("myModule", myModule_methods);
}
