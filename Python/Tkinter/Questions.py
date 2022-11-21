import tkinter
root=tkinter.Tk()

#Black
ColorA1="#1f211e"
ColorB1="#211e21"
#Gray
ColorA2="#323631"
ColorB2="#343136"
#Light
ColorA3="#aab3a6"
ColorB3="#aea6b3"

FrameHeader = tkinter.Frame(master=root, height=25, bg=ColorA1)
FrameHeader.pack(fill=tkinter.X, expand=False)

FrameMain=tkinter.Frame(master=root,height=10,width=10,bg=ColorB1)
FrameMain.pack(fill=tkinter.BOTH,expand=True)

FrameFooter = tkinter.Frame(master=root, height=25, bg=ColorA1)
FrameFooter.pack(fill=tkinter.X,expand=False)

HeaderLabelAmount=2
HeaderLabel=[0]*HeaderLabelAmount

HeaderLabel[0]=tkinter.Button(FrameHeader,text="File",bg=ColorA1,fg=ColorA3)
HeaderLabel[1]=tkinter.Button(FrameHeader,text="Options",bg=ColorA1,fg=ColorA3)

HeaderLabel[0].pack(side=tkinter.LEFT)
HeaderLabel[1].pack(side=tkinter.LEFT)

FooterLabelAmount=1
FooterLabel=[0]*FooterLabelAmount
FooterLabel[0]=tkinter.Label(master=FrameFooter,text="Copyright, all rights reserved.",bg=ColorA1,fg=ColorA2)
FooterLabel[0].pack(side=tkinter.LEFT)

root.mainloop()
