package vista;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Point;
import java.awt.Window;

import javax.swing.JButton;
import javax.swing.JPanel;

public class PanelSuperior extends JPanel {

    public static final int ALTO = 30;

    public PanelSuperior(Window marco, int tipo) {
        this.setSize(new Dimension(10, PanelSuperior.ALTO));
        this.setLocation(posicion);
        this.setBackground(Color.WHITE);
        eventoDeMovimiento(marco);
    }

    public PanelSuperior(Window marco, int tipo, int ancho, Color color) {
        this.setSize(new Dimension(ancho, PanelSuperior.ALTO));
        this.setLocation(posicion);
        this.setBackground(color);
        eventoDeMovimiento(marco);
    }

    private final Point posicion = new Point(0, 0);
    private int x, y;
    private JButton botonMinimizar = new JButton();
    private JButton botonAlternar = new JButton();
    private JButton botonCerrar = new JButton();

    private void colocarBotonMinimizar() {
        //botonMinimizar.setBackground(Color.red);
    }

    private void colocarBotonAlternar() {
        
    }

    private void colocarBotonCerrar() {

    }

    private void eventoDeMovimiento(Window marco) {
        this.addMouseListener(new MouseAdapter() {

            @Override
            public void mousePressed(MouseEvent me) {
                x = me.getX();
                y = me.getY();
            }
        });
        this.addMouseMotionListener(new MouseAdapter() {

            @Override
            public void mouseDragged(MouseEvent me) {
                marco.setLocation(marco.getLocation().x + me.getX() - x, marco.getLocation().y + me.getY() - y);
            }
        });
    }
}
