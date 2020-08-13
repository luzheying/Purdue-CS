import javax.swing.*;

/**
 * Lab02
 *
 * created a Dialog which will get favorite from users and displays the input.
 *
 * @author Zheying Lu, lab02
 * @version June 12th
 */

public class ColorQuestionnaire {
    public static void main(String[] args) {
        String color;
        String result;

        color = JOptionPane.showInputDialog("What's your favourite color? ");

        result = "Nice! I think " + color + " is a great color too!";
        JOptionPane.showMessageDialog(null, result);
    }
}
