import java.lang.reflect.Array;

public class Main {

    public static void main(String[] args) {
        int storageSize = 5;
        final int consumers = 4;
        final int producers = 3;
        int[] items_consumer = {4, 5, 6, 7};
        int[] items_producer = {7, 8, 7};
        Manager manager = new Manager(storageSize);

        for(int i=0; i<consumers; i++){
            new Consumer(items_consumer[i], manager, i);
        }
        for(int i=0; i<producers; i++){
            new Producer(items_producer[i], manager, i);
        }

    }
}
