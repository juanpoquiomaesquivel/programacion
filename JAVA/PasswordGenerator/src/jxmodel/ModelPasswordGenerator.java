package jxmodel;

public class ModelPasswordGenerator {

    public ModelPasswordGenerator() {
        this.uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        this.lowercase = "abcdefghijklmnopqrstuvwxyz";
        this.number = "0123456789";
        this.symbol = "$#%&!?;;.,<>()[]{}+-/*_";
    }

    private final String uppercase;
    private final String lowercase;
    private final String number;
    private final String symbol;

    public String generatePassword(int length) {
        var password = "";
        var min = 1;
        var max = 4;
        var range = max - min + 1;
        var randomIndex = 0;
        var randomCharacterIndex = 0;

        for (var i = 0; i < length; i++) {
            randomIndex = (int) (Math.random() * range) + min; // https://www.geeksforgeeks.org/java-math-random-method-examples/

            switch (randomIndex) {
                case 1 -> {
                    randomCharacterIndex = (int) (Math.random() * this.uppercase.length());
                    password += this.uppercase.charAt(randomCharacterIndex);
                }
                case 2 -> {
                    randomCharacterIndex = (int) (Math.random() * this.lowercase.length());
                    password += this.lowercase.charAt(randomCharacterIndex);
                }
                case 3 -> {
                    randomCharacterIndex = (int) (Math.random() * this.number.length());
                    password += this.number.charAt(randomCharacterIndex);
                }
                case 4 -> {
                    randomCharacterIndex = (int) (Math.random() * this.symbol.length());
                    password += this.symbol.charAt(randomCharacterIndex);
                }
            }
        }

        return password;
    }
}
