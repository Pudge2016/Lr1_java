public class SumThread extends Thread{
    private final int id;
    private final StopThread stopThread;
    private final int step;

    public SumThread(int id, StopThread stopThread, int step) {
        this.id = id;
        this.stopThread = stopThread;
        this.step=step;
    }

    @Override
    public void run() {
        long sum = 0;
        int additions = 0;
        boolean isStop = false;
        do{
            sum += additions * step;
            additions++;
            isStop = stopThread.isCanStop();
        } while (!isStop);
        System.out.println("Thread " + id + " - Sum: " + sum + " - Additions: " + additions);
    }
}
