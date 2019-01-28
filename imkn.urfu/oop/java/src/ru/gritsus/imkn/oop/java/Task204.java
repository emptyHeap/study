package ru.gritsus.imkn.oop.java;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;

@SuppressWarnings("serial")
public class Task204 extends Applet {
	static Thread firstThread;
	
	public void start() {
		firstThread = new Thread(new DrawBall(this, 100, Color.black));
		firstThread.start();
	}
	
	public void paint(Graphics g)
	{
		Dimension dimAppWndDimension = getSize();
		g.setColor(Color.yellow);
		g.fillRect(0, 0, 
			dimAppWndDimension.width  - 1, 
			dimAppWndDimension.height - 1);
		g.setColor(Color.black);
		g.drawRect(0, 0, 
			dimAppWndDimension.width  - 1, 
			dimAppWndDimension.height - 1);
	}
	
	public static void main(String[] args) {
//		JFrame mainFrame = new JFrame("Balls");
//		firstThread = new Thread(new DrawBall(mainFrame, 10, Color.black));
//		mainFrame.setVisible(true);
//		firstThread.start();
	}
}
