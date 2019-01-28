package ru.gritsus.imkn.oop.java;

import java.awt.Graphics;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class Ball extends Point {
	protected double sx;
	protected double sy;
	protected double r;
	protected Rect rect;
	protected double m;
	protected int id;
	protected int c = 0;
	Map<Integer, Ball> ignore = new HashMap<Integer, Ball>();
	
	static private int _id = 0;
	
	public Ball(Rect rect, double x, double y, double r, double m, double sx, double sy) {
		this.x = x;
		this.y = y;
		this.r = r;
		this.m = m;
		this.sx = sx;
		this.sy = sy;
		this.id = _id++;
		this.rect = rect;
	}
	
	public void move() {
		x += sx;
		y += sy;
		this.bounceIfNeeded(this.rect);
		this.ignore.clear();
		this.c = 0;
	}
	
	public void checkCollision(Ball b) {
		double R = r + b.r;
		if (this.c < 3 && b.c < 3
		&& !this.ignore.containsKey(b.id) 
		&& !b.ignore.containsKey(this.id)
		&& Math.abs(x - b.x) < R && Math.abs(y - b.y) < R
		&& Math.sqrt(Math.pow(x - b.x, 2) + Math.pow(y - b.y, 2)) < R) {
			// collision

//			if (this.sx / b.sx > 0.8
//			&&	this.sy / b.sy > 0.8) {
//				return;
//			}
			
			this.ignore.put(b.id, b);
			b.ignore.put(this.id, this);
			this.c++;
			b.c++;
			
			this.sx = (2*b.sx*b.m + sx*(m - b.m))/(b.m + m);
			b.sx = (2*sx*m + b.sx*(b.m - m))/(b.m + m);
			this.sy = (2*b.sy*b.m + sy*(m - b.m))/(b.m + m);
			b.sy = (2*sy*m + b.sy*(b.m - m))/(b.m + m);
		}
	}
	
	public void bounceIfNeeded(Rect r) {
		if (this.x < r.x1) {
			this.sx = Math.abs(this.sx)*0.8;
			this.x = r.x1 + this.sx;
		} else if (this.x > r.x2) {
			this.sx = -Math.abs(this.sx)*0.8;
			this.x = r.x2 + this.sx;
		}
		
		if (this.y < r.y1) {
			this.sy = Math.abs(this.sy)*0.8;
			this.y = r.y1 + this.sy;
		} else if (this.y > r.y2) {
			this.sy = -Math.abs(this.sy)*0.8;
			this.y = r.y2 + this.sy;
		}
	}
	
	public void draw(Graphics g) {
		g.drawOval((int) Math.round(x), (int) Math.round(y), (int) Math.round(this.r), (int) Math.round(this.r)); 
	}
	
	public static void checkCollisions(List<Ball> balls) {
		for (int i = 0; i < balls.size()-1; i++) {
			for (int j = i+1; j < balls.size(); j++) {
				balls.get(i).checkCollision(balls.get(j));
			}
		}
	}
	
	public static void move(Iterable<Ball> balls) {
		Iterator<Ball> i = balls.iterator();
		while (i.hasNext()) {
			i.next().move();
		}
	}
	
	public static void draw(Iterable<Ball> balls, Graphics g) {
		Iterator<Ball> i = balls.iterator();
		while (i.hasNext()) {
			i.next().draw(g);
		}
	}
}
