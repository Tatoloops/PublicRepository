import tkinter as MyLib

"""
Unicode
"\N{GREEK CAPITAL LETTER DELTA}"  # Using the character name
'\u0394'
"\u0394"                          # Using a 16-bit hex value
'\u0394'
"\U00000394"                      # Using a 32-bit hex value
'\u0394'
"""
root = MyLib.Tk()

#Define functions
class Hero:
	GridX =5
	GridY =5
class Bulb:
	GridX =2
	GridY =2

def Button01Click():
	ClickMessage	=MyLib.Label(text="You clicked a button")
	ClickMessage.grid(row=1,column=0)

#Creating objects
"""
Message01	= MyLib.Label(text="Hello World!")
Message02	= MyLib.Label(text="This is a test")

Button01	= MyLib.Button(window, text="Click me!", bg="black",fg="white",command=Button01Click,padx=100, pady=200)
"""
DefaultText="\U00002623"
Player01=Hero()
Enemy=[Bulb()]*10
#placing objects
EnemiesAmount=1

MainGrid=[[0]*10]*10
MainGridWidth=7
MainGridHeight=3
GridColor01="#332d2e"
GridColor02="#2d3332"
GridColorLight01="#e6838d"
GridColorLight02="#77e0d5"
GridColorDark01="#851722"
GridColorDark02="#0f7368"

for i in range (10):
	root.columnconfigure(i,minsize=100,weight=1)
	root.rowconfigure(i,minsize=10,weight=1)
	for j in range (10):
		Check=0
		if (i%2==0 and j%2==0) or (i%2!=0 and j%2!=0):
			GridPar=0
		else:
			GridPar=1
		if Player01.GridX==i and Player01.GridY==j:
			if GridPar==0:
				MainGrid[i][j]	=MyLib.Label(text=DefaultText, bg=GridColorLight01, fg="white",width=MainGridWidth,height=MainGridHeight)
			else:
				MainGrid[i][j]	=MyLib.Label(text=DefaultText, bg=GridColorLight02, fg="white",width=MainGridWidth,height=MainGridHeight)
			Check=1
		for k in range (EnemiesAmount):
			if Enemy[i].GridX==i and Enemy[j].GridY==j:
				if GridPar==0:
					MainGrid[i][j]	=MyLib.Label(text="X", bg=GridColorDark01, fg="black",width=MainGridWidth,height=MainGridHeight)
				else:
					MainGrid[i][j]	=MyLib.Label(text="X", bg=GridColorDark02, fg="black",width=MainGridWidth,height=MainGridHeight)
				Check=1
				k=EnemiesAmount
		if Check==0:
			if GridPar==0:
				MainGrid[i][j]	=MyLib.Label(bg=GridColor01, fg=GridColor01,width=MainGridWidth,height=MainGridHeight)
			else:
				MainGrid[i][j]	=MyLib.Label(bg=GridColor02, fg=GridColor02,width=MainGridWidth,height=MainGridHeight)

		
		MainGrid[i][j].grid(row=i,column=j)

root.mainloop()