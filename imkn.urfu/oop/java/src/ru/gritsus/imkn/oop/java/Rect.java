package ru.gritsus.imkn.oop.java;

public class Rect {
    protected int x1,y1,x2,y2;

    public Rect(int x1, int y1, int x2, int y2){
        this.x1=Math.min(x1, x2);
        this.y1=Math.min(y1, y2);     
        this.x2=Math.max(x1, x2);
        this.y2=Math.max(y1, y2);
    }

    public Rect(int width, int height) {this(0, 0, width, height);}

    public Rect() {this(0,0,0,0);}  
    
    public void move(int deltax, int deltay){
        x1 +=deltax;
        y1 +=deltay;
        x2 +=deltax;
        y2 +=deltay;
    }
    
    public boolean isInside(int x, int y) {
        return ((x>=x1) && (x<=x2) && (y>=y1) && (y<=y2));
    }
    
    // Возвращает новый прямоугольник, в который вписаны прямоугольники this и r
    public Rect union(Rect r){
        return new Rect(
        	(this.x1<r.x1)? this.x1 : r.x1,
            (this.y1<r.y1)? this.y1 : r.y1, 
            (this.x2>r.x2)? this.x2 : r.x2,         
            (this.y2>r.y2)? this.y2 : r.y2);
    }
    
    // Возвращает новый прямоугольник - пересечение прямоугольников this и r. Если пересечения нет, координаты результата - нули (ну почти).
    public Rect intersection(Rect r) {
        Rect result = new Rect (
        	(this.x1>r.x1)? this.x1 : r.x1,
            (this.y1>r.y1)? this.y1 : r.y1, 
            (this.x2<r.x2)? this.x2 : r.x2,         
            (this.y2<r.y2)? this.y2 : r.y2);
        // соглашение x1, y1 что левая нижняя точка x2, y2 правая верхняя
        //if (result .x1> result.x2) {result.x1 = result.x2 = 0;}
        //if (result .y1> result.y2) {result.y1 = result.y2 = 0;}
        return result;
    }
    
    // Вычисление площади
    public double square() {
    	return Math.abs(this.x1 - this.x2) * Math.abs(this.y1 - this.y2);
    }
    
    // Радиус описанной окружности
    public double circumcircleRadius() {
    	return Math.sqrt(Math.pow(this.x1 - this.x2, 2) + Math.pow(this.y1 - this.y2, 2)) / 2;
    }
    
    public String toString() {
        return "[" + x1+", "+y1+", "+x2+", "+y2+"]";
    }
}
