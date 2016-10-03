package ASCIIArt;

import java.util.*;

class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int L = in.nextInt();
        in.nextLine();
        int H = in.nextInt();
        in.nextLine();
        String T = in.nextLine();

        // keep a dictionary that maps each letter to an array of strings
        Map<Character, String[]> dictionary = new HashMap<Character, String[]>();
        String alphabet = "abcdefghijklmnopqrstuvwxyz?";

        for (int i = 0; i < H; i++) {
            String ROW = in.nextLine();
            for (int alphaIndex = 0; alphaIndex < 27; alphaIndex++) {
                String value = ROW.substring(alphaIndex*L, alphaIndex*L+L);
                char letter = alphabet.charAt(alphaIndex);

                if (i == 0) {
                    // first row
                    String[] line = new String[H];
                    line[i] = value;
                    dictionary.put(letter, line);
                } else {
                    String[] line = dictionary.get(letter);
                    line[i] = value;
                    dictionary.put(letter, line);
                }
            }
        }

        StringBuilder output = new StringBuilder();
        for (int height = 0; height < H; height ++) {
            for (char l: T.toLowerCase().toCharArray()) {
                if (!dictionary.containsKey(l)) {
                    l = '?';
                }
                output.append(dictionary.get(l)[height]);
            }
            output.append("\n");
        }

        System.out.println(output);
    }
}
