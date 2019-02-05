#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include <Windows.h>
#include <Config.h>

class GameManager
{
public:
  static void IniciarSistemas(HINSTANCE,int nCmdShow);
  static void FinalizarSistemas();
};

#endif
