package ru.gritsus.imkn.oop.java;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GraphicsEnvironment;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.JLabel;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class BannerPanel extends JPanel{
	
	LinkedList<JLabel> labels = new LinkedList<JLabel>();
	String string;
	String[] fontNames;
	
	Thread updateThread;
	Timer updateTimer;
	
	int position;
	int speed;
	int refreshRate;
	int letterIndent;
	int fontsCount;
	int fontsSizes;
	
	ArrayList<Font> fonts = new ArrayList<Font>();
	
	public BannerPanel() {
		super();
		this.setText("test");
		fontNames = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
		speed = 2;
		position = 0;
		refreshRate = 24;
		letterIndent = 10;
		fontsCount = 40;
		fontsSizes = 100;
		
		for (int i = 0; i < fontsCount; i++) {
			//Font newFont = new Font(fontNames[i], Font.PLAIN, (int) (10 + Math.round(Math.random()*20)));
			Font newFont = new Font(fontNames[i], Font.PLAIN, (int) (12 + Math.round(Math.random()*10)));
			fonts.add(newFont);
		}
		
		this.updateTimer = new Timer();
		this.updateTimer.schedule(new TimerTask() {
			
			@Override
			public void run() {
				repaint();
				revalidate();
			}
		}, (long)0, (long)1000/refreshRate); 
		
//		this.updateThread = new Thread(this);
//		this.updateThread.start();
	}
	
	public void paint(Graphics g) {
		g.clearRect(0, 0, this.getWidth(), this.getHeight());
		if (position > this.getWidth()) {
			position = -string.length() * letterIndent;
		}
		for (int i = 0; i < string.length(); i++) {
//			g.setFont(new Font(
//					fontNames[(int) Math.round(fontNames.length*Math.random())], 
//					Font.PLAIN, 
//					(int) (10 + Math.round(Math.random()*20)))
//			);
			g.setColor(new Color((float)Math.random(), (float)Math.random(), (float)Math.random())); 
			g.setFont(fonts.get((int) Math.round((Math.random() * fonts.size() - 0.5))));
			g.drawString(string.substring(i, i+1), position + i * letterIndent, 50);
		}
		position += speed;
	}
	
	public Dimension getPreferredSize() {
		return new Dimension(400,400);
	}
	
	public void setText(String newText) {
		this.string = newText;
//		Iterator<JLabel> iter = labels.iterator();
//		while(iter.hasNext()) {
//			this.remove(iter.next());
//		}
//		labels.clear();
//		
//		for (int i = 0; i < newText.length(); i++) {
//			JLabel newLabel = new JLabel(newText.substring(i, i+1));
//			labels.add(newLabel);
//		}
	}

	public void run() {
		while (true) {
			this.repaint();
			try {
				Thread.sleep(1000 / this.refreshRate);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
