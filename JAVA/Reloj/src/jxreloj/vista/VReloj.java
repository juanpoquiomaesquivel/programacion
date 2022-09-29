package jxreloj.vista;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.HeadlessException;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class VReloj extends JFrame {

    public VReloj() throws HeadlessException {
        this.dimensionVReloj = new Dimension(400, 400);
        this.panelVReloj = new PanelVReloj();

        this.setSize(this.dimensionVReloj);
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setTitle("Reloj");
        this.getContentPane().setLayout(null);
        this.getContentPane().setPreferredSize(this.dimensionVReloj);
        this.pack();

        this.add(this.panelVReloj);
    }

    private final Dimension dimensionVReloj;
    private final PanelVReloj panelVReloj;

    public void cargarTiempo(int[] hhmmss) {
        this.panelVReloj.horas = hhmmss[0];
        this.panelVReloj.minutos = hhmmss[1];
        this.panelVReloj.segundos = hhmmss[2];
        this.panelVReloj.textoDeLabelDigital();
    }

    private class PanelVReloj extends JPanel {

        public PanelVReloj() {
            this.labelDigital = this.colocarLabelDigital(new Point(50, 55));
            this.add(this.labelDigital);

            var labelAnalogico = this.colocarLabelAnalogico(new Point(90, 150));
            this.add(labelAnalogico);

            this.setLayout(null);
            this.setSize(dimensionVReloj);
            this.setLocation(0, 0);

            this.colocarTitulo("RELOJ DIGITAL/ANALÓGICO", new Point(10, 5));
            this.colocarEtiquetasDeRelojDigital("HORAS", new Point(42, 100));
            this.colocarEtiquetasDeRelojDigital("MINUTOS", new Point(150, 100));
            this.colocarEtiquetasDeRelojDigital("SEGUNDOS", new Point(257, 100));
        }

        private final JLabel labelDigital;
        private int horas;
        private int minutos;
        private int segundos;

        private void textoDeLabelDigital() {
            // Transformamos a String los valores del tiempo actual
            var hh = (this.horas < 10 ? "0" + Integer.toString(this.horas) : Integer.toString(this.horas));
            var mm = (this.minutos < 10 ? "0" + Integer.toString(this.minutos) : Integer.toString(this.minutos));
            var ss = (this.segundos < 10 ? "0" + Integer.toString(this.segundos) : Integer.toString(this.segundos));

            this.labelDigital.setText(hh + ":" + mm + ":" + ss);
        }

        private JLabel colocarLabelDigital(Point posicion) {
            // Propiedades del label digital
            var dimension = new Dimension(300, 50);
            var fuente = new Font("Courier New", Font.BOLD, 60);
            var color = new Color(70, 20, 44);

            return this.generarJLabel("00:00:00", dimension, posicion, fuente, color);
        }

        private JLabel colocarLabelAnalogico(Point posicion) {
            // Propiedades del label analogico
            var dimension = new Dimension(220, 220);

            // Creamos la etiqueta (JLabel)
            var labelAnalogico = new JLabel() {

                @Override
                protected void paintComponent(Graphics g) {
                    super.paintComponent(g);

                    // Casteamos a Graphics2D
                    var g2 = (Graphics2D) g;

                    var color = new Color(0, 0, 0, 100); // Color del reloj

                    // Colocamos el circulo de fondo
                    g2.setPaint(color);
                    g2.fillOval(10, 10, 200, 200);

                    // Colocamos la circunferencia de borde
                    g2.setPaint(new Color(color.getRGB(), false));
                    g2.setStroke(new BasicStroke(3)); // Grosor del borde
                    g2.drawOval(10, 10, 200, 200);

                    var anchura = dimension.width;
                    var altura = dimension.height;

                    var tamano = (anchura < altura ? anchura : altura) - 2 * 200;
                    var xCentro = dimension.width / 2;
                    var yCentro = dimension.height / 2;

                    // Agregamos las marcas de borde
                    // g2.setPaint(color); // Color de las marcas
                    for (var seg = 0; seg < 60; seg++) {
                        var inicio = 0;

                        if (seg % 5 == 0) {
                            g2.setStroke(new BasicStroke(2)); // Grosor de las marcas de las horas
                            inicio = tamano / 2 - 10;
                            diseno(g2, xCentro, yCentro, rad * seg, inicio, tamano / 2);
                        } else {
                            g2.setStroke(new BasicStroke(1)); // Grosor de las marcas de los segundos
                            inicio = tamano / 2 - 5;
                        }

                        diseno(g2, xCentro, yCentro, rad * seg, inicio, tamano / 2);
                    }

                    // Definimos las propiedades del segundero e implementamos
                    g2.setPaint(new Color(220, 0, 0)); // Color del segundero
                    g2.setStroke(new BasicStroke(1)); // Grosor del segundero
                    float fsegundos = PanelVReloj.this.segundos;
                    float anguloSegundero = tresPi - (rad * fsegundos);
                    diseno(g2, xCentro, yCentro, anguloSegundero, 0, 100);

                    // Definimos las propiedades del minutero e implementamos
                    g2.setPaint(new Color(color.getRGB(), false)); // Color del minutero
                    g2.setStroke(new BasicStroke(2)); // Grosor del minutero
                    float fminutos = (float) (PanelVReloj.this.minutos + fsegundos / 60.0);
                    float anguloMinutero = tresPi - (rad * fminutos);
                    diseno(g2, xCentro, yCentro, anguloMinutero, 0, 68);

                    //Definimos las propiedades del horario e implementamos
                    g2.setPaint(new Color(color.getRGB(), false)); // Color del horario
                    g2.setStroke(new BasicStroke(3)); // Grosor del horario
                    float fhours = (float) (PanelVReloj.this.horas + fminutos / 60.0);
                    float anguloHora = tresPi - (5 * rad * fhours);
                    diseno(g2, xCentro, yCentro, anguloHora, 0, 34);

                    var etiquetas = new String[]{"12", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11"};
                    var fluctuaciones = new int[][]{
                        {0, -78}, {40, -68}, {69, -37}, {82, 2}, {69, 41},
                        {40, 68}, {0, 80}, {-37, 68}, {-68, 41}, {-80, 2},
                        {-63, -37}, {-39, -66}};

                    // Agregamos las etiquetas del reloj analogico 
                    var fuente = new Font("Courier New", Font.BOLD, 16);
                    g2.setFont(fuente); // Fuente de las etiquetas
                    g2.setPaint(new Color(0, 0, 0)); // Color de las etiquetas

                    for (var i = 0; i < etiquetas.length; i++) {
                        var loc = generarStringCentrado(g2, etiquetas[i], new Rectangle(dimension), fuente);
                        g2.drawString(etiquetas[i], loc.x + fluctuaciones[i][0], loc.y + fluctuaciones[i][1]);
                    }
                }
            };
            labelAnalogico.setSize(dimension);
            labelAnalogico.setLocation(posicion);

            return labelAnalogico;
        }

        private Point generarStringCentrado(Graphics2D g2, String texto, Rectangle rectangulo, Font fuente) {
            var metricas = g2.getFontMetrics(fuente);
            var x = rectangulo.x + (rectangulo.width - metricas.stringWidth(texto)) / 2;
            var y = rectangulo.y + ((rectangulo.height - metricas.getHeight()) / 2) + metricas.getAscent();

            return new Point(x, y);
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);

            // Casteamos a Graphics2D
            var g2 = (Graphics2D) g;

            // Seteamos propiedades para trazos suaves
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BICUBIC);
            g2.setRenderingHint(RenderingHints.KEY_ALPHA_INTERPOLATION, RenderingHints.VALUE_ALPHA_INTERPOLATION_QUALITY);
            g2.setRenderingHint(RenderingHints.KEY_COLOR_RENDERING, RenderingHints.VALUE_COLOR_RENDER_QUALITY);
            g2.setRenderingHint(RenderingHints.KEY_DITHERING, RenderingHints.VALUE_DITHER_ENABLE);
            g2.setRenderingHint(RenderingHints.KEY_RENDERING, RenderingHints.VALUE_RENDER_QUALITY);

            // Agregamos el color de fondo del lienzo
            this.colocarColorDeFondo(g2);
        }

        private void colocarColorDeFondo(Graphics2D g2) {
            // Propiedades del color de fondo del lienzo
            var color1 = new Color(213, 204, 255);
            var color2 = new Color(68, 0, 224);

            // Colocamos el color de fondo del lienzo
            g2.setPaint(new GradientPaint(25, 25, color1, 375, 375, color2));
            g2.fillRect(0, 0, 400, 400);
        }

        private void colocarTitulo(String rotulo, Point posicion) {
            // Propiedades del titulo
            var dimension = new Dimension(380, 50);
            var fuente = new Font("Victor Mono SemiBold", Font.BOLD, 28);
            var color = new Color(70, 20, 44);

            // Creamos la etiqueta (JLabel)
            var etiqueta = this.generarJLabel(rotulo, dimension, posicion, fuente, color);

            // Colocamos la etiqueta
            this.add(etiqueta);
        }

        private void colocarEtiquetasDeRelojDigital(String rotulo, Point posicion) {
            // Propiedades de las etiquetas del deloj digital
            var dimension = new Dimension(100, 30);
            var fuente = new Font("Victor Mono", Font.BOLD, 15);
            var color = new Color(70, 20, 44);

            // Creamos la etiqueta (JLabel)
            var etiqueta = this.generarJLabel(rotulo, dimension, posicion, fuente, color);

            // Colocamos la etiqueta
            this.add(etiqueta);
        }

        private JLabel generarJLabel(String rotulo, Dimension dimension, Point posicion, Font fuente, Color color) {
            // Seteamos las propiedades del JLabel
            var jlabel = new JLabel(rotulo, JLabel.CENTER);
            jlabel.setSize(dimension);
            jlabel.setLocation(posicion);
            jlabel.setFont(fuente);
            jlabel.setForeground(color);

            return jlabel;
        }

        private static final float tresPi = (float) (3.0 * Math.PI);
        private static final float rad = (float) (Math.PI / 30.0);

        private void diseno(Graphics2D g2, int x, int y, double angulo, int minRadius, int maxRadius) {
            var sine = (float) Math.sin(angulo);
            var cosine = (float) Math.cos(angulo);

            var dxmin = (int) (minRadius * sine);
            var dymin = (int) (minRadius * cosine);

            var dxmax = (int) (maxRadius * sine);
            var dymax = (int) (maxRadius * cosine);
            g2.drawLine(x + dxmin, y + dymin, x + dxmax, y + dymax);
        }
    }
}
