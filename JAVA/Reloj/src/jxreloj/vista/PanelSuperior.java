package jxreloj.vista;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Image;
import java.awt.Point;
import java.awt.Window;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class PanelSuperior extends JPanel {

    public final static int ALTURA = 30;

    public PanelSuperior(Window marco, int anchura) {
        this.marco = marco;

        this.setLayout(null);
        this.setSize(anchura, 30);
        this.setLocation(0, 0);
        this.setBackground(Color.black);

        eventoMoverMarco(); // Agregamos el evento del marco

        colocarTitulo(new Dimension((int) (anchura / 2), 24), "Reloj", "reloj_mini", "png"); // Agregamos el titulo

        Point locacionBotonMinimizar = new Point(anchura - (dimensionBoton.width + (30 - dimensionBoton.height) / 2) * 2, (30 - dimensionBoton.height) / 2); // Agregamos boton minimizar
        colocarBoton(dimensionBoton, locacionBotonMinimizar, "minimizar", "png").addActionListener((ActionEvent ae) -> {
            ((JFrame) marco).setExtendedState(JFrame.ICONIFIED);
        });

        Point locacionBotonCerrar = new Point(anchura - (dimensionBoton.width + (30 - dimensionBoton.height) / 2), (30 - dimensionBoton.height) / 2); // Agregamos boton cerrar
        colocarBoton(dimensionBoton, locacionBotonCerrar, "cerrar", "png").addActionListener((ActionEvent ae) -> {
            marco.dispose();
        });

        colocarHorizontal(new Dimension(anchura, 30), "bgpintura", "jpg", false); // Agregamos el horizontal
    }

    private final Window marco;
    private final Dimension dimensionBoton = new Dimension(20, 20);

    private void eventoMoverMarco() {
        EventoDeMarco edm = new EventoDeMarco();
        this.addMouseListener(edm);
        this.addMouseMotionListener(edm);
    }

    private void colocarTitulo(Dimension dimension, String rotulo, String recurso, String extension) {
        JLabel lbl = new JLabel(rotulo);
        lbl.setSize(dimension);
        lbl.setLocation(3, (30 - dimension.height) / 2);
        lbl.setVerticalAlignment(JLabel.CENTER);
        lbl.setIcon(new ImageIcon(getClass().getResource("/assets/" + recurso + "." + extension)));
        lbl.setFont(new Font(Ventana.FUENTE, Font.BOLD, 12));
        lbl.setForeground(Color.white);
        this.add(lbl);
    }

    private void colocarHorizontal(Dimension dimension, String recurso, String extension, boolean ajustar) {
        JLabel lbl = new JLabel();
        lbl.setSize(dimension);
        lbl.setLocation(0, 0);
        ImageIcon imc = new ImageIcon(getClass().getResource("/assets/" + recurso + "." + extension));

        if (ajustar) {
            Image conv = imc.getImage().getScaledInstance(lbl.getWidth(), lbl.getHeight(), Image.SCALE_DEFAULT);
            lbl.setIcon(new ImageIcon(conv));
        } else {
            lbl.setIcon(imc);
        }

        this.add(lbl);
    }

    private JButton colocarBoton(Dimension dimension, Point locacion, String recurso, String extension) {
        JButton btn = new JButton();
        btn.setSize(dimension);
        btn.setLocation(locacion);
        btn.setBorderPainted(false);
        btn.setContentAreaFilled(false);
        btn.setFocusPainted(false);
        btn.setIcon(new ImageIcon(getClass().getResource("/assets/" + recurso + "_out." + extension)));
        btn.setRolloverIcon(new ImageIcon(getClass().getResource("/assets/" + recurso + "_in." + extension)));
        this.add(btn);

        return btn;
    }

    private class EventoDeMarco extends MouseAdapter {

        private int x_marco, y_marco;

        @Override
        public void mousePressed(MouseEvent me) {
            x_marco = me.getX();
            y_marco = me.getY();
        }

        @Override
        public void mouseDragged(MouseEvent me) {
            marco.setLocation(marco.getLocation().x + me.getX() - x_marco, marco.getLocation().y + me.getY() - y_marco);
        }
    }
}
