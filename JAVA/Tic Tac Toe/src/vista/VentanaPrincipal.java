package vista;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Image;
import java.awt.Point;
import java.awt.Window;
import java.net.URL;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class VentanaPrincipal extends JFrame implements Ventana {

    public VentanaPrincipal() {
        this.setLayout(null);
        this.setTitle("Ventana Principal");
        this.setUndecorated(true);
        this.setSize(new Dimension(tamano.width, tamano.height + PanelSuperior.ALTO));
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Color colorPanelSuperior = new Color(51, 51, 255);
        Color colorPanelPrincipal = new Color(230, 230, 255);

        panelSuperior = new PanelSuperior(this, Ventana.VENTANA_NORMAL, tamano.width, colorPanelSuperior);
        panelPrincipal = new PanelPrincipal(this, tamano, "fondo.jpg");

        this.add(panelSuperior);
        this.add(panelPrincipal);
    }

    private final Dimension tamano = new Dimension(400, 400);
    private final PanelSuperior panelSuperior;
    private final PanelPrincipal panelPrincipal;

    @Override
    public Window getPadre() {
        return null;
    }
}

class PanelPrincipal extends JPanel {

    public PanelPrincipal(Window marco, Dimension tamano, Color color) {
        this.tamano = tamano;
        this.setLayout(null);
        this.setSize(tamano);
        this.setLocation(posicion);
        this.setBackground(color);
    }

    public PanelPrincipal(Window marco, Dimension tamano, String recurso) {
        this.tamano = tamano;
        this.setLayout(null);
        this.setSize(tamano);
        this.setLocation(posicion);
        colocarFondo(recurso);
    }

    private final Dimension tamano;
    private final Point posicion = new Point(0, PanelSuperior.ALTO);
    private JLabel fondo;

    private void colocarFondo(String recurso) {
        URL fuente = this.getClass().getResource("/assets/" + recurso);

        if (fuente != null) {
            ImageIcon imagen = new ImageIcon(fuente);
            fondo = new JLabel();
            fondo.setSize(tamano.width, tamano.height);
            fondo.setLocation(new Point(0, 0));

            if (imagen.getIconWidth() == fondo.getWidth() && imagen.getIconHeight() == tamano.getHeight())
                fondo.setIcon(imagen);
            else {
                Image conversor = imagen.getImage().getScaledInstance(fondo.getWidth(), fondo.getHeight(),
                        Image.SCALE_AREA_AVERAGING);
                fondo.setIcon(new ImageIcon(conversor));
            }

            this.add(fondo);
        } else
            this.setBackground(Color.WHITE);
    }
}