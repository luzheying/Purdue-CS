import javax.swing.*;

/**
 * Lab02
 *
 * created a Dialog which will get frist name and last name from users and displays the input.
 *
 * @author Zheying Lu, lab02
 * @version June 12th
 */

public class PersonalizedGreeting {

    public static void main(String[] args) {
        String firstName;
        String lastName;
        String greeting;

        firstName = JOptionPane.showInputDialog("Please enter your first name: ");
        lastName = JOptionPane.showInputDialog("Please enter your last name: ");

        greeting = "Hello, " + firstName + " " + lastName + "!";
        JOptionPane.showMessageDialog(null, greeting);
    }
}
