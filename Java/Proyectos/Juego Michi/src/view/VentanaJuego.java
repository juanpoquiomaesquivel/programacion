package view;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import model.Jugador;
import model.Michi;
import shared.PanelSuperior;
import shared.Ventana;

public class VentanaJuego extends JFrame implements Ventana {

    public VentanaJuego(JFrame jfather, Jugador gamer1, Jugador gamer2) {
        this.jfather = jfather;
        this.setLayout(null);
        this.setSize(ANCHO, ALTO + PanelSuperior.ALTO);
        this.setLocationRelativeTo(jfather);
        this.setUndecorated(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        panelSuperior = new PanelSuperior(this, Ventana.WINDOW, ANCHO, "A jugar!");
        this.add(panelSuperior);

        String enfoque = (gamer2 == null ? "online" : "local");
        panelJuego = new PanelJuego(this, ANCHO, ALTO, enfoque, gamer1, gamer2);
        this.add(panelJuego);
    }

    private JFrame jfather;
    private static final int ANCHO = 400, ALTO = 370;
    private PanelSuperior panelSuperior;
    private PanelJuego panelJuego;

    @Override
    public JFrame getPadre() {
        return this.jfather;
    }
}

class PanelJuego extends JPanel {

    public PanelJuego(JFrame jframe, int ancho, int alto, String enfoque, Jugador gamer1, Jugador gamer2) {
        this.jframe = jframe;
        this.enfoque = enfoque;
        this.gamer1 = gamer1;
        this.gamer2 = gamer2;
        this.michi = new Michi();
        this.setLayout(new GridLayout(3, 3));
        this.setSize(ancho, alto);
        this.setLocation(0, PanelSuperior.ALTO);
        this.setBackground(Color.WHITE);

        this.colocarJButton();
    }

    private void colocarJButton() {
        this.btnMichi = new JButton[3][3];

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                this.btnMichi[i][j] = this.generarJButton(i, j);
                this.btnMichi[i][j].addMouseListener(new MouseAdapter() {

                    @Override
                    public void mouseReleased(MouseEvent me) {
                        actualizar();
                    }
                });

                this.add(btnMichi[i][j]);
            }
        }
    }

    private JButton generarJButton(int i, int j) {
        JButton btn = new JButton(null, null);
        btn.setBackground(new Color(250, 241, 255));
        btn.setName(i + "" + j);
        btn.setFocusPainted(false);
        btn.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent ae) {
                int i = Character.getNumericValue(btn.getName().charAt(0));
                int j = Character.getNumericValue(btn.getName().charAt(1));

                if (btn.getIcon() != null) {
                    return;
                }

                boolean turno = gamer1.isTurno();

                if (enfoque.equals("local")) {
                    btn.setIcon(new ImageIcon(getClass().getResource("/img/" +
                            (turno ? "x" : "o") + ".png")));
                    michi.tabla[i][j] = (turno ? gamer1.getFigura() : gamer2.getFigura());
                    gamer1.setTurno(!turno);
                } else if (turno) {
                    btn.setIcon(new ImageIcon(getClass().getResource("/img/" +
                            gamer1.getFigura().toLowerCase() + ".png")));
                    michi.tabla[i][j] = gamer1.getFigura();
                }

            }
        });

        return btn;
    }

    private void actualizar() {
        int datos[] = michi.comprobar();

        switch (datos[0]) {
            case Michi.WINNER1:
                btnMichi[datos[1]][datos[2]].setBackground(new Color(255, 206, 206));
                btnMichi[datos[3]][datos[4]].setBackground(new Color(255, 206, 206));
                btnMichi[datos[5]][datos[6]].setBackground(new Color(255, 206, 206));

                vg = new VentanaGanador(jframe, gamer1.getNickname(), gamer2.getNickname());
                vg.setVisible(true);
                jframe.dispose();
                /*
                 * vg = new VentanaGanador(marco, LaminaJuegoLocal.gamer1,
                 * LaminaJuegoLocal.gamer2, 1);
                 * vg.setVisible(true);
                 * 
                 * for (int k = 0; k < 3; k++) {
                 * for (int l = 0; l < 3; l++) {
                 * juego.michi[k][l] = "";
                 * botones[k][l].setIcon(null);
                 * botones[k][l].setBackground(new Color(250, 241, 255));
                 * }
                 * }
                 * 
                 * LaminaJuegoLocal.gamer1.setTurno(true);
                 */
                break;
            case Michi.WINNER2:
                btnMichi[datos[1]][datos[2]].setBackground(new Color(206, 237, 255));
                btnMichi[datos[3]][datos[4]].setBackground(new Color(206, 237, 255));
                btnMichi[datos[5]][datos[6]].setBackground(new Color(206, 237, 255));

                vg = new VentanaGanador(jframe, gamer2.getNickname(), gamer1.getNickname());
                vg.setVisible(true);
                jframe.dispose();
                /*
                 * vg = new VentanaGanador(marco, LaminaJuegoLocal.gamer1,
                 * LaminaJuegoLocal.gamer2, 2);
                 * vg.setVisible(true);
                 * 
                 * for (int k = 0; k < 3; k++) {
                 * for (int l = 0; l < 3; l++) {
                 * juego.michi[k][l] = "";
                 * botones[k][l].setIcon(null);
                 * botones[k][l].setBackground(new Color(250, 241, 255));
                 * }
                 * }
                 * 
                 * LaminaJuegoLocal.gamer1.setTurno(true);
                 */
                break;
            case Michi.DRAW:
                // int a = 0;

                /*
                 * for (int k = 0; k < 3; k++) {
                 * for (int l = 0; l < 3; l++) {
                 * if ("X".equals(juego.michi[k][l]) || "O".equals(juego.michi[k][l])) {
                 * a++;
                 * }
                 * }
                 * }
                 * 
                 * if (a == 9) {
                 * vg = new VentanaGanador(marco, LaminaJuegoLocal.gamer1,
                 * LaminaJuegoLocal.gamer2, 0);
                 * vg.setVisible(true);
                 * 
                 * for (int k = 0; k < 3; k++) {
                 * for (int l = 0; l < 3; l++) {
                 * juego.michi[k][l] = "";
                 * botones[k][l].setIcon(null);
                 * }
                 * }
                 * 
                 * LaminaJuegoLocal.gamer1.setTurno(true);
                 * break;
                 * }
                 */
        }
    }

    private JFrame jframe;
    private Jugador gamer1;
    private Jugador gamer2;
    private JButton[][] btnMichi;
    private Michi michi;
    private String enfoque;
    private VentanaGanador vg;
}