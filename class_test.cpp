#include <Python/Python.h>

class Book {
public:
  Book(int num_levels) {
    num_levels = num_levels
    levels = int* [num_levels]
  };
  void update();
private:
  int num_levels;
  int* levels;
  int* bids, asks;
}

class FeatureSet {
public:
  float*
}



class

int main(int argc, char *argv[])
{
  PyObject *pName, *pModule, *pDict, *pFunc;
  PyObject *pArgs, *pValue;
  int i;

  Py_Initialize();

  PyObject *sys = PyImport_ImportModule("sys");
  PyObject *path = PyObject_GetAttrString(sys, "path");
  PyList_Append(path, PyString_FromString("."));

  pName = PyString_FromString("class_test");
  pModule = PyImport_Import(pName);
  Py_DECREF(pName);

  pFunc = PyObject_GetAttrString(pModule, "incrementer");
  Py_DECREF(pModule);


  PyObject *pObject = PyObject_CallObject(pFunc, NULL);
  Py_DECREF(pFunc);

  for (i = 0; i < 3; ++i) {
    PyObject_CallMethod(pObject, "next", NULL);
  }
  Py_DECREF(pObject);

  Py_Finalize();
  return 0;
}


/*
#include </usr/include/python2.7/Python.h>

int main(int, char **) {
  	Py_Initialize();

    PyObject *sys = PyImport_ImportModule("sys");
    PyObject *path = PyObject_GetAttrString(sys, "path");
    PyList_Append(path, PyString_FromString("."));

    PyRun_SimpleString("import os,hello");
    PyRun_SimpleString("print os.getcwd()");

    PyRun_SimpleString("hello.hello()");

 	  Py_Finalize();
  	return 0;
}
*/
