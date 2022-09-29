package jxreloj.controlador;

import javax.swing.Timer;
import jxreloj.modelo.MReloj;
import jxreloj.vista.VReloj;

public class CReloj {

    public CReloj(MReloj modelo, VReloj vista) {
        this.modelo = modelo;
        this.vista = vista;
    }

    private final MReloj modelo;
    private final VReloj vista;

    public void iniciar() {
        var tempo = new Timer(1000, (ae) -> {
            vista.cargarTiempo(modelo.obtenerTiempoActual());
            vista.repaint();
        });
        tempo.start();
    }
}
