public class StopThread implements Runnable {
    private boolean canStop=false;
    @Override
    public void run() {
        try {
            Thread.sleep(3*1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        canStop= true;
    }

    synchronized public boolean isCanStop()
    {
        return  canStop;
    }
}
