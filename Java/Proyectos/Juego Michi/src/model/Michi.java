package model;

public class Michi {

    public Michi() {
        this.tabla = new String[3][3];
    }

    public int[] comprobar() {
        int[] datos = new int[7];
        datos[0] = Michi.DRAW;
        datos[1] = 0;
        datos[2] = 0;
        datos[3] = 1;
        datos[4] = 1;
        datos[5] = 2;
        datos[6] = 2;

        if ("XXX".equals(tabla[0][0] + tabla[1][1] + tabla[2][2]))
            datos[0] = Michi.WINNER1;
        else if ("OOO".equals(tabla[0][0] + tabla[1][1] + tabla[2][2]))
            datos[0] = Michi.WINNER2;
        else {
            datos[1] = 0;
            datos[2] = 2;
            datos[3] = 1;
            datos[4] = 1;
            datos[5] = 2;
            datos[6] = 0;

            if ("XXX".equals(tabla[0][2] + tabla[1][1] + tabla[2][0]))
                datos[0] = Michi.WINNER1;
            else if ("OOO".equals(tabla[0][2] + tabla[1][1] + tabla[2][0]))
                datos[0] = Michi.WINNER2;
            else {
                int i;
                int j;

                for (i = 0; i < 3; i++) {
                    String cadena1 = "";
                    String cadena2 = "";

                    for (j = 0; j < 3; j++) {
                        cadena1 += tabla[i][j];
                        cadena2 += tabla[j][i];
                    }
                    j--;

                    datos[1] = datos[3] = datos[5] = i;
                    datos[2] = j - 2;
                    datos[4] = j - 1;
                    datos[6] = j;

                    if ("XXX".equals(cadena1)) {
                        datos[0] = Michi.WINNER1;
                        break;
                    } else if ("OOO".equals(cadena1)) {
                        datos[0] = Michi.WINNER2;
                        break;
                    } else if ("XXX".equals(cadena2)) {
                        datos[0] = Michi.WINNER1;
                        datos[2] = datos[4] = datos[6] = i;
                        datos[1] = j;
                        datos[3] = j - 1;
                        datos[5] = j - 2;
                        break;
                    } else if ("OOO".equals(cadena2)) {
                        datos[0] = Michi.WINNER2;
                        datos[2] = datos[4] = datos[6] = i;
                        datos[1] = j;
                        datos[3] = j - 1;
                        datos[5] = j - 2;
                        break;
                    }
                }
            }
        }

        return datos;
    }

    public static final int DRAW = 0;
    public static final int WINNER1 = 1;
    public static final int WINNER2 = 2;
    public String[][] tabla;
}
