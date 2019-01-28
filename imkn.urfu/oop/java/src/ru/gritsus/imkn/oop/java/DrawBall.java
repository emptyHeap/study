package ru.gritsus.imkn.oop.java;

import java.applet.Applet;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

import javax.swing.JFrame;

public class DrawBall implements Runnable{
	Graphics g;
	Applet applet;
	ArrayList<Ball> balls = new ArrayList<Ball>();
	
	public DrawBall(Applet applet, int count, Color baseColor) {
		this.applet = applet;
		this.g = applet.getGraphics().create();
		Rect rect = new Rect(20, 20, applet.getWidth(), applet.getHeight());
		
		for (int i = 0; i < count; i++) {
			this.balls.add(new Ball(rect, 
					Math.random()*applet.getWidth(), Math.random()*applet.getHeight(), 
					Math.random()*2 + 3, Math.random()*1 + 4, 
					Math.random()*1, Math.random()*1));
		}
	}

	@Override
	public void run() {
		while (true) {
			Ball.checkCollisions(balls);
			Ball.move(balls);
			g.clearRect(0, 0, applet.getHeight(), applet.getWidth());
			Ball.draw(balls, g);
			try {
				Thread.sleep(20);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
