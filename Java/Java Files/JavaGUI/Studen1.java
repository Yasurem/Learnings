import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import javax.swing.text.*;

public class Studen1 {
    JFrame frame;
    JPanel pnlWest, pnlCenter, pnlSouth;
    
    String[] strLabels = {"Name", "Number", "Bday","Email","Confirm Email","Password","Confirm Password","Course","Semester",};
    JFormattedTextField ftfField[] = new JFormattedTextField[strLabels.length];
    String[] strCourses = {"BSCS", "BSIT", "BSIS"};
    JComboBox<String> cbCourse;
    ButtonGroup btnGroup;
    JRadioButton rbSem1, rbSem2;
    JTextArea taDisplay;
    JButton btnAdd, btnReset, btnClear;
    JPasswordField pwMain, pwConfirm;
    
    Studen1() throws Exception {
        frame = new JFrame();
        frame.setLayout(new BorderLayout());
        
        JLabel lbHeader = new JLabel("Account Register");
        
        pnlWest = createWestPanel();
        pnlCenter = createCenterPanel();
        pnlSouth = createSouthPanel();
        
        frame.add(lbHeader, BorderLayout.NORTH);
        frame.add(pnlWest, BorderLayout.WEST);
        frame.add(pnlCenter, BorderLayout.CENTER);
        frame.add(pnlSouth, BorderLayout.SOUTH);
        
        frame.pack();
        frame.setVisible(true);
    }
    
    JPanel createWestPanel(){
        JPanel panel = new JPanel(new GridLayout(9, 1));
        
        for(int i = 0; i < strLabels.length; i++){
            JLabel lbTextField = new JLabel(strLabels[i]);
            panel.add(lbTextField);
        }
        
        return panel;
    }
    
    JPanel createCenterPanel() throws Exception  {
        JPanel panel = new JPanel(new GridLayout(9, 1));
        
        for(int i = 0; i < strLabels.length - 4; i++){
            ftfField[i] = new JFormattedTextField();
            
            if(i == 1) {
                ftfField[i].setFormatterFactory(new DefaultFormatterFactory(new MaskFormatter("###########")));
            } else if ( i == 2) {
                ftfField[i].setFormatterFactory(new DefaultFormatterFactory(new MaskFormatter("####-##-##")));
            }
            panel.add(ftfField[i]);
        }
        
        pwMain = new JPasswordField();
        pwConfirm = new JPasswordField();
        panel.add(pwMain);
        panel.add(pwConfirm);
        
        
        cbCourse = new JComboBox<>(strCourses);
        panel.add(cbCourse);
        
        btnGroup = new ButtonGroup();
        rbSem1 = new JRadioButton("1st Semester");
        rbSem2 = new JRadioButton("2nd Semester");
        
        btnGroup.add(rbSem1);
        btnGroup.add(rbSem2);
        
        JPanel pnl = new JPanel();
        pnl.add(rbSem1);
        pnl.add(rbSem2);
        
        panel.add(pnl);
        
        return panel;
    }
    
    JPanel createSouthPanel(){
        JPanel panel = new JPanel(new GridLayout(2, 1));
        
        taDisplay = new JTextArea(5, 3);
        
        JPanel pnlbtn = new JPanel();
        btnAdd = new JButton("btnADD");
        btnReset = new JButton("btnReset");
        btnClear = new JButton("btnClear");
        
        btnAdd.addActionListener(e -> {
            int validCount = 0;
            boolean isValid = false;
            for(int i = 0; i < strLabels.length - 4;i++) {
                if(!ftfField[i].getText().isEmpty()) {
                    validCount++;
                }
            }
            
            if((ftfField[3].getText().endsWith("@gmail.com") || ftfField[3].getText().endsWith("@yahoo.com"))&&
               ftfField[3].getText().equals(ftfField[4].getText())){
                validCount++;
            }
            String pwM = new String(pwMain.getPassword());
            String pwC = new String(pwConfirm.getPassword());
            
            if (pwM.equals(pwC)) {
                validCount++;
            }
            
            if(validCount == 7 && (rbSem1.isSelected() || rbSem2.isSelected())) {
                isValid = true;
            }
            
            if(isValid) {
                taDisplay.append(ftfField[0].getText() + " - " + cbCourse.getSelectedItem());
            }
            System.out.println(validCount);
            
        });
        
        btnReset.addActionListener(e -> {
            for(JFormattedTextField i: ftfField) {
                i.setValue(null);
            }
            pwMain.setText("");
            pwConfirm.setText("");
            
            cbCourse.setSelectedIndex(0);
            taDisplay.setText("");
            
        });
        pnlbtn.add(btnAdd);
        pnlbtn.add(btnReset);
        pnlbtn.add(btnClear);
        
        panel.add(taDisplay);
        panel.add(pnlbtn);
        
        return panel;
    }
    
    public static void main(String[] args) throws Exception {
        SwingUtilities.invokeLater(() -> {
        try {
            new Studen1();
       
        } catch (Exception e) {
            System.out.println("Failed");
        }
        });
    }
}

