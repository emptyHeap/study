package ru.gritsus.imkn.oop.java;

import java.applet.*;
import java.awt.*;
public class Rectangles extends Applet
{
  DrawRectangles m_DrawRectThread = null;
  DrawEllipse m_DrawEllipseThread = null;
  NotifyTask m_NotifyTaskThread = null;
// Эти поля являются ссылками на классы, соответственно DrawRectangles,
// DrawEllipse и NotifyTask . Первый из них создан для рисования 
// прямоугольников, второй - эллипсов, а третий - для управления потоком
 // рисования эллипсов. Указанные поля инициализируются значением null,
// что соответствует неработающим или не созданным задачам.
 public String getAppletInfo()
  {
    return "Name: Rectangles";
  }
  public void paint(Graphics g)
  {
    Dimension dimAppWndDimension = getSize();
    g.setColor(Color.yellow);
    g.fillRect(0, 0, 
      dimAppWndDimension.width  - 1, 
      dimAppWndDimension.height - 1);
    g.setColor(Color.black);
    g.drawRect(0, 0, 
      dimAppWndDimension.width  - 1, 
      dimAppWndDimension.height - 1);
  }
  public void start()
  {
// Метод start класса Rectangles Этот метод последовательно создает 
// три потока и запускает их на выполнение
    if (m_DrawRectThread == null)
    {
      m_DrawRectThread = 
        new DrawRectangles(this);
      m_DrawRectThread.start(); // 1-ый поток
    }
    if (m_DrawEllipseThread == null)
    {
      m_DrawEllipseThread = 
        new DrawEllipse(this);
      m_DrawEllipseThread.start();  // 2-ой поток
    }
    if (m_NotifyTaskThread == null)
    {
      m_NotifyTaskThread = 
        new NotifyTask(m_DrawEllipseThread);
      m_NotifyTaskThread.start();// 3-ий поток
    }
  }
// Когда пользователь покидает страницу сервера Web с апплетом, метод 
// stop класса Rectangles последовательно останавливает рисования 
// прямоугольников и эллипсов, а также управляющий поток:
  public void stop()
  {
    if (m_DrawRectThread != null)
    {
      m_DrawRectThread.stop();
      m_DrawRectThread = null;
    }
    if (m_DrawEllipseThread == null)
    {
      m_DrawEllipseThread.stop();
      m_DrawEllipseThread = null;
    }    
    if (m_NotifyTaskThread != null)
    {
      m_NotifyTaskThread.stop();
      m_NotifyTaskThread = null;
    }
  }
}
// Класс DrawRectangles определен для потока рисования прямоугольников
// В поле g класса хранится контекст отображения окна апплета, а в поле 
// dimAppWndDimension – размеры этого окна: Значения этих полей 
// определяются конструктором класса по ссылке на главный класс апплета.
class DrawRectangles extends Thread
{
  Graphics g;
  Dimension dimAppWndDimension;
  public DrawRectangles(Applet Appl)
  {
    g = Appl.getGraphics(); // В качестве параметра конструктору передается 
                                                        // ссылка на класс апплета
    dimAppWndDimension = Appl.getSize();
//Конструктор использует эту ссылку для получения и сохранения в полях
// класса контекста отображения и размеров окна апплета
  }
// Программный код метода run работает в рамках отдельного потока. 
//  Он рисует в окне апплета закрашенные прямоугольники. Прямоугольники
// имеют случайные  координаты, расположение и цвет. Для того чтобы 
// рисовать, необходимо получить  контекст отображения. Этот контекст был 
// получен конструктором  класса DrawRectangles и может быть использован 
// методом run. // Вооружившись контекстом отображения и размерами окна 
// апплета, поток входит  в бесконечный цикл рисования прямоугольников. 
// В качестве генератора случайных чисел мы используем метод random из 
//  класса  Math, который при каждом  вызове возвращает новое случайное
// число типа  double, лежащее в диапазоне значений от 0.0 до 1.0. 
//  Координаты по осям X и Y  рисуемого прямоугольника определяются 
// простым умножением случайного  числа, полученного от метода random, 
// соответственно, на ширину и высоту  окна апплета: 
  public void run()
  {
    while (true)
    {
      int x, y, width, height;
      int rColor, gColor, bColor;      
      x =      (int)(dimAppWndDimension.width * Math.random());
  y =      (int)(dimAppWndDimension.height * Math.random());
 width  = (int)(dimAppWndDimension.width * Math.random()) / 2;
 height = (int)(dimAppWndDimension.height  * Math.random()) / 2;      
 rColor = (int)(255 * Math.random()); // Для случайного выбора цвета 
 gColor = (int)(255 * Math.random());// прямоугольника вычисляем 
 bColor = (int)(255 * Math.random()); // отдельные цветовые компоненты, 
                           // умножая значение, полученное от метода random, на 255
 g.setColor(new Color(rColor, gColor, bColor)); //цвет устанавливается в 
                                                     // контексте отображения методом setColor
      g.fillRect(x, y, width, height);
      try     // После рисования прямоугольника метод run задерживает свою 
               // работу на 50 миллисекунд, вызывая метод sleep:
      {
        Thread.sleep(50);
      }
      catch (InterruptedException e)
      {
        stop();
      }     // Для обработки исключения InterruptedException, которое может
    }       // возникнуть во время работы этого метода, предусмотриv блок.
  }        // try – catch.  При возникновении указанного исключения работа 
}          // потока останавливается вызовом метода stop

class DrawEllipse extends Thread
{                         //   Класс DrawEllipse очень похож на только что 
  Graphics g;      // рассмотренный класс DrawRectangles
  Dimension dimAppWndDimension;
  public DrawEllipse(Applet Appl)
  {
    g = Appl.getGraphics();
    dimAppWndDimension = Appl.getSize();
  }
  public synchronized void run()
  {
    while (true)
    {
      int x, y, width, height;
      int rColor, gColor, bColor;
      x =      (int)(dimAppWndDimension.width  * Math.random());
      y =      (int)(dimAppWndDimension.height  * Math.random());
      width  = (int)(dimAppWndDimension.width * Math.random()) / 2;
      height = (int)(dimAppWndDimension.height  * Math.random()) / 2;
      rColor = (int)(255 * Math.random());
      gColor = (int)(255 * Math.random());
      bColor = (int)(255 * Math.random());
      g.setColor(new Color(rColor,  gColor, bColor));
      g.fillOval(x, y, width, height);
      try
      {
        this.wait();
      }
      catch (InterruptedException e)
      {
      }
    }
  }
}
class NotifyTask extends Thread
{ // В классе NotifyTask мы определили одно поле STask класса Thread.
   // Это поле которое хранит ссылку на поток, работой которого управляет 
   // данный класс:
  Thread STask;
  public NotifyTask(Thread SynchroTask)
  {
    STask = SynchroTask;
  }
//  Метод run класса NotifyTask периодически разблокирует поток рисования
//  эллипсов, вызывая для этого метод notify в цилке с задержкой 30 
//  миллисекунд. Обращение к объекту STask, который хранит ссылку 
// на поток рисования эллипсов, выполняется с использованием синхронизации: 
  public void run()
  {
    while (true)
    {
      try
      {
        Thread.sleep(30);
      }
      catch (InterruptedException e)
      {
      }
      synchronized(STask)
      {
        STask.notify();
      }    }  }  }