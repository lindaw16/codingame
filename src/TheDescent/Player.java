package TheDescent;

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

        // game loop
        while (true) {
            int SX = in.nextInt();
            int SY = in.nextInt();
            int tallestMountain = -1;
            int fireHere = -1;

            for (int i = 0; i < 8; i++) {
                int MH = in.nextInt(); // represents the height of one mountain, from 9 to 0. Mountain heights are provided from left to right.

                if (MH >= tallestMountain) {
                    tallestMountain = MH;
                    fireHere = i;
                }
            }

            // Write an action using System.out.println()
            // To debug: System.err.println("Debug messages...");
            if (SX == fireHere) {
                System.out.println("FIRE");
                tallestMountain = -1;
                fireHere = -1;
            } else if (fireHere == -1) {
                System.out.println("HOLD");
            } else {
                System.out.println("HOLD");
            }
            // System.out.println("HOLD"); // either:  FIRE (ship is firing its phase cannons) or HOLD (ship is not firing).
        }
    }
}