package shared;

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

public class PanelSuperior extends JPanel {

    public PanelSuperior(JFrame jframe, int ancho, String titulo) {
        this.setLayout(null);
        this.setSize(ancho, ALTO);
        this.setLocation(0, 0);
        this.setBackground(Color.BLACK);

        this.lblFondo = generarFondo(jframe, "fondo_.jpg");
        this.lblFondo.setBounds(0, 0, ancho, ALTO);

        this.lblTitulo = this.generarJLabel(" " + titulo, Color.BLACK, Font.PLAIN, 12);
        this.lblTitulo.setBounds(0, 0, ancho / 2, ALTO);
        this.add(this.lblTitulo);

        this.colocarJButtonMinimizar(jframe);
        this.colocarJButtonCerrar(jframe);

        this.add(this.lblFondo);
    }

    private JLabel generarFondo(JFrame jframe, String recurso) {
        JLabel lbl = new JLabel(new ImageIcon(getClass().getResource("/img/" + recurso)));
        lbl.addMouseListener(new MouseAdapter() {

            @Override
            public void mousePressed(MouseEvent me) {
                x = me.getX();
                y = me.getY();
            }
        });
        lbl.addMouseMotionListener(new MouseAdapter() {

            @Override
            public void mouseDragged(MouseEvent me) {
                jframe.setLocation(jframe.getLocation().x + me.getX() - x, jframe.getLocation().y + me.getY() - y);
            }
        });

        return lbl;
    }

    private JLabel generarJLabel(String etiqueta, Color color, int estilo, int tamano) {
        JLabel lbl = new JLabel(etiqueta);
        lbl.setFont(new Font("Berlin Sans FB", estilo, tamano));
        lbl.setForeground(color);

        return lbl;
    }

    private void colocarJButtonMinimizar(JFrame jframe) {
        JButton btn = new JButton(new ImageIcon(getClass().getResource("/img/minimizar.png")));
        btn.setBorderPainted(false);
        btn.setContentAreaFilled(false);
        btn.setFocusPainted(false);
        btn.setBorder(null);
        btn.setBounds(344, 3, 24, 24);
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                jframe.setExtendedState(JFrame.ICONIFIED);
            }
        });
        btn.addMouseListener(new MouseAdapter() {

            @Override
            public void mouseEntered(MouseEvent me) {
                btn.setIcon(new ImageIcon(getClass().getResource("/img/_minimizar.png")));
            }

            @Override
            public void mouseExited(MouseEvent me) {
                btn.setIcon(new ImageIcon(getClass().getResource("/img/minimizar.png")));
            }
        });
        this.add(btn);
    }

    private void colocarJButtonCerrar(JFrame jframe) {
        JButton btn = new JButton(new ImageIcon(getClass().getResource("/img/cerrar.png")));
        btn.setBorderPainted(false);
        btn.setContentAreaFilled(false);
        btn.setFocusPainted(false);
        btn.setBorder(null);
        btn.setBounds(370, 3, 24, 24);
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                System.exit(0);
            }
        });
        btn.addMouseListener(new MouseAdapter() {

            @Override
            public void mouseEntered(MouseEvent me) {
                btn.setIcon(new ImageIcon(getClass().getResource("/img/_cerrar.png")));
            }

            @Override
            public void mouseExited(MouseEvent me) {
                btn.setIcon(new ImageIcon(getClass().getResource("/img/cerrar.png")));
            }
        });
        this.add(btn);
    }

    public static final int ALTO = 30;
    private int x, y;
    private JLabel lblFondo;
    private JLabel lblTitulo;
}
