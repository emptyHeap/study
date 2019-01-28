package ru.gritsus.imkn.oop.java;

import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

public class Task203 {
	
	public static void main(String[] args) {
		javax.swing.SwingUtilities.invokeLater(new Runnable() {
			
			@Override
			public void run() {
				// TODO Auto-generated method stub
		        JFrame jFrame = new JFrame();
		        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		        jFrame.getContentPane().setLayout(new BoxLayout(jFrame.getContentPane(), BoxLayout.Y_AXIS));
		        
		        JTextField inputField = new JTextField();
		    	BannerPanel bannerPanel = new BannerPanel();
		    	
		    	inputField.getDocument().addDocumentListener(new DocumentListener() {
					
					@Override
					public void removeUpdate(DocumentEvent e) {
						bannerPanel.setText(inputField.getText());
					}
					
					@Override
					public void insertUpdate(DocumentEvent e) {
						bannerPanel.setText(inputField.getText());
					}
					
					@Override
					public void changedUpdate(DocumentEvent e) {
					}
				});

		        jFrame.add(inputField);
		        jFrame.add(bannerPanel);

		        jFrame.pack();
		        jFrame.setVisible(true);
			}
		});
	}
}
