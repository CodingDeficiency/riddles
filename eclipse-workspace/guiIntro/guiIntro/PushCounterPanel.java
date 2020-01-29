package guiIntro;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JTextField;
import javax.swing.JSpinner;
import javax.swing.JTextArea;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.JSlider;
import javax.swing.event.ChangeListener;
import javax.swing.event.ChangeEvent;

public class PushCounterPanel extends JPanel{
	private int count;
	private JButton push;
	private JButton fastChange;
	private JButton clear;
	private JLabel lblCounter;
	private JLabel oddEven;
	private JPasswordField passwordField;
	private JTextField sliderValue;
	
	public PushCounterPanel() {
		count = 0;
		push = new JButton ("Push Me!");
		push.setBounds(30, 50, 128, 23);
		push.addActionListener(new ButtonListener());
		
		fastChange = new JButton("Push Me x5");
		fastChange.setBounds(30, 75, 128, 23);
		fastChange.addActionListener(new ButtonListener());
		add(fastChange);		
		
		
		clear = new JButton ("Clear");
		clear.setBounds(168, 50, 74, 23);
		clear.addActionListener(new ButtonListener());		
		lblCounter = new JLabel ("counter: 0");		
		lblCounter.setBounds(252, 54, 95, 14);
		oddEven = new JLabel ("Odd");
		oddEven.setBounds(252, 79, 95, 14);
		oddEven.setVisible(false);
		setLayout(null);
		
		
		add (push);
		add(clear);
		add(lblCounter);
		add(oddEven);
		setBackground(Color.LIGHT_GRAY);
		setPreferredSize(new Dimension(414, 394));
		
		passwordField = new JPasswordField();
		passwordField.setBounds(30, 148, 161, 41);
		add(passwordField);

		
		final JTextArea showPassword = new JTextArea();
		showPassword.setBounds(243, 205, 48, 108);
						
		JScrollPane scrollPane = new JScrollPane(showPassword);
		scrollPane.setBounds(201, 160, 146, 109);
		add(scrollPane);
		
		JButton btnClicker = new JButton("show password");
		btnClicker.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent arg0) {
				String toShow = "";
				for (int i=0; i < 10; i++){
					toShow += new String(passwordField.getPassword())+" \n ";
				}
				showPassword.setText(toShow);
			}
		});
		btnClicker.setBounds(201, 126, 146, 23);
		add(btnClicker);

		sliderValue = new JTextField();
		sliderValue.setText("0");
		sliderValue.setBounds(21, 292, 86, 20);
		add(sliderValue);
		sliderValue.setColumns(10);		
		
		final JSlider slider = new JSlider(0,150,70);
		sliderValue.setText(""+slider.getValue());
		slider.addChangeListener(new ChangeListener() {
			public void stateChanged(ChangeEvent arg0) {
				sliderValue.setText(""+slider.getValue());
			}
		});
		slider.setBounds(21, 320, 200, 23);
		add(slider);	
		
		JLabel lblEnterPassword = new JLabel("Enter password");
		lblEnterPassword.setBounds(30, 130, 98, 14);
		add(lblEnterPassword);

	}
	
	private class ButtonListener implements ActionListener {
		public void actionPerformed (ActionEvent event){
			if (event.getSource()== push) {
				System.out.println("slow button");
				count++;
			}	
			if (event.getSource()== fastChange) {
				System.out.println("fast button");
				count+=5;		
			}
			if (event.getSource()== clear) {
				System.out.println("clear button");
				count=0;		
			}			
			lblCounter.setText ("Pushes: "+count);
			if (count%2==1)
				oddEven.setVisible(true);
			else
				oddEven.setVisible(false);
		}
	}	

}
