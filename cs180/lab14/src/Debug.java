/**
 * A recursive table tennis game. 
 *
 * <p>Purdue University -- CS18000 -- Summer 2019 -- Dynamic Data Structures -- Lab</p>
 *
 * @version July 24, 2019
 */

public class Debug {

    /**
     * The current active move. 
     */
    private static String currentMove = "";
    private static int moveMax;
    private static int moveCounter;
    private static String winner;
    
    public static void main(String[] args)
    {
        moveMax = Integer.parseInt(args[0]);
        startGame();
    }

    /**
     * Begins the game by calling {@code ping()}.
     */
    private static void startGame() {
        ping();
    }

    /**
     * Updates {@code currentMove} with the new move and prints it, then calls {@code pong()}.
     */
    private static void ping() {
        if (moveMax == moveCounter) {
            //winner = "Ping";
            System.out.println("The winner is: " + currentMove+ "!");
            return;
        }
        moveCounter++;
        currentMove = "Ping";
        System.out.println(currentMove);
        pong();
    }

    /**
     * Updates {@code currentMove} with the new move and prints it, then calls {@code ping()}.
     */
    private static void pong() {
        if (moveMax == moveCounter) {
          //  winner = "Pong";
            System.out.println("The winner is: " + currentMove+ "!");
            return;
        }
        moveCounter++;
        currentMove = "Pong";
        System.out.println(currentMove);
        ping();
    }
}
