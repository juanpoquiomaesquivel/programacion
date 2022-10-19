package jxcontroller;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ToggleButton;
import jxmodel.ModelChronometer;

public class ControllerDigitalChronometer implements Initializable {

    private ModelChronometer model;

    @FXML
    private Label display_minutes;

    @FXML
    private Label display_seconds;

    @FXML
    private Label display_miliseconds;

    @FXML
    private ToggleButton play_pause_button;

    @FXML
    private Button stop_button;

    @FXML
    public void handlePlayPauseButton(ActionEvent evt) {
        if (this.stop_button.isDisable()) {
            this.model.stop();
        } else {
            this.model.start();
        }

        this.stop_button.setDisable(this.play_pause_button.isSelected());
    }

    @FXML
    public void handleStopButton(ActionEvent evt) {
        this.model.reset();
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        this.model = new ModelChronometer(); // https://community.oracle.com/tech/developers/discussion/2531283/illegalstateexception-not-on-fx-application-thread
        this.model.getMilisecondsProperty().addListener((observable, oldValue, newValue) -> {
            Platform.runLater(() -> {
                this.display_miliseconds.setText((newValue.intValue() < 10 ? "00" : (newValue.intValue() < 100 ? "0" + newValue.toString().charAt(0) : newValue.toString().substring(0, 2))));
            });
        });
        this.model.getSecondsProperty().addListener((observable, oldValue, newValue) -> {
            Platform.runLater(() -> {
                this.display_seconds.setText((newValue.intValue() < 10 ? "0".concat(newValue.toString()) : newValue.toString()));
            });
        });
        this.model.getMinutesProperty().addListener((observable, oldValue, newValue) -> {
            Platform.runLater(() -> {
                this.display_minutes.setText((newValue.intValue() < 10 ? "0".concat(newValue.toString()) : newValue.toString()));
            });
        });
        this.display_miliseconds.layoutBoundsProperty().addListener((observable) -> {
            int newSize = (int) (this.display_miliseconds.getWidth() / 2);
            this.display_miliseconds.setStyle("-fx-font-size: " + newSize + "px;");
        });
        this.display_seconds.layoutBoundsProperty().addListener((observable) -> {
            int newSize = (int) (this.display_seconds.getWidth() / 2);
            this.display_seconds.setStyle("-fx-font-size: " + newSize + "px;");
        });
        this.display_minutes.layoutBoundsProperty().addListener((observable) -> {
            int newSize = (int) (this.display_minutes.getWidth() / 2);
            this.display_minutes.setStyle("-fx-font-size: " + newSize + "px;");
        });
    }

    public void dispose() {
        this.model.stop();
    }
}
