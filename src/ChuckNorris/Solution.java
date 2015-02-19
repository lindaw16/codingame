package ChuckNorris;

class Solution {

    public static void main(String args[]) {
        //Scanner in = new Scanner(System.in);
        //String MESSAGE = in.nextLine();
        String MESSAGE = "Chuck Norris' keyboard has 2 keys: 0 and white space.";

        char[] letters = MESSAGE.toCharArray();
        String prevNum = "";
        int counter = 0;

        StringBuilder binaryRep = new StringBuilder();

        //convert to binary
        for (char c: letters) {
            String cBinary = Integer.toString(c, 2);
            // make sure they are length 7
            while (cBinary.length() < 7) {
                cBinary = "0" + cBinary;
            }
            binaryRep.append(cBinary);
        }

        char[] binaryMessage = binaryRep.toString().toCharArray();
        StringBuilder encoding = new StringBuilder();

        for (char c: binaryMessage) {
            String s = c+"";
            if (s.equals(prevNum)) {
                //increment the counter and keep going
                counter++;
            } else {
                //new number
                if (!prevNum.isEmpty()) {
                    // append the contents to the encoding
                    encoding.append(addToEncoding(prevNum, counter) + " ");
                    // reset counter
                    counter = 1;
                } else {
                    // just starting
                    counter++;
                }
            }
            prevNum = s;
        }

        encoding.append(addToEncoding(prevNum, counter));
        System.out.println(encoding.toString());
    }



    private static String addToEncoding(String prevNum, int counter) {
        StringBuilder sb = new StringBuilder();
        if (prevNum.equals("0")) {
            sb.append("00");
        } else if (prevNum.equals("1")) {
            sb.append("0");
        } else {
            //throw new RuntimeException("invalid binary character: " + prevNum);
        }

        sb.append(" ");

        for (int i = 0; i < counter; i++) {
            sb.append("0");
        }

        return sb.toString();
    }
}