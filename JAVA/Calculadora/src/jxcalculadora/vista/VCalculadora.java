package jxcalculadora.vista;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Point;
import java.awt.Window;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

public class VCalculadora extends JFrame {

    public VCalculadora() {
        this.dimensionVCalculadora = new Dimension(300, 400);
        this.panelVCalculadora = new PanelVCalculadora();

        this.setResizable(false);
        this.setSize(this.dimensionVCalculadora);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Calculadora");
        this.getContentPane().setLayout(null);
        this.getContentPane().setPreferredSize(this.dimensionVCalculadora);
        this.pack();

        this.add(this.panelVCalculadora);
    }

    private final Dimension dimensionVCalculadora;
    private final PanelVCalculadora panelVCalculadora;

    public String obtenerValorDisplay() {
        return this.panelVCalculadora.display.getText();
    }

    public void cargarValorDisplay(String txt) {
        this.panelVCalculadora.display.setText(txt);
    }

    public void cargarTipNumeroListener(ActionListener al) {
        for (JButton btn : this.panelVCalculadora.numeros) {
            btn.addActionListener(al);
        }
    }

    public void cargarTipOperadorListener(ActionListener al) {
        for (JButton btn : this.panelVCalculadora.operadores) {
            btn.addActionListener(al);
        }
    }

    public void cargarTipOtroListener(ActionListener al) {
        for (JButton btn : this.panelVCalculadora.otros) {
            btn.addActionListener(al);
        }
    }

    private class PanelVCalculadora extends JPanel {

        public PanelVCalculadora() {
            var gbl = new GridBagLayout();
            var c = new GridBagConstraints();

            this.setLayout(gbl);
            this.setSize(dimensionVCalculadora);
            this.setLocation(0, 0);

            c.fill = GridBagConstraints.BOTH;
            c.weightx = 1;
            c.weighty = 0;
            c.insets.top = 4;
            c.insets.bottom = 1;
            c.insets.left = 1;
            c.insets.right = 1;
            c.gridwidth = GridBagConstraints.REMAINDER;
            this.display = this.colocarDisplay(gbl, c);

            this.numeros = new JButton[11];
            this.operadores = new JButton[5];
            this.otros = new JButton[2];

            c.weighty = 1;
            c.insets.top = 1;
            c.gridwidth = 2;
            this.otros[0] = this.colocarBoton("DEL", gbl, c);
            c.gridwidth = 1;
            this.otros[1] = this.colocarBoton("C", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            this.operadores[4] = this.colocarBoton("/", gbl, c);

            c.gridwidth = 1;
            this.numeros[7] = this.colocarBoton("7", gbl, c);
            this.numeros[8] = this.colocarBoton("8", gbl, c);
            this.numeros[9] = this.colocarBoton("9", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            this.operadores[3] = this.colocarBoton("*", gbl, c);

            c.gridwidth = 1;
            this.numeros[4] = this.colocarBoton("4", gbl, c);
            this.numeros[5] = this.colocarBoton("5", gbl, c);
            this.numeros[6] = this.colocarBoton("6", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            this.operadores[2] = this.colocarBoton("-", gbl, c);

            c.gridwidth = 1;
            this.numeros[1] = this.colocarBoton("1", gbl, c);
            this.numeros[2] = this.colocarBoton("2", gbl, c);
            this.numeros[3] = this.colocarBoton("3", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            this.operadores[1] = this.colocarBoton("+", gbl, c);

            c.gridwidth = 2;
            c.insets.bottom = 4;
            this.numeros[0] = this.colocarBoton("0", gbl, c);
            c.gridwidth = 1;
            this.numeros[10] = this.colocarBoton(".", gbl, c);
            c.gridwidth = GridBagConstraints.REMAINDER;
            this.operadores[0] = this.colocarBoton("=", gbl, c);
        }

        private JLabel display;
        private JButton numeros[];
        private JButton operadores[];
        private JButton otros[];

        private JLabel colocarDisplay(GridBagLayout gbl,
                GridBagConstraints c) {
            // Propiedades del display
            var fuente = new Font("Nirmala UI", Font.PLAIN, 30);
            var color = new Color(10, 50, 70);
            var bgcolor = new Color(0, 48, 100, 70);

            // Creamos la etiqueta (JLabel)
            var jlabel = this.generarJLabel("0.0", fuente, bgcolor, color);
            gbl.setConstraints(jlabel, c);
            this.add(jlabel);

            return jlabel;
        }

        private JLabel generarJLabel(String rotulo, Font fuente, Color bgcolor, Color color) {
            // Seteamos las propiedades del JLabel
            var jlabel = new JLabel(rotulo, JLabel.RIGHT);
            jlabel.setBorder(BorderFactory.createEmptyBorder(5, 4, 5, 4));
            jlabel.setOpaque(true);
            jlabel.setBackground(bgcolor);
            jlabel.setFont(fuente);
            jlabel.setForeground(color);

            return jlabel;
        }

        private JButton colocarBoton(String rotulo, GridBagLayout gbl,
                GridBagConstraints c) {
            // Propiedades del boton
            var fuente = new Font("Nirmala UI", Font.BOLD, 25);
            var bgcolor = new Color(0, 0, 0);
            var color = new Color(255, 255, 255);

            var jbutton = this.generarJButton(rotulo, fuente, bgcolor, color);
            jbutton.addMouseMotionListener(new MouseAdapter() {
                @Override
                public void mouseMoved(MouseEvent me) {
                    jbutton.setBackground(Color.yellow);
                    jbutton.setForeground(Color.black);
                }

            });
            jbutton.addMouseListener(new MouseAdapter() {
                @Override
                public void mouseExited(MouseEvent me) {
                    jbutton.setBackground(Color.black);
                    jbutton.setForeground(Color.white);
                }
            });
            gbl.setConstraints(jbutton, c);
            this.add(jbutton);

            return jbutton;
        }

        private JButton generarJButton(String rotulo, Font fuente, Color bgcolor, Color color) {
            var jbutton = new JButton(rotulo);
            jbutton.setBackground(bgcolor);
            jbutton.setBorder(null);
            jbutton.setFocusPainted(false);
            jbutton.setFont(fuente);
            jbutton.setForeground(color);
            jbutton.setCursor(new Cursor(Cursor.HAND_CURSOR));

            return jbutton;
        }
    }
}
