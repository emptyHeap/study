package ru.gritsus.imkn.oop.java;

import java.util.Arrays;
import java.util.Iterator;

class Point {

    public double x; // абсцисса точки
    public double y; // ордината точки

    // возвращает строку с описанием точки

    public String toString() {
        return "("+x+";"+y+")";
    }

    // выводит на экран описание точки

    public void printPoint() {
        System.out.print(this.toString());
    } 
    
    // выводит на экран четверть в которой расположена точка
    
    public void printQuarter() {
    	String position;
    	
    	if (this.x > 0) {
    		if (this.y > 0) {
    			position = "первая четверть";
    		} else if (this.y < 0) {
    			position = "четвёртая четверть";
    		} else {
    			position = "первая и четвёртая четверть";
    		}
    	} else if (this.x < 0) {
    		if (this.y > 0) {
    			position = "вторая четверть";
    		} else if (this.y < 0) {
    			position = "третья четверть";
    		} else {
    			position = "вторая и третья четверти";
    		}
    	} else {
    		if (this.y > 0) {
    			position = "первая и вторая четверти";
    		} else if (this.y < 0) {
    			position = "третья и четвёртая четверти";
    		} else {
    			position = "все четверти";
    		}
    	}
    	
    	System.out.println(position);
    }

    // метод перемещает точку на указанный вектор

    public void movePoint(double a, double b) {
        x = x + a;
        y = y + b;
    }

    // метод изменяет координаты точки на указанные    	


    public void setPoint(double a, double b) {
        x = a;
        y = b;
    } 

    // конструктор по умолчанию, создающий точку в начале координат

    public Point() {
        x = 0.0;
        y = Math.random() * 99;
    }

    // конструктор, создающий точку с указанными координатами

    public Point(double a, double b) {
        x = a;
        y = b;
    }  

    // метод вычисляющий расстояние между точками

    public double length(Point p) {
        return Math.sqrt( Math.pow(p.x-x,2) + Math.pow(p.y-y,2) );
    }

    // метод проверяющий совпадают ли точки

    public boolean equalsPoint(Point p) {
        if(this.x == p.x && this.y == p.y) {
            return true;
        } else {
            return false;
        }
    }
    
    // метод проверяющий симметричны ли точки
    
    public boolean simmetrical(Point another) {
    	return this.x == -another.x && this.y == -another.y;
    }
    
    // метод проверяющий коллинеарность точек
    
    static public boolean collinear(Iterable<Point> points) {
    	Iterator<Point> i = points.iterator();
    	Point firstOne = i.next();
    	Point secondOne = i.next();
    	double k = (firstOne.y - secondOne.y) / (firstOne.x - secondOne.x);
    	
    	while (i.hasNext()) {
    		Point next = i.next();
    		
    		if (next.equalsPoint(firstOne)) continue;
    		
    		double nextK = (firstOne.y - next.y) / (firstOne.x - next.x);
    		if (nextK != k) return false;
    	}
    	
    	return true;
    }
    
    // прибавляет координаты другой точки
    
    public void add(Point another) {
    	this.x += another.x;
    	this.y += another.y;
    }
    
    // вычитает координаты другой точки
    
    public void sub(Point another) {
    	this.x -= another.x;
    	this.y -= another.y;
    }
    
    // деление на скаляр
    
    public void div(double v) {
    	this.x /= v;
    	this.y /= v;
    }
    
    // поворачивает относительно точки
    
    public void rotate(double g, Point p) {
    	this.sub(p);
    	this.rotate(g);
    	this.add(p);
    }
    
    // поворачивает относительно начала координат
    
    public void rotate(double g) {
    	double sin = Math.sin((g/180)*Math.PI);
    	double cos = Math.cos((g/180)*Math.PI);
    	double nx = this.x * cos - this.y * sin;
    	double ny = this.y * cos + this.x * sin;
    	this.x = nx;
    	this.y = ny;
    }
    
    // проверяет коллинеарность точек
    
    static public boolean collinear(Point[] points) {
    	return Point.collinear(Arrays.asList(points));
    }

}
