import tkinter
import math
root=tkinter.Tk()
global f

class GlobalVariables:
	LogMax=10
	FileMax=3
	Log=[""]*LogMax
	File=[0]*FileMax

MainVariables=GlobalVariables()
FileFolder="Files/"
#f=open('prueba.txt','w')
#print("Hola Mundo!",file=f)
def AlphaToRGB(Divisions):
	AlphaPerDivision=256/(Divisions)
	Color=[""]*Divisions
	for i in range(Divisions):
		CurrentAlpha=math.floor(AlphaPerDivision*(i+1))
		d1=str(math.floor(CurrentAlpha/16))
		d2=str(math.floor(CurrentAlpha%16))
		if d1=='10':
			d1='A'
		elif d1=='11':
			d1='B'
		elif d1=='12':
			d1='C'
		elif d1=='13':
			d1='d'
		elif d1=='14':
			d1='e'
		elif d1=='15':
			d1='f'
		if d2=='10':
			d2='A'
		elif d2=='11':
			d2='B'
		elif d2=='12':
			d2='C'
		elif d2=='13':
			d2='d'
		elif d2=='14':
			d2='e'
		elif d2=='15':
			d2='f'
		Color[i]="#"+d1+d2+d1+d2+d1+d2
	return Color

def clone(widget):
    parent = widget.nametowidget(widget.winfo_parent())
    cls = widget.__class__

    clone = cls(parent)
    for key in widget.configure():
        clone.configure({key: widget.cget(key)})
    return clone

def HolaUSS():
	f.write("Hola Mundo\n")
def FileOpen():
	name=FileFolder+(input("filenameto open: "))
	print(name)
	global f
	f =open(name,'w')

def FileClose():
	f.close()

def FileRead():
	name=FileFolder+input("filenameto open: ")
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
		Count+=1
		type= input(str(Count) +" ")
		if type!="quit":
			f.write(type)
			f.write("\n")
def FileCopyTo():
	name=FileFolder+input("source name: ")
	name2=FileFolder+input("destiny name: ")
	f=open(name,'r')
	g=open(name2,'w')
	linea=f.readline()
	while linea != "":
		g.write(linea)
		print(linea)
		linea=f.readline()
	f.close()
	g.close()
def ButtonPress(MainVar,Action):
	TempText=""
	if Action==1:
		TempText="Hola USS"
		HolaUSS()
	elif Action==2:
		TempText="File Opened"
		FileOpen()
	elif Action==3:
		TempText="File Closed"	
		FileClose()
	elif Action==4:
		TempText="File Read"
		FileRead()
	elif Action==5:
		TempText="File Wrote input"
		FileWriteInput()
	elif Action==6:
		TempText="File Copied"
		FileCopyTo()
	ColorLog=AlphaToRGB(MainVar.LogMax)
	for i in range(0,MainVar.LogMax-1):
		MainVar.Log[MainVar.LogMax-1-i].destroy()
		MainVar.Log[MainVar.LogMax-1-i]=clone(MainVar.Log[MainVar.LogMax-2-i])
		MainVar.Log[MainVar.LogMax-1-i].config(fg=ColorLog[i])
		MainVar.Log[MainVar.LogMax-1-i].pack()
	MainVar.Log[0].destroy()
	MainVar.Log[0]=tkinter.Label(FrameLog,text=TempText,bg="black",fg="white")
	MainVar.Log[0].pack()


FrameMain=tkinter.Frame(root,bg="black")
FrameMain.pack(fill="both",expand=True)
FrameLog=tkinter.Frame(root,bg="black")
FrameLog.pack(fill="both",expand=True)
for i in range(0,MainVariables.LogMax):
	MainVariables.Log[MainVariables.LogMax-i-1]=tkinter.Label(FrameLog,text="",bg="black",fg="white")
	MainVariables.Log[MainVariables.LogMax-i-1].pack()

Button02=tkinter.Button(FrameMain, text="Open Write",bg="#42472f",fg="white",
	command=lambda:ButtonPress(MainVariables,2))
Button02.pack(side="left")
Button01=tkinter.Button(FrameMain, text="write: Hola USS",bg="black",fg="white",
	command=lambda:ButtonPress(MainVariables,1))
Button01.pack(side="left")

Button03=tkinter.Button(FrameMain, text="Close",bg="#342f47",fg="white",
	command=lambda:ButtonPress(MainVariables,3))
Button03.pack(side="left")
Button04=tkinter.Button(FrameMain, text="Open Read",bg="black",fg="white",
	command=lambda:ButtonPress(MainVariables,4))
Button04.pack(side="left")
Button05=tkinter.Button(FrameMain, text="write Cutom Input",bg="black",fg="white",
	command=lambda:ButtonPress(MainVariables,5))
Button05.pack(side="left")
Button06=tkinter.Button(FrameMain, text="OPEN Copy Text CLOSE",bg="black",fg="yellow",
	command=lambda:ButtonPress(MainVariables,6))
Button06.pack(side="left")



root.mainloop()