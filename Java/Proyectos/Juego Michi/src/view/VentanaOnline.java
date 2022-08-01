package view;

import java.awt.Color;
import javax.swing.JFrame;
import javax.swing.JPanel;

import shared.PanelSuperior;
import shared.Ventana;

public class VentanaOnline extends JFrame implements Ventana {

    public VentanaOnline(JFrame jfather) {
        this.jfather = jfather;
        this.setLayout(null);
        this.setSize(ANCHO, ALTO + PanelSuperior.ALTO);
        this.setLocationRelativeTo(jfather);
        this.setUndecorated(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        panelSuperior = new PanelSuperior(this, Ventana.WINDOW, ANCHO, "Juego Online");
        this.add(panelSuperior);

        panelOnline = new PanelOnline(this, ANCHO, ALTO);
        this.add(panelOnline);
    }

    private JFrame jfather;
    private static final int ANCHO = 400, ALTO = 370;
    private PanelSuperior panelSuperior;
    private PanelOnline panelOnline;

    @Override
    public JFrame getPadre() {
        return this.jfather;
    }
}

class PanelOnline extends JPanel {

    public PanelOnline(JFrame jframe, int ancho, int alto) {
        this.setLayout(null);
        this.setSize(ancho, alto);
        this.setLocation(0, PanelSuperior.ALTO);
        this.setBackground(Color.WHITE);
    }
}
