from tkinter import *
from time import sleep
import conts
import jogo

class Janela(Tk):
    def __init__(self, *args, **kwargs):
        Tk.__init__(self, *args, *kwargs)
        self.geometry("" + str(conts.LARGURA_JANELA) +
                      "x" + str(conts.ALTURA_JANELA))
        self.canvas = jogo.Jogo()
        self.canvas.pack(fill=BOTH, expand=1)

        self.bind('<KeyPress>', self.tratar_tecla_up)
        self.bind('<KeyRelease>', self.tratar_tecla_down)

    def atualizar(self):
        self.canvas.atualizar()
        self.after(10, self.atualizar)

    def tratar_tecla_up(self, evento):
        tecla = evento.keycode
        if(tecla == 37):
            self.canvas.mover_peca(-5)
            return
        if(tecla == 39):
            self.canvas.mover_peca(5)
            return


    def tratar_tecla_down(self, evento):
        tecla = evento.keycode
        if(tecla == 37):
            self.canvas.mover_peca(0)
            return
        if(tecla == 39):
            self.canvas.mover_peca(0)
            return

app = Janela()
app.after(100, app.atualizar)
app.mainloop()
