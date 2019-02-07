#include <Windows.h>
#include "GameManager.h"

// A unidade de compilação deve saber dos membros estáticos antes de define-las em função
HDC GameManager::hDC;
HWND GameManager::hWnd;
HGLRC GameManager::hRC;
GLuint GameManager::PixelFormat;

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void GameManager::IniciarSistemas(HINSTANCE hInstance, int nCmdShow)
{

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = TEXT("ClasseJanela");

    if (!RegisterClass(&wc))
        MessageBox(NULL, TEXT("Erro"), TEXT("Erro:Registrar Classe Janela"), MB_OK);

    hWnd = CreateWindow(
        TEXT("ClasseJanela"),
        TEXT("Janela"),
        WS_OVERLAPPEDWINDOW,
        0, 0,
        LARGURA_WND,
        ALTURA_WND,
        NULL, NULL,
        hInstance,
        NULL);

    if (!hWnd)
        MessageBox(NULL, TEXT("Erro"), TEXT("Erro:Criar Janela"), MB_OK);

    hDC = GetDC(hWnd);

    GameManager::DefinirFormatoPixels();

    ShowWindow(hWnd, nCmdShow);
    SetForegroundWindow(hWnd);
    SetFocus(hWnd);
    UpdateWindow(hWnd);
}

void GameManager::DefinirFormatoPixels()
{
    PIXELFORMATDESCRIPTOR pfd = {sizeof(pfd), 1};
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_SUPPORT_COMPOSITION | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;
    pfd.cAlphaBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;

    if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))
    {
        MessageBox(NULL, TEXT("Erro"), TEXT("Erro:Escolher Formato de Pixel"), MB_OK);
    }
    if (!SetPixelFormat(hDC, PixelFormat, &pfd))
    {
        MessageBox(NULL, TEXT("Erro"), TEXT("Erro:Setar Formato de Pixel"), MB_OK);
    }
    if (!(hRC = wglCreateContext(hDC)))
    {
        MessageBox(NULL, TEXT("Erro"), TEXT("Erro:Criar contexto de renderização"), MB_OK);
    }
    if (!wglMakeCurrent(hDC, hRC))
    {
        MessageBox(NULL, TEXT("Erro"), TEXT("Erro:Definir o contexto de renderizacao"), MB_OK);
    }

    GameManager::ReSizeGLScene(800, 600);

    if (!GameManager::InitGL())
    {
        MessageBox(NULL, TEXT("Erro"), TEXT("Erro:Definir o Inicializar GL"), MB_OK);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Screen And Depth Buffer
    glLoadIdentity();   
}


GLvoid GameManager::ReSizeGLScene(GLsizei width, GLsizei height)     // Resize And Initialize The GL Window
{
    if (height==0)                                      // Prevent A Divide By Zero By
    {
        height=1;                                       // Making Height Equal One
    }

    glViewport(0,0,width,height);                       // Reset The Current Viewport

    glMatrixMode(GL_PROJECTION);                        // Select The Projection Matrix
    glLoadIdentity();                                   // Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
    
    glMatrixMode(GL_MODELVIEW);                         // Select The Modelview Matrix
    glLoadIdentity();                                   // Reset The Modelview Matrix
}

int GameManager::InitGL(GLvoid)                                      // All Setup For OpenGL Goes Here
{
    glShadeModel(GL_SMOOTH);                            // Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);               // Black Background
    glClearDepth(1.0f);                                 // Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);                            // Enables Depth Testing
    glDepthFunc(GL_LEQUAL);                             // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Really Nice Perspective Calculations
    return TRUE;                                        // Initialization Went OK
}

void GameManager::FinalizarSistemas()
{
}
