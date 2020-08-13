import javax.swing.*;

public class Debug {
    public static void main(String args[]) {
       // *//*Variable declarations *//*
        String word1; String word2; String word3;
        String word4;String word5;

     //   *//*Assignments*//*
        word1 = "Purdue University";
        word2 = "Pot-boiler";
        word3 = "Newsgroup";
        word4 = "sledgehammers";
        word5= "Countdowns";


        word2 = word2.substring(4, 10);
        word2 = word2.substring(0, 1).toUpperCase() + word2.substring(1);
        word3 = word3.substring(word3.length() - 2);
        word3 = word3.substring(0, 1).toUpperCase() + word3.substring(1);
        word4 = word4.substring(6,12);
        word4 = word4.substring(0, 1).toUpperCase() + word4.substring(1);
        word5 = word5.substring(5, 9);
        word5 = word5.substring(0, 1).toUpperCase() + word5.substring(1);

        JOptionPane.showMessageDialog(null, "We are " + word1+", "+ word2 +" "+ word3+" " + word4 +" "+ word5);
    }
}
