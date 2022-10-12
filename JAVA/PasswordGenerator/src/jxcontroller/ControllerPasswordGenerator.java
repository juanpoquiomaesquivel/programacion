package jxcontroller;

import java.awt.Toolkit;
import java.awt.datatransfer.StringSelection;
import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import jxmodel.ModelPasswordGenerator;

public class ControllerPasswordGenerator implements Initializable {

    private ModelPasswordGenerator passwordGenerator;

    @FXML
    private TextField passwordField;

    @FXML
    private void copiarPasswordField(MouseEvent evt) {
        var cb = Toolkit.getDefaultToolkit().getSystemClipboard();
        var str = new StringSelection(this.passwordField.getText());
        cb.setContents(str, null);
    }

    @FXML
    private void limpiarPasswordField(MouseEvent evt) {
        this.passwordField.setText("");
    }

    @FXML
    private void generarPassword(ActionEvent evt) {
        var password = this.passwordGenerator.generatePassword(24);
        this.passwordField.setText(password);
    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {
        this.passwordGenerator = new ModelPasswordGenerator();
    }

}
