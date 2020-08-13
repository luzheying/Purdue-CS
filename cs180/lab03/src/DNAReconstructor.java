import javax.swing.*;
import java.util.Scanner;

/**
 * Lab02
 *
 * created a new DNA sequence with two inputs.
 *
 * @author Zheying Lu, lab03
 * @version June 17th
 */

public class DNAReconstructor {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input DNA fragments one line at a time.");
        System.out.println("We start with no DNA\n");
        String output = " ";
        System.out.print("Current DNA (1): ");
        System.out.println(output);
        System.out.print("Add Sequence: ");
        String seq = sc.nextLine();
        if ( seq.isEmpty() || seq.length() < 3) {
            System.out.println("Current DNA (2): g" );
        }
        else {
            seq = seq.toLowerCase();
            System.out.println("Current DNA (2):" + seq);

            System.out.print("Add Sequence: ");
            String nextSeq = sc.nextLine();
            nextSeq = nextSeq.toLowerCase();

            int length = seq.length();
            length = length - 3;
            seq = seq.substring(0, length);

            output = seq + nextSeq;
            System.out.println("Current DNA (3):" + output);
        }
    }
}
