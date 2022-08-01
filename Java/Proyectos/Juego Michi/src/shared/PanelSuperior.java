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
import java.awt.Window;

public class PanelSuperior extends JPanel {

    public PanelSuperior(Window frame, int tipo, int ancho, String titulo) {
        this.ancho = ancho;
        this.setLayout(null);
        this.setSize(ancho, ALTO);
        this.setLocation(0, 0);
        this.setBackground(Color.BLACK);

        this.lblTitulo = this.generarJLabel(titulo, Color.BLACK, Font.PLAIN, 12);
        this.lblTitulo.setBounds(3, 0, ancho / 2, ALTO);
        this.add(this.lblTitulo);
        if (tipo == Ventana.WINDOW)
            this.colocarJButtonMinimizar(frame);
        this.colocarJButtonCerrar(frame);
        this.colocarFondo(frame, "fondo_.jpg");
    }

    private void colocarFondo(Window frame, String recurso) {
        JLabel lbl = new JLabel(new ImageIcon(getClass().getResource("/img/" + recurso)));
        lbl.setBounds(0, 0, this.ancho, PanelSuperior.ALTO);
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
                frame.setLocation(frame.getLocation().x + me.getX() - x, frame.getLocation().y + me.getY() - y);
            }
        });
        this.add(lbl);
    }

    private JLabel generarJLabel(String rotulo, Color color, int estilo, int tamano) {
        JLabel lbl = new JLabel(rotulo);
        lbl.setFont(new Font(Ventana.FONT, estilo, tamano));
        lbl.setForeground(color);

        return lbl;
    }

    private void colocarJButtonMinimizar(Window frame) {
        JButton btn = new JButton(new ImageIcon(getClass().getResource("/img/minimizar.png")));
        btn.setBorderPainted(false);
        btn.setContentAreaFilled(false);
        btn.setFocusPainted(false);
        btn.setBorder(null);
        btn.setBounds(ancho - 54, 3, 24, 24);
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                ((JFrame) frame).setExtendedState(JFrame.ICONIFIED);
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

    private void colocarJButtonCerrar(Window frame) {
        JButton btn = new JButton(new ImageIcon(getClass().getResource("/img/cerrar.png")));
        btn.setBorderPainted(false);
        btn.setContentAreaFilled(false);
        btn.setFocusPainted(false);
        btn.setBorder(null);
        btn.setBounds(ancho - 27, 3, 24, 24);
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                Window aux = ((Ventana) frame).getPadre();

                if (aux != null) {
                    aux.setLocation(frame.getLocation());
                    aux.setVisible(true);
                }

                frame.dispose();
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

    private int ancho;
    public static final int ALTO = 30;
    private int x, y;
    private JLabel lblTitulo;
}
