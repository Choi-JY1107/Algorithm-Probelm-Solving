import java.util.Scanner;

public class Main {
    public static int countWhite = 0;
    public static int countBlue = 0;
    public static int size;
    public static int[][] board;
    
    public static void main(String[] args) {
        input();
        divide(0, 0, size);
        output();
    }

    private static void output() {
        System.out.println(countWhite);
        System.out.println(countBlue);
    }

    private static void divide(int startX, int startY, int size) {
        if(checkSameColor(startX, startY, size)) {
            return;
        }

        divide(startX, startY, size / 2);
        divide(startX, startY + size / 2, size / 2);
        divide(startX + size / 2, startY, size / 2);
        divide(startX + size / 2, startY + size / 2, size / 2);
    }

    private static boolean checkSameColor(int startX, int startY, int size) {
        if (isSameColor(startX, startY, size)) {
            if (board[startX][startY] == 0) {
                countWhite++;
                return true;
            }
            countBlue++;
            return true;
        }
        return false;
    }

    private static boolean isSameColor(int startX, int startY, int size) {
        for (int i = startX ; i < startX + size; ++i) {
            for (int j = startY ; j < startY + size; ++j) {
                if (board[i][j] != board[startX][startY]) {
                    return false;
                }
            }
        }
        return true;
    }

    private static void input() {
        Scanner in = new Scanner(System.in);
        size = in.nextInt();
        board = new int[size][size];

        for(int i = 0 ; i < size ; ++i) {
            for(int j = 0 ; j < size ; ++j) {
                board[i][j] = in.nextInt();
            }
        }
    }
}
