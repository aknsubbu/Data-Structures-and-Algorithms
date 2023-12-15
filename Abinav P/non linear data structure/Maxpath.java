import java.util.ArrayList;
import java.util.Scanner;

public class Maxpath {
    static ArrayList<Integer> list = new ArrayList<>();

    public static void findmaxpath(int[] array, int sum, int index, int levels) {
        if (index >= array.length || levels == 0) {
            sum += 0;
            System.out.println(sum);
            list.add(sum);
            return;
        }
        sum += array[index];
        findmaxpath(array, sum, 2 * index + 1, levels - 1);
        findmaxpath(array, sum, 2 * index + 2, levels - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of levels in the tree ");
        int n = sc.nextInt();
        int[] array = new int[(int) Math.pow(2, n)];
        for (int i = 0; i < n; i++) {
            array[i] = 0;
        }
        System.out.println("Enter the number of nodes in the tree ");
        int m = sc.nextInt();
        System.out.println("Enter the nodes ");
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt();
            array[i] = x;
        }
        int sum = 0;
        findmaxpath(array, sum, 0, n);
        list.sort(null);
        System.out.println("The maximum sum is " + list.get(list.size() - 1));

    }
}