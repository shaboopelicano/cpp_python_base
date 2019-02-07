#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <Windows.h>
#include <Config.h>
#include <gl/GL.h>
#include <gl/GLU.h>

class GameManager
{
public:
  static HWND hWnd;
  static HDC hDC;
  static HGLRC hRC;
  static GLuint PixelFormat;
  
  static void IniciarSistemas(HINSTANCE,int nCmdShow);
  static void DefinirFormatoPixels();
  static void FinalizarSistemas();
  static GLvoid ReSizeGLScene(GLsizei width, GLsizei height);
  static int InitGL(GLvoid);

};


#endif
