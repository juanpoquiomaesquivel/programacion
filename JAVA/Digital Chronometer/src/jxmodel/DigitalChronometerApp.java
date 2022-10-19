package jxmodel;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import jxcontroller.ControllerDigitalChronometer;

public class DigitalChronometerApp extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        var fxml = new FXMLLoader(getClass().getResource("/jxview/ViewDigitalChronometer.fxml")); // https://foroayuda.es/javafx-como-obtener-el-escenario-del-controlador-durante-la-inicializacion/
        var root = (Parent) fxml.load();
        var scene = new Scene(root);
        var controller = (ControllerDigitalChronometer) fxml.getController();
        var css = getClass().getResource("/assets/viewdigitalchronometer.css").toExternalForm();
        Font.loadFont(getClass().getResourceAsStream("/assets/E1234-p7pER.ttf"), 20);
        scene.getStylesheets().add(css);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Digital Chronometer");
        primaryStage.show();
        primaryStage.setOnCloseRequest((evt) -> {
            controller.dispose();
        });
    }

    public static void main(String[] args) {
        launch(args);
    }
}
