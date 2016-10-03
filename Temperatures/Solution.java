package Temperatures;

import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt(); // the number of temperatures to analyse
        int closest = Integer.MAX_VALUE;

        if (N == 0) {
            closest = 0;
        } else {
            in.nextLine();
            String TEMPS = in.nextLine(); // the N temperatures expressed as integers ranging from -273 to 5526

            String[] ts = TEMPS.split(" ");
            for (String s: ts) {
                int i = Integer.parseInt(s);
                int absI = Math.abs(i);
                int absClosest = Math.abs(closest);
                if (absI < absClosest || (absI == absClosest && absI > 0)) {
                    closest = i;
                } // else continue
            }
        }

        System.out.println(closest);
    }
}