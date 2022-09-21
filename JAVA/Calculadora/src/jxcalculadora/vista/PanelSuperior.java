package jxcalculadora.vista;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Point;
import java.awt.Window;
import javax.swing.JPanel;

public class PanelSuperior extends JPanel {

    public final static int ALTURA = 30;

    public PanelSuperior(Window marco, int ancho) {
        this.setLayout(null);
        this.setSize(new Dimension(ancho, 30 + Ventana.BORDE));
        this.setLocation(new Point(0, 0));
        this.setBackground(Color.yellow);
    }

}
