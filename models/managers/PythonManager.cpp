#include <PythonManager.h>

PythonManager::PythonManager()
{
    PyObject *pInt;
    Py_Initialize();
    pInt = PyString_FromString("teste");
    Py_Finalize();
    
}

PythonManager::~PythonManager()
{
}
