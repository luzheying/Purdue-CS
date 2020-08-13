import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class SudokuGUI {



    public void initGridGUI() {
        //TODO: create JFrame and grid of JPanels within the JFrame
        JFrame frame = new JFrame("Sudoku");
        frame.setSize(500,500);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        JPanel[][] panel = new JPanel[9][9];
        GridLayout grid = new GridLayout(9, 9);
        frame.setLayout(grid);

        //TODO: loop through each JPanel and add either a label or a TextField based on the value of that location in
        // the solution (SudokuModel.game[i][j]).
//        JTextField field = new JTextField("     ");

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (SudokuModel.game[i][j]!= 0) {
                    panel[i][j] = new JPanel();
                    JLabel jl = new JLabel(Integer.toString(SudokuModel.game[i][j]));
                    jl.setVisible(true);
                    panel[i][j].add(jl);
                    frame.add(panel[i][j]);
                }
                else {
                    panel[i][j] = new JPanel();
                    panel[i][j].setSize(100,100);
                    JTextField field = new JTextField("   ");
                    field.setSize(100,100);
                    int x =i;
                    int y = j;
                    panel[i][j].add(field);
                    JLabel jl = new JLabel(Integer.toString(0));
                    jl.setVisible(false);
                    frame.add(panel[i][j]);
                    field.addKeyListener(new KeyAdapter() {
                        public void keyPressed(KeyEvent e) {
                            if(e.getKeyCode()==KeyEvent.VK_ENTER) {
                                System.out.println("check");
                                int in = Integer.parseInt(field.getText().trim());
                                System.out.println(x + " " + y);
                                if (checkValid(x,y, in)) {
                                    field.setVisible(false);
                                    //jl.setText(Integer.toString(in));
                                    JLabel jLabel = new JLabel(Integer.toString(in));
                                    jLabel.setVisible(true);
                                    //jl.setVisible(true);
                                    //field.setText(Integer.toString(in));
                                  //  field.setVisible(true);
                                    panel[x][y].add(jLabel);
                                    frame.setVisible(true);
                                    //frame.add(panel[x][y]);
                                }
//                                else {
//                                    JTextField field = new JTextField("   ");
//                                    JLabel jl = new JLabel(Integer.toString(0));
//                                    jl.setVisible(false);
//                                    panel[x][y].add(field);
//                                    frame.add(panel[x][y]);
//                                }
                            }
                        }

                    });
                }

            }
        }
//        if(SudokuModel.game[i][j])
//        //if value is zero, in addition to the JTextField, include the code below
//        JLabel jl = new JLabel(Integer.toString(0));
//        jl.setVisible(false);
        //TODO: create keyListener for the 'enter' key
        frame.setVisible(true);
    }

    private boolean checkValid(int x, int y, int in){
        if (SudokuModel.solution[x][y]==in){
            return true;
        }
        System.out.println(SudokuModel.solution[x][y]);
        return false;
    }

    public static void main(String[] args) {
        SudokuGUI gui = new SudokuGUI();
        SudokuModel sm = new SudokuModel();
        gui.initGridGUI();
    }
}
