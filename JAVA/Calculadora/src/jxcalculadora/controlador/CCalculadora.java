package jxcalculadora.controlador;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import jxcalculadora.modelo.MCalculadora;
import jxcalculadora.vista.VCalculadora;

public class CCalculadora {

    public CCalculadora(MCalculadora modelo, VCalculadora vista) {
        this.modelo = modelo;
        this.vista = vista;
        this.vista.cargarTipNumeroListener(new TipNumeroListener());
        this.vista.cargarTipOperadorListener(new TipOperadorListener());
        this.vista.cargarTipOtroListener(new TipOtroListener());
    }

    private MCalculadora modelo;
    private VCalculadora vista;

    private class TipNumeroListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent ae) {
            String token = ((JButton) ae.getSource()).getText();
            String operacion = modelo.getOperacion();
            String tipPrevio = modelo.getTip();
            int decimales = modelo.getDecimales();

            if ("operator".equals(tipPrevio)) {
                double valor = modelo.getAcumulado();
                double display = Double.parseDouble(vista.obtenerValorDisplay());
                double resultado = 0.0;

                switch (operacion) {
                    case "+" -> {
                        resultado = MCalculadora.sumar(valor, display);
                    }
                    case "-" -> {
                        resultado = MCalculadora.restar(valor, display);
                    }
                    case "*" -> {
                        resultado = MCalculadora.multiplicar(valor, display);
                    }
                    case "/" -> {
                        resultado = MCalculadora.dividir(valor, display);
                    }
                    case "none" -> {
                        resultado = MCalculadora.sumar(valor, display);
                    }
                }

                modelo.setAcumulado(resultado);
                vista.cargarValorDisplay(token);
            }

            if (".".equals(token) && decimales == 0) {
                modelo.setDecimales(1);
            }

            if ("0123456789".contains(token)) {
                double valor = Double.parseDouble(vista.obtenerValorDisplay());

                if (decimales == 0) {
                    valor = valor * 10 + Double.parseDouble(token);
                } else {
                    valor *= Math.pow(10.0, decimales);
                    valor += Double.parseDouble(token);
                    valor /= Math.pow(10.0, decimales);
                    modelo.setDecimales(++decimales);
                }

                modelo.setAcumulado(valor);
                vista.cargarValorDisplay(Double.toString(valor));
            }

            modelo.setTip("number");
            vista.repaint();
        }
    }

    private class TipOperadorListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent ae) {
            String token = ((JButton) ae.getSource()).getText();
            String operacion = modelo.getOperacion();
            String tipPrevio = modelo.getTip();

            if ("+-*/".contains(token)) {
                if ("number".equals(tipPrevio)) {
                    double acumulado = modelo.getAcumulado();
                    double display = Double.parseDouble(vista.obtenerValorDisplay());
                    double resultado = 0.0;

                    switch (operacion) {
                        case "+" -> {
                            resultado = MCalculadora.sumar(acumulado, display);
                        }
                        case "-" -> {
                            resultado = MCalculadora.restar(acumulado, display);
                        }
                        case "*" -> {
                            resultado = MCalculadora.multiplicar(acumulado, display);
                        }
                        case "/" -> {
                            resultado = MCalculadora.dividir(acumulado, display);
                        }
                        case "none" -> {
                            resultado = MCalculadora.sumar(acumulado, display);
                        }
                    }

                    modelo.setAcumulado(resultado);
                    modelo.setOperacion(token);
                }
            }

            modelo.setTip("operator");
        }
    }

    private class TipOtroListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent ae) {
            String token = ((JButton) ae.getSource()).getText();

            switch (token) {
                case "DEL" -> {
                    modelo.init();
                    vista.cargarValorDisplay("0.0");
                }
                case "C" -> {
                }
            }
        }
    }
}
