package jxcalculadora.vista;

import java.awt.Color;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class PanelSuperior extends JPanel {

    public final static int ALTURA = 30;

    public PanelSuperior(Window marco, int ancho) {
        this.marco = marco;
        this.ancho = ancho;
        this.setLayout(null);
        this.setSize(ancho, 30);
        this.setLocation(Ventana.BORDE / 2, Ventana.BORDE / 2);
        colocarBotonMinimizar();
        colocarBotonCerrar();
        eventoMoverMarco();
    }

    private Window marco;
    private int ancho;
    private int x, y;
    private final int altura = 24;
    private final int margen = 3;

    private void colocarBotonMinimizar() {
        JButton btn = new JButton();
        btn.setSize(altura, altura);
        btn.setLocation(ancho - (altura + margen) * 2, margen);
        eventoMinimizarMarco(btn);
        this.add(btn);
    }

    private void colocarBotonCerrar() {
        JButton btn = new JButton();
        btn.setSize(altura, altura);
        btn.setLocation(ancho - (altura + margen), margen);
        eventoCerrarMarco(btn);
        this.add(btn);
    }

    private void eventoMoverMarco() {
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

    private void eventoMinimizarMarco(JButton btn) {
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                ((JFrame) marco).setExtendedState(JFrame.ICONIFIED);
            }
        });
    }

    private void eventoCerrarMarco(JButton btn) {
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                marco.dispose();
            }
        });
    }
}
