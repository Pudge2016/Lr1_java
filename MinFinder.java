public class MinFinder extends Thread {
    private final int startIndex;
    private final int endIndex;
    private final int[] arr;
    private final Main main;

    public MinFinder(int startIndex, int endIndex, int[] arr, Main main) {
        this.startIndex = startIndex;
        this.endIndex = endIndex;
        this.arr = arr;
        this.main = main;
    }

    @Override
    public void run() {
        int localMin = Integer.MAX_VALUE;
        for (int i = startIndex; i < endIndex; i++) {
            if (arr[i] < localMin) {
                localMin = arr[i];
            }
        }
        main.updateMin(localMin);
        main.threadFinished();
    }
}
