package ru.gritsus.imkn.oop.java;

public class Task01 {

    public static void main(String[] args) {

        Point p1 = new Point();
        Point p2 = new Point(1,1);

        System.out.println("Расстояние между точками "+p1+" и "+p2+" равно "+p1.length(p2));
        
        Point p3 = new Point(2,2);
        Point p4 = new Point(1,2);
        
        Point[] points = {p2, p3, p4};
        if (Point.collinear(points)) {
        	System.out.println("Коллинеарны");
        } else {
        	System.out.println("Не коллинеарны");
        }
        
    }

}
