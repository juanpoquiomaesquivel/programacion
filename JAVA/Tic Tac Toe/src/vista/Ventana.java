package vista;

import java.awt.Window;

public interface Ventana {

    public static final String LETRA = "HP Simplified Jpan";
    public static final int VENTANA_NORMAL = 0;
    public static final int VENTANA_SEMI = 0;
    public static final int VENTANA_DIALOGO = 2;
    
    public Window getPadre();
}
