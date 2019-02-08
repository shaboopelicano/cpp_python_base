from tkinter import *
from time import sleep


class Jogo(Canvas):
    def __init__(self):
        super().__init__()
        self.x = 0

    def atualizar(self):
        self.pintar()
        pass

    def pintar(self):
        self.delete("all")
        self.x += 1
        self.create_oval(
            10 + self.x, 10, 80 + self.x, 80, outline="#f11",width=1)
        pass


class Janela(Tk):
    def __init__(self, *args, **kwargs):
        Tk.__init__(self, *args, *kwargs)
        self.canvas = Jogo()
        self.canvas.pack(fill=BOTH, expand=1)
        self.canvas.create_line(15, 25, 200, 25)

        self.bind('<KeyPress>', self.tratar_tecla)

    def atualizar(self):
        self.canvas.atualizar()
        self.after(10, self.atualizar)

    def tratar_tecla(self, evento):
        tecla = evento.keycode
        if(tecla == 37):
            print("esq")
            return
        if(tecla == 38):
            print("cim")
            return
        if(tecla == 39):
            print("d")
            return
        if(tecla == 40):
            print("bai")
            return


app = Janela()
app.after(100, app.atualizar)
app.mainloop()
