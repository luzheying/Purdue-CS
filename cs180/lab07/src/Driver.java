import java.util.Scanner;

public class Driver {
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        
        int numRows = 0;
        int numColumns = 0;
        boolean invalid = false;
        
        System.out.println("Welcome to Matrix Driver Calculator!");
        do{
        System.out.print("Enter the number of rows: ");
        if (!input.hasNextInt()) {
            input.next();
            input.nextLine();
            System.out.println("Invalid Entry, Integers Only");
            invalid = true;
        }else {
            numRows = input.nextInt();
            input.nextLine();
            invalid = false;
        } }while (invalid);
        do{
            System.out.print("Enter the number of columns: ");
            if (!input.hasNextInt()) {
                input.next();
                input.nextLine();
                System.out.println("Invalid Entry, Integers Only");
                invalid = true;
            }else {
                numColumns = input.nextInt();
                input.nextLine();
                invalid = false;
            } }while (invalid);


        //Creates new matrix
        Matrix origMatrix = new Matrix(numRows,numColumns);
        origMatrix.makeMatrix(input);

        //Display original matrix
        origMatrix.displayMatrix();

        //Create new transpose
        Transpose transpose = new Transpose(origMatrix);
        transpose.transposeMatrix(origMatrix);

        //Display transposed matrix
        transpose.displayTranspose();
    }
}