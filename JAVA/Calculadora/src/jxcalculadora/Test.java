package jxcalculadora;

import jxcalculadora.controlador.CCalculadora;
import jxcalculadora.modelo.MCalculadora;
import jxcalculadora.vista.VCalculadora;

public class Test {

    public static void main(String[] args) {
        MCalculadora modelo = new MCalculadora();
        VCalculadora vista = new VCalculadora();
        CCalculadora controlador = new CCalculadora(modelo, vista);
        vista.setVisible(true);
    }
}
