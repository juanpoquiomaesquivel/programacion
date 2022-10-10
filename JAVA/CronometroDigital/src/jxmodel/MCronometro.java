package jxmodel;

import javafx.animation.Animation;
import javafx.animation.KeyFrame;
import javafx.animation.Timeline;

public class MCronometro {

    public static final int MILLIS_STEP = 10;

    public MCronometro(KeyFrame kf) {
        this.timeline = new Timeline(kf);
        this.timeline.setCycleCount(Animation.INDEFINITE);
        this.reset();
    }

    private final Timeline timeline;
    public int minutos;
    public int segundos;
    public int milisegundos;

    public void play() {
        this.timeline.play();
    }

    public void pause() {
        this.timeline.pause();
    }

    public void reset() {
        this.minutos = this.segundos = this.milisegundos = 0;
    }
}
