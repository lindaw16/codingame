package MarsLanderLvl1;

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
        int N = in.nextInt(); // the number of points used to draw the surface of Mars.

        // The flat ground has the same y coordinates
        int yFlat = -1;
        int minXFlat = -1;
        int maxXFlat = -1;
        int prevY = Integer.MAX_VALUE;
        int prevX = Integer.MAX_VALUE;

        boolean inFlat = false;
        for (int i = 0; i < N; i++) {
            int LAND_X = in.nextInt(); // X coordinate of a surface point. (0 to 6999)
            int LAND_Y = in.nextInt(); // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.

            if (LAND_Y == prevY) {
                if (!inFlat) {
                    //start of flat
                    minXFlat = prevX;
                    yFlat = LAND_Y;
                    inFlat = true;
                } //else in the middle of the flat, do nothing
            } else {
                if (inFlat) {
                    // just ended flat
                    maxXFlat = prevX;
                    inFlat = false;
                } // else not reached flat yet, do nothing
            }
            prevY = LAND_Y;
            prevX = LAND_X;
        }

        System.err.println(yFlat + "  " + minXFlat + "   " + maxXFlat);

        // game loop
        while (true) {
            int X = in.nextInt();
            int Y = in.nextInt();
            int HS = in.nextInt(); // the horizontal speed (in m/s), can be negative.
            int VS = in.nextInt(); // the vertical speed (in m/s), can be negative.
            int F = in.nextInt(); // the quantity of remaining fuel in liters.
            int R = in.nextInt(); // the rotation angle in degrees (-90 to 90).
            int P = in.nextInt(); // the thrust power (0 to 4).

            // Write an action using System.out.println()
            // To debug: System.err.println("Debug messages...");
            int desR;
            int desP = 4;
            if (Math.abs(HS) > 15) {
                desP = 1;
            }

            if (X < minXFlat) {
                System.err.println("A");
                desR = -90;
            } else if (X > maxXFlat) {
                System.err.println("B");
                desR = 90;
            } else {
                System.err.println("C");
                desR = 0;
                if (Math.abs(VS) > 35) {
                    desP = 4;
                } else {
                    desP = 0;
                }
            }

            System.out.println(desR + " " + desP); // R P. R is the desired rotation angle. P is the desired thrust power.
        }
    }
}