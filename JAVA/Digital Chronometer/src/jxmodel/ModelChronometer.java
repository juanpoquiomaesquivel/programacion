package jxmodel;

import javafx.beans.property.IntegerProperty; // https://docs.oracle.com/javase/8/javafx/properties-binding-tutorial/binding.htm#JFXBD107
import javafx.beans.property.SimpleIntegerProperty;
import javax.swing.Timer;

public class ModelChronometer {

    private static final int STEP = 10;

    public ModelChronometer() {
        this.miliseconds = new SimpleIntegerProperty();
        this.seconds = new SimpleIntegerProperty();
        this.minutes = new SimpleIntegerProperty();
        this.chrono = new Timer(ModelChronometer.STEP, (var ae) -> {
            this.miliseconds.set(this.miliseconds.get() + ModelChronometer.STEP);

            if (this.miliseconds.get() == 1000) {
                this.miliseconds.set(0);
                this.seconds.set(this.seconds.get() + 1);

                if (this.seconds.get() == 60) {
                    this.seconds.set(0);
                    this.minutes.set(this.minutes.get() + 1);

                    if (this.minutes.get() == 100) {
                        this.reset();
                    }
                }
            }
        });
        this.reset();
    }

    private Timer chrono;
    private IntegerProperty miliseconds;
    private IntegerProperty seconds;
    private IntegerProperty minutes;

    public final void start() {
        this.chrono.start();
    }

    public final void stop() {
        this.chrono.stop();
    }

    public final void reset() {
        this.miliseconds.set(0);
        this.seconds.set(0);
        this.minutes.set(0);
    }

    public final int getMiliseconds() {
        return this.miliseconds.get();
    }

    public IntegerProperty getMilisecondsProperty() {
        return this.miliseconds;
    }

    public final int getSeconds() {
        return this.seconds.get();
    }

    public IntegerProperty getSecondsProperty() {
        return this.seconds;
    }

    public final int getMinutes() {
        return this.minutes.get();
    }

    public IntegerProperty getMinutesProperty() {
        return this.minutes;
    }
}
