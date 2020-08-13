import javax.swing.*;

/**
 * Lab02
 *
 * created a Dialog which will get frist name and last name from users and displays the input.
 *
 * @author Zheying Lu, lab02
 * @version June 12th
 */

public class Debug3 {
    public static void main(String[] args){
        String firstName = JOptionPane.showInputDialog("Enter your first name: ");
        String lastName = JOptionPane.showInputDialog("Enter your last name: ");

        JOptionPane.showMessageDialog(null, "Hello " + firstName + " " + lastName);
    }
}
