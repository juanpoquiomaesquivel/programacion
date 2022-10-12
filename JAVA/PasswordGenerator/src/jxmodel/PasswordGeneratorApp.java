package jxmodel;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class PasswordGeneratorApp extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception {
        var root = (Parent) FXMLLoader.load(getClass().getResource("/jxview/ViewPasswordGenerator.fxml"));
        var scene = new Scene(root);
        var css = getClass().getResource("/assets/viewpasswordgenerator.css").toExternalForm();
        Font.loadFont(getClass().getResourceAsStream("/assets/fonts/PasswordBook.ttf"), 30); // https://www.cufonfonts.com/font/password
        scene.getStylesheets().add(css);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Password Generator");
        primaryStage.show();
    }
    
    public static void main(String[] args) {
        launch(args);
    }
}
