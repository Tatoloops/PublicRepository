import tkinter
root=tkinter.Tk()
global f

#f=open('prueba.txt','w')
#print("Hola Mundo!",file=f)

def HolaUSS():
	f.write("Hola Mundo\n")
def FileOpen():
	name=input("filenameto open: ")
	global f
	f =open(name,'w')
def FileClose():
	f.close()

def FileRead():
	name=input("filenameto open: ")
	f=open(name,'r')
	linea=f.readline()
	while linea != "":
		print(linea)
		linea=f.readline()
def FileWriteInput():
	type="a"
	print("type \"quit\" to close: ")
	Count=0
	while type!="quit":
		++Count
		type= input(string(Count) ," ")
		if type!="quit":
			f.write(type)
			f.write("\n")
def FileCopyTo():
	name=input("source name: ")
	name2=input("destiny name: ")
	f=open(name,'r')
	g=open(name2,'w')
	linea=f.readline()
	while linea != "":
		g.write(linea)
		print(linea)
		linea=f.readline()
	f.close()
	g.close()

FrameMain=tkinter.Frame(root,bg="black")
FrameMain.pack(fill="both",expand=True)

Button02=tkinter.Button(FrameMain, text="Open Write",bg="#42472f",fg="white",command=FileOpen)
Button02.pack(side="left")
Button01=tkinter.Button(FrameMain, text="write: Hola USS",bg="black",fg="white",command=HolaUSS)
Button01.pack(side="left")

Button03=tkinter.Button(FrameMain, text="Close",bg="#342f47",fg="white",command=FileClose)
Button03.pack(side="left")
Button04=tkinter.Button(FrameMain, text="Open Read",bg="black",fg="white",command=FileRead)
Button04.pack(side="left")
Button05=tkinter.Button(FrameMain, text="write Cutom Input",bg="black",fg="white",command=FileWriteInput)
Button05.pack(side="left")
Button06=tkinter.Button(FrameMain, text="OPEN Copy Text CLOSE",bg="black",fg="yellow",command=FileCopyTo)
Button06.pack(side="left")



root.mainloop()