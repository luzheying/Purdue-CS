import java.util.Scanner;

public class Matrix {

        int numRows;
        int numColumns;
        int[][] matrix;

    public Matrix(int numRows, int numColumns) {
        this.numColumns = numColumns;
        this.numRows = numRows;
        this.matrix = new int[this.numRows][this.numColumns];
    }


    public void makeMatrix(Scanner input) {
        boolean invalid = false;
        int value = 0;
        for (int i = 0; i < this.numRows; i++) {
            for ( int j = 0; j< this.numColumns;j++) {
                do {
                    System.out.print("Enter a number: ");
                    if (!input.hasNextInt()) {
                        input.next();
                        input.nextLine();
                        System.out.println("Invalid Entry, Integers Only");
                        invalid = true;
                    } else {
                        value = input.nextInt();
                        input.nextLine();
                        this.matrix[i][j] = value;
                        invalid = false;
                    }
                }while (invalid);
            }
        }
    }

    public void displayMatrix(){
        System.out.println("##################################");
        System.out.println("Original Matrix:");
        for (int i = 0; i < this.numRows; i++) {
            for ( int j = 0; j< this.numColumns;j++) {
                System.out.print(this.matrix[i][j] + " ");
                if (j == this.matrix[0].length-1 && i != this.matrix.length-1) {
                    System.out.println("");
                }
            }
        }

    }
}
