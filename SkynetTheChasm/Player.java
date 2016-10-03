package SkynetTheChasm;

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
        int R = in.nextInt(); // the length of the road before the gap.
        int G = in.nextInt(); // the length of the gap.
        int L = in.nextInt(); // the length of the landing platform.

        // game loop
        while (true) {
            int S = in.nextInt(); // the motorbike's speed.
            int X = in.nextInt(); // the position on the road of the motorbike.

            // we want to maintain the speed G+1
            if (X == R - 1) {
                //right in front of the gap
                System.out.println("JUMP");
            } else if (X > R - 1) {
                // on landing platform - slow down
                System.out.println("SLOW");
            } else if (S == G + 1) {
                // maintiain this speed
                System.out.println("WAIT");
            } else if (S > G + 1) {
                // slow down
                System.out.println("SLOW");
            } else {
                System.out.println("SPEED");
            }
        }
    }
}