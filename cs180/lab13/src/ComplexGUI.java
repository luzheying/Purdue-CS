import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ComplexGUI {

    public static void main(String[] args) {
        JFrame frame = new JFrame("Frame title");
//        frame.setVisible(true);
        frame.setSize(350,200);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JPanel panel = new JPanel();
        JButton thisButton = new JButton("This");
        JButton thatButton = new JButton("That");
        panel.add(thisButton);
        panel.add(thatButton);
        JTextField field = new JTextField("Text input and output area");
        panel.add(field);
        frame.add(panel);
        thisButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                field.setText("You can get with this");
            }
        });

        thatButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                field.setText("Or you can get with that");
            }
        });
        frame.setVisible(true);
    }


}


