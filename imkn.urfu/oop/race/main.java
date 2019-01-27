class OutThread extends Thread{
  private String msg;

  OutThread(String s, String name) {
    super(name);
    msg=s;
  }

  public void run() {
    for(int i=0; i<5;i++) {
      //try{
      // Thread.sleep(5);
      //} catch(InterruptedException ie){}
      System.out.print(msg+" ");
    }

    System.out.print("End of "+getName());
    }

    public static void main(String[] args) {
      new OutThread("FIRST","Thread 1").start();
      new OutThread("Second","Thread 2").start();
      new OutThread("Hip","Thread 3").start();
      new OutThread("hop","Thread 4").start();
      System.out.println("END");
    }
  }
}
