#include <windows.h>
#include <tchar.h>
#include <Python.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{

    PyObject* pInt;
    Py_Initialize();
    pInt = PyString_FromString("teste");

    MessageBox(NULL, _T("TESTE"), _T("TESTE"), MB_OK);

    Py_Finalize();
}
