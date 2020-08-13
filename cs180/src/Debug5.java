import javax.swing.*;

/**
 * Lab02
 *
 * created a Dialog which will display a message with greeting and year number.
 *
 * @author Zheying Lu, lab02
 * @version June 12th
 */

public class Debug5 {
    public static void main(String[] args) {
        String years = "2019";
        String word = "Hello, world!";
        JOptionPane.showMessageDialog(null,word + " It is " + years);
    }
}
