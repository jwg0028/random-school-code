import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JButton;
import javax.swing.JFrame;
public class Checkers {
   public static void main(String[] args) {
      JFrame frame = new JFrame("Checkers");
      
      JButton button = new JButton("Click to Close!");
      button.setPreferredSize(new Dimension(40, 40));
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      Checkers content = new Checkers();
      button.addActionListener(e -> {
         frame.dispose();
      });
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.setPreferredSize(new Dimension(1000, 300));
      frame.getContentPane().setBackground(Color.red);
      frame.pack();
      frame.setVisible(true);
   }
}
   
    
