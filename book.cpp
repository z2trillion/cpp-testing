//compile with g++ -I/usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/include/python2.7/ /usr/local/Cellar/python/2.7.9/Frameworks/Python.framework/Versions/2.7/lib/libpython2.7.dylib -o book book.cpp
#include <Python.h>
#include <iostream>

class Book {
public:
  Book(PyObject*);
  double getBid();
  //double getAsk();
  //double getMid();
  double getSpread();
private:
  PyObject* pbook;
};

Book::Book(PyObject* pbook): pbook(pbook){
};

double Book::getBid(){
  PyObject* pfloat = PyObject_GetAttrString(pbook, "bid");
  double bid = PyFloat_AsDouble(pfloat);
  Py_DECREF(pfloat);
  return 2;
};

double Book::getSpread(){
  PyObject* pfloat = PyObject_GetAttrString(pbook, "spread");
  double spread = PyFloat_AsDouble(pfloat);
  Py_DECREF(pfloat);
  return spread;
};

using namespace std;
int main(){
  PyObject *pName, *pModule, *pDict, *pFunc;
  PyObject *pArgs, *pValue;

  Py_Initialize();

  PyObject *sys = PyImport_ImportModule("sys");
  PyObject *path = PyObject_GetAttrString(sys, "path");
  PyList_Append(path, PyString_FromString("."));

  pName = PyString_FromString("book");
  pModule = PyImport_Import(pName);
  //Py_DECREF(pName);

  PyObject* pObject = PyObject_GetAttrString(pModule, "python_book");
  //Py_DECREF(pModule);


  //PyObject *pObject = PyObject_CallObject(pFunc, NULL);
  //Py_DECREF(pFunc);

  Book myBook = Book(pObject);
  //Py_DECREF(pObject);
  cout << "num_levels = " << myBook.getSpread() << endl;

  Py_Finalize();
  return 0;
};
