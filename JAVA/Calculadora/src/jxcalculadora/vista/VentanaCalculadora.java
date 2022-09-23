package jxcalculadora.vista;

import java.awt.Color;
import java.awt.Component;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Window;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;

public class VentanaCalculadora extends JFrame implements Ventana {

    public VentanaCalculadora() {
        this.setTitle("Calculadora");
        this.setLayout(null);
        this.setSize(dimension.width + Ventana.BORDE, dimension.height + Ventana.BORDE + PanelSuperior.ALTURA);
        this.setLocationRelativeTo(null);
        this.setUndecorated(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.getContentPane().setBackground(Color.black);

        this.add(panelSuperior);
        this.add(panelCalculadora);
    }

    private final Dimension dimension = new Dimension(300, 400);
    private final PanelSuperior panelSuperior = new PanelSuperior(this, dimension.width);
    private final PanelCalculadora panelCalculadora = new PanelCalculadora();

    @Override
    public Window getPadre() {
        return null;
    }

    private class PanelCalculadora extends JPanel {

        public PanelCalculadora() {
            GridBagLayout gbl = new GridBagLayout();
            GridBagConstraints c = new GridBagConstraints();

            this.setLayout(gbl);
            this.setSize(dimension);
            this.setLocation(Ventana.BORDE / 2, Ventana.BORDE / 2 + PanelSuperior.ALTURA);
            this.setBackground(Color.red);

            c.fill = GridBagConstraints.BOTH;
            c.weightx = 1;
            c.weighty = 2;
            c.insets.top = 4;
            c.insets.bottom = 1;
            c.insets.left = 1;
            c.insets.right = 1;
            c.gridwidth = GridBagConstraints.REMAINDER;
            display = colocarDisplay(gbl, c);

            c.weighty = 1;
            c.insets.top = 1;
            c.gridwidth = 2;
            colocarBoton("C", gbl, c);
            c.gridwidth = 1;
            colocarBoton("←", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            colocarBoton("/", gbl, c);

            c.gridwidth = 1;
            colocarBoton("7", gbl, c);
            colocarBoton("8", gbl, c);
            colocarBoton("9", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            colocarBoton("*", gbl, c);

            c.gridwidth = 1;
            colocarBoton("4", gbl, c);
            colocarBoton("5", gbl, c);
            colocarBoton("6", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            colocarBoton("-", gbl, c);

            c.gridwidth = 1;
            colocarBoton("1", gbl, c);
            colocarBoton("2", gbl, c);
            colocarBoton("3", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            colocarBoton("+", gbl, c);

            c.gridwidth = 2;
            c.insets.bottom = 4;
            colocarBoton("0", gbl, c);
            c.gridwidth = 1;
            colocarBoton(".", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            colocarBoton("=", gbl, c);
        }

        private JLabel display;
        private JButton botones;

        private JLabel colocarDisplay(GridBagLayout gbl,
                GridBagConstraints c) {
            JLabel lbl = new JLabel("0", JLabel.RIGHT);
            lbl.setOpaque(true);
            lbl.setBackground(Color.gray);
            lbl.setBorder(new EmptyBorder(0, 7, 0, 7));
            lbl.setFont(new Font(Ventana.FUENTE, Font.BOLD, 25));
            lbl.setForeground(Color.white);
            gbl.setConstraints(lbl, c);
            this.add(lbl);

            return lbl;
        }

        private JButton colocarBoton(String texto, GridBagLayout gbl,
                GridBagConstraints c) {
            JButton btn = new JButton(texto);
            btn.setBackground(Color.black);
            btn.setBorder(null);
            btn.setFocusPainted(false);
            btn.setFont(new Font(Ventana.FUENTE, Font.BOLD, 20));
            btn.setForeground(Color.white);
            btn.setCursor(new Cursor(Cursor.HAND_CURSOR));
            btn.addMouseMotionListener(new MouseAdapter() {
                @Override
                public void mouseMoved(MouseEvent me) {
                    btn.setBackground(Color.yellow);
                    btn.setFont(new Font(Ventana.FUENTE, Font.PLAIN, 15));
                    btn.setForeground(Color.black);
                }

            });
            btn.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseExited(MouseEvent me) {
                    btn.setBackground(Color.black);
                    btn.setFont(new Font(Ventana.FUENTE, Font.BOLD, 20));
                    btn.setForeground(Color.white);
                }
            });
            gbl.setConstraints(btn, c);
            this.add(btn);

            return btn;
        }
    }
}
