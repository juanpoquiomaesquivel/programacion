package jxcalculadora.modelo;

public final class MCalculadora {

    public static double sumar(double a, double b) {
        return a + b;
    }

    public static double restar(double a, double b) {
        return a - b;
    }

    public static double multiplicar(double a, double b) {
        return a * b;
    }

    public static double dividir(double a, double b) {
        return a / b;
    }

    public MCalculadora() {
        this.init();
    }

    private double acumulado;
    private int decimales;
    private String operacion;
    private String tip;

    public double getAcumulado() {
        return acumulado;
    }

    public void setAcumulado(double acumulado) {
        this.acumulado = acumulado;
    }

    public int getDecimales() {
        return decimales;
    }

    public void setDecimales(int decimal) {
        this.decimales = decimal;
    }

    public String getOperacion() {
        return operacion;
    }

    public void setOperacion(String operacion) {
        this.operacion = operacion;
    }

    public String getTip() {
        return tip;
    }

    public void setTip(String tip) {
        this.tip = tip;
    }

    public void init() {
        this.acumulado = 0.0;
        this.decimales = 0;
        this.operacion = "none";
        this.tip = "none";
    }
}
