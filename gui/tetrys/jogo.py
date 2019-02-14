from tkinter import Canvas
import peca
from conts import *


class Jogo(Canvas):
    def __init__(self):
        super().__init__()
        self.x = 0
        self.peca = peca.Peca(POX_X_INIT - 100, 0)
        self.lista_pecas = []
        # self.lista_pecas.append(peca.Peca(POX_X_INIT,0))

    def atualizar(self):
        self.peca.y += VEL_Y
        self.peca.x += self.peca.dx
        self.pintar()
        self.verificar_colisao()

    def pintar(self):
        self.delete("all")
        self.x += 1
        for ret in self.lista_pecas:
            self.create_rectangle(
                ret.x, ret.y, ret.x + LARGURA_PECA, ret.y + LARGURA_PECA, fill="#476042")

        self.create_rectangle(self.peca.x, self.peca.y, self.peca.x +
                              LARGURA_PECA, self.peca.y + LARGURA_PECA, fill="#476042")

    def verificar_colisao(self):
        if self.peca.y + LARGURA_PECA > ALTURA_JANELA:
            self.lista_pecas.append(self.peca)
            self.peca = peca.Peca(POX_X_INIT - 100, 0)
            return

        for ret in self.lista_pecas:
            if (self.peca.x >= ret.x + LARGURA_PECA) and (self.peca.x + LARGURA_PECA <= ret.x):
                self.peca.dx = 0

        for ret in self.lista_pecas:
            if (self.peca.y + LARGURA_PECA >= ret.y) and (self.peca.x >= ret.x + LARGURA_PECA) and (self.peca.x + LARGURA_PECA <= ret.x):
                self.lista_pecas.append(self.peca)
                self.peca = peca.Peca(POX_X_INIT - 100, 0)
                return

    def mover_peca(self, dx):
        self.peca.dx = dx
