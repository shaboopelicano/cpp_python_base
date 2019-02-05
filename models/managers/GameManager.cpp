#include <Windows.h>
#include "GameManager.h"

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

    HWND hWnd = CreateWindow(
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

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
}

void GameManager::FinalizarSistemas()
{
}
