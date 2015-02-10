package PowerOfThor;

import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Player {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int LX = in.nextInt(); // the X position of the light of power
        int LY = in.nextInt(); // the Y position of the light of power
        int TX = in.nextInt(); // Thor's starting X position
        int TY = in.nextInt(); // Thor's starting Y position

        // game loop
        while (true) {
            int E = in.nextInt(); // The level of Thor's remaining energy, representing the number of moves he can still make.

            String dir = "";

            if (LY > TY) {
                // the light is to the south
                dir = "S";
                TY += 1;
            } else if (LY < TY) {
                // the light is to the north
                dir = "N";
                TY -= 1;
            } else {
                // the light is directly east or west
                // do nothing
            }

            if (LX > TX) {
                // the light is to the east
                dir += "E";
                TX += 1;
            } else if (LX < TX) {
                // the light is to the west
                dir += "W";
                TX -= 1;
            } else {
                // the light is directly above or below
                // don't append
            }

            System.out.println(dir); // A single line providing the move to be made: N NE E SE S SW W or NW
        }
    }
}