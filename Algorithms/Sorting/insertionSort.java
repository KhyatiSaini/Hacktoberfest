import java.util.Arrays;

public class insertionSort {

    static void InsertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && key < array[j]) {
                array[j + 1] = array[j];
                --j;
            }
            array[j + 1] = key;
        }
    }
    
    public static void main(String[] args) {
        int[] arr = {9, 4, 3, 1, 7, 2, 8, 6, 5};
        InsertionSort(arr);
        System.out.println("Sorted Array: " + Arrays.toString(arr));
    }
}
