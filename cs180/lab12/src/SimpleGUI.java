import javax.swing.*;

public class SimpleGUI {
    public static void main(String[] args) {
        JOptionPane.showMessageDialog(null, "Welcome, this is lab 12.", "Welcome", JOptionPane.INFORMATION_MESSAGE);
        JOptionPane.showInputDialog(null, "What lab section are you in?", "Section", JOptionPane.QUESTION_MESSAGE);
        int reply = JOptionPane.showConfirmDialog(null, "Would you like to exit?", "Exit", JOptionPane.YES_NO_OPTION);
        if ( reply== JOptionPane.YES_OPTION) {
            System.exit(0);
        }
        else {
            JOptionPane.showMessageDialog(null, "You have selected to continue.","Continue",JOptionPane.INFORMATION_MESSAGE);
        }
    }
}
