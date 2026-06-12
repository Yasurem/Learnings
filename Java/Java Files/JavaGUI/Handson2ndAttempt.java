import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Handson2ndAttempt extends JFrame {
    //declare needed variables


    private JRadioButton rbOneWay, rbRoundTrip, rbDomestic, rbInternational, rbDiscount;

    private JLabel lblTitle, lblDestination, lblReturn, lblFrom, lblTo, lblDiscount, lblVoucher, lblTotalCost;

    private JTextField tfDestination, tfReturn, tfVoucher, tfTotalCost;

    private JComboBox cbFrom, cbTo;

    private JButton btnCalculate;

    private double flightFee;

    String additionalOpionals[] = {"Additional 20kg luggage", "Additional 12kg luggage", "Meals", "Closed Seat"};

    String cbDomesticFrom[] = {"Manila", "Cebu"};
    String cbInternationalFrom[] = {"Manila", "Hong Kong"};
    String cbDomesticTo[] = {"Manila", "Cebu"};
    String cbInternationalTo[] = {"Manila", "Hong Kong"};

    private JPanel panelTitle, panelRadioButton, panelTrip, panelDestination,
                    panelFromTo, panelAdditionals, panelDiscounts, panelFee;

    public Handson2ndAttempt() {

        Container container = getContentPane();
        container.setLayout(new BoxLayout(container, BoxLayout.Y_AXIS));

        //for title
        panelTitle = new JPanel(new FlowLayout(FlowLayout.CENTER));

        lblTitle = new JLabel("ABC Travels");

        panelTitle.add(lblTitle);
        add(panelTitle);

        //radiobuttons
        panelRadioButton = new JPanel(new GridLayout(2,2));

        ButtonGroup group1 = new ButtonGroup();
        ButtonGroup group2 = new ButtonGroup();

        rbOneWay = createRadio("One Way", group1, panelRadioButton);
        rbRoundTrip = createRadio("Round Trip", group1, panelRadioButton);
        rbDomestic = createRadio("Domestic", group2, panelRadioButton);
        rbInternational = createRadio("International", group2, panelRadioButton);

        add(panelRadioButton);

        //destianiton
        panelDestination = new JPanel(new FlowLayout(FlowLayout.CENTER));

        lblDestination = new JLabel("DESTINATION");
        lblReturn = new JLabel("RETURN");
        tfDestination = new JTextField(25);
        tfReturn = new JTextField(25);

        tfDestination.setEditable(false);
        tfReturn.setEditable(false);


        panelDestination.add(lblDestination);
        panelDestination.add(tfDestination);
        panelDestination.add(lblReturn);
        panelDestination.add(tfReturn);
        add(panelDestination);

        //checkbox
        panelFromTo = new JPanel(new GridLayout(2,2));

        lblFrom = new JLabel("FROM:");
        lblTo = new JLabel("TO:");

        cbFrom = new JComboBox<>();
        cbTo = new JComboBox<>();

        panelFromTo.add(lblFrom);
        panelFromTo.add(cbFrom);
        panelFromTo.add(lblTo);
        panelFromTo.add(cbTo);
        add(panelFromTo);

        //discount
        panelDiscounts = new JPanel(new GridLayout(2,2));

        ButtonGroup group3 = new ButtonGroup();

        lblDiscount = new JLabel("DISCOUNTS");
        lblVoucher = new JLabel("VOUCHERS");

        tfVoucher = new JTextField(25);

        panelDiscounts.add(lblDiscount);
        panelDiscounts.add(lblVoucher);
        rbDiscount = createRadio("PWD / Senior Citizen", group3, panelDiscounts);
        panelDiscounts.add(tfVoucher);
        add(panelDiscounts);

        //fee
        panelFee = new JPanel(new FlowLayout(FlowLayout.CENTER));

        btnCalculate = new JButton("Total Fee");
        tfTotalCost = new JTextField(25);

        panelFee.add(btnCalculate);
        panelFee.add(tfTotalCost);
        add(panelFee);







        pack();
        setVisible(true);


    }

    private JRadioButton createRadio(String name, ButtonGroup group, JPanel panel) {
        JRadioButton rb = new JRadioButton(name);
        group.add(rb);
        panel.add(rb);

        return rb;
    }

    public static void main(String[] args) {
        Handson2ndAttempt application = new Handson2ndAttempt();
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}