package ru.gritsus.imkn.oop.java;

public class Square extends Rect {
	
	public Square(int size) {
		this(0, 0, size);
	}
	
	public Square(int x, int y, int size){
		super(x, y, x + Math.abs(size), y + Math.abs(size));
    }

	public Square union(Square s) {
		// TODO Auto-generated method stub
		return (Square) super.union(s);
	}
	
	public double publicInscribedCircleRadius() {
		return Math.abs(this.x1 - this.x2) / 2;
	}
}
