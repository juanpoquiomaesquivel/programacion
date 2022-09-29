package jxreloj.modelo;

import java.util.Calendar;

public class MReloj {

    public int[] obtenerTiempoActual() {
        var tiempoActual = Calendar.getInstance();
        var horas = tiempoActual.get(Calendar.HOUR);
        var minutos = tiempoActual.get(Calendar.MINUTE);
        var segundos = tiempoActual.get(Calendar.SECOND);

        return new int[]{horas, minutos, segundos};
    }
}
