public class Transpose {

    int numRows;
    int numColumns;
    Matrix tranMatrix;

    public Transpose(Matrix matrix) {
        this.numRows = matrix.numColumns;
        this.numColumns = matrix.numRows;
        this.tranMatrix = new Matrix(this.numRows,this.numColumns);
    }
    public void transposeMatrix(Matrix matrix) {
        for (int i = 0; i < this.numColumns; i++) {
            for (int j = 0; j < this.numRows; j++) {
                tranMatrix.matrix[j][i] = matrix.matrix[i][j];
            }
        }
        matrix = tranMatrix;
    }

    public void displayTranspose() {

        System.out.println("\nTranspose Matrix:");
        for (int i = 0; i < this.numRows; i++) {
            for (int j = 0; j < this.numColumns; j++) {
                System.out.print(this.tranMatrix.matrix[i][j]+ " ");
                if (j == this.tranMatrix.matrix[0].length-1 && i != this.tranMatrix.matrix.length-1) {
                    System.out.println("");
                }
            }
        }
    }
}