public class Main {
    public static void main(String[] args) {
        StopThread stopThread = new StopThread();


        for(int i=1;i<=10;i++)
        {
            new SumThread(i, stopThread, 5).start();
        }

        new Thread(stopThread).start();
    }
}