package jxreloj;

import jxreloj.vista.VReloj;
import jxreloj.modelo.MReloj;
import jxreloj.controlador.CReloj;

public class Test {

    public static void main(String[] args) {
        var modelo = new MReloj();
        var vista = new VReloj();
        var controlador = new CReloj(modelo, vista);
        controlador.iniciar();
        vista.setVisible(true);
    }
}
