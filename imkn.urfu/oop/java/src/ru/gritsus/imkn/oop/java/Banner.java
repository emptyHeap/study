package ru.gritsus.imkn.oop.java;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;

@SuppressWarnings("serial")
public class Banner extends Applet implements Runnable{

	Thread thread = null;
	String message = "-- moving banner --";
	
	public void init() {
		setBackground(Color.cyan);
		setForeground(Color.red);
		
		thread = new Thread(this);
		
		thread.start();
	}
	
	@Override
	public void run() {
		while (true) {
			repaint();
			try {
				Thread.sleep(250);
				char c = message.charAt(0);
				message = message.substring(1) + c;
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public void destroy() {
		if (thread != null) {
			thread.interrupt();
			thread = null;
		}
	}

	public void paint(Graphics g) {
		g.drawString(message, 10, 20);
	}
}
