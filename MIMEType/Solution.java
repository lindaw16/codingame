package MIMEType;

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
        int N = in.nextInt(); // Number of elements which make up the association table.
        in.nextLine();
        int Q = in.nextInt(); // Number Q of file names to be analyzed.
        in.nextLine();

        Map<String, String> ext2Mime = new HashMap<String, String>();
        StringBuilder output = new StringBuilder();

        for (int i = 0; i < N; i++) {
            String EXT = in.next(); // file extension
            String MT = in.next(); // MIME type.
            ext2Mime.put(EXT.toLowerCase(), MT);
            in.nextLine();
        }

        for (int i = 0; i < Q; i++) {
            String FNAME = in.nextLine(); // One file name per line.
            int dot = FNAME.lastIndexOf(".");
            if (dot == -1) {
                output.append("UNKNOWN\n");
            } else {
                String ext = FNAME.substring(dot+1, FNAME.length()).toLowerCase();
                System.err.println(ext);
                String type = "";
                if (ext2Mime.containsKey(ext)) {
                    type = ext2Mime.get(ext);
                } else {
                    type = "UNKNOWN";
                }

                output.append(type + "\n");
            }
        }

        System.out.println(output.toString()); // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    }
}