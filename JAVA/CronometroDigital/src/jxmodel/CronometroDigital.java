package jxmodel;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class CronometroDigital extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        var root = (Parent) FXMLLoader.load(getClass().getResource("/jxview/VCronometroDigital.fxml"));
        var scene = new Scene(root);
        var css = getClass().getResource("/assets/vcronometrodigital.css").toExternalForm();
        Font.loadFont(getClass().getResourceAsStream("/assets/E1234-p7pER.ttf"), 11);
        scene.getStylesheets().add(css);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Cronometro Digital");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

// MVC en JavaFX - https://edencoding.com/mvc-in-javafx/#:~:text=MVC%20stands%20for%20Model-View-Controller%2C%20and%20JavaFX%20is%20fundamentally,separate%20the%20business%20logic%20from%20the%20user%20interface.
// CSS en JavaFX - https://docs.oracle.com/javafx/2/api/javafx/scene/doc-files/cssref.html

// https://stackoverflow.com/questions/54495381/how-to-dynamically-change-font-size-in-ui-to-always-be-the-same-width-in-javafx
