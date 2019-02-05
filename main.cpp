#include <windows.h>
#include <tchar.h>
#include <Python.h>

#define CMD_ARGS TRUE

void PreferenciasRuntime(LPSTR);
BOOL IniciarConsolePython();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
#if CMD_ARGS
    PreferenciasRuntime(pCmdLine);
#endif
}

void PreferenciasRuntime(LPSTR args)
{

    // Se forem iguais retorna 0
    if (!lstrcmp(TEXT(args), TEXT("debug")))
        IniciarConsolePython();
}

BOOL IniciarConsolePython()
{

    PyObject *pInt;
    Py_Initialize();
    pInt = PyString_FromString("teste");
    Py_Finalize();

    return TRUE;
}
