import java.util.concurrent.atomic.AtomicInteger;

public class Main {

    public static void main(String[] args) {
        Main main = new Main();
        ArrayManager arrayManager = new ArrayManager(1000, 10);
        arrayManager.generateArray();
        arrayManager.findMin(main);
        System.out.println("Мінімальний елемент масиву: " + main.min.get());
        System.out.println("Індекс мінімального елементу: " + arrayManager.findIndex(main.min.get()));
    }

    private final AtomicInteger min = new AtomicInteger(Integer.MAX_VALUE);

    public void updateMin(int localMin) {
        min.updateAndGet(currentMin -> Math.min(currentMin, localMin));
    }
}
