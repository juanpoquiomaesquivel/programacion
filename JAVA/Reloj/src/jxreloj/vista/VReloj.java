package jxreloj.vista;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.HeadlessException;
import java.awt.Window;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class VReloj extends JFrame implements Ventana {

    public VReloj() throws HeadlessException {
        this.setLayout(null);
        //this.setIconImage(new ImageIcon(getClass().getResource("/assets/reloj_icono.png")).getImage());
        this.setTitle("RELOJ");
        this.setSize(dimension.width, dimension.height + PanelSuperior.ALTURA);
        this.setUndecorated(true);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        this.add(panelSuperior);
        this.add(panelReloj);
    }

    private final Dimension dimension = new Dimension(400, 400);
    private final PanelSuperior panelSuperior = new PanelSuperior(this, dimension.width);
    private final PanelMultitrabajo panelReloj = new PanelMultitrabajo();

    @Override
    public Window getPadre() {
        return null;
    }

    private class PanelMultitrabajo extends JPanel {

        public PanelMultitrabajo() {
            this.setSize(dimension);
            this.setLocation(0, PanelSuperior.ALTURA);
            this.setBackground(Color.yellow);
        }
        private final PanelOpciones panelOpciones = new PanelOpciones(null, null, null);
        private final PanelReloj panelReloj = new PanelReloj();
        private final PanelCronometro panelCronometro = new PanelCronometro();
        private final PanelTemporizador panelTemporizador = new PanelTemporizador();

        private class PanelOpciones extends JPanel {

            public PanelOpciones(PanelReloj panelReloj, PanelCronometro panelCronometro, PanelTemporizador panelTemporizador) {
                this.panelReloj = panelReloj;
                this.panelCronometro = panelCronometro;
                this.panelTemporizador = panelTemporizador;
            }

            private final PanelReloj panelReloj;
            private final PanelCronometro panelCronometro;
            private final PanelTemporizador panelTemporizador;
        }

        private class PanelReloj extends JPanel {

            public PanelReloj() {
            }
        }

        private class PanelCronometro extends JPanel {

            public PanelCronometro() {
            }

        }

        private class PanelTemporizador extends JPanel {

            public PanelTemporizador() {
            }

        }
    }
}
