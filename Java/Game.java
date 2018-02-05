import javax.swing.JButton;
import javax.swing.JPanel;

public class Game extends JPanel{
	private int map[][];
	private JButton mapS[][];
	
	public Game() {
		map = new int[3][3];
		mapS = new JButton[3][3];
	}

	private void initValues() {
		int k = 1;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				mapS[i][j] = new JButton((k == 9 ? String.valueOf(k) : " "));
				map[i][j] = k-1;
			}
		}
	}

	private void positionItems() {
		int x, y = 20;
		for(int i = 0; i < 3; j++) {
			x = 20;
			for(int j = 0; j < 3; j++) {
				mapS.setBounds(x, y, 50, 50);
				x += 60;
			}
			y+= 60;
		}
	}

	private void addItems() {
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				this.add(mapS);
			}
		}
	}
}