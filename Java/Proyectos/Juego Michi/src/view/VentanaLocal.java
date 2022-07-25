package view;

import java.awt.Color;
import java.awt.Font;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import shared.PanelSuperior;
import shared.Ventana;

public class VentanaLocal extends JFrame implements Ventana {

    public VentanaLocal(JFrame jfather) {
        this.jfather = jfather;
        this.setLayout(null);
        this.setSize(ANCHO, ALTO + PanelSuperior.ALTO);
        this.setLocationRelativeTo(null);
        this.setUndecorated(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        panelSuperior = new PanelSuperior(this, ANCHO, "Juego Local");
        this.add(panelSuperior);

        panelLocal = new PanelLocal(this, ANCHO, ALTO);
        this.add(panelLocal);
    }

    private JFrame jfather;
    private static final int ANCHO = 400, ALTO = 370;
    private PanelSuperior panelSuperior;
    private PanelLocal panelLocal;

    @Override
    public JFrame getPadre() {
        return this.jfather;
    }
}

class PanelLocal extends JPanel {

    public PanelLocal(JFrame jframe, int ancho, int alto) {
        this.jframe = jframe;
        this.setLayout(null);
        this.setSize(ancho, alto);
        this.setLocation(0, PanelSuperior.ALTO);
        this.setBackground(Color.WHITE);

        this.lblJugador1 = this.generarJLabel("jugador1.png", "Jugador 1", Font.PLAIN, 18);
        this.lblJugador1.setBounds((ancho - 150) / 2, 40, 150, 35);
        this.add(this.lblJugador1);

        this.lblJugador2 = this.generarJLabel("jugador2.png", "Jugador 2", Font.PLAIN, 18);
        this.lblJugador2.setBounds((ancho - 150) / 2, 120, 150, 35);
        this.add(this.lblJugador2);

        this.txtJugador1 = this.generarJTextField();
        this.txtJugador1.setBounds((ancho - 120) / 2, 72, 120, 25);
        this.add(this.txtJugador1);

        this.txtJugador2 = this.generarJTextField();
        this.txtJugador2.setBounds((ancho - 120) / 2, 152, 120, 25);
        this.add(this.txtJugador2);

        this.colocarFondo("fondo_principal.png", ancho, alto);
    }

    private void colocarFondo(String recurso, int ancho, int alto) {
        JLabel lbl = new JLabel(new ImageIcon(getClass().getResource("/img/" + recurso)));
        lbl.setBounds(0, 0, ancho, alto);
        this.add(lbl);
    }

    private JLabel generarJLabel(String recurso, String rotulo, int estilo, int tamano) {
        JLabel lbl = new JLabel(rotulo, new ImageIcon(getClass().getResource("/img/" + recurso)), JLabel.CENTER);
        lbl.setFont(new Font(Ventana.FONT, estilo, tamano));
        lbl.setForeground(Color.BLACK);

        return lbl;
    }

    private JTextField generarJTextField() {
        JTextField txt = new JTextField();
        txt.setFont(new Font("Cascadia Mono", Font.PLAIN, 12));
        txt.setForeground(Color.BLACK);

        return txt;
    }

    private JFrame jframe;
    private JLabel lblJugador1;
    private JLabel lblJugador2;
    private JTextField txtJugador1;
    private JTextField txtJugador2;
}