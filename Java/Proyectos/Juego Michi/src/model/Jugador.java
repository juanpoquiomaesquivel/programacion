package model;

import java.io.Serializable;

public class Jugador implements Serializable {

    public Jugador(String nickname, String figura, boolean turno) {
        this.nickname = nickname;
        this.figura = figura;
        this.turno = turno;
    }

    public String getNickname() {
        return nickname;
    }

    public void setNickname(String nickname) {
        this.nickname = nickname;
    }

    public String getFigura() {
        return figura;
    }

    public void setFigura(String figura) {
        this.figura = figura;
    }

    public String getIp() {
        return ip;
    }

    public void setIp(String ip) {
        this.ip = ip;
    }

    public boolean isTurno() {
        return turno;
    }

    public void setTurno(boolean turno) {
        this.turno = turno;
    }

    public String getJugada() {
        return jugada;
    }

    public void setJugada(String jugada) {
        this.jugada = jugada;
    }

    private String nickname;
    private String figura;
    private String ip;
    private boolean turno;
    private String jugada;
}
