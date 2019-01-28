package ru.gritsus.imkn.oop.java;

public class Task02 {

	public static void main(String[] args) throws Exception {
		System.out.println("Введите координаты точек треугольника");
		Triangle tri = new Triangle(System.in);
		
		tri.print();
		tri.rotate(180);
		tri.print();
	}

}
