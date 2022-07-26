package view;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

import model.Jugador;
import shared.PanelSuperior;
import shared.Ventana;

public class VentanaJuego extends JFrame implements Ventana {

    public VentanaJuego(JFrame jfather, Jugador gamer1, Jugador gamer2) {
        this.jfather = jfather;
        this.setLayout(null);
        this.setSize(ANCHO, ALTO + PanelSuperior.ALTO);
        this.setLocationRelativeTo(null);
        this.setUndecorated(true);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        panelSuperior = new PanelSuperior(this, ANCHO, "A jugar!");
        this.add(panelSuperior);

        panelJuego = new PanelJuego(this, ANCHO, ALTO);
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

    public PanelJuego(JFrame jframe, int ancho, int alto) {
        this.jframe = jframe;
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

                        //actualizar(juego.comprobar());
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

                /*if (Michi.enfoque.equals("local")) {
                    if (LaminaJuegoLocal.gamer1.isTurno()) {
                        casilla.setIcon(new ImageIcon(getClass().getResource("/Imagenes/" + LaminaJuegoLocal.gamer1.getFigura().toLowerCase() + ".png")));
                        michi[i][j] = LaminaJuegoLocal.gamer1.getFigura();
                        
                        LaminaJuegoLocal.gamer1.setTurno(false);
                    } else {
                        casilla.setIcon(new ImageIcon(getClass().getResource("/Imagenes/" + LaminaJuegoLocal.gamer2.getFigura().toLowerCase() + ".png")));
                        michi[i][j] = LaminaJuegoLocal.gamer2.getFigura();
                        
                        LaminaJuegoLocal.gamer1.setTurno(true);
                    }
                } else if (LaminaJuegoOnline.gamer1.isTurno()) {
                    casilla.setIcon(new ImageIcon(getClass().getResource("/Imagenes/" + LaminaJuegoOnline.gamer1.getFigura().toLowerCase() + ".png")));
                    michi[i][j] = LaminaJuegoOnline.gamer1.getFigura();

                    x = i;
                    y = j;
                }*/
            }
        });

        return btn;
    }

    private JFrame jframe;
    private Jugador gamer1;
    private Jugador gamer2;
    private JButton[][] btnMichi;
}