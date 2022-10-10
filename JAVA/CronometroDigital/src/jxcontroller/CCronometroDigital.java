package jxcontroller;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.animation.KeyFrame;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Bounds;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleButton;
import javafx.scene.input.SwipeEvent;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.util.Duration;
import jxmodel.MCronometro;

public class CCronometroDigital implements Initializable {

    private MCronometro modelo;

    @FXML
    private Label display;

    @FXML
    private Label bgdisplay;

    @FXML
    private ToggleButton btnPlayPause;

    @FXML
    private Button btnReset;

    @FXML
    private void eventoBtnPlayPause(ActionEvent evt) {
        if (this.btnReset.isDisable()) {
            this.modelo.pause();
        } else {
            this.modelo.play();
        }

        this.btnReset.setDisable(this.btnPlayPause.isSelected());
        //this.display.setStyle("-fx-font-size: 50px;");
    }

    @FXML
    private void eventoBtnReset(ActionEvent evt) {
        this.modelo.reset();
        this.display.setText("00:00:00");
    }

    private void cronometro() {
        this.modelo.milisegundos += MCronometro.MILLIS_STEP;

        if (this.modelo.milisegundos == 1000) {
            this.modelo.milisegundos = 0;
            this.modelo.segundos++;

            if (this.modelo.segundos == 60) {
                this.modelo.minutos++;
                this.modelo.segundos = 0;

                if (this.modelo.minutos == 100) {
                    this.modelo.reset();
                }
            }
        }

        var ms = Integer.toString(this.modelo.milisegundos);
        var ss = Integer.toString(this.modelo.segundos);
        var mm = Integer.toString(this.modelo.minutos);
        ms = (this.modelo.milisegundos < 100 ? "0" + ms.charAt(0) : ms.substring(0, 2));
        ms = (this.modelo.milisegundos < 10 ? "00" : ms);
        ss = (this.modelo.segundos < 10 ? "0" + ss : ss);
        mm = (this.modelo.minutos < 10 ? "0" + mm : mm);

        this.display.setText(mm + ":" + ss + ":" + ms);
    }

    private final double defaultSize = 15;

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        this.display.layoutBoundsProperty().addListener((observable) -> {
            double ww = this.display.getWidth();
            double hh = this.display.getHeight();

            if (ww == 0) {
                ww = this.display.getMinWidth();
            }

            if (hh == 0) {
                hh = this.display.getMinHeight();
            }

            double w = ww / this.display.getMinWidth();
            double h = hh / this.display.getMinHeight();
            double coefW = this.display.getMinWidth() / defaultSize;
            double coefH = this.display.getMinHeight() / defaultSize;
            int newSize = (int) (coefW * w + coefH * h);

            this.display.setStyle("-fx-font-size: " + newSize + "px;");
        });
        this.bgdisplay.layoutBoundsProperty().addListener((observable) -> {
            double ww = this.bgdisplay.getWidth();
            double hh = this.bgdisplay.getHeight();

            if (ww == 0) {
                ww = this.bgdisplay.getMinWidth();
            }

            if (hh == 0) {
                hh = this.bgdisplay.getMinHeight();
            }

            double w = ww / this.bgdisplay.getMinWidth();
            double h = hh / this.bgdisplay.getMinHeight();
            double coefW = this.bgdisplay.getMinWidth() / defaultSize;
            double coefH = this.bgdisplay.getMinHeight() / defaultSize;
            int newSize = (int) (coefW * w + coefH * h);

            this.bgdisplay.setStyle("-fx-font-size: " + newSize + "px;");
        });
        this.modelo = new MCronometro(new KeyFrame(Duration.millis(MCronometro.MILLIS_STEP), evt -> this.cronometro()));
    }
}
