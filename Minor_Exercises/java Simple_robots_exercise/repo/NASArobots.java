import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * @author Oani da silva da Costa
 * 
 *         Tested on VScode with the extension Extension Pack for Java
 *         https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack
 * 
 */

// ======================== Problem Two: ========================

public class NASArobots {

    public static void main(String[] args) {


        // https://www.w3schools.com/java/java_files_read.asp
        try {
            // -------------------------------------------------------------------
            // -IMPORTANT: You have to open the root folder in Explorer in VScode-
            // ---------------------so it can read input.txt----------------------
            // -------------------------------------------------------------------

            File myObj = new File("input.txt");
            Scanner myReader = new Scanner(myObj);

            int maxX = myReader.nextInt();
            int maxY = myReader.nextInt();

            ArrayList<Robot> squad = new ArrayList<Robot>();

            int numbot = 0;

            // while there are orders
            while (myReader.hasNext()) {
                // make a new robot in the squad
                squad.add(new Robot(myReader.nextInt(), myReader.nextInt(), maxX, maxY, myReader.next(), 
                        myReader.next()));
                // give it the orders, as each one will act independently
                squad.get(numbot).receiveOrders();
                numbot++;

            }
            // closes the scanner
            myReader.close();

            // if (!myReader.hasNext()) {
            // myReader.close();
            // }
        } catch (FileNotFoundException e) {
            System.out.println("|--------------------------------------------------------------------------------|");
            System.out.println("|File not found. Please input your data in the input.txt file in the root folder.|");
            System.out.println("|--------------------------------------------------------------------------------|");
            e.printStackTrace();
        }

    }
};
