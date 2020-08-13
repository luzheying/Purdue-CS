import javax.swing.*;

/**
 * Lab02
 *
 * Get user emial with name by getting its first index of charactor and last name
 * and appened a specific pattern to it.
 * created a Dialog which will show the username and user email.
 *
 * @author Zheying Lu, lab03
 * @version June 17th
 */

public class UserGenerator {
    public static void main(String[] args) {
        String name = "John Doe";
        char firstChar = name.charAt(0); //get the first charactor of name
        int startIndex = name.indexOf(" ") +1;//get the first index of last name of name
        int stopIndex = name.length();//get the last index which is the length of the name
        String username = firstChar+name.substring(startIndex, stopIndex); //create username
        username = username.toLowerCase(); //transform username to lowercase
        String email = username + "@purdue.edu";
        JOptionPane.showMessageDialog(null, "Username:" + username + "\nEmail:" +
                email);
    }

}
