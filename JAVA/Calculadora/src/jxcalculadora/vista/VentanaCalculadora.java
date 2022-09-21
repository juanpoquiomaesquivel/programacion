package jxcalculadora.vista;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Window;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class VentanaCalculadora extends JFrame implements Ventana {
    
    public VentanaCalculadora() {
        this.setTitle("Calculadora");
        this.setSize(dimension.width + Ventana.BORDE, dimension.height + Ventana.BORDE + PanelSuperior.ALTURA);
        this.setLocationRelativeTo(null);
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setUndecorated(true);
        this.getContentPane().setBackground(Color.blue);
        this.add(panelSuperior);
        this.add(panelCalculadora);
    }
    
    private final Dimension dimension = new Dimension(400, 400);
    private final PanelSuperior panelSuperior = new PanelSuperior(this, dimension.width);
    private PanelCalculadora panelCalculadora = new PanelCalculadora();
    
    @Override
    public Window getPadre() {
        return null;
    }
    
    private class PanelCalculadora extends JPanel {
        
        public PanelCalculadora() {
            this.setLayout(null);
            this.setSize(dimension);
            this.setLocation(Ventana.BORDE / 2, Ventana.BORDE / 2 + PanelSuperior.ALTURA);
            this.setBackground(Color.white);
        }
    }
}
