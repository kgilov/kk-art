#!/usr/bin/env python

import os.path
import serial
from Tkinter import *

if (os.path.exists("/dev/ttyACM0")):
    usbport = '/dev/ttyACM0'
else:
    if (os.path.exists("/dev/ttyUSB0")):
        usbport = '/dev/ttyUSB0'
    else:
        usbport = ''

#H_max = 1680
#V_max = 1050

serialConn = serial.Serial(usbport, 115200, timeout=0.5)

class App_Arm_Export:

    def __init__(self, window, h_max=800, v_max=600):

        self.window = window
        self.canvas = Canvas(self.window, width=h_max, height=v_max)
        self.canvas.pack()

        self.xoff = h_max/10;
        self.yoff = v_max/4;

        self.Nsec = 5
        self.startYear = 1960
        self.yearsPerSec = 10
        self.Nstep = 6

        self.Nstep = 6;
        self.startAmount = 2500
        self.amountPerStep = 2500

        self.x0 = self.xoff
        self.y0 = v_max - self.yoff
        self.xMax = h_max - self.xoff
        self.yMax = self.yoff/2

        self.xOld = self.x0
        self.yOld = self.y0

        self.period = (self.xMax - self.x0)/self.Nsec
        self.step = (self.y0 - self.yMax)/self.Nstep

        self.title = "Annual Expenditure on Arms Exports (constant 1990 US$)"
        self.source1 = "Stockholm International Peace Research Institute (SIPRI), Yearbook: Armaments, Disarmament and International Security."
        self.source2 = "Catalog Sources: World Development Indicators"
	self.text1 = "The Last Gun, created from instruments of both destruction and harmony, is a commentary on the excesses of the technological age and the exploits of war. The programmable robot graphically charts and then musically depicts the rise & fall of U.S. annual arms exports from 1960 to 2010. The flute's aural response is based upon a value judgment where a rise in arms exports triggers it to play a somber melody and for every drop in the exports it plays a celebratory, upbeat tune."

    def drawTemplate(self):

        self.canvas.config(bg="black")
        self.canvas.create_text((self.xMax+self.xoff)/2, self.yMax/2, width=self.xMax - self.xoff, text=self.title, font="Arial 16 bold", fill="white")
        self.canvas.create_line(self.x0, self.y0, self.x0, self.yMax-7, width=2, arrow=LAST, fill="gray50")
        self.canvas.create_line(self.x0, self.y0, self.xMax+7, self.y0, width=2, arrow=LAST, fill="gray50")
        for i in range(0, self.Nsec+1):
            self.canvas.create_line(self.x0+i*self.period, self.y0, self.x0+i*self.period, self.yMax, fill="gray25")
            self.canvas.create_text(self.x0+i*self.period, self.y0+15, text=self.startYear+i*self.yearsPerSec , fill="gray25", font="Arial 10")

        for i in range(1, self.Nstep+1):
            self.canvas.create_line(self.x0-5, self.y0-i*self.step, self.xMax, self.y0-i*self.step, fill="gray25")
            self.canvas.create_text(self.x0-10, self.y0-i*self.step, text=self.startAmount+i*self.amountPerStep , fill="gray25", font="Arial 10", anchor=NE)

        self.canvas.create_rectangle(self.x0, self.y0+25, self.x0+30, self.y0+25+10, fill="red")
        self.canvas.create_text(self.x0+35, self.y0+25, text="United States (in millions)", font="Arial 10", anchor=NW, fill="white")
        self.canvas.create_text(self.x0, self.y0+60, text=self.text1, font="Monospace 12", width=self.xMax - self.xoff, anchor=NW, fill="white")
        self.canvas.create_text(self.x0, self.y0+self.yoff-self.yMax/2, text=self.source1, font="Times 10", width=self.xMax - self.xoff, anchor=NW, fill="white")
        self.canvas.create_text(self.x0, self.y0+self.yoff-self.yMax/2+15, text=self.source2, font="Times 10", width=self.xMax - self.xoff, anchor=NW, fill="white")
	
    def templateLine(self,dataReal, dataPos):

        self.xNew = self.x0 + dataPos*self.period/10
        self.yNew = self.y0 - dataReal
        self.canvas.create_line(self.xOld, self.yOld, self.xNew, self.yNew, fill="gray50", width=2)
        self.xOld = self.xNew
        self.yOld = self.yNew


    def serialRead(self):

        self.sread = serialConn.readline().strip("\r\n") 
        if len(self.sread) > 0:
            if self.sread == "s0000":
                self.canvas.delete(ALL)
                self.drawTemplate()
                self.xOld = self.x0
                self.yOld = self.y0
		data = [5998,6590,5721,9334,12291,11532,8603,7472,8400,11606,8889,11194,9941,12088,11778,16111,15463,15789,14696,10095,10985,13775,14096,13547,11540,10591,11487,12276,11696,11079,10495,12578,14254,14516,11700,11188,10839,14247,15293,11293,7220,5694,5091,5596,6750,6600,7394,7658,6090,6795,6000]
		yearCurrentT = 0
		for x in data:
                    inByteT = (x - 2500)*(self.y0-self.yMax)/15000
                    self.templateLine(inByteT, yearCurrentT)
                    yearCurrentT = yearCurrentT +1
 
                self.xOld = self.x0
                self.yOld = self.y0
            else:
                yearCurrent = int(self.sread[:4]) % self.startYear
                inByte = (int(self.sread[4:]) - 2500)*(self.y0-self.yMax)/15000
                self.drawGraphLine(inByte, yearCurrent)


        self.window.after(500, self.serialRead)

    def drawGraphLine(self, dataReal, dataPos):

        self.xNew = self.x0 + dataPos*self.period/10
        self.yNew = self.y0 - dataReal
        self.canvas.create_oval(self.xNew-3, self.yNew-3, self.xNew + 3, self.yNew + 3, fill="red")
        if self.yOld != self.y0 :
            self.canvas.create_line(self.xOld, self.yOld, self.xNew, self.yNew, fill="red", width=3)
        self.xOld = self.xNew
        self.yOld = self.yNew


def serialClear():
    while True:
        sread = serialConn.readline().strip("\r\n")
        if sread == "c":
            return

def main():

    serialClear()
    graph = Tk()
    H_max = graph.winfo_screenwidth()
    V_max = graph.winfo_screenheight()
    app = App_Arm_Export(graph, H_max, V_max)
    graph.wm_title("US Arms Export")
    graph.geometry("{0}x{1}+0+0".format(H_max, V_max))
    graph.after(500, app.serialRead)
    graph.mainloop()


if __name__ == '__main__':
        main()
