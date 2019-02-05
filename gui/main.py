import tkinter as tk

LARGE_FONT = ("Verdana",12)

class SeaBTCApp(tk.Tk):
    # propio , variaveis , dicionarios
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        # inicializando janela em si
        container = tk.Frame(self)
        # setando o layout
        container.pack(side="top", fill="both", expand=True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        # dicionario vazio, que vai conter todas as telas do App
        self.frames = {}
        # criando a pagina inicia
        frame = StartPage(container, self)
        # defininindo no dicionario com a entrada StarterPage tem o conteúdo de frame
        self.frames[StartPage] = frame
        # configurando o frame
        frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(StartPage)

    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()

class StartPage(tk.Frame):
    def __init__(self,parent,controller):
        tk.Frame.__init__(self,parent)
        label = tk.Label(text="Start Page",font=LARGE_FONT)
        label.pack(pady=10,padx=10)


app = SeaBTCApp()
app.mainloop()