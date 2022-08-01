package view;

import java.awt.Color;
import java.awt.GridLayout;

import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JPanel;

import shared.PanelSuperior;
import shared.Ventana;

public class VentanaGanador extends JDialog implements Ventana {

    public VentanaGanador(JFrame jfather, String winner, String loser) {
        super(jfather, true);
        this.jfather = jfather;
        this.setLayout(null);
        this.setSize(ANCHO, ALTO + PanelSuperior.ALTO);
        this.setLocationRelativeTo(jfather);
        this.setUndecorated(true);

        panelSuperior = new PanelSuperior(this, Ventana.DIALOG, ANCHO, "Resultado de la batalla!");
        this.add(panelSuperior);

        panelGanador = new PanelGanador(ANCHO, ALTO, winner, loser);
        this.add(panelGanador);
    }

    private JFrame jfather;
    private static final int ANCHO = 300, ALTO = 170;
    private PanelSuperior panelSuperior;
    private PanelGanador panelGanador;

    @Override
    public JFrame getPadre() {
        return ((VentanaJuego) jfather).getPadre();
    }
}

class PanelGanador extends JPanel {

    public PanelGanador(int ancho, int alto, String winner, String loser) {
        this.setLayout(new GridLayout(3, 3));
        this.setSize(ancho, alto);
        this.setLocation(0, PanelSuperior.ALTO);
        this.setBackground(Color.WHITE);
    }
}