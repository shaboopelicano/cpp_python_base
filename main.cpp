#include <GameManager.h>
#include <PythonManager.h>
#include <Config.h>

#define CMD_ARGS TRUE

void PreferenciasRuntime(LPSTR);
BOOL IniciarConsolePython();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
{
#if CMD_ARGS
    PythonManager* pyMng = new PythonManager;
#endif
    GameManager::IniciarSistemas(hInstance, nCmdShow);
    
    // @TODO(tulio) - Mover esse códigio para outro lugar
    // Para criar o contexto OGL
    // https://stackoverflow.com/questions/6287660/win32-opengl-window-creation
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}


