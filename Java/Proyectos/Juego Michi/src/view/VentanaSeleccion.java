package view;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import shared.PanelSuperior;
import shared.Ventana;

public class VentanaSeleccion extends JFrame implements Ventana {

    public VentanaSeleccion() {
        this.setLayout(null);
        this.setSize(ANCHO, ALTO + PanelSuperior.ALTO);
        this.setLocationRelativeTo(null);
        this.setUndecorated(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        panelSuperior = new PanelSuperior(this, ANCHO, "Iniciar Sesion");
        this.add(panelSuperior);

        panelPrincipal = new PanelSeleccion(this, ANCHO, ALTO);
        this.add(panelPrincipal);
    }

    private static final int ANCHO = 400, ALTO = 370;
    private PanelSuperior panelSuperior;
    private PanelSeleccion panelPrincipal;

    @Override
    public JFrame getPadre() {
        return null;
    }
}

class PanelSeleccion extends JPanel {

    public PanelSeleccion(JFrame jframe, int ancho, int alto) {
        this.setLayout(null);
        this.setSize(ancho, alto);
        this.setLocation(0, PanelSuperior.ALTO);
        this.setBackground(Color.WHITE);

        this.lblFondo = this.generarFondo("fondo_principal.png");
        this.lblFondo.setBounds(0, 0, ancho, alto);

        this.lblTitulo = this.generarJLabel("Tic Tac Toe", Color.BLACK, Font.BOLD, 35);
        this.lblTitulo.setBounds(50, 10, 300, 40);
        this.add(this.lblTitulo);

        this.lblSubtitulo = this.generarJLabel("¡Disfruta el juego!", Color.BLACK, Font.PLAIN, 15);
        this.lblSubtitulo.setBounds(50, 55, 300, 20);
        this.add(this.lblSubtitulo);

        this.btnLocal = this.generarJButton("local.png");
        this.btnLocal.setBounds(136, 82, 128, 128);
        this.add(this.btnLocal);

        this.btnOnline = this.generarJButton("online.png");
        this.btnOnline.setBounds(136, 220, 128, 128);
        this.add(this.btnOnline);

        this.add(this.lblFondo);
    }

    private JLabel generarFondo(String recurso) {
        JLabel lbl = new JLabel(new ImageIcon(getClass().getResource("/img/" + recurso)));

        return lbl;
    }

    private JLabel generarJLabel(String etiqueta, Color color, int estilo, int tamano) {
        JLabel lbl = new JLabel(etiqueta);
        lbl.setHorizontalAlignment(JLabel.CENTER);
        lbl.setFont(new Font("Berlin Sans FB", estilo, tamano));
        lbl.setForeground(color);

        return lbl;
    }

    private JButton generarJButton(String recurso) {
        JButton btn = new JButton();
        btn.setIcon(new ImageIcon(getClass().getResource("/img/" + recurso)));
        btn.setBorderPainted(false);
        btn.setContentAreaFilled(false);
        btn.setFocusPainted(false);
        btn.setBorder(null);
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {

                // Michi.enfoque = "local";

                // if (cont_local == 0) {
                // vp_local = new VentanaPrincipal(marco, "local");
                // vp_local.setVisible(true);

                // cont_local++;
                // } else {
                // vp_local.setLocation(marco.getLocation());
                // vp_local.setVisible(true);
                // }

                // marco.dispose();
            }
        });
        btn.addMouseListener(new MouseAdapter() {

            @Override
            public void mouseEntered(MouseEvent me) {
                btn.setIcon(new ImageIcon(getClass().getResource("/img/_" + recurso)));
            }

            @Override
            public void mouseExited(MouseEvent me) {
                btn.setIcon(new ImageIcon(getClass().getResource("/img/" + recurso)));
            }
        });

        return btn;
    }

    private JLabel lblFondo;
    private JLabel lblTitulo;
    private JLabel lblSubtitulo;
    private JButton btnLocal;
    private JButton btnOnline;
}