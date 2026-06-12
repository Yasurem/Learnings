import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class Practice {
    public static void main(String[] args) {
        // Create JFrame
        JFrame mainframe = new JFrame("JM's Program");
        int width = 720;
        int height = 480;
        Color bgColor = new Color(0x00ff00);
        LayoutManager manager = new FlowLayout();
        mainframe.setSize(width, height);
        mainframe.setResizable(false);
        mainframe.setBackground(bgColor);
        mainframe.setLayout(manager);

        // Create objects inside the frame
        JButton button = new JButton("Don't Click Me!");
        JLabel label = new JLabel("Should you click me?");
        JTextField field = new JTextField(10);

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                label.setText(field.getText());
            }
        });

        // Add the components inside the frame
        mainframe.add(button);
        mainframe.add(label);
        mainframe.add(field);

        // Make frame visible
        mainframe.setVisible(true);
    }
}
