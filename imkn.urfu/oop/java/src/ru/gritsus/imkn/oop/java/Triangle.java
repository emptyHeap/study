package ru.gritsus.imkn.oop.java;

import java.io.InputStream;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class Triangle {
	private LinkedList<Point> points;
	
	// Конструктор из потока
	
	Triangle(InputStream stream) throws Exception {
		Scanner scanner = new Scanner(stream);
		points = new LinkedList<Point>();
		for (int i = 0; i < 3; i++) {
			points.add(new Point(scanner.nextDouble(), scanner.nextDouble()));
		}
		scanner.close();
		
		
		if (Point.collinear(points)) {
			throw new Exception("Точки треугольника не должны лежать на одной прямой");
		}
	}
	
	// Вывод на экран информации о треугольнике
	
	void print() {
		System.out.print("Треугольник, состоящий из точек: (");
		Iterator<Point> i = points.iterator();
		while(i.hasNext()) {
			i.next().printPoint();
		}
		System.out.print(")");
	}
	
	// Поворот на градусы относительно центра тяжести
	
	void rotate(double g) {
		Point mass = new Point(0,0);
		
		Iterator<Point> i = points.iterator();
		int total = 0;
		while (i.hasNext()) {
			total++;
			mass.add(i.next());
		}
		mass.div(total);
		
		this.rotate(g, mass);
	}
	
	// Вращение относительно точки
	
	void rotate(double g, Point center) {
		Iterator<Point> i = points.iterator();
		while(i.hasNext()) {
			Point figurePoint = i.next();
			figurePoint.rotate(g, center);
		}
	}
}
